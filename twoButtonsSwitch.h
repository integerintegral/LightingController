#include "Arduino.h"
#include "GyverButton.h"

class TwoButtonsSwitch
{
public:
	GButton button;

  	TwoButtonsSwitch(uint8_t buttonPin, uint8_t firstRelayPin, uint8_t secondRelayPin, uint8_t ledPin);
  	void tick();
  	bool wasHolded();
	void turnOff();

private:
  	uint8_t _butt, _relay1, _relay2, _led;
  	bool _firstRelayState, _secondRelayState;
  	bool turnOffEverything;

  	void setState(bool firstRelayState, bool secondRelayState);
};
