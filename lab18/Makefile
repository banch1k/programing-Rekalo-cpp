# Компiлятор та опції для C
CXX = clang++
CXX_OPTS = -I./src -std=c++14 -g -O0 -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla

# Шляхи до бібліотек
LAB_OPTS = -I./src
LIB_DIRS = -L/usr/local/lib

# Ціль для очищення
clean:
	rm -rf dist

# Ціль для створення директорії
prep:
	mkdir -p dist

# Ціль для компіляції
compile: prep main.bin test.bin

# Компiляція основного виконуваного файлу
main.bin: src/main.cpp src/list.cpp src/entity.cpp
	$(CXX) $(CXX_OPTS) src/main.cpp src/list.cpp src/entity.cpp -o ./dist/main.bin

# Компiляція тестового виконуваного файлу
test.bin: test/test.cpp src/list.cpp src/entity.cpp
	$(CXX) $(CXX_OPTS) $(LIB_DIRS) $(LIBS) test/test.cpp src/list.cpp src/entity.cpp -o ./dist/test.bin

# Виконання тестів
test: clean prep compile
	LLVM_PROFILE_FILE="dist/test.profraw" ./dist/test.bin
	llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
	llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
	llvm-cov show dist/test.bin -instr-profile=dist/test.profdata src/*.c --format html > dist/coverage.html

# Запуск основної програми
run:
	./dist/main.bin

# Запуск тестової програми
run_test:
	./dist/test.bin

# Перевірка стилю коду та якості
check:
	clang-format --verbose -dry-run --Werror src/*.c
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

# Генерація документації
doxy:
	doxygen Doxyfile
