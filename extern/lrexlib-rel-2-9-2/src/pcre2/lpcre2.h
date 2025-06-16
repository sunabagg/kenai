#include "lua.h"
#include "lauxlib.h"
#include "../common.h"

#ifndef REX_OPENLIB
#  define REX_OPENLIB luaopen_rex_pcre2
#endif

REX_API int REX_OPENLIB (lua_State *L);