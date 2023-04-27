# The CFLAGS variable sets compile flags for gcc:
#  -g          	compile with debug information
#  -Wall       	give verbose compiler warnings
#  -O0         	do not optimize generated code
#  -O1 			The compiler attempts to reduce both the size of the output binary code and the execution speed, 
#				but it does not perform optimizations that might substantially increase the compilation time.
#  -O2 			The compiler performs optimizations that do not require a tradeoff of space for speed. Compared to level 1, 
#				level 2 optimization improves the performance of the output binary but it also increases the compilation time.
#  -O3 			The compiler turns on the -fgcse-after-reload, -finline-functions, -fipa-cp-clone, -fpredictive-commoning,
#			 	-ftree-vectorize, and -funswitch-loops options, which require a tradeoff of space for speed, 
#				in addition to the level 2 optimizations.
#  -Os			The compiler optimizes to reduce the size of the binary instead of execution speed.
CFLAGS = -g -Os

all: system.bin

std_lib.o: std_lib.c std_lib.h
	arm-none-eabi-gcc -c $(CFLAGS) -mcpu=cortex-m3 -mthumb -o std_lib.o std_lib.c

startup_lm3s6965.o: startup_lm3s6965.c irq.h std_lib.o
	arm-none-eabi-gcc -c $(CFLAGS) -mcpu=cortex-m3 -mthumb -o startup_lm3s6965.o startup_lm3s6965.c

nvic.o: nvic.c nvic.h lm3s6965_memmap.h
	arm-none-eabi-gcc -c $(CFLAGS) -mcpu=cortex-m3 -mthumb -o nvic.o nvic.c

uart_drv.o: uart_drv.c uart_drv.h lm3s6965_memmap.h
	arm-none-eabi-gcc -c $(CFLAGS) -mcpu=cortex-m3 -mthumb -o uart_drv.o uart_drv.c

serial_print.o: serial_print.c irq.h nvic.h uart_drv.h
	arm-none-eabi-gcc -c $(CFLAGS) -mcpu=cortex-m3 -mthumb -o serial_print.o serial_print.c

startup_lm3s6965.elf: startup_lm3s6965.o nvic.o uart_drv.o serial_print.o
	arm-none-eabi-ld -T lm3s6965_layout.ld -o startup_lm3s6965.elf std_lib.o startup_lm3s6965.o nvic.o uart_drv.o serial_print.o 

system.bin: startup_lm3s6965.elf
	arm-none-eabi-objcopy -O binary startup_lm3s6965.elf system.bin

run: system.bin
	qemu-system-arm -M lm3s6965evb -kernel system.bin -nographic -monitor telnet:127.0.0.1:1234,server,nowait 

rundbg: system.bin
	qemu-system-arm -S -M lm3s6965evb -kernel system.bin -gdb tcp::5678 -nographic -monitor telnet:127.0.0.1:1234,server,nowait 

clean:
	rm -f startup_lm3s6965.o serial_print.o uart_drv.o nvic.o startup.elf startup.bin std_lib.o
            
dump: 
	arm-none-eabi-nm -n startup_lm3s6965.o
	arm-none-eabi-objdump -h startup_lm3s6965.o
	arm-none-eabi-nm -n serial_print.o
	arm-none-eabi-objdump -h serial_print.o
	arm-none-eabi-nm -n uart_drv.o
	arm-none-eabi-objdump -h uart_drv.o
	arm-none-eabi-nm -n nvic.o
	arm-none-eabi-objdump -h nvic.o
	arm-none-eabi-nm -n startup_lm3s6965.elf
	arm-none-eabi-objdump -h startup_lm3s6965.elf
	arm-none-eabi-size startup_lm3s6965.elf
