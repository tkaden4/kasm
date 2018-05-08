SCANNER=scan.l
DISPOSE=$(wildcard *.o *.so *.a *.gch)
DISPOSE:=${DISPOSE} lex.yy.c kasm.tab.c kasm.tab.h

all: lex.yy.c kasm.tab.c
	g++ -fPIC -c $^ -lfl

kasm.tab.h kasm.tab.c:
	bison -d kasm.y

scan.o: lex.yy.c kasm.tab.h
	g++ -c $^ -lfl

lex.yy.c:
	flex ${SCANNER}

clean:
	rm ${DISPOSE}
