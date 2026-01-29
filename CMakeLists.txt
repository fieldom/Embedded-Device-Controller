cmake_minimum_required(VERSION 3.10)
project(device_controller)

set(CMAKE_CXX_STANDARD 17)

# --- DAL library ---
add_library(dal
	src/dal/gpio.cpp
	src/dal/uart.cpp
)

target_include_directories(dal
	PUBLIC
		src
)

# --- Logger library  ---
add_library(logger
	src/utils/logger.cpp

)

target_include_directories(logger
	PUBLIC
		src
)

# --- FSM library ---
add_library(fsm
	src/fsm/fsm.cpp
)

target_include_directories(fsm
	PUBLIC
		src
)

# --- Executable ---
add_executable(device_controller
	src/main.cpp
)

target_link_libraries(device_controller
	PRIVATE
		logger
		fsm
	PUBLIC
		dal
)
