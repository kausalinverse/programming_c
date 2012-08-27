CODE = my_shell_programm.c
OBJS = my_shell_programm.o

CC = gcc
LD = gcc
CC_FLAGS = -c
LD_FLAGS = -o
EXECUTEABLE = my_shell_programm

my_shell_programm: $(OBJS) 
	$(LD) $(CODE) $(LD_FLAGS) $(EXECUTEABLE) 

all : my_shell_programm 

clean :
	rm $(OBJS) $(EXECUTEABLE)
