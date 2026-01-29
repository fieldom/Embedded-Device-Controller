#pragma once
#include <string>

namespace dal{

class UART {
public:
	virtual ~UART() = default;

	virtual void send(const std::string& data) = 0;
	virtual std::string receive() = 0;
};

class FakeUART: public UART
{
public:
	void send(const std::string& data) override;
	std::string receive() override;
};
}
