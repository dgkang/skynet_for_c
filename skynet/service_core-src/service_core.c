#include "skynet_module.h"
#include "skynet_imp.h"
#include "skynet_env.h"
#include "skynet_server.h"
#include "service_core.h"

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct enter * enter_create(void);
void enter_release(struct enter *e);
int enter_init(struct enter *e , struct skynet_context * ctx, char * parm);

struct logger * logger_create(void);
void logger_release(struct logger * inst);
int logger_init(struct logger * inst, struct skynet_context *ctx, const char * parm);

struct snlua * snlua_create(void);
void snlua_release(struct snlua *l);
int snlua_init(struct snlua *l, struct skynet_context *ctx, const char * args);

struct harbor * harbor_create(void);
void harbor_release(struct harbor *h);
int harbor_init(struct harbor *h, struct skynet_context *ctx, const char * args);

struct gate * gate_create(void);
void gate_release(struct gate *g);
int gate_init(struct gate *g , struct skynet_context * ctx, char * parm);

struct client * client_create(void);
int client_init(struct client *c, struct skynet_context *ctx, const char * args);
void client_release(struct client *c);

void skynet_module_core_create(int service_type)
{
    if (service_type & SERVICE_CORE_TYPE_GATE){
        skynet_module_create(SERVICE_CORE_NAME_GATE,(skynet_dl_create)gate_create,(skynet_dl_init)gate_init,(skynet_dl_release)gate_release);
    }

    if (service_type & SERVICE_CORE_TYPE_CLIENT){
        skynet_module_create(SERVICE_CORE_NAME_CLIENT,(skynet_dl_create)client_create,(skynet_dl_init)client_init,(skynet_dl_release)client_release);
    }

    skynet_module_create("logger",(skynet_dl_create)logger_create,(skynet_dl_init)logger_init,(skynet_dl_release)logger_release);
    skynet_module_create("snlua",(skynet_dl_create)snlua_create,(skynet_dl_init)snlua_init,(skynet_dl_release)snlua_release);
    skynet_module_create("harbor",(skynet_dl_create)harbor_create,(skynet_dl_init)harbor_init,(skynet_dl_release)harbor_release);
    skynet_module_create("enter",(skynet_dl_create)enter_create,(skynet_dl_init)enter_init,(skynet_dl_release)enter_release);
    return;
}


void skynet_service_core_start(struct skynet_config* config)
{
    struct skynet_context *ctx = skynet_context_new(config->logservice, config->logger);
    if (ctx == NULL) {
        fprintf(stderr, "Can't launch %s service\n", config->logservice);
        exit(1);
    }

    ctx = skynet_context_new("snlua","launcher");
    if (ctx == NULL){
        fprintf(stderr,"Launch launcher service failed.\n");
        exit(1);
    }else{
        skynet_command(ctx,"REG",".launcher");
    }

    int harbor_id = skynet_getenv_int("harbor",0);
    fprintf(stderr,"harbor: %d\n",harbor_id);
    const char* standalone = skynet_getenv_string("standalone",NULL);
    if (harbor_id != 0){
        assert (standalone != NULL);
        if (harbor_id != 1){
            standalone = NULL;
        }
        if(standalone){
            ctx = skynet_context_new("snlua","cmaster");
            if (ctx == NULL){
                fprintf(stderr,"Launch cmaster service failed.\n");
                exit(1);
            }
        }
    }else{
        assert(standalone == NULL);
        ctx = skynet_context_new("snlua","cdummy");
        if (ctx == NULL){
            fprintf(stderr,"Launch cdummy service failed.\n");
            exit(1);
        }
    }
    ctx = skynet_context_new("snlua","cslave");
    if (ctx == NULL){
        fprintf(stderr,"Launch cslave service failed.\n");
        exit(1);
    }else{
        skynet_command(ctx,"REG",".cslave");
    }
}