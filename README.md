# subOS

```bash
# build
podman run --rm -v .:/subOS subos-dev make

# build + run in QEMU
podman run --rm -v .:/subOS -e DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix subos-dev make run

# clean
podman run --rm -v .:/subOS subos-dev make clean
```
