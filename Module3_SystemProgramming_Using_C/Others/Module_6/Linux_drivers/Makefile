

obj-m += hello_module.o

obj-m += hello_nass.o

CC := gcc-11

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
