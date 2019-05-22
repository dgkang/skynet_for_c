include ../../platform.mk

CPP_FILE = $(wildcard *.cc)
OBJ_FILE = $(patsubst %.cc, %.o, $(CPP_FILE))
OUT_FILE = ./xls.a


COMP_INC = -I./

all:$(OUT_FILE)
$(OUT_FILE): $(OBJ_FILE)
	cd ./libxls/ && $(MAKE)
	$(AR) rc $(OUT_FILE) $(OBJ_FILE)

%.o:%.cc
	$(CXX) $(CXXFLAGS) -o $@ $(COMP_INC) -c $<

clean:
	cd ./libxls/ && $(MAKE) clean
	rm -f $(OUT_FILE) $(OBJ_FILE) 
