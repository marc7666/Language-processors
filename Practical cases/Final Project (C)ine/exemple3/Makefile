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
TARGET= array_if_while_adreces
CFLAGS = -Wall

######################################################################

$(TARGET) : $(TARGET).tab.c  lex.yy.c symtab.c
	gcc $(CFLAGS) $(TARGET).tab.c lex.yy.c symtab.c -o $(TARGET)

	
$(TARGET).tab.c: $(TARGET).y
	$(YACC) -d -v $(TARGET).y -o $(TARGET).tab.c

lex.yy.c : $(TARGET).l
	flex $(TARGET).l
	
clean : 
	rm -f $(TARGET) $(TARGET).tab.c $(TARGET).tab.h lex.yy.c $(TARGET).output