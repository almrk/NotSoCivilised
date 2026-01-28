#pragma once

#include "Renderer/Shapes.hpp"
#include "Renderer/Tilemap.hpp"
#include <string_view>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

namespace Renderer {
	class Renderer {
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_canvas;
		TTF_Font* m_font;
		SDL_Texture* m_tilemap;

	public:
		Renderer();
		~Renderer();

		void Update();
		void DrawTriangle(Triangle triangle, SDL_Color color);
		void DrawRectangle(Rectangle rectangle, SDL_Color color);
		void DrawText(Vector2i position, const std::string_view& text, SDL_Color color);
		void DrawTile(Vector2i position, Rectangle tile);

	private:
		SDL_FColor ColorToFColor(SDL_Color color);
	};
}