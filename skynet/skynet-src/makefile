include ../../platform.mk

C_FILE = $(wildcard *.c)
OBJ_FILE = $(patsubst %.c, %.o, $(C_FILE))
OUT_FILE = ./skynet.a

COMP_INC = $(LUA_INC) $(LUA_SERI_INC) $(SERVICE_CORE_INC)
COMP_LIB = -lpthread -lm -lrt -Wl,-E -ldl -lz

all: $(OUT_FILE)
$(OUT_FILE): $(OBJ_FILE)
	$(AR) rc $(OUT_FILE) $(OBJ_FILE)
	
%.o:%.c
	$(CC) $(CFLAGS) -o $@ $(COMP_INC) -c $<
	
clean:
	rm -f $(OUT_FILE) $(OBJ_FILE)
