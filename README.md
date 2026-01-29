_______________________[EGNLISH VERSION]__________________________

# Embedded Device Controller (C++)

Embedded-style C++ application simulating a device controller using
Finite State Machine (FSM) and Device Abstraction Layer (DAL).

## Features
- Finite State Machine (INIT / IDLE / ACTIVE / ERROR)
- Device Abstraction Layer (GPIO, UART)
- Platform-independent design
- Embedded-style main loop
- Logging subsystem
- Graceful shutdown
- Fake hardware implementations for desktop testing

## Architecture
FSM is fully decoupled from hardware via abstract interfaces.
Hardware implementation can be replaced without changing business logic.

## Build
```bash
mkdir build
cd build
cmake ..
make

##Run
```bash
./device_controller

##Tech Stack
-C++
-CMake
-Linux / WSL
-Embedded design patterns

____________________[РУССКАЯ ВЕРСИЯ]___________________
