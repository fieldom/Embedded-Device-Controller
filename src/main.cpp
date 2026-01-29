#include <iostream>
#include <thread>
#include <chrono>

#include "dal/gpio.h"
#include "dal/uart.h"
#include "utils/logger.h"
#include "fsm/fsm.h"

using namespace dal;
using namespace fsm;

int main(){

	logger::log(logger::Level::INFO, "Device controller started");

	FakeGPIO gpio;
	FakeUART uart;

	FSM controller (gpio,uart);


	while (true){
		/*if(std::cin.rdbuf()->in_avail() > 0){
			char c;
			std::cin.get(c);
			if(c == ' '){break;}
		}*/
		static int counter = 0;
		controller.handle_event(Event::START);
		if(counter == 3){
			controller.handle_event(Event::ACTIVATE);
		}
//		std::cout<<controller.get_state()<<std::endl;
		if(counter == 6){
			controller.handle_event(Event::FAIL);
		}
		if(counter == 9){
			controller.handle_event(Event::RESET);
			counter = 0;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
		counter++;
	}
	/*//INIT -> IDLE
	fsm::handle_event(fsm::Event::START);
	std::this_thread::sleep_for(std::chrono::seconds(1));

	//IDLE -> ACTIVE
	fsm::handle_event(fsm::Event::ACTIVATE);
	std::this_thread::sleep_for(std::chrono::seconds(1));

	//ACTIVE -> ERROR
	fsm::handle_event(fsm::Event::FAIL);
	std::this_thread::sleep_for(std::chrono::seconds(1));

	//ERROR -> INIT
	fsm::handle_event(fsm::Event::RESET);*/

	logger::log(logger::Level::INFO, "Device controller finished");
	return 0;

}

