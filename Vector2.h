#pragma once

#include <cmath>
#include <cfloat>
#include "Define.h"

class Vector2 final
{
private:
	float _x;
	float _y;
public:
	Vector2(float x = 0, float y = 0) : _x(x), _y(y) {}
	~Vector2() = default;

	inline float GetX() const { return _x; }
	inline float GetY() const { return _y; }
	inline float GetTheta() const { 
		if (_x < 0) {
			float a = Define::_pi - std::atanf(-_y / -_x);
			return a * 180 / Define::_pi;
		}
		return std::atanf(-_y / _x) * 180 / Define::_pi;
	}
	inline float Dot(const Vector2& other) const { return (_x * other._x) + (_y * other._y); }
	inline float Cross(const Vector2& other) const { return (_x * other._y) - (_y * other._x); }
	inline float Length() const { return std::sqrt(Dot(*this)); }
	inline float Distance(const Vector2& other) const { return (*this - other).Length(); }
	inline Vector2 Normalize() const
	{
		const float len = Length();
		if (len < FLT_EPSILON) return Vector2::_zero;
		return *this / len;
	}
	inline bool isZero() const { return  *this == Vector2::_zero; }
	inline Vector2& operator += (const Vector2& other) { return  *this = *this + other; }
	inline Vector2& operator -= (const Vector2& other) { return  *this = *this - other; }
	inline Vector2& operator *= (float scalar) { return  *this = *this * scalar; }
	inline Vector2& operator /= (float scalar) { return  *this = *this / scalar; }
	inline const Vector2 operator + (const Vector2& other) const { return Vector2(_x + other._x, _y + other._y); }
	inline const Vector2 operator - (const Vector2& other) const { return Vector2(_x - other._x, _y - other._y); }
	inline const Vector2 operator * (float scalar) const { return Vector2(_x * scalar, _y * scalar); }
	inline const Vector2 operator / (float scalar) const { return Vector2(_x / scalar, _y / scalar); }
	inline const Vector2 operator - () const { return Vector2(-_x, -_y); }
	inline bool operator == (const Vector2& other) const { return (_x == other._x) && (_y == other._y); }
	inline bool operator != (const Vector2& other) const { return !(*this == other); }
	inline bool operator < (const Vector2& other) const
	{
		if (_x < other._x) return true;
		if (_y < other._y) return true;
		return false;
	}
	inline Vector2 Turn(const float alpha) const
	{
		const Vector2 tmp(*this);
		const float r = tmp.Length();
		const float theta = 2.0f * Define::_pi - std::acosf(tmp.ReverseUp().Dot(_right) / (tmp.Length()));
		const float thetaPrime = Define::_pi + 2.0 * (alpha * Define::_pi / 180.0f) - theta;
		if (std::abs(thetaPrime - Define::_pi) < Define::_pi / 9.0f || std::abs(thetaPrime) < Define::_pi / 9.0f) {
			return tmp.ReverseUp();
		}
		return Vector2(r * std::cosf(thetaPrime), -r * std::sinf(thetaPrime));
	}
	inline Vector2 Reverse() const
	{
		return Vector2(_x * -1, _y * -1);
	}
	inline Vector2 ReverseUp() const { return Vector2(_x, -std::abs(_y)); }
	inline Vector2 ReverseDown() const { return Vector2(_x, std::abs(_y)); }
	inline Vector2 ReverseLeft() const { return Vector2(-std::abs(_x), _y); }
	inline Vector2 ReverseRight() const { return Vector2(std::abs(_x), _y); }
	inline Vector2 ReverseLU() const { return Vector2(-std::abs(_x), -std::abs(_y)); }
	inline Vector2 ReverseRU() const { return Vector2(std::abs(_x), -std::abs(_y)); }
	inline Vector2 ReverseRD() const { return Vector2(std::abs(_x), std::abs(_y)); }
	inline Vector2 ReverseLD() const { return Vector2(-std::abs(_x), std::abs(_y)); }

	static const Vector2 _zero;
	static const Vector2 _left;
	static const Vector2 _right;
	static const Vector2 _down;
	static const Vector2 _up;
};



