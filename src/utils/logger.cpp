#include "logger.h"

#include "iostream"
#include "chrono"
#include "ctime"

namespace logger {

static std::string level_to_string(Level level) {
	switch (level) {
		case Level::INFO: return "INFO";
		case Level::ERROR: return "ERROR";
		default: return "UNKNOWN";
	}
}

void log(Level level, const std::string& message) {
	auto now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);

	std::string time_str = std::ctime(&time);
	time_str.pop_back();

	std::cout << "[" << time_str << "] "
			<< "[" << level_to_string(level) << "]"
			<< message << std::endl;
}
}
