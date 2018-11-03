#pragma once

// ---------
// Vector
// ----------
//POD type, no constructor.
//public x, y, z
//subscript operator []
//scalar mul / div * /
//arithmetic assign +=, *=, -=. /=
//binary add / sub + -
//unary negation -
//Eq / Neq ==/!=
//assign =
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
    const float & operator[] (size_t idx) const { return (idx == 0) ? x : y; }
    float & operator[] (size_t idx) { return (idx == 0) ? x : y; }
    Vector2 & operator+= (const Vector2 & other);
    Vector2 & operator-= (const Vector2 & other);
    Vector2 & operator/= (float scalar);
    Vector2 & operator*= (float scalar);
};

inline Vector2 & Vector2::operator+= (const Vector2 & other) {
    // UNIMPLEMENTED
    return *this;
}

inline Vector2 & Vector2::operator-= (const Vector2 & other) {
    // UNIMPLEMENTED
    return *this;
}

inline Vector2 & Vector2::operator*= (float scalar) {
    // UNIMPLEMENTED
    return *this;
}

inline Vector2 & Vector2::operator/= (float scalar) {
    // UNIMPLEMENTED
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
