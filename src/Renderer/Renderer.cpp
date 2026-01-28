#include "Logger.hpp"
#include "Renderer.hpp"
#include <SDL3_image/SDL_image.h>

#define CHECK(V, M) { \
	if (V) { \
		Logger::Info(M); \
	} else { \
		Logger::Error(SDL_GetError()); \
	} \
}

namespace Renderer {
	Renderer::Renderer() {
		CHECK(SDL_Init(SDL_INIT_VIDEO), "SDL initialised.");

		m_window = SDL_CreateWindow("NotSoCivilised", 1000, 1000, 0);
		CHECK(m_window != nullptr, "Window created sucessfully.");

		m_renderer = SDL_CreateRenderer(m_window, nullptr);
		CHECK(m_renderer != nullptr, "Renderer created sucessfully.");

		m_canvas = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 480);
		CHECK(m_canvas != nullptr, "Canvas created sucessfully.");

		CHECK(TTF_Init(), "SDL_ttf initialised.");

		m_font = TTF_OpenFont("../../../assets/NotoSans-Regular.ttf", 30.0f);
		CHECK(m_font != nullptr, "Font loaded sucessfully.");

		m_tilemap = IMG_LoadTexture(m_renderer, "../../../assets/tilemap.png");
		CHECK(m_tilemap != nullptr, "Tilemap loaded sucessfully.");

		Logger::Info("Renderer has been constructed.");
	}

	Renderer::~Renderer() {
		SDL_DestroyTexture(m_tilemap);
		TTF_CloseFont(m_font);
		TTF_Quit();
		SDL_DestroyTexture(m_canvas);
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

	void Renderer::DrawTriangle(Triangle triangle, SDL_Color color) {
		SDL_Vertex verticies[] = {
			{ { static_cast<float>(triangle.a.x), static_cast<float>(triangle.a.y) }, ColorToFColor(color) },
			{ { static_cast<float>(triangle.b.x), static_cast<float>(triangle.b.y) }, ColorToFColor(color) },
			{ { static_cast<float>(triangle.c.x), static_cast<float>(triangle.c.y) }, ColorToFColor(color) },
		};
		SDL_RenderGeometry(m_renderer, nullptr, verticies, 3, nullptr, 0);
	}

	void Renderer::DrawRectangle(Rectangle rectangle, SDL_Color color) {
		SDL_FRect sdlRectangle = rectangle.ToSDLFRect();
		SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
		SDL_RenderFillRect(m_renderer, &sdlRectangle);
	}

	void Renderer::DrawText(Vector2i position, const std::string_view& text, SDL_Color color) {
		SDL_Surface* textSurface = TTF_RenderText_Blended(m_font, text.data(), text.size(), color);
		SDL_Texture* textTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);
		SDL_FRect textDestination = {
			static_cast<float>(position.x),
			static_cast<float>(position.y),
			textSurface->w,
			textSurface->h
		};
		SDL_RenderTexture(m_renderer, textTexture, nullptr, &textDestination);
		SDL_DestroySurface(textSurface);
		SDL_DestroyTexture(textTexture);
	}

	void Renderer::DrawTile(Vector2i position, Rectangle tile) {
		SDL_FRect source = tile.ToSDLFRect();
		SDL_FRect destination = {
			static_cast<float>(position.x),
			static_cast<float>(position.y),
			source.w,
			source.h
		};
		SDL_RenderTexture(m_renderer, m_tilemap, &source, &destination);
	}

	SDL_FColor Renderer::ColorToFColor(SDL_Color color) {
		return SDL_FColor{
			color.r / 255.f,
			color.g / 255.f,
			color.b / 255.f,
			color.a / 255.f
		};
	}
}