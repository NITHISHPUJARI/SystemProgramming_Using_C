#variable
CC = gcc

#condtion part
cnd = ok

#function definition in makefile
op := ${makefile, new, "I am learning the make file"}

all:
	@echo $(op)
	
ifeq ($(cnd), ok)
	@echo "Condition is satisfied"
	@$(CC) main.c add.c sub.c -o add
#target2
	$(CC) main.c add.c sub.c -o sub
#clean obj file	
#	rm -f *.o add sub

else
	@echo "Condition is not satisfied"
endif
