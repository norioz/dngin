#pragma once

// ---------
// Vector
// ----------
//scalar mul / div * /
//binary add / sub + -
//unary negation -
//Eq / Neq ==/!=
// ---
//magnitude
//normalize
//dist
//distSq
//convert to a float *
//project   `
//deproject `
//reflect   `
//lerp      `
//min / max   `
//clamp     `
//snap      `
//cross     `
// ---------
//vec3 norm{ 5, 0, 0 };
//norm = normalize(norm);
//norm = norm.normalize();
//EXPECT_EQ(vec3{ 1, 0, 0 }, norm);

union Vector2 {
    struct { float x, y; };
    float v[2];
    const float & operator[] (size_t idx) const { return v[idx]; }
    float & operator[] (size_t idx) { return v[idx]; }
    Vector2 & operator= (Vector2 & other);
    Vector2 & operator+= (const Vector2 & other);
    Vector2 & operator-= (const Vector2 & other);
    Vector2 & operator/= (float scalar);
    Vector2 & operator*= (float scalar);
};

Vector2 & Vector2::operator= (Vector2 & other) {
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
