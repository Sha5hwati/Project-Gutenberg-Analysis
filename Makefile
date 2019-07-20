SOURCE = main.cpp \
         bookInfo.cpp \
         bookInfo_Tree.cpp \
         bookInfo_Trie.cpp \
         helper.cpp \

OBJS = $(SOURCE:.cpp=.o)

GCC = g++

CFLAGS = -Wall -O -std=c++11 

.PHONY: clean

all : main

main: $(OBJS)
	$(GCC) -o analysis $^ 

clean:
	rm -rf *.o *.d core analysis

tar: clean
	tar zcvf analysis.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core main"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

