#pragma once

#include <string_view>

namespace Logger {
	void Start(const std::string_view& path);
	void Stop();

	void Info(const std::string_view& message);
	void Warning(const std::string_view& message);
	void Error(const std::string_view& message);

	void Log(const std::string_view& type, const std::string_view& message);
}