
_DEPS= cp3Types.h MiniEvent.h ntupleReader.h Converter.h cp3Builder.h Tools.h BtagWeight.h
_OBJ = MiniEvent.o ntupleReader.o Converter.o cp3Builder.o Tools.o Dict.o BtagWeight.o
_PLUGINS = ntupleToCp3.out verifyIntegrity.out ntupleToCp3_jec.out plotter.out

IDIR = .
LDIR = ./lib
ODIR = ./src
PDIR = ./plugins
BDIR = ./bin

PLUGINS = $(patsubst %,$(BDIR)/%,$(_PLUGINS))


CFLAGS = -I$(IDIR) -I./
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
OBJ  = $(patsubst %,$(ODIR)/%,$(_OBJ))
CC = g++
COpt = -Wall -Wextra  `root-config --cflags --libs` -O3 -lGenVector 

DICTC = Dict.cc
DICTH = Dict.h

HDRS_DICT = include/MiniEvent.h include/cp3Types.h include/Linkdef.h

#include/DataFormats.h include/MyHeader.h include/Linkdef.h

all:
	@echo "############# COMPILING ALL #############"
	@echo "###### CINT..."
	@make cint
	@echo "###### DONE !"
	@echo "###### COMPILING DEPENDENCIES..."
	@make  -j4 $(OBJ)
	@echo "###### COMPILING $(PLUGINS)..."
	@make -j8 $(PLUGINS)
	
	 
cint: $(ODIR)/$(DICTC)

$(ODIR)/$(DICTC): $(HDRS_DICT)
	rootcint -f $@ -c $(CFLAGS) $^ 
	@mv src/Dict_rdict.pcm .
	@cp Dict_rdict.pcm ..


%.o: %.cc
	$(CC) $(COpt) -c -o $@ $< $(CFLAGS) $(ROOTLIBS) -L$(ROOTSYS)/lib


bin/%.out: plugins/%.cc $(OBJ)
	$(CC) $(COpt) -o $@ $^ $(CFLAGS) $(ROOTLIBS) -L$(ROOTSYS)/lib

#%.out : %.cc $(OBJ)
#	@echo "###### ------> $@"
#	@echo $^
#	#$(CC) $(COpt) -o $@ $(patsubst %.out,%.cc,$(subst $(BDIR),$(PDIR),./$@)) $^ $(CFLAGS) $(ROOTLIBS) -L$(ROOTSYS)/lib
#	$(CC) $(COpt) -o $@ $^ $(CFLAGS) $(ROOTLIBS) -L$(ROOTSYS)/lib
	

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o hellomake src/Dict.cc include/Dict.h bin/* Dict_rdict.pcm plugins/*.out

