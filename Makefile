
REQUIRED_LIBS = libhashmap.so
REQUIRED_HEADERS = hashmap.h
INCLUDE_DIR = include
SRC_DIR = src


all:super.o

super.o: headers shared_libs


headers:
	cp -a ./HashMap/include/. ./include/

shared_libs:
	$(MAKE) -C ./HashMap/
	cp ./HashMap/*.so ./

clean:
	rm -rf ./include/hash*
	rm -rf ./*.so
	rm -rf ./*.o
