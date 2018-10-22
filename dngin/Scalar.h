#pragma once

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
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator!= (Scalar, Scalar) {
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator<= (Scalar, Scalar) {
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator>= (Scalar, Scalar) {
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator> (Scalar, Scalar) {
    /*HEY WE DOIN EPSILON STUFF*/ 
}

bool operator< (Scalar, Scalar) {
    /*HEY WE DOIN EPSILON STUFF*/ 
}
