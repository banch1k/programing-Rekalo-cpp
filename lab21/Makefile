CXX = clang++
CXX_OPTS = -I./src -std=c++14 -g -O0 -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla

LAB_OPTS = -I./src
LIB_DIRS = -L/usr/local/lib

clean:
	rm -rf dist

prep:
	mkdir -p dist

compile: prep main.bin test.bin

main.bin: src/main.cpp
	$(CXX) $(CXX_OPTS) src/main.cpp -o ./dist/main.bin

test.bin: test/test.cpp
	$(CXX) $(CXX_OPTS) $(LIB_DIRS) $(LIBS) test/test.cpp -o ./dist/test.bin

test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

run:
	./dist/main.bin

run_test:
	./dist/test.bin

check:
	clang-format --verbose -dry-run --Werror src/*.c
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

doxy:
	doxygen Doxyfile
