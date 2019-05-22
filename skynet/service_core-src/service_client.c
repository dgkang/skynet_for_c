#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "skynet_core.h"

struct client {
    int header_size;
	int gate;
	uint8_t id[4];
};

static int _cb(struct skynet_context * context, void * ud, int type, int session, uint32_t source, const void * msg, size_t sz) {
    struct client * c = (struct client * )ud;  
    if (c->id[0] == 0 && c->id[1] == 0 && c->id[2] == 0 && c->id[3] == 0){
        return 0;
    }
    uint8_t *tmp = (uint8_t*)msg + sz - 4; //后四个字节填充 skynet socket id
	memcpy(tmp, c->id, 4);
    if (c->header_size == 4){
        *((uint32_t*)(msg)) = htonl(sz- 4 - c->header_size); //头四个字节填写大端消息包大小，自然要减去头4或2个字节和后4个字节
    }else if(c->header_size == 2){
        *((uint16_t*)(msg)) = htonl(sz- 4 - c->header_size); //头四个字节填写大端消息包大小，自然要减去头4或2个字节和后4个字节
    }
	skynet_send(context, source, c->gate, PTYPE_CLIENT | PTYPE_TAG_DONTCOPY, 0, (void*)msg, sz); //整体发送到gate服务。
	return 1;
}

int client_init(struct client *c, struct skynet_context *ctx, const char * args) 
{
	char header = 0;
    int gate = 0, id = 0;
	int n = sscanf(args, "%c %d %d",&header, &gate, &id);
	if (n != 3 || gate == 0){
        skynet_error(ctx,"Invalid init client %s",args);
		return 1;
	}

    if (header != 'S' && header !='L') {
         skynet_error(ctx, "Invalid data header style");
        return 1;
    }

	c->gate = gate;
    c->header_size = header == 'S' ? 2 : 4;
	c->id[0] = id & 0xff;
	c->id[1] = (id >> 8) & 0xff;
	c->id[2] = (id >> 16) & 0xff;
	c->id[3] = (id >> 24) & 0xff;
	skynet_callback(ctx, c, _cb);
	return 0;
}

struct client * client_create(void) {
	struct client *c = (struct client *)skynet_malloc(sizeof(*c));
	memset(c,0,sizeof(*c));
	return c;
}

void client_release(struct client *c) {
	skynet_free(c);
}
