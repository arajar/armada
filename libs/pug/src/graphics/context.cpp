#include <pug.h>
#include <pug/graphics/context.h>

namespace gfx
{
	context::context()
		: renderer_(nullptr)
		, window_(nullptr)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
	}

	context::~context()
	{
		SDL_Quit();
	}

	void context::init(const std::string& name, int x, int y, int w, int h)
	{
		glewExperimental = GL_TRUE;
		glewInit();

		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		window_ = new gfx::window(name, x, y, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		renderer_ = window_->createRenderer();

		auto gl_vendor = glGetString(GL_VENDOR);
		auto gl_renderer = glGetString(GL_RENDERER);
		util::log.info("Vendor: {0}", gl_vendor);
		util::log.info("Renderer: {0}", gl_renderer);

		auto major = 0;
		auto minor = 0;
		SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &major);
		SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &minor);

		util::log.info("OpenGL {0}.{1}", major, minor);

		auto shadingLangVersion = reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));
		util::log.info("Shading Language Version {0}", shadingLangVersion);

		//SDL_GL_MakeCurrent(*window_, renderer_);
	}

	void context::resize(int w, int h) const { window_->resize(w, h); }
	gfx::renderer& context::renderer() const { return *renderer_; }

}
