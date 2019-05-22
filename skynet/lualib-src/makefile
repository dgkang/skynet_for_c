include ../../platform.mk

C_FILE = $(wildcard *.c )
OBJ_FILE = $(patsubst %.c, %.o, $(C_FILE))
SHARED_FILE = socketdriver.so skynet.so profile.so memory.so lpeg.so sproto.so netpack.so multicast.so \
cluster.so mysqlaux.so sharedata.so crypt.so debugchannel.so stm.so bson.so clientsocket.so md5.so mongo.so

COMP_INC = $(LUA_INC) $(SKYNET_INC) $(LUA_SERI_INC)
COMP_LIB = -lpthread -lm -lrt -Wl,-E -ldl -lz

all: $(SHARED_FILE)

socketdriver.so: lua-socket.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 

skynet.so: lua-skynet.c $(LUA_SERI_PATH)/lua-seri.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 
	
profile.so: lua-profile.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 

memory.so: lua-memory.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 

lpeg.so : $(LPEG_PATH)/lpcap.c $(LPEG_PATH)/lpcode.c $(LPEG_PATH)/lpprint.c $(LPEG_PATH)/lptree.c $(LPEG_PATH)/lpvm.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 

sproto.so : $(SPROTO_PATH)/sproto.c $(SPROTO_PATH)/lsproto.c 
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 
	
netpack.so : lua-netpack.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@ 
	
multicast.so : lua-multicast.c 
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

cluster.so : lua-cluster.c	
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@
	
mysqlaux.so : lua-mysqlaux.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

debugchannel.so : lua-debugchannel.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@
	
crypt.so : lua-crypt.c lsha1.c 
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

sharedata.so : lua-sharedata.c 
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

stm.so: lua-stm.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@
	
bson.so :lua-bson.c 
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

mongo.so : lua-mongo.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

md5.so : $(MD5_PATH)/md5.c $(MD5_PATH)/md5lib.c $(MD5_PATH)/compat-5.2.c
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

clientsocket.so : lua-clientsocket.c 
	$(CC) $(CFLAGS) $(SHARED) $(COMP_INC) $(SKYNET_LIB) $(LUA_LIB) $^ -o $@

clean:
	rm -f $(OUT_FILE) $(OBJ_FILE) $(SHARED_FILE)
