#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "skynet_core.h"

int global_env_start();

struct enter
{
    
};

struct enter * enter_create(void)
{
    struct enter * e = (struct enter *)skynet_malloc(sizeof(struct enter));
    return e;
}

void enter_release(struct enter *e)
{
    skynet_free(e);
}

int enter_init(struct enter *e , struct skynet_context * ctx, char * parm)
{
    int ret = global_env_start();
    if( ret != 0){
        skynet_error(ctx,"global environment start failed,%d",ret);
        exit(1);
    }
    return 0;
}