#pragma once
#include <glm.hpp>
#include <gtc/quaternion.hpp>
#include <gtc/matrix_transform.hpp>

namespace gfx
{
	struct transform
	{
		glm::vec3 position = glm::vec3{ 0 };
		glm::quat orientation = glm::quat();
		glm::vec3 scale = glm::vec3{ 1 };

		transform operator*(const transform& other) const
		{
			transform t;

			t.position = position + orientation * (scale * other.position);
			t.orientation = orientation * other.orientation;
			t.scale = scale * (orientation * other.scale);

			return t;
		}

		transform& operator*=(const transform& other)
		{
			*this = operator*(other);
			return *this;
		}

		transform operator/(const transform& ps) const
		{
			transform t;

			const auto psConjugate = glm::conjugate(ps.orientation);

			t.position = (psConjugate * (position - ps.position)) / ps.scale;
			t.orientation = psConjugate * orientation;
			t.scale = psConjugate * (scale / ps.scale);

			return t;
		}

		transform& operator/=(const transform& ps)
		{
			*this = operator/(ps);
			return *this;
		}

		operator glm::mat4() const
		{
			auto m = glm::translate(glm::mat4(), position);
			m *= glm::mat4_cast(orientation);
			m = glm::scale(m, scale);

			return m;
		}

		glm::vec3 transformPoint(const glm::vec3& point) const;
		transform inverse() const;
	};
}
