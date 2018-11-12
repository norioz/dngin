#pragma once

#include <math.h>
#include "Scalar.h"

// ---------
// Vector
// ----------
// convert to a Scalar pointer (implicit conversion?) -- doc this

union Vector2 {
    struct { Scalar x, y; };
    Scalar v[2];
    const Scalar & operator[] (size_t idx) const { return v[idx]; }
    Scalar & operator[] (size_t idx) { return v[idx]; }
    Vector2 & operator= (Vector2 & other);
    Vector2 operator- () { return Vector2{ -x, -y }; };
    Vector2 & operator+= (const Vector2 & other);
    Vector2 & operator-= (const Vector2 & other);
    Vector2 & operator/= (Scalar s);
    Vector2 & operator*= (Scalar s);
};

inline Vector2 & Vector2::operator= (Vector2 & other) {
    x = other.x;
    y = other.y;
    return *this;
}

inline Vector2 & Vector2::operator+= (const Vector2 & other) {
    x += other.x;
    y += other.y;
    return *this;
}

inline Vector2 & Vector2::operator-= (const Vector2 & other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

inline Vector2 & Vector2::operator*= (Scalar s) {
    x *= s;
    y *= s;
    return *this;
}

inline Vector2 & Vector2::operator/= (Scalar s) {
    x /= s;
    y /= s;
    return *this;
}

inline Vector2 operator+ (Vector2 a, Vector2 b) {
    return Vector2{ a.x + b.x, a.y + b.y };
}

inline Vector2 operator- (Vector2 a, Vector2 b) {
    return Vector2{ a.x - b.x, a.y - b.y };
}

inline Vector2 operator* (Vector2 v, Scalar f) {
    return Vector2{ v.x * f , v.y * f };
}

inline Vector2 operator* (Scalar f, Vector2 v) {
    return v * f;
}

inline Vector2 operator/ (Vector2 v, Scalar f) {
    return Vector2{ v.x / f, v.y / f };
}

inline bool operator== (Vector2 a, Vector2 & b) {
    return Scalar(a.x) == Scalar(b.x) && Scalar(a.y) == Scalar(b.y);
}

inline bool operator!= (Vector2 & a, Vector2 & b) {
    return !(a == b);
}

// magnitude
inline Scalar magnitudeSq (Vector2 & v) {
    return v.x * v.x + v.y * v.y;
}

inline Scalar magnitude (Vector2 & v) {
    return sqrtf(magnitudeSq(v));
}

// normalize
inline Vector2 normalize (Vector2 & v) {
    Scalar m = magnitude(v);
    if (m == Scalar{ 0 }) {
        return Vector2{ 0, 0 };
    }
    return Vector2{ v.x / m, v.y / m };
}

// perpendicular
// Returns a vector that is perpendicular to the given vector.
// Direction is no considerred.
// (x, y) = > (-y, x)
inline Vector2 perpendicular (Vector2 & v) {
    return Vector2{ -v.y, v.x };
}

// distance
inline Scalar distSq (Vector2 & a, Vector2 & b) {
    Scalar dx = a.x - b.x, dy = a.y - b.y;
    return (dx * dx + dy * dy);
}

inline Scalar dist (Vector2 & a, Vector2 & b) {
    return sqrtf(distSq(a, b));
}

//min
Vector2 min (Vector2 & a, Vector2 & b) {
    return Vector2{ min(a.x, b.x), min(a.y, b.y) };
}

template<typename... Args>
Vector2 min (Vector2 & a, Vector2 & b, Args... args) {
    return min(min(a, b), args...);
}

// max
Vector2 max (Vector2 & a, Vector2 & b) {
    return Vector2{ max(a.x, b.x), max(a.y, b.y) };
}

template<typename... Args>
Vector2 max (Vector2 & a, Vector2 b, Args... args) {
    return max(max(a, b), args...);
}

// Scalar product - dot product
Scalar sprod (Vector2 a, Vector2 b) {
    return a.x * b.x + a.y * b.y;
}

// projection
// project a onto b
Vector2 project (Vector2 & a, Vector2 & b) {
    Scalar bb = sprod(b, b);
    if (Scalar(bb) == Scalar(0)) {
        return Vector2{ 0, 0 };
    }
    return (sprod(a, b) / bb) * b;
}

// deprojection -- vector rejection
// deproject a onto b
Vector2 deproject (Vector2 & a, Vector2 & b) {
    Vector2 p = project(a, b);
    return a - p;
}

//reflect
// n := normal vector
// i := incident vector
// Credit: HLSL documentation; GLSL spec documentation
Vector2 reflect (Vector2 & i, Vector2 & n) {
    return i - 2.f * sprod(i, n) * n;
}

// refract
// o := incident
// n := normal
// eta := refraction index
Vector2 refract (Vector2 & i, Vector2 & n, Scalar eta) {
    Scalar nDotI = sprod(n, i);
    Scalar k = 1.f - eta * eta * (1.f - nDotI * nDotI);
    if (k < 0.f) {
        return Vector2{0, 0};
    }
    return eta * i - (eta * nDotI + sqrtf(k)) * n;
}

// clamp
// component wise clamp
Vector2 clamp (Vector2 & v, Vector2 & low, Vector2 & high) {
    return Vector2{ clamp(v.x, low.x, high.x), clamp(v.y, low.y, high.y) };
}

//clampM
// Constrains the magnitude of the vector to less than or
// equal to the passed in magnitude (maxLength).
Vector2 clampM (Vector2 & v, Scalar maxLength) {
    Scalar mag = magnitude(v);
    Vector2 result = v;
    if (mag > maxLength) {
        (result / mag) * maxLength;
    }
    return result;
}

//snap
Vector2 snap (Vector2 & v, Vector2 & low, Vector2 & high) {
    return Vector2{ snap(v.x, low.x, high.x), snap(v.y, low.y, high.y) };
}

// lerp
// component wise lerp
Vector2 lerp (Vector2 & a, Vector2 & b, Scalar t) {
    return Vector2{ lerp(a.x, b.x, t), lerp(a.y, b.y, t) };
}

// slerp
// Spherically interpolates between two vectors.
// Interpolates between a and b by amount t.
// The direction of the returned vector is interpolated by the angle
// and its magnitude is the interpolation beteen the magnitudes of a
// and b.
//Vector2 slerp (Vector2 & a, Vector2 & b) {
//    
//}
