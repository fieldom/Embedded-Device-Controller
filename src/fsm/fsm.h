#pragma once

#include "dal/gpio.h"
#include "dal/uart.h"

namespace fsm {
enum class State {
	INIT,
	IDLE,
	ACTIVE,
	ERROR
};

enum class Event {
	START,
	ACTIVATE,
	FAIL,
	RESET
};

class FSM{
public:
	FSM(dal::GPIO& gpio, dal::UART& uart);

	void handle_event(Event event);
	std::string get_state() const;
private:
	State current_state{State::INIT};

	dal::GPIO& gpio_;
	dal::UART& uart_;
};

}
