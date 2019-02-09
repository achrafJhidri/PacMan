.PHONY: all rebuild
all: 
	make -C build

run:
	build/pacman

build cmake build/Makefile:
	@mkdir -p build
	@(cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES ..)

rebuild: cleanbuild cmake all

cleanbuild:
	@rm -rf build

%: build/Makefile
	@make -C build $@
