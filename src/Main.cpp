#include "Renderer/Renderer.hpp"
#include <iostream>

int main() {
	Renderer r{};

	r.Update();
	r.DrawRectangle({ { 0, 0 }, { 100, 100 } }, { 255, 0, 0, 255 });
	r.DrawText({ 10, 10 }, "Hello world!", { 255, 255, 255, 255 });
	r.Update();

	while (true) {
		SDL_Event ev;
		SDL_WaitEvent(&ev);
		if (ev.type == SDL_EVENT_QUIT)
			break;
	}
}