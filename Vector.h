#ifndef VECTOR_H
#define VECTOR_H

struct Vector2D 
{
	double x;
	double y;

	Vector2D() : x(0.0), y(0.0) {}
	Vector2D(double a, double b) : x(a), y(b) {}

	// Sets x and y to zero
	inline void Zero();

	// Returns true if x and y are zero
	inline bool isZero() const;

	// Returns the squared length of the vector
	inline double LengthSq() const;

	// Nomalize vector
	inline void Normalize();

	// Returns the dot product of this and v2
	inline double Dot(const Vector2D& v2) const;

	// Returns positive if v2 is clockwise of vector
	// Else negative
	inline int Sign(const Vector2D& v2) const;

	// Returns perpendicular vector
	inline Vector2D Perp() const;

	// Adjust x and y so that the length of the vector does not exceed max
	inline void Truncate(double max);

	// Returns the distance between this vector and parameter
	inline double Distance(const Vector2D& v2) const;

	// Returns the squared distance between this vector and parameter
	inline double DistanceSq(const Vector2D& v2) const;

	// Returns the reverse of this vector
	inline Vector2D GetReverse() const;

	// Operators
	const Vector2D& operator += (const Vector2D& rhs);
	const Vector2D& operator -= (const Vector2D& rhs);
	const Vector2D& operator *= (const double& rhs);
	const Vector2D& operator /= (const double& rhs);
	bool operator == (const Vector2D& rhs) const;
	bool operator != (const Vector2D& rhs) const;


};
#endif // !VECTOR_H

