#pragma once

#include <math.h>
#include "Scalar.h"

// ---------
// Vector
// ----------
// convert to a float pointer (implicit conversion?) -- doc this

union Vector2 {
    struct { float x, y; };
    float v[2];
    const float & operator[] (size_t idx) const { return v[idx]; }
    float & operator[] (size_t idx) { return v[idx]; }
    Vector2 & operator= (Vector2 & other);
    Vector2 operator- ();
    Vector2 & operator+= (const Vector2 & other);
    Vector2 & operator-= (const Vector2 & other);
    Vector2 & operator/= (float scalar);
    Vector2 & operator*= (float scalar);
};

inline Vector2 Vector2::operator- () {
    Vector2 v;
    v.x = -x;
    v.y = -y;
    return v;
}

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

inline Vector2 & Vector2::operator*= (float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

inline Vector2 & Vector2::operator/= (float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

inline Vector2 operator+ (Vector2 a, Vector2 b) {
    Vector2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

inline Vector2 operator- (Vector2 a, Vector2 b) {
    Vector2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

inline Vector2 operator* (Vector2 v, float f) {
    Vector2 result;
    result.x = v.x * f;
    result.y = v.y * f;
    return result;
}

inline Vector2 operator* (float f, Vector2 v) {
    Vector2 result;
    result.x = v.x * f;
    result.y = v.y * f;
    return result;
}

inline Vector2 operator/ (Vector2 v, float f) {
    Vector2 result;
    result.x = v.x / f;
    result.y = v.y / f;
    return result;
}

inline bool operator== (Vector2 a, Vector2 & b) {
    return eq(a.x, b.x) && eq(a.y, b.y);
}

inline bool operator!= (Vector2 & a, Vector2 & b) {
    return !(a == b);
}

// magnitude
inline float magnitudeSq (Vector2 & v) {
    return v.x * v.x + v.y * v.y;
}

inline float magnitude (Vector2 & v) {
    return sqrtf(magnitudeSq(v));
}

// normalize
inline Vector2 normalize (Vector2 & v) {
    float m = magnitude(v);
    if (eq(m, 0.f)) {
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
inline float distSq (Vector2 & a, Vector2 & b) {
    float dx = a.x - b.x, dy = a.y - b.y;
    return (dx * dx + dy * dy);
}

inline float dist (Vector2 & a, Vector2 & b) {
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
float dot (Vector2 a, Vector2 b) {
    return a.x * b.x + a.y * b.y;
}

// projection
// project a onto b
Vector2 project (Vector2 & a, Vector2 & b) {
    float bb = dot(b, b);
    if (eq(bb, 0.f)) {
        return Vector2{ 0, 0 };
    }
    return (dot(a, b) / bb) * b;
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
    return i - 2.f * dot(i, n) * n;
}

// refract
// o := incident
// n := normal
// eta := refraction index
Vector2 refract (Vector2 & i, Vector2 & n, float eta) {
    float nDotI = dot(n, i);
    float k = 1.f - eta * eta * (1.f - nDotI * nDotI);
    if (lt(k, 0.f)) {
        return Vector2{ 0, 0 };
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
Vector2 clampM (Vector2 & v, float maxLength) {
    float mag = magnitude(v);
    Vector2 result = v;
    if (gt(mag, maxLength)) {
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
Vector2 lerp (Vector2 & a, Vector2 & b, float t) {
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
