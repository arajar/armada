#pragma once
#include <core/math/vec2.h>

namespace core
{
	namespace gfx
	{
		class texture2d;
		class renderer;
	}
}

enum class ResourceType
{
	Texture2d,
	Font,
};

class IResource
{
public:
	virtual ~IResource()
	{
	}

	virtual bool load() = 0;
	virtual ResourceType getType() = 0;
};

class IDrawable
{
public:
	virtual ~IDrawable()
	{
	}

	virtual const math::vec2& size() = 0;
	virtual core::gfx::texture2d& getTexture() = 0;
};

class IText
{
public:
	virtual ~IText()
	{
	}

	virtual void write(core::gfx::renderer& renderer, const std::string& text, const math::vec2& pos, const SDL_Color& color) = 0;
	virtual SDL_Rect getRect() const = 0;
};