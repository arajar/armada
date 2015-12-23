#pragma once
#include <core/graphics/texture2d.h>

namespace core
{
	class Image : public IResource, public IDrawable
	{
	public:
		explicit Image(const std::string& name);
		virtual ~Image();

	public: // IResource interface
		virtual bool load() override;
		virtual ResourceType getType() override;

	public: // IDrawable interface
		virtual const math::vec2& size() override;
		virtual gfx::texture2d& getTexture() override;

	private:
		const std::string name_;
		math::vec2 size_;
		gfx::texture2d texture_;
	};
}

