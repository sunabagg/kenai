#ifndef GLOBAL_THEME_H
#define GLOBAL_THEME_H

#include "theme.h"

namespace sunaba::ui {
    class uiGlobals {
        private:
            static Theme* globalTheme;
        public:
            static Theme* getGlobalTheme() {
                return globalTheme;
            }
            static void setGlobalTheme(Theme* theme) {
                globalTheme = theme;
            }
    };
}

#endif