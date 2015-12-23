#pragma once

namespace math
{
	// utility vector class from my vector math library: https://github.com/arajar/math
	template<typename T>
	struct vec2_type
	{
		union { T x; T u; };
		union { T y; T v; };

		explicit vec2_type(T value) : x(value), y(value) {}
		vec2_type() : vec2_type(0) {}
		vec2_type(T x, T y) : x(x), y(y) {}
		vec2_type(const vec2_type<T>& other) : x(other.x), y(other.y) {}

		vec2_type<T> operator+() const { return vec2_type<T>(+x, +y); }
		vec2_type<T> operator-() const { return vec2_type<T>(-x, -y); }

		vec2_type<T> operator+(const vec2_type<T>& other) const { return vec2_type<T>(x + other.x, y + other.y); }
		vec2_type<T> operator-(const vec2_type<T>& other) const { return vec2_type<T>(x - other.x, y - other.y); }
		vec2_type<T> operator*(const vec2_type<T>& other) const { return vec2_type<T>(x * other.x, y * other.y); }
		vec2_type<T> operator/(const vec2_type<T>& other) const { return vec2_type<T>(x / other.x, y / other.y); }

		vec2_type<T>& operator+=(const vec2_type<T>& other) { return *this = *this + other; }
		vec2_type<T>& operator-=(const vec2_type<T>& other) { return *this = *this - other; }
		vec2_type<T>& operator*=(const vec2_type<T>& other) { return *this = *this * other; }
		vec2_type<T>& operator/=(const vec2_type<T>& other) { return *this = *this / other; }
		vec2_type<T>& operator+=(T other) { return *this = *this + other; }
		vec2_type<T>& operator-=(T other) { return *this = *this - other; }
		vec2_type<T>& operator*=(T other) { return *this = *this * other; }
		vec2_type<T>& operator/=(T other) { return *this = *this / other; }

		bool operator==(const vec2_type<T>& other) const { return x == other.x && y == other.y; }
		bool operator!=(const vec2_type<T>& other) const { return x != other.x || y != other.y; }
	};

	using vec2 = vec2_type<int>;
	using vec2f = vec2_type<float>;
	
	// useful operators
	template<typename T>
	vec2_type<T> operator+(const vec2_type<T>& a, const T& b)
	{
		return vec2_type<T>(a.x + b, a.y + b);
	}

	template<typename T>
	vec2_type<T> operator+(const T& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a + b.x, a + b.y);
	}

	template<typename T>
	vec2_type<T> operator+(const vec2_type<T>& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a.x + b.x, a.y + b.y);
	}

	template<typename T>
	vec2_type<T> operator-(const vec2_type<T>& a, const T& b)
	{
		return vec2_type<T>(a.x - b, a.y - b);
	}

	template<typename T>
	vec2_type<T> operator-(const T& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a - b.x, a - b.y);
	}

	template<typename T>
	vec2_type<T> operator-(const vec2_type<T>& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a.x - b.x, a.y - b.y);
	}

	template<typename T>
	vec2_type<T> operator*(const vec2_type<T>& a, const T& b)
	{
		return vec2_type<T>(a.x * b, a.y * b);
	}

	template<typename T>
	vec2_type<T> operator*(const T& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a * b.x, a * b.y);
	}

	template<typename T>
	vec2_type<T> operator*(const vec2_type<T>& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a.x * b.x, a.y * b.y);
	}

	template<typename T>
	vec2_type<T> operator/(const vec2_type<T>& a, const T& b)
	{
		return vec2_type<T>(a.x / b, a.y / b);
	}

	template<typename T>
	vec2_type<T> operator/(const T& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a / b.x, a / b.y);
	}

	template<typename T>
	vec2_type<T> operator/(const vec2_type<T>& a, const vec2_type<T>& b)
	{
		return vec2_type<T>(a.x / b.x, a.y / b.y);
	}
}