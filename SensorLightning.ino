#include "oneButtonSwitch.h"
#include "twoButtonsSwitch.h"
#include "configuration.h"

#define ONEBUTTON_SWITCHES_AMOUNT 8

OneButtonSwitch oneButtonSwitches[ONEBUTTON_SWITCHES_AMOUNT]{
    OneButtonSwitch(CORRIDOR1_BUTTON, CORRIDOR1_RELAY, CORRIDOR1_LED),  
    OneButtonSwitch(CORRIDOR2_BUTTON, CORRIDOR2_RELAY, CORRIDOR2_LED),  
    OneButtonSwitch(BEDROOM1_BUTTON, BEDROOM1_RELAY, BEDROOM1_LED),
    OneButtonSwitch(BEDROOM3_BUTTON, BEDROOM3_RELAY, BEDROOM3_LED),
    OneButtonSwitch(BATHROOM1_BUTTON, BATHROOM1_RELAY, BATHROOM1_LED),
    OneButtonSwitch(BATHROOM2_BUTTON, BATHROOM2_RELAY, BATHROOM2_LED),
    OneButtonSwitch(WARDROBE1_BUTTON, WARDROBE1_RELAY, WARDROBE1_LED),
    OneButtonSwitch(WARDROBE2_BUTTON, WARDROBE2_RELAY, WARDROBE2_LED)};

#define TWOBUTTONS_SWITCHES_AMOUNT 4

TwoButtonsSwitch twoButtoSwitches[TWOBUTTONS_SWITCHES_AMOUNT]{
    TwoButtonsSwitch(KITCHEN_BUTTON, KITCHEN_RELAY1, KITCHEN_RELAY2, KITCHEN_LED),
    TwoButtonsSwitch(HALL_BUTTON, HALL_RELAY1, HALL_RELAY2, HALL_LED),
    TwoButtonsSwitch(BEDROOM2_BUTTON, BEDROOM2_RELAY1, BEDROOM2_RELAY2, BEDROOM2_LED),
    TwoButtonsSwitch(KIDSROOM_BUTTON, KIDSROOM_RELAY1, KIDSROOM_RELAY2, KIDSROOM_LED)};

void setup()
{
}

void loop()
{
  bool wasHolded = false;
  for (int i = 0; i < ONEBUTTON_SWITCHES_AMOUNT; i++)
  {
    oneButtonSwitches[i].tick();
    wasHolded |= oneButtonSwitches[i].wasHolded();
  }

  for (int i = 0; i < TWOBUTTONS_SWITCHES_AMOUNT; i++)
  {
    twoButtoSwitches[i].tick();
    wasHolded |= twoButtoSwitches[i].wasHolded();
  }

  if (wasHolded)
  {
    for (int i = 0; i < ONEBUTTON_SWITCHES_AMOUNT; i++)
    {
      oneButtonSwitches[i].turnOff();
    }

    for (int i = 0; i < TWOBUTTONS_SWITCHES_AMOUNT; i++)
    {
      twoButtoSwitches[i].turnOff();
    }
  }
}