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
//magnitude
//normalize
//dist
//distSq
//Eq / Neq ==/!=
//assign =
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

union Vector3 {
    struct { float x, y, z; };
    float v[3];
    const float & operator[] (size_t idx) const;
    float & operator[] (size_t idx);
    Vector3 & operator+= (const Vector3 & other);
    Vector3 & operator-= (const Vector3 & other);
    Vector3 & operator/= (float scalar);
    Vector3 & operator*= (float scalar);
};

inline Vector3 & Vector3::operator+= (const Vector3 & other) {
    // etc... 
}
