#include "Arduino.h"
#include "GyverButton.h"

class OneButtonSwitch
{
public:
  GButton button;

  OneButtonSwitch(uint8_t buttonPin, uint8_t relayPin, uint8_t ledPin);
  void switchState();
  void tick();
  bool wasHolded();
  void turnOff();

private:
  uint8_t _butt, _relay, _led;
  bool _state;
  bool turnOffEverything;

  void setState(bool state);
};
