FROM archlinux:latest

RUN pacman -Syu --noconfirm && \
    pacman -S --noconfirm \
        gcc \
        nasm \
        binutils \
        grub \
        xorriso \
        mtools \
        qemu-system-x86 \
        make \
    && pacman -Scc --noconfirm

WORKDIR /subOS
CMD ["make"]
