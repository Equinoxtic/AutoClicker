build_autoclicker:
	mkdir -p build/
	clang src/main.cpp -include src/custom_io.hpp -include src/ui_option.hpp -o build/main.exe
