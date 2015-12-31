#pragma once
#include "unit.h"
#include <gtc/constants.hpp>

namespace math
{
	namespace impl
	{
		template <typename T>
		struct radian;

		template <typename T>
		struct degree : unit<degree, T>
		{
			degree() {}
			explicit degree(T value) : unit<math::impl::degree, T>(value) {}
			explicit degree(unit<math::impl::degree, T> value) : unit<math::impl::degree, T>(value) {}
			template <class U>
			explicit degree(unit<math::impl::degree, U> value) : unit<math::impl::degree, T>(value) {}
			explicit degree(unit<radian, T> value);
		};

		template <typename T>
		struct radian : unit<radian, T>
		{
			radian() {}
			explicit radian(T value) : unit<math::impl::radian, T>(value) {}
			explicit radian(unit<math::impl::radian, T> value) : unit<math::impl::radian, T>(value) {}
			template <class U>
			explicit radian(unit<math::impl::radian, U> value) : unit<math::impl::radian, T>(value) {}
			explicit radian(unit<degree, T> value);

		};

		template <typename T>
		degree<T>::degree(unit<radian, T> value)
			: unit<math::impl::degree, T>((T(value) * T(180)) / glm::pi<T>())
		{
		}

		template <typename T>
		radian<T>::radian(unit<degree, T> value)
			: unit<math::impl::radian, T>(T(value) * glm::pi<T>() / T(180))
		{
		}
	}

	using radian = impl::radian<float>;
	using degree = impl::degree<float>;
}
