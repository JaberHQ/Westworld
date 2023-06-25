#include "Vector.h"

inline void Vector2D::Zero()
{
}

inline bool Vector2D::isZero() const
{
	return false;
}

inline double Vector2D::LengthSq() const
{
	return 0.0;
}

inline void Vector2D::Normalize()
{
}

inline double Vector2D::Dot(const Vector2D& v2) const
{
	return 0.0;
}

inline int Vector2D::Sign(const Vector2D& v2) const
{
	return 0;
}

inline Vector2D Vector2D::Perp() const
{
	return Vector2D();
}

inline void Vector2D::Truncate(double max)
{
}

inline double Vector2D::Distance(const Vector2D& v2) const
{
	return 0.0;
}

inline double Vector2D::DistanceSq(const Vector2D& v2) const
{
	return 0.0;
}

inline Vector2D Vector2D::GetReverse() const
{
	return Vector2D();
}

const Vector2D& Vector2D::operator+=(const Vector2D& rhs)
{
	// TODO: insert return statement here
	return Vector2D();
}

const Vector2D& Vector2D::operator-=(const Vector2D& rhs)
{
	// TODO: insert return statement here
	return Vector2D();

}

const Vector2D& Vector2D::operator*=(const double& rhs)
{
	// TODO: insert return statement here
	return Vector2D();
}

const Vector2D& Vector2D::operator/=(const double& rhs)
{
	// TODO: insert return statement here
	return Vector2D();
}

bool Vector2D::operator==(const Vector2D& rhs) const
{
	return false;
}

bool Vector2D::operator!=(const Vector2D& rhs) const
{
	return false;
}
