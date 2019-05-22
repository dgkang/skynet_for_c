#ifndef SKYNET_ENV_H
#define SKYNET_ENV_H

const char * skynet_getenv(const char *key);

void skynet_setenv(const char *key, const char *value);

void skynet_setenv_nil(const char *key);

void skynet_env_init();

const char * skynet_getenv_string(const char *key,const char * opt);

int skynet_getenv_int(const char *key, int opt);

#endif
