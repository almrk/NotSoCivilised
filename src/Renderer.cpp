#include "Logger.hpp"
#include "Renderer.hpp"

#define CHECK(V, M) { \
	if (V) { \
		Logger::Info(M); \
	} else { \
		Logger::Error(SDL_GetError()); \
	} \
}

Renderer::Renderer() {	
	CHECK(SDL_Init(SDL_INIT_VIDEO), "SDL initialised.");

	m_window = SDL_CreateWindow("NotSoCivilised", 1000, 1000, 0);
	CHECK(m_window != nullptr, "Window created sucessfully.");
	
	m_renderer = SDL_CreateRenderer(m_window, nullptr);
	CHECK(m_renderer != nullptr, "Renderer created sucessfully.");
	
	m_canvas = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 480);
	CHECK(m_canvas != nullptr, "Canvas created sucessfully.");
	
	Logger::Info("Renderer has been constructed.");
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	Logger::Info("Renderer has been destroyed");
}

void Renderer::DrawTriangle(int ax, int ay, int bx, int by, int cx, int cy, SDL_Color color) { }

void Renderer::DrawRectangle(int x, int y, int width, int height, SDL_Color color) { 
	SDL_FRect* rectangle = {
		
	};
}

void Renderer::DrawText(int x, int y, const std::string_view& text, SDL_Color color) { }

void Renderer::DrawImage(int x, int y, const std::string_view& name) { }