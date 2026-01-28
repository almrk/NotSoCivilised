#pragma once

#include <string_view>
#include <SDL3/SDL.h>

class Renderer {
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_canvas;

public:
	Renderer();
	~Renderer();

	void DrawTriangle(int ax, int ay, int bx, int by, int cx, int cy, SDL_Color color);
	void DrawRectangle(int x, int y, int width, int height, SDL_Color color);
	void DrawText(int x, int y, const std::string_view& text, SDL_Color color);
	void DrawImage(int x, int y, const std::string_view& name);
};