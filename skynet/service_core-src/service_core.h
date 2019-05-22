#ifndef SKYNET_SERVICE_CORE_H
#define SKYNET_SERVICE_CORE_H

#define SERVICE_CORE_TYPE_GATE      1
#define SERVICE_CORE_TYPE_CLIENT    2
#define SERVICE_CORE_TYPE_ALL       0xffffffff

#define SERVICE_CORE_NAME_GATE   "gate"
#define SERVICE_CORE_NAME_CLIENT "client"

void skynet_module_core_create(int service_type);

void skynet_service_core_start(struct skynet_config* config); //必须使用bootstrap.lua来启动，暂时放弃

#endif //SKYNET_SERVICE_CORE_H