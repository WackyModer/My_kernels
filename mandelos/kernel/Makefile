
all:
	nasm -f bin ../boot/bootloader.asm -o bootloader.bin
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c kernel.c -o kernel.o -m32
	gcc -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/stdio.c -o stdio.o  -m32
	gcc -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/stdlib.c -o stdlib.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/string.c -o string.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../drivers/video.c -o video.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../drivers/keyboard.c -o keyboard.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/math.c -o math.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ./mandel.c -o mandel.o  -m32
	nasm  -f elf32 kernel_head.asm -o kernel_head.o 
	ld  -melf_i386 -o kernel.bin -Ttext 0x1000 kernel_head.o kernel.o stdlib.o stdio.o string.o video.o keyboard.o math.o mandel.o --oformat binary -T link.ld
	cat bootloader.bin kernel.bin > ../wackos.img
	rm *.bin *.o

flash:
	sudo dd if=/dev/zero bs=512  count=200 of=/dev/sda
	sudo dd if=../wackos.img of=/dev/sda


emu: 
	qemu-system-x86_64 ../wackos.img -display default,show-cursor=on

both:
	nasm -f bin ../boot/bootloader.asm -o bootloader.bin
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c kernel.c -o kernel.o -m32
	gcc -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/stdio.c -o stdio.o  -m32
	gcc -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/stdlib.c -o stdlib.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/string.c -o string.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../drivers/video.c -o video.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../drivers/keyboard.c -o keyboard.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ../lib/math.c -o math.o  -m32
	gcc  -ffreestanding -fno-stack-protector  -fno-pie -c ./mandel.c -o mandel.o  -m32
	nasm  -f elf32 kernel_head.asm -o kernel_head.o 
	ld  -melf_i386 -o kernel.bin -Ttext 0x1000 kernel_head.o kernel.o stdlib.o stdio.o string.o video.o keyboard.o math.o mandel.o --oformat binary -T link.ld
	cat bootloader.bin kernel.bin > ../wackos.img
	rm *.bin *.o
	qemu-system-x86_64 ../wackos.img -display default,show-cursor=on -usbdevice mouse

