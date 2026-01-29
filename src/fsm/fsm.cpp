#include "fsm.h"
#include "utils/logger.h"

namespace fsm{

FSM::FSM(dal::GPIO& gpio, dal::UART& uart)
	:gpio_(gpio), uart_(uart){}

static const char* state_to_string(State state) {
	switch (state) {
		case State::INIT: return "INIT";
		case State::IDLE: return "IDLE";
		case State::ACTIVE: return "ACTIVE";
		case State::ERROR: return "ERROR";
		default: return "UNKNOWN";
	}
}

void FSM::handle_event(Event event) {
	switch (current_state){
		case State::INIT:
			if (event == Event::START) {
				logger::log(logger::Level::INFO, "INIT -> IDLE");
				current_state = State::IDLE;
			}
			break;
		case State::IDLE:
			if (event == Event::ACTIVATE) {
				logger::log(logger::Level::INFO, "IDLE ->  ACTIVE");
				gpio_.set_high();
				uart_.send("device activated");
				current_state = State::ACTIVE;
			}
			break;
		case State::ACTIVE:
			if (event == Event::FAIL) {
				logger::log(logger::Level::INFO, "ACTIVE -> ERROR");
				gpio_.set_low();
				current_state = State::ERROR;
			}
		case State::ERROR:
			if (event == Event::RESET) {
				logger::log(logger::Level::INFO, "ERROR -> INIT");
				current_state = State::INIT;
			}
			break;
	}
}

std::string FSM::get_state() const {
	return state_to_string(current_state);
}

}
