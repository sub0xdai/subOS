OBJECTS = src/loader.o src/kernelmain.o src/lib/io.o

CC       = gcc
CFLAGS   = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
           -nostartfiles -nodefaultlibs -ffreestanding \
           -Wall -Wextra -Werror -c -Iinclude

LDFLAGS  = -T link.ld -melf_i386
AS       = nasm
ASFLAGS  = -f elf32

all: kernel.elf
	mkdir -p iso/boot/grub
	cp grub/grub.cfg iso/boot/grub/grub.cfg
	cp kernel.elf iso/boot/kernel.elf
	grub-mkrescue -o subOS.iso iso -d /usr/lib/grub/i386-pc

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

run: all
	qemu-system-i386 -cdrom subOS.iso -display curses

clean:
	rm -rf $(OBJECTS) kernel.elf subOS.iso iso
