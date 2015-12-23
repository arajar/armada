#include "pch.h"
#include "Image.h"

#include <core/graphics/renderer.h>
#include <core/graphics/context.h>

namespace core
{
	Image::Image(const std::string& name)
		: name_(name)
		, texture_(nullptr)
	{
	}

	Image::~Image()
	{
	}

	bool Image::load()
	{
		//texture_ = core::gfx::texture2d(IMG_LoadTexture(core::gfx::context::get_instance()->getRenderer(), name_.c_str()));

		SDL_QueryTexture(texture_, nullptr, nullptr, &size_.x, &size_.y);

		return texture_ != nullptr;
	}

	ResourceType Image::getType()
	{
		return ResourceType::Texture2d;
	}

	const math::vec2& Image::size()
	{
		return size_;
	}

	gfx::texture2d& Image::getTexture()
	{
		return texture_;
	}
}
