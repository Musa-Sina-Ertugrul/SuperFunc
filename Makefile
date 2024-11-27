
REQUIRED_LIBS = libhashmap.so
REQUIRED_HEADERS = hashmap.h
INCLUDE_DIR = include
SRC_DIR = src


all:super.o

super.o: headers shared_libs
	gcc -g -Wall -Wextra -c -fPIC $(SRC_DIR)/*.c -I$(INCLUDE_DIR) -o super.o
	gcc super.o -shared -o libsuper.so
	gcc -g -o main main.c -L. -lsuper -lhashmap -I$(INCLUDE_DIR) -Wl,-rpath=.

headers:
	cp -a ./HashMap/include/. ./include/

shared_libs:
	$(MAKE) -C ./HashMap/
	cp ./HashMap/*.so ./

clean:
	$(MAKE) -C ./HashMap/ clean
	rm -rf ./include/hash*.h
	rm -rf ./*.so
	rm -rf ./*.o
