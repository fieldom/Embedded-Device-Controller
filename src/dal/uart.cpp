#include "dal/uart.h"
#include "utils/logger.h"

namespace dal {

//class FakeUART : public UART {
//public:
	void FakeUART::send(const std::string& data) /*override*/{
		logger::log(logger::Level::INFO, "UART send: " + data);
	}

	std::string FakeUART::receive() /*override*/ {
		logger::log(logger::Level::INFO, "UART receive");
		return "OK";
	}
//};

}
