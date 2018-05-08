SOURCES=$(wildcard ./src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
CXXFLAGS=-Wall -Wextra -Werror -pipe -O2 -Wno-unused-variable \
	-Wno-unused-function -std=c++17 -I./include/
LDFLAGS=
NAME=kasm
EXE=build/$(NAME)
DISCARD=$(OBJECTS) $(EXE)
PARSE_OBJECTS=grammar/kasm.tab.o grammar/lex.yy.o

# check and see if we have ccache
HAS_CCACHE := $(shell command -v ccache 2> /dev/null)
ifdef HAS_CCACHE
	CXX := ccache $(CXX)
else
	CXX := $(CXX)
endif

.PHONY: clean tst run install 

$(shell mkdir build)

all: $(EXE)

$(PARSE_OBJECTS):
	make -C grammar

$(EXE) : $(PARSE_OBJECTS) $(OBJECTS) 
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

install:
	install -s $(EXE) /usr/local/bin/$(NAME)
	#cp $(NAME).1 /usr/local/man/man1/
	#man-db

run:
	./kasm test/test.kasm

clean:
	$(RM) $(DISCARD)
	make -C grammar clean
