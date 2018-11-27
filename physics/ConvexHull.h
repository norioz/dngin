#pragma once

// ConvexHull{
//	vec vertices[N];
//	vec normals[N];
//
//	struct { float m, n; } CalcAxialExtents(vec) const;
//};
//
//
//struct SATDResults {
//	float depth;
//	vec axis;
//};
//
//SAT(ConvexHull A, ConvexHull B)->SATDresults
//For each axis of A U B :
//Find the min / max axial extents of A and B.
//Do 1D SAT.
//
//Returns :
//	The smallest positive depth and its axis.
//	OR the largest negative depth and its axis.
//
//
//
//
//	// For later-- appropriatel transforms each vertex/normal of a convex hull by the provided matrix.
//	ConvexHull operator* (matrix, ConvexHull);
