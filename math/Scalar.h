#pragma once

#ifndef EPSILON
#define EPSILON 0.000001
#endif // !EPSILON

// ----------
// Scalar
// ----------
//min
//max
//clamp
//snap
//lerp
//eq / neq - IMPORTANTE
// ----------
// Float is equals:
// absolute - pick some arbitrary epsilon that is significantly small
// relative - pick the float w / worse error and scale epsilon
// ulp (Units in the Last Place) - does a bitwise comparison
// https://www.floating-point-gui.de/errors/comparison/
// https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/

struct Scalar {
    float value;

    Scalar () { }
    Scalar (float value) : value(value) { }

    Scalar & operator= (float o) { return *this = Scalar{ o }; }
    Scalar & operator+= (float o) { return *this += o; }
    Scalar & operator/= (float o) { return *this /= o; }
    Scalar & operator-= (float o) { return *this -= o; }
    Scalar & operator*= (float o) { return *this *= o; }

    operator float & () { return value; }
    operator float () const { return value; }
};

bool operator< (Scalar a, Scalar b) {
    return (a.value + EPSILON) < b.value;
}

bool operator== (Scalar a, Scalar b) {
    return !(a < b) && !(b < a);
}

bool operator> (Scalar a, Scalar b) {
    return b < a;
}

bool operator!= (Scalar a, Scalar b) {
    return !(a == b);
}

bool operator<= (Scalar a, Scalar b) {
    return !(a > b);
}

bool operator>= (Scalar a, Scalar b) {
    return !(a < b);
}
