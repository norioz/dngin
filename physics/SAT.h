//#pragma once

//Separating Axis Theorem (Discrete) :
//    The strategy is to evaluate all possible axes of separation between two concave volumes.
//    We want to find the shortest direction / distance we need to move one object so that neither
//    will be in collision - this is the Minimum Translation Vector (MTV).To find this, we need
//    to evaluate the Penetration Depth (which will become the magnitude of the MTV) and the direction
//    along the axis we need to move.
//
//    For each possible Axis of separation (A) :
//    Determine min / max extents (Amin, Amax, Bmin, Bmax)  (project A and B along axis A)
//    Determine Handedness (H)                            (Which side is A on ? )
//    Determine Penetration Depth (D)                     (smallest displacement / overlap)
//
//    The smallest positive D will be from the axis of least separation : MTV = A * D * H
//
//    If there is no smallest positive D, then the largest negative D is the axis of least separation.
//
//    This algorithm can be broken up into 3 steps :
//    Determining the possible axes of separation.
//    Determining the min / max extents along each axis.
//    Determining handedness / penetration depth along each axis.
//
//
//    We will start with the third, as it will help w / testing and implies the other two.
//
//    NOTE: For the extents to be valid, expect the mins to actually be less than the maxes.
//
//    SAT1D(Amin, Amax, Bmin, Bmax) -> (PenetrationDepth, Handedness)
//
//    Consider the provided volumes :
//    Extents:  A(-2, 5), B(3, 6)
//    PDepth : 2 (penetration depth of two units between Amax and Bmin)
//    Handed : -1 (A is on the left - hand side because, hint: Amax and Bmin were compared)
//
//    Setting up tests for this is straightforward and a great way to get started.
//    Although there are
//    specialized variants of these algorithms for primitive volumes can make assumptions that help
//    reduce computation, but they are ALL fundamentally based on the above algorithm.
//
//    ---
//
//    Separating Axis Theorem (Continuous) :
//    Where SAT traditionally aims to solve for distance, we can instead solve for a parametric.
//    This requires that volumes not only have a minimum and maximum extents, but also a velocity.
//
//    For each possible Axis of separation (A) :
//    Determine min / max extents (Amin, Amax, Bmin, Bmax)  (project A and B along axis A)
//    Determine velocities      (Avel, Bvel)              (project A / B velocity along axis A)
//    Determine min / max T       (tMin, tMax)              (at which t is the penetration depth 0)
//
//    There are two results in evaluating the parametric.There is a bit of branching to evaluate them :
//          If both results are positive :
//          Smallest t is the time of entry.
//
//              If one result is negative :
//          The two objects were already colliding.
//
//              If both results are negative :
//          The two objects will not collide.
//
//              If the velocities were based on deltaTime, then the t values between 0 and 1 describe a collision
//              that will occur on this frame (prior to those velocities being integrated).Anything outside of 0, 1
//              can be ignored (assuming that collisions have been properly resolved each frame).
//
//              The axis of the earliest time of entry describes the Handedness / Axis.
//
//              SAT1DC(Amin, Amax, Avel, Bmin, Bmax, Bvel) -> { tMin, tMax, handedness }

//    SAT1D(Amin, Amax, Bmin, Bmax) -> (PenetrationDepth, Handedness)
//    SAT1DC(Amin, Amax, Avel, Bmin, Bmax, Bvel) -> { tMin, tMax, handedness }

// ---
#include "../math/Scalar.h"
#include "../math/Vector2.h"
#define MAX_SHAPE_SIZE 100

// Shape Representation:
// Each shape is an orderred array of Vector2 objects
// such that the difference between each pair of vectors is
// a vector that has the magnitude of an edge length. The
// last -> first vector in the array are also connected in
// this way.
//
// Shapes can have at most MAX_SHAPE_SIZE edges and vertices.
struct Shape {
    int size = -1;
    Vector2 vertices[MAX_SHAPE_SIZE];
};

struct AxisProjection {
    Scalar min, max;
};

// find shape edge normals, these are the axis
void determineAxis (Shape a, Vector2 rAxis[], int startIdx) {
    for (int i = 0; i < a.size; ++i) {
        const Vector2 & current = a.vertices[i];
        const Vector2 & next = (i == a.size - 1) ? a.vertices[0] : a.vertices[i + 1];
        Vector2 edge = current - next;
        Vector2 axis = perpendicular(edge);
        rAxis[startIdx + i] = axis;
    }
}

// project shapes onto axis to find extents
AxisProjection findExtents (Shape a, const Vector2 & axis, Vector2 & rMinExtent, Vector2 & rMaxExtent) {
    float min = sprod(axis, a.vertices[0]);
    float max = min;
    for (int i = 0; i < a.size; ++i) {
        float m = sprod(axis, a.vertices[i]);
        if (m < min) {
            min = m;
        }
        if (m > max) {
            max = m;
        }
    }
    return AxisProjection{ min, max };
}

// compare extents
// a negative number is a separation distance
Scalar findOverlap (AxisProjection & aExtents, AxisProjection & bExtents) {
    return Scalar(0);
}

// Find the shortest direction / distance we need to move one object so
// that neither will be in collision - this is the Minimum Translation 
// Vector (MTV).
Vector2 findMTV (Shape a, Shape b) {
    Vector2 axis[MAX_SHAPE_SIZE];
    int axisCount = a.size + b.size;
    determineAxis(a, axis, 0);
    determineAxis(b, axis, a.size);

    int minAxisIdx = -1;
    Scalar minOverlap = 10000;
    for (int i = 0; i < axisCount; ++i) {
        Vector2 currentAxis = axis[i];
        Vector2 aMin, aMax, bMin, bMax;
        AxisProjection aExtents = findExtents(a, currentAxis, aMin, aMax);
        AxisProjection bExtents = findExtents(b, currentAxis, bMin, bMax);
        Scalar overlap = findOverlap(aExtents, bExtents);
        if (overlap < Scalar(0)) {
            // they aren't overlapping
            return Vector2{ 0, 0 };  // ??? what should we return here?
        }
        if (overlap < minOverlap) {
            minOverlap = overlap;
            minAxisIdx = i;
        }
    }

    // a little painful because of the sqrt
    return normalize(axis[minAxisIdx]) * minOverlap;
}
