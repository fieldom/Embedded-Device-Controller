#pragma once

namespace dal{

class GPIO {
public:
	virtual ~GPIO() = default;

	virtual void set_high() = 0;
	virtual void set_low() = 0;
	virtual bool read() = 0;
};

class FakeGPIO: public GPIO
{
public:
	void set_high() override;
	void set_low() override;
	bool read() override;

private:
	bool state{false};
};
}
