# Makefile voor HelloGoodbye
#
# Marc_G 2012 (Aangepast door Roel Vugts)

NAME = bank #enter name here

CC = g++
CFLAGS = -Wall
PROG = $(NAME)
SRC = $(NAME).cpp $(NAME)_main.cpp
OBJS = bank.o bank_main.o

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS)
	@rm $(OBJS)
	@echo "\n" 
	@./$(NAME) 

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	/bin/rm -f $(PROG) $(OBJS)
	
depend:
	makedepend $(SRC)
