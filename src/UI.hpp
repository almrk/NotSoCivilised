#pragma once

namespace UI {
	void Text(Renderer& renderer, Vector2i position, const std::string_view& text);
	bool Button(Renderer& renderer, Vector2i position, const std::string_view& text);
	float Slider(Renderer& renderer, float min, float max);
}
