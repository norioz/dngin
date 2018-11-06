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

inline Vector2 & Vector2::operator= (Vector2 & other) {
    x = other.x;
    y = other.y;
    return *this;
}

inline Vector2 Vector2::operator-() {
    Vector2 v;
    v.x = -x;
    v.y = -y;
    return v;
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
    return Scalar(a.x) == Scalar(b.x) && Scalar(a.y) == Scalar(b.y);
}

inline bool operator!= (Vector2 & a, Vector2 & b) {
    return !(a == b);
}

inline float magnitudeSq (Vector2 & v) {
    return v.x * v.x + v.y * v.y;
}

inline float magnitude (Vector2 & v) {
    return sqrtf(magnitudeSq(v));
}

inline Vector2 normalize (Vector2 & v) {
    Scalar m = magnitude(v);
    if (m == Scalar{ 0 }) {
        return Vector2{ 0, 0 };
    }
    return Vector2{ v.x / m, v.y / m };
}

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
float sprod (Vector2 a, Vector2 b) {
    return a.x * b.x + a.y * b.y;
}

// projection
// project a onto b
Vector2 project (Vector2 & a, Vector2 & b) {
    float bMSq = magnitudeSq(b);
    if (Scalar(bMSq) == Scalar(0)) {
        return Vector2{ 0, 0 };
    }
    return b * (sprod(b, a) / bMSq);
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
Vector2 refract (Vector2 & i, Vector2 & n, float eta) {
    float nDotI = sprod(n, i);
    float k = 1.f - eta * eta * (1.f - nDotI * nDotI);
    if (k < 0.f) {
        return Vector2{0, 0};
    }
    return eta * i - (eta * nDotI + sqrtf(k)) * n;
}

//clamp
//snap

//lerp

// ----------

union Vector3 {
    struct { float x, y, z; };
    const float & operator[] (size_t idx) const { }
    float & operator[] (size_t idx) { }
    Vector3 & operator+= (const Vector3 & other);
    Vector3 & operator-= (const Vector3 & other);
    Vector3 & operator/= (float scalar);
    Vector3 & operator*= (float scalar);
};

inline Vector3 & Vector3::operator+= (const Vector3 & other) {
    // UNIMPLEMENTED
    return *this;
}

inline Vector3 & Vector3::operator-= (const Vector3 & other) {
    // UNIMPLEMENTED
    return *this;
}

inline Vector3 & Vector3::operator*= (float scalar) {
    // UNIMPLEMENTED
    return *this;
}

inline Vector3 & Vector3::operator/= (float scalar) {
    // UNIMPLEMENTED
    return *this;
}

//cross product

