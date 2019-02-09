all:

cmake:
	@mkdir -p build
	@(cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=YES ..)

%:
	make -C build $@
