
REQUIRED_LIBS = libhashmap.so
REQUIRED_HEADERS = hashmap.h
INCLUDE_DIR = include
SRC_DIR = src


all:super.o

super.o: headers


headers:
	cp ./HashMap/include/* ./*


clean:
	cd ./HashMap/include/
	ls -a | grep . | rm -rf
