##########################################   OPTION SETTING ###########################################

OUTPUT = mini_shell 
CCOMPILE = gcc

LINK = gcc

LINKOPTION += -o $(OUTPUT)
INCLUDEDIR += -I.

INCLUDEDIR += -I./Include/

OBJS += Check_Command/check_command.o
OBJS += Echo/echo.o

OBJS += Get_Command/get_command.o
OBJS += Internals/internal.o
OBJS += Scan_Input/scan_input.o
OBJS += Pipe_Commands/piped_commands.o
OBJS += Store_Signal_Info/store_signal_info.o

OBJS += main.o

##########################################     OPTION END   ###########################################



$(OUTPUT):$(OBJS) 

	$(LINK) $(LINKOPTION)  $(OBJS) 

clean: 
	rm -f $(OBJS)
	rm -f $(OUTPUT)

all: clean $(OUTPUT)
.PRECIOUS:%.cpp %.cc %.cxx %.c 
.SUFFIXES:
.SUFFIXES: .cpp .cc .cxx .c  .o

.cpp.o:
	$(CPPCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR)  $*.cpp
	
.cc.o:
	$(CCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR)  $*.cc

.cxx.o:
	$(CPPCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR)  $*.cxx

.c.o:
	$(CCOMPILE) -c -o $*.o $(COMPILEOPTION) $(INCLUDEDIR) $*.c


#######################################################################################################	
