include ../../../platform.mk

CPP_FILE = $(wildcard *.c )
OBJ_FILE = $(patsubst %.c, %.o, $(CPP_FILE))
OUT_FILE = ./libxls.a


COMP_INC = -I../

all:$(OUT_FILE)
$(OUT_FILE): $(OBJ_FILE)
	$(AR) rc $(OUT_FILE) $(OBJ_FILE)

%.o:%.c
	$(CC) $(WARNSNO) --std=c99 -o $@ $(COMP_INC) -c $<

clean:
	rm -f $(OUT_FILE) $(OBJ_FILE) 
