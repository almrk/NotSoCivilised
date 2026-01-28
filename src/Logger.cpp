#include "Logger.hpp"
#include <chrono>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

namespace Logger {
	static std::ofstream g_logFile;
	static std::string g_path;

	void Start(const std::string_view& path) {
		g_logFile = std::ofstream{ path.data() };
		g_path = path;
		if (!g_logFile.is_open()) {
			std::cerr << "Failed to open log file!" << std::endl;
			std::terminate();
		}
	}

	void Stop() {
		g_logFile.close();
	}

	void Info(const std::string_view& message) {
		Log("INF", message);
	}

	void Warning(const std::string_view& message) {
		Log("WRN", message);
	}
	
	void Error(const std::string_view& message) {
		Log("ERR", message);
	}

	void Log(const std::string_view& type, const std::string_view& message) {
		auto now = std::chrono::system_clock::now();
		auto date = std::format("{:%Y-%m-%d %H:%M:%S}", now);
		auto finalMessage = std::format("[{} {}] {}", date, type, message);

		std::cout << finalMessage << std::endl;
		g_logFile << finalMessage << '\n';
	}
}