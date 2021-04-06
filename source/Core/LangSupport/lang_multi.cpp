#include "../../configuration.h"
#include "OLED.hpp"
#include "Translation.h"
#include "gui.hpp"

const char *translatedString(const char *str) {
  if (systemSettings.uiLanguage >= LanguageCount) {
    systemSettings.uiLanguage = 0;
  }
  uint8_t skipCnt = systemSettings.uiLanguage;
  while (skipCnt > 0) {
    while (str[0]) {
      str++;
    }
    str++;
    skipCnt--;
  }
  return str;
}

bool settings_setLanguageSwitch(void) {
  systemSettings.uiLanguage = (systemSettings.uiLanguage + 1) % LanguageCount;
  return systemSettings.uiLanguage == (LanguageCount - 1);
}

bool settings_displayLanguageSwitch(void) {
  const char *langCodeStr = translatedString(LanguageCodes);
  uint16_t    len         = str_display_len(langCodeStr);
  printShortDescription(SettingsItemIndex::LanguageSwitch, 8 - len);
  OLED::print(langCodeStr, FontStyle::LARGE);
  return false;
}
