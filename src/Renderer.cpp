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

void Renderer::Update() {
	SDL_SetRenderTarget(m_renderer, nullptr);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderTexture(m_renderer, m_canvas, nullptr, nullptr);
	SDL_RenderPresent(m_renderer);
	SDL_SetRenderTarget(m_renderer, m_canvas);
}

void Renderer::DrawTriangle(int ax, int ay, int bx, int by, int cx, int cy, SDL_Color color) {
	auto toFColor = [](SDL_Color color) {
		return SDL_FColor{ color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f };
	};
	SDL_Vertex verticies[] = {
		{ { static_cast<float>(ax), static_cast<float>(ay) }, toFColor(color) },
		{ { static_cast<float>(bx), static_cast<float>(by) }, toFColor(color) },
		{ { static_cast<float>(cx), static_cast<float>(cy) }, toFColor(color) },
	};
	SDL_RenderGeometry(m_renderer, nullptr, verticies, 3, nullptr, 0);
}

void Renderer::DrawRectangle(int x, int y, int width, int height, SDL_Color color) { 
	SDL_FRect rectangle = {
		static_cast<float>(x),
		static_cast<float>(y),
		static_cast<float>(width),
		static_cast<float>(height)
	};
	SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(m_renderer, &rectangle);
}

void Renderer::DrawText(int x, int y, const std::string_view& text, SDL_Color color) {
	
}

void Renderer::DrawImage(int x, int y, const std::string_view& name) { 

}