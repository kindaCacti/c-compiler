all: build_main

build_main:
	cc ./src/main.c -o ./build/compiler -std=c99 -Wall -Werror

clean:
	rm -rf ./build/*