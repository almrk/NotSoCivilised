#include "Renderer/Shapes.hpp"

namespace Renderer {
	SDL_Point Vector2i::ToSDLPoint() {
		return {
			x,
			y
		};
	}

	SDL_FPoint Vector2i::ToSDLFPoint() {
		return {
			static_cast<float>(x),
			static_cast<float>(y)
		};
	}

	SDL_Rect Rectangle::ToSDLRect() {
		return {
			position.x,
			position.y,
			size.x,
			size.y
		};
	}

	SDL_FRect Rectangle::ToSDLFRect() {
		return {
			static_cast<float>(position.x),
			static_cast<float>(position.y),
			static_cast<float>(size.x),
			static_cast<float>(size.y)
		};
	}

	bool Rectangle::Intersects(Rectangle rectangle) {
		return
			rectangle.position.x > position.x &&
			rectangle.position.x < position.x + size.x &&
			rectangle.position.y > position.y &&
			rectangle.position.y < position.y + size.y;
	}

	bool Rectangle::Intersects(Vector2i point) {
		return
			point.x > position.x &&
			point.x < position.x + size.x &&
			point.y > position.y &&
			point.y < position.y + size.y;
	}
}