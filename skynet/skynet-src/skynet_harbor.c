#include "skynet.h"
#include "skynet_harbor.h"
#include "skynet_server.h"
#include "skynet_mq.h"
#include "skynet_handle.h"

#include <string.h>
#include <stdio.h>
#include <assert.h>

static struct skynet_context * REMOTE = 0;
static unsigned int HARBOR = ~0;

void 
skynet_harbor_send(struct remote_message *rmsg, uint32_t source, int session) {
	int type = rmsg->sz >> MESSAGE_TYPE_SHIFT;
	rmsg->sz &= MESSAGE_TYPE_MASK;
	assert(type != PTYPE_SYSTEM && type != PTYPE_HARBOR && REMOTE);
	skynet_context_send(REMOTE, rmsg, sizeof(*rmsg) , source, type , session);
}

int 
skynet_harbor_message_isremote(uint32_t handle) {
	assert(HARBOR != ~0);
	int h = (handle & ~HANDLE_MASK);
	return h != HARBOR && h !=0;
}

void
skynet_harbor_init(int harbor) {
	HARBOR = (unsigned int)harbor << HANDLE_REMOTE_SHIFT;
}

void
skynet_harbor_start(void *ctx) {
	// the HARBOR must be reserved to ensure the pointer is valid.
	// It will be released at last by calling skynet_harbor_exit
	skynet_context_reserve(ctx);
	REMOTE = ctx;
}

void
skynet_harbor_exit() {
	struct skynet_context * ctx = REMOTE;
	REMOTE= NULL;
	if (ctx) {
		skynet_context_release(ctx);
	}
}

#include "liblua-seri.h"

void 
 skynet_harbor_register(struct remote_name *rname) {
     int i;
     int number = 1;
     for (i=0;i<GLOBALNAME_LENGTH;i++) {
         char c = rname->name[i];
         if (!(c >= '0' && c <='9')) {
             number = 0;
             break;
         }
     }
     assert(number == 0);

     struct lua_seri_handle* h = lua_seri_init(); 
     lua_seri_push_string(h,"REGISTER",8);
     lua_seri_push_string(h,rname->name,strlen(rname->name));
     lua_seri_push_integer(h,rname->handle);
     void* msg = lua_seri_buffer(h);
     skynet_sendname(REMOTE,0,".cslave",PTYPE_RESERVED_LUA,0,msg,lua_seri_buffer_len(h));
     lua_seri_buffer_free(msg);
     lua_seri_free(h);
}
