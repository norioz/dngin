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

bool eq (Scalar a, Scalar b) {
    return a == b;
}

bool neq (Scalar a, Scalar b) {
    return a != b;
}

Scalar min (Scalar a) { return a; }

template<typename... Args>
Scalar min (Scalar a, Args... args) {
    Scalar b = min(...args);
    return (a < b) ? a : b;
}

Scalar max (Scalar a) { return a; }

template<typename... Args>
Scalar max (Scalar a, Args... args) {
    Scalar b = max(args...);
    return (a > b) ? a : b;
}

//function clamp(x, min, max) :
//    if (x < min) then
//        x = min;
//    else if (x > max) then
//        x = max;
//return x;
//end clamp

//Scalar clamp (Scalar a) {
//
//}
//
//Scalar snap (Scalar a) {
//
//}

// linear interpolation between two values
//Scalar lerp (Scalar a) {
//
//}
