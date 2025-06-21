#ifndef UNIX_H
#define UNIX_H
/*=========================================================================*\
* Unix domain object
* LuaSocket toolkit
*
* This module is just an example of how to extend LuaSocket with a new 
* domain.
\*=========================================================================*/
#include "luasocket.h"

#include "buffer.h"
#include "timeout.h"
#include "socket.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct t_unix_ {
    t_socket sock;
    t_io io;
    t_buffer buf;
    t_timeout tm;
} t_unix;
typedef t_unix *p_unix;

LUASOCKET_API int luaopen_socket_unix(lua_State *L);

#ifdef __cplusplus
}
#endif

#endif /* UNIX_H */
