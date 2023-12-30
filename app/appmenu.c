#include "appmenu.h"
#include "../ui/welcome.h"
#ifdef ENABLE_MESSENGER
	#include "../app/messenger.h"
  #include "frequencies.h"
  #include "external/printf/printf.h"
  #include "settings.h"
#endif
void APPMENU_ProcessKeys(KEY_Code_t Key, bool bKeyPressed, bool bKeyHeld) {
  switch (Key) {
  case KEY_EXIT:
    gRequestDisplayScreen = DISPLAY_MAIN;
    break;

  case KEY_MENU:
    gRequestDisplayScreen = DISPLAY_MENU;
	  break;

  case KEY_0:
	UI_DisplayWelcome();
    //gRequestDisplayScreen = DISPLAY_MAIN;
	  break;

  case KEY_1:
    gAppToDisplay = APP_SCANLIST;
    gRequestDisplayScreen = DISPLAY_MAIN;
    break;

#ifdef ENABLE_MESSENGER
  case KEY_2:
    hasNewMessage = false;
    uint32_t frequency = gEeprom.VfoInfo[gEeprom.TX_CHANNEL].pTX->Frequency;
    if ( IsTXAllowed(gEeprom.VfoInfo[gEeprom.TX_CHANNEL].pTX->Frequency) ) {
      frequency = GetScreenF(frequency);
      sprintf(msgFreqInfo, "%u.%05u Mhz", frequency / 100000, frequency % 100000);
    } else {
      sprintf(msgFreqInfo, "TX DISABLE");
    }
    gUpdateStatus = true;
    gAppToDisplay = APP_MESSENGER;
	  gRequestDisplayScreen = DISPLAY_MAIN;
    break;
#endif

/*
  case KEY_1:
    gAppToDisplay = APP_SPLIT;
    gRequestDisplayScreen = DISPLAY_MAIN;
    break;
  case KEY_2:
    gAppToDisplay = APP_OOK;
    gRequestDisplayScreen = DISPLAY_MAIN;
    break;
*/
  default:
    break;
  }
}