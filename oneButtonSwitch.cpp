#include "GyverButton.h"
#include "oneButtonSwitch.h"

OneButtonSwitch::OneButtonSwitch(uint8_t buttonPin, uint8_t relayPin, uint8_t ledPin) : button(buttonPin, LOW_PULL, NORM_OPEN)
{
  button.setTimeout(5000);
  _butt = buttonPin;
  _relay = relayPin;
  _led = ledPin;
  _state = false;

  pinMode(_relay, OUTPUT);
  pinMode(_led, OUTPUT);
}

void OneButtonSwitch::switchState()
{
  _state = !_state;
  setState(_state);
}

void OneButtonSwitch::tick()
{
  button.tick();
  if (button.isSingle())
  {
    switchState();
  }
  else if (button.isHolded())
  {
    turnOffEverything = true;
  }
}

bool OneButtonSwitch::wasHolded()
{
  if (turnOffEverything)
  {
    turnOffEverything = false;
    return true;
  }
  else
  {
    return false;
  }
}

void OneButtonSwitch::turnOff()
{
  setState(false);
}

void OneButtonSwitch::setState(bool state)
{
  digitalWrite(_relay, state);
  digitalWrite(_led, !state);
}
