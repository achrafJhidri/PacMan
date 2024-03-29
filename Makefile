.PHONY: all rebuild
all: 
	make -C build

run:
	build/pacman 
build cmake build/Makefile:
	@mkdir -p build
	@(cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES ..)
	@ln -fs build/compile_commands.json .

rebuild: cleanbuild cmake all

cleanbuild:
	@rm -rf build

%: build/Makefile
	@make -C build $@

winbuild:
	@mkdir -p build
	@cp -r c:/msys64/mingw64/bin build
	make -C . build
