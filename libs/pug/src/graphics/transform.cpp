#include <pug/graphics/transform.h>

namespace gfx
{
	transform transform::inverse() const
	{
		const auto invOrientation = glm::conjugate(orientation);

		transform invtransform;

		invtransform.position = (invOrientation * -position) / scale;
		invtransform.orientation = invOrientation;
		invtransform.scale = invOrientation * (glm::vec3{ 1 } / scale);

		return invtransform;
	}

	glm::vec3 transform::transformPoint(const glm::vec3& point) const
	{
		return (glm::conjugate(orientation) * (position - point)) / scale;
	}
}
