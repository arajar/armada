#pragma once

#include <type_traits>

namespace math
{
	template <template <typename> class derived, typename T>
	struct unit
	{
		template <template <typename> class, typename>
		friend struct unit;

	public:
		using Type = T;

		unit() : unit(0) {}
		explicit unit(T value) : value_{ value } {}

		template <typename U>
		explicit unit(unit<derived, U> value) : value_{ T{value.value_} } {}

		operator T() const { return value_; }

		bool operator==(unit<derived, T> other) const { return value_ == other.value_; }
		bool operator!=(unit<derived, T> other) const { return !operator==(other); }
		bool operator<(unit<derived, T> other) const { return value_ < other.value_; }
		bool operator>(unit<derived, T> other) const { return value_ > other.value_; }
		bool operator<=(unit<derived, T> other) const { return !operator>(other); }
		bool operator>=(unit<derived, T> other) const { return !operator<(other); }

		unit<derived, T> operator-() const { return unit<derived, T>{-value_}; }
		unit<derived, T>& operator+=(unit<derived, T> other) { value_ += other.value_; return *this; }
		unit<derived, T> operator+(unit<derived, T> other) const { return unit<derived, T>{value_ + other.value_}; }
		unit<derived, T>& operator-=(unit<derived, T> other) { value_ -= other.value_; return *this; }
		unit<derived, T> operator-(unit<derived, T> other) const { return unit<derived, T>{value_ - other.value_}; }
		unit<derived, T>& operator*=(T number) { value_ *= number; return *this; }
		unit<derived, T> operator*(T number) const { return unit<derived, T>{value_ * number}; }
		unit<derived, T>& operator/=(T number) { value_ /= number; return *this; }
		unit<derived, T> operator/(T number) const { return unit<derived, T>{value_ / number}; }

		T operator/(unit<derived, T> other) const { return value_ / other.value_; }

	private:
		T value_;
	};

	template <template <typename> class derived, typename T>
	unit<derived, T> operator*(typename std::common_type<T>::type number, const unit<derived, T>& value)
	{
		return value * number;
	}
}
