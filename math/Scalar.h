#pragma once

#ifndef EPSILON
#define EPSILON 0.000001
#endif // !EPSILON

// ----------
// Scalar
// ----------
// Represents a numeric value.
// ----------
// Notes:
// Scalars are only accurate for comparision to within the absolute (or fixed)
// value of EPSILON. Because EPSILON is absolute, rather than relative, comparison
// of numbers that are much larger than EPSILON is not advised.
// For more information about floating point equality see: absolute, relative, or
// "units in last place" (ULP).

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

inline bool operator< (Scalar a, Scalar b) {
    return (a.value + EPSILON) < b.value;
}

inline bool operator<= (Scalar a, Scalar b) {
    return !(a > b);
}

inline bool operator> (Scalar a, Scalar b) {
    return b < a;
}

inline bool operator>= (Scalar a, Scalar b) {
    return !(a < b);
}

inline bool operator== (Scalar a, Scalar b) {
    return !(a < b) && !(b < a);
}

inline bool operator!= (Scalar a, Scalar b) {
    return !(a == b);
}

// -----------
//  min
// -----------
// Indicates whether a is strictly less than b.
inline Scalar min (Scalar a, Scalar b) { return (a < b) ? a : b; }

template<typename... Args>
Scalar min (Scalar a, Scalar b, Args... args) {
    return min(min(a, b), args...);
}

// -----------
// max
// -----------
// Indicates whether a is strictly greater than b.
inline Scalar max (Scalar a, Scalar b) { return (a > b) ? a : b; }

template<typename... Args>
Scalar max (Scalar a, Scalar b, Args... args) {
    return max(max(a, b), args...);
}

// -----------
// clamp
// -----------
// Constrains x to a value that is between low and high.
// If x <= low, the clamped value is low.
// If x >= high, the clamed value is high.
inline Scalar clamp (Scalar x, Scalar low, Scalar high) {
    return max(min(x, high), low);
}

// -----------
// snap
// -----------
// Returns either low or high, based on which is closer to x.
inline Scalar snap (Scalar x, Scalar low, Scalar high) {
    if (x <= low) { return low; }
    if (x >= high) { return high; }
    return (x - low) > (high - x) ? high : low;
}

// -----------
// lerp
// -----------
// Linearly extrapolates a factor t along the line through
// a and b.
// Ex. lerp(1, 2, 0.5) == 1.5
inline Scalar lerp (Scalar a, Scalar b, Scalar t) {
    return a * (1 - t) + b * t;
}
