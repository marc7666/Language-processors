######################################################################
#
#
#
#             Integracio de les eines flex, bison, symtab i gcc
#
#                           Tere Alsinet
#
#
#
#
######################################################################

# General defines
CC = gcc
LEX = flex
YACC = bison
TARGET= cine
CFLAGS = -Wall

######################################################################

$(TARGET) : $(TARGET).tab.c  lex.yy.c symtab.c
	gcc $(CFLAGS) $(TARGET).tab.c lex.yy.c symtab.c -o $(TARGET)

lex : $(TARGET).l
	lex $(TARGET).l
	gcc -Wall lex.yy.c -o $(TARGET) -ll

$(TARGET).tab.c: $(TARGET).y
	$(YACC) -d -v $(TARGET).y -o $(TARGET).tab.c

lex.yy.c : $(TARGET).l
	flex $(TARGET).l

clean :
	rm -f $(TARGET) $(TARGET).tab.c $(TARGET).tab.h lex.yy.c $(TARGET).output
