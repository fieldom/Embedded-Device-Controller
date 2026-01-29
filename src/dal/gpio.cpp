#include "dal/gpio.h"
#include "utils/logger.h"

namespace dal {
//class FakeGPIO : public GPIO {
//public:
	void FakeGPIO::set_high()/*override*/{
		logger::log(logger::Level::INFO, "GPIO set HIGH");
		state = true;
	}

	void FakeGPIO::set_low()/*override*/{
		logger::log(logger::Level::INFO, "GPIO set LOW");
		state = false;
	}

	bool FakeGPIO::read()/*override*/{
		return state;
	}

//private:
//	bool state{false};

//};

}
