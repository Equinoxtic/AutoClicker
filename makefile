build_autoclicker:
	mkdir -p build/
	clang src/main.cpp -include src/custom_io.hpp -include src/ui_option.hpp -include src/optionslist.hpp -o build/main.exe
