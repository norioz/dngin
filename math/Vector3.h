#pragma once
#include <math.h>
#include "Scalar.h"

union Vector3 {
    struct { float x, y, z; };
    float v[3];
    const float & operator[] (size_t idx) const { return v[idx]; }
    float & operator[] (size_t idx) { return v[idx]; }
    Vector3 & operator= (const Vector3 & other);
    Vector3 & operator+= (const Vector3 & other);
    Vector3 & operator-= (const Vector3 & other);
    Vector3 & operator/= (float scalar);
    Vector3 & operator*= (float scalar);
    Vector3 operator- ();
};

inline Vector3 & Vector3::operator= (const Vector3 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

inline Vector3 & Vector3::operator+= (const Vector3 & other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

inline Vector3 & Vector3::operator-= (const Vector3 & other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

inline Vector3 & Vector3::operator*= (float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

inline Vector3 & Vector3::operator/= (float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
}

inline Vector3 operator+ (Vector3 a, Vector3 b) {
    Vector3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

inline Vector3 operator- (Vector3 a, Vector3 b) {
    Vector3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

inline Vector3 operator* (Vector3 v, float f) {
    Vector3 result;
    result.x = v.x * f;
    result.y = v.y * f;
    result.z = v.z * f;
    return result;
}

inline Vector3 operator* (float f, Vector3 v) {
    return v * f;
}

inline Vector3 operator/ (Vector3 v, float f) {
    Vector3 result;
    result.x = v.x / f;
    result.y = v.y / f;
    result.z = v.z / f;
    return result;
}

inline bool operator== (Vector3 a, Vector3 & b) {
    return Scalar(a.x) == Scalar(b.x) &&
        Scalar(a.y) == Scalar(b.y) &&
        Scalar(a.z) == Scalar(b.z);
}

inline bool operator!= (Vector3 & a, Vector3 & b) {
    return !(a == b);
}

// magnitude
inline float magnitudeSq (Vector3 & v) {
    // UNIMPLEMENTED
    return v.x * v.x + v.y * v.y;
}

inline float magnitude (Vector3 & v) {
    // UNIMPLEMENTED
    return sqrtf(magnitudeSq(v));
}

// norm
inline Vector3 normalize (Vector3 & v) {
    // UNIMPLEMENTED
    Scalar m = magnitude(v);
    if (m == Scalar{ 0 }) {
        return Vector3{ 0, 0 };
    }
    return Vector3{ v.x / m, v.y / m };
}

// distance
inline float distSq (Vector3 & a, Vector3 & b) {
    // UNIMPLEMENTED
    float dx = a.x - b.x, dy = a.y - b.y;
    return (dx * dx + dy * dy);
}

inline float dist (Vector3 & a, Vector3 & b) {
    // UNIMPLEMENTED
    return sqrtf(distSq(a, b));
}

//min
Vector3 min (Vector3 & a, Vector3 & b) {
    // UNIMPLEMENTED
    return Vector3{ min(a.x, b.x), min(a.y, b.y) };
}

template<typename... Args>
Vector3 min (Vector3 & a, Vector3 & b, Args... args) {
    // UNIMPLEMENTED
    return min(min(a, b), args...);
}

// max
Vector3 max (Vector3 & a, Vector3 & b) {
    // UNIMPLEMENTED
    return Vector3{ max(a.x, b.x), max(a.y, b.y) };
}

template<typename... Args>
Vector3 max (Vector3 & a, Vector3 b, Args... args) {
    // UNIMPLEMENTED
    return max(max(a, b), args...);
}

// Scalar product - dot product
float sprod (Vector3 a, Vector3 b) {
    // UNIMPLEMENTED
    return a.x * b.x + a.y * b.y;
}

// projection
// project a onto b
Vector3 project (Vector3 & a, Vector3 & b) {
    // UNIMPLEMENTED
    float bMSq = magnitudeSq(b);
    if (Scalar(bMSq) == Scalar(0)) {
        return Vector3{ 0, 0 };
    }
    return b * (sprod(b, a) / bMSq);
}

// deprojection -- vector rejection
// deproject a onto b
Vector3 deproject (Vector3 & a, Vector3 & b) {
    // UNIMPLEMENTED
    Vector3 p = project(a, b);
    return a - p;
}

//reflect
// n := normal vector
// i := incident vector
// Credit: HLSL documentation; GLSL spec documentation
Vector3 reflect (Vector3 & i, Vector3 & n) {
    // UNIMPLEMENTED
    return i - 2.f * sprod(i, n) * n;
}

// refract
// o := incident
// n := normal
// eta := refraction index
Vector3 refract (Vector3 & i, Vector3 & n, float eta) {
    // UNIMPLEMENTED
    float nDotI = sprod(n, i);
    float k = 1.f - eta * eta * (1.f - nDotI * nDotI);
    if (k < 0.f) {
        return Vector3{ 0, 0 };
    }
    return eta * i - (eta * nDotI + sqrtf(k)) * n;
}

//clamp
// Constrains the magnitude of the vector to less than or
// equal to the passed in magnitude (maxLength).
Vector3 clamp (Vector3 & v, float maxLength) {
    // UNIMPLEMENTED
}

//snap

//lerp
// Spherically interpolates between two vectors.
// Interpolates between a and b by amount t.
// The direction of the returned vector is interpolated by the angle
// and its magnitude is the interpolation beteen the magnitudes of a
// and b.

