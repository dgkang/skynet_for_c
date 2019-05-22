CC = gcc
CXX = g++

CFLAGS = -O0 -g3 -ggdb -DNOUSE_JEMALLOC

override CXXFLAGS += -O0 -g3 -ggdb -D_cplusplus

COMMON_LIBS = -lpthread -lm -lrt -Wl,-E -ldl -lz

SHARED = -fPIC --shared

CWARNS = -Wall -Wextra -pedantic \
	-Waggregate-return \
	-Wcast-align \
	-Wcast-qual \
	-Wdisabled-optimization \
	-Wpointer-arith \
	-Wshadow \
	-Wsign-compare \
	-Wundef \
	-Wwrite-strings \
	-Wbad-function-cast \
	-Wdeclaration-after-statement \
	-Wmissing-prototypes \
	-Wnested-externs \
	-Wstrict-prototypes \
 -Wunreachable-code \

WARNSNO = -Wno-aggregate-return \
	-Wno-cast-align \
	-Wno-cast-qual \
	-Wno-disabled-optimization \
	-Wno-pointer-arith \
	-Wno-shadow \
	-Wno-sign-compare \
	-Wno-undef \
	-Wno-write-strings \
	-Wno-bad-function-cast \
	-Wno-declaration-after-statement \
	-Wno-missing-prototypes \
	-Wno-nested-externs \
	-Wno-strict-prototypes \
	-Wno-unreachable-code \
	-Wno-pointer-to-int-cast \
	-Wno-int-to-pointer-cast \
	-Wno-implicit-function-declaration \

PRJ_PATH =/root/workspace/git/skynet_project

ICONV_LIB = /usr/local/lib/libiconv.a
PROTOC_INC=-I/usr/local/protobuf/include/
PROTOC_LIB=/usr/local/lib/libprotobuf.a

MYSQL_INC=-I/usr/local/mysql/include/
MYSQL_LIB=/usr/local/mysql/lib/libmysqlclient_r.a

LUA_PATH = $(PRJ_PATH)/3rd/lua
LUA_INC = -I$(LUA_PATH)/
LUA_LIB = $(LUA_PATH)/liblua.a

LUA_SERI_PATH = $(PRJ_PATH)/3rd/lua-seri
LUA_SERI_INC = -I$(LUA_SERI_PATH)/
LUA_SERI_LIB = $(LUA_SERI_PATH)/lua_seri.a

XLS_PATH = $(PRJ_PATH)/3rd/xls
XLS_INC = -I$(XLS_PATH)/
XLS_LIB = $(XLS_PATH)/xls.a $(XLS_PATH)/libxls/libxls.a

SPROTO_PATH = $(PRJ_PATH)/3rd/sproto
SPROTO_INC = -I$(SPROTO_PATH)/
SPROTO_LIB = $(SPROTO_PATH)/sproto.a

LPEG_PATH = $(PRJ_PATH)/3rd/lpeg

MD5_PATH = $(PRJ_PATH)/3rd/lua-md5

SKYNET_PATH = $(PRJ_PATH)/skynet/skynet-src
SKYNET_INC = -I$(SKYNET_PATH)/
SKYNET_LIB = $(SKYNET_PATH)/skynet.a

SERVICE_CORE_PATH = $(PRJ_PATH)/skynet/service_core-src
SERVICE_CORE_INC = -I$(SERVICE_CORE_PATH)/
SERVICE_CORE_LIB = $(SERVICE_CORE_PATH)/service_core.a

LUALIB_PATH = $(PRJ_PATH)/skynet/lualib-src
LUALIB_INC = -I$(LUALIB_PATH)/

FRAME_PATH = $(PRJ_PATH)/frame
FRAME_SERVICE_PATH = $(FRAME_PATH)/service

SERVICE_SQLMGR_PATH=$(FRAME_SERVICE_PATH)/sqlmgr
SERVICE_SQLMGR_INC=-I$(SERVICE_SQLMGR_PATH)/
SERVICE_SQLMGR_LIB=$(SERVICE_SQLMGR_PATH)/sqlmgr.a

SERVICE_CACHEWRITER_PATH=$(FRAME_SERVICE_PATH)/cache_writer
SERVICE_CACHEWRITER_INC=-I$(SERVICE_CACHEWRITER_PATH)/
SERVICE_CACHEWRITER_LIB=$(SERVICE_CACHEWRITER_PATH)/writer.a

SERVICE_LOGIN_PATH=$(FRAME_SERVICE_PATH)/login
SERVICE_LOGIN_INC=-I$(SERVICE_LOGIN_PATH)/
SERVICE_LOGIN_LIB=$(SERVICE_LOGIN_PATH)/login.a

SERVICE_SENDER_PATH=$(FRAME_SERVICE_PATH)/sender
SERVICE_SENDER_INC=-I$(SERVICE_SENDER_PATH)/
SERVICE_SENDER_LIB=$(SERVICE_SENDER_PATH)/sender.a

SERVICE_AGENT_PATH=$(FRAME_SERVICE_PATH)/agent
SERVICE_AGENT_INC=-I$(SERVICE_AGENT_PATH)/
SERVICE_AGENT_LIB=$(SERVICE_AGENT_PATH)/agent.a


FRAME_PB_PATH = $(FRAME_PATH)/pb

CONFIGPB_PATH = $(FRAME_PB_PATH)/config
CONFIGPB_INC  =-I$(CONFIGPB_PATH)/
CONFIGPB_LIB  = $(CONFIGPB_PATH)/config_pb.a

DATAPB_PATH = $(FRAME_PB_PATH)/data
DATAPB_INC = -I$(DATAPB_PATH)
DATAPB_LIB = $(DATAPB_PATH)/data_pb.a

CLIENTPB_PATH = $(FRAME_PB_PATH)/client
CLIENTPB_INC = -I$(CLIENTPB_PATH)
CLIENTPB_LIB = $(CLIENTPB_PATH)/client_pb.a

SERVERPB_PATH = $(FRAME_PB_PATH)/server
SERVERPB_INC = -I$(SERVERPB_PATH)
SERVERPB_LIB = $(SERVERPB_PATH)/server_pb.a

BASE_PATH = $(FRAME_PATH)/base
BASE_INC = -I$(BASE_PATH)/
BASE_LIB = $(BASE_PATH)/base.a
