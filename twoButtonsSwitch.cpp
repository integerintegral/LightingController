#include "GyverButton.h"
#include "twoButtonsSwitch.h"

TwoButtonsSwitch::TwoButtonsSwitch(uint8_t buttonPin, uint8_t firstRelayPin, uint8_t secondRelayPin, uint8_t ledPin) : button(buttonPin, LOW_PULL, NORM_OPEN)
{
    button.setTimeout(5000);
    _butt = buttonPin;
    _relay1 = firstRelayPin;
    _relay2 = secondRelayPin;
    _led = ledPin;
    _firstRelayState = false;
    _secondRelayState = false;

    pinMode(_relay1, OUTPUT);
    pinMode(_relay2, OUTPUT);
    pinMode(_led, OUTPUT);
}

void TwoButtonsSwitch::tick()
{
    button.tick();
    if (button.isSingle())
    {
        if (!_firstRelayState)
        {
            _firstRelayState = true;
        }
        else
        {
            _firstRelayState = false;
            _secondRelayState = false;
        }
    }
    else if (button.isDouble())
    {
        _firstRelayState = true;
        _secondRelayState = true;
    }
    else if (button.isHolded())
    {
        turnOffEverything = true;
    }
    setState(_firstRelayState, _secondRelayState);
}

bool TwoButtonsSwitch::wasHolded()
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

void TwoButtonsSwitch::turnOff()
{
    setState(false, false);
}

void TwoButtonsSwitch::setState(bool firstRelayState, bool secondRelayState)
{
    digitalWrite(_relay1, firstRelayState);
    digitalWrite(_relay2, secondRelayState);
    digitalWrite(_led, !firstRelayState);
}
