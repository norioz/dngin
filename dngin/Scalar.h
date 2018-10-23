#pragma once

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

bool operator== (Scalar, Scalar) {
    // UNIMPLEMNETED
    return false;
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator!= (Scalar, Scalar) {
    // UNIMPLEMNETED
    return false;
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator<= (Scalar, Scalar) {
    // UNIMPLEMNETED
    return false;
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator>= (Scalar, Scalar) {
    // UNIMPLEMNETED
    return false;
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator> (Scalar, Scalar) {
    // UNIMPLEMNETED
    return false;
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator< (Scalar, Scalar) {
    // UNIMPLEMNETED
    return false;
    /*HEY WE DOIN EPSILON STUFF*/ 
}
