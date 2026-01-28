#pragma once

#include <SDL3/SDL_rect.h>

namespace Renderer {
	struct Vector2i {
		int x;
		int y;

		SDL_Point ToSDLPoint();
		SDL_FPoint ToSDLFPoint();
	};

	struct Triangle {
		Vector2i a;
		Vector2i b;
		Vector2i c;
	};

	struct Rectangle {
		Vector2i position;
		Vector2i size;

		SDL_Rect ToSDLRect();
		SDL_FRect ToSDLFRect();
		bool Intersects(Rectangle rectangle);
		bool Intersects(Vector2i point);
	};
}