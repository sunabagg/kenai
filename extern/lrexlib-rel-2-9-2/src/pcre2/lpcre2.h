#include "lua.h"
#include "lauxlib.h"
#include "../common.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef REX_OPENLIB
#  define REX_OPENLIB luaopen_rex_pcre2
#endif

LUALIB_API int REX_OPENLIB (lua_State *L);

#ifdef __cplusplus
}
#endif