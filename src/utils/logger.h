#pragma once

#include <string>

namespace logger{

enum class Level{
	INFO,
	ERROR
};

void log(Level level, const std::string& message);

} //namespace logger
