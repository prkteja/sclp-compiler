#PARSE= left-recursion-removed
PARSE= parse
SCAN = program

sclp: lex.yy.o y.tab.o
	#g++ -o $(PARSE) lex.yy.o y.tab.o -ly -ll
	g++ --std=c++11 main.cc user-options.cc ast.cc symbol-table.cc tac.cc -o sclp -lfl -ly

y.tab.o y.tab.h: $(PARSE).y
	yacc -dv $(PARSE).y
	g++ --std=c++11 -c y.tab.c ast.h ast.cc symbol-table.h symbol-table.cc tac.cc tac.h

lex.yy.o : $(SCAN).l y.tab.h
	lex $(SCAN).l
	 g++ --std=c++11 -c lex.yy.c ast.h symbol-table.h ast.cc symbol-table.cc tac.cc tac.h

clean:
	rm -f lex.yy.* y.tab.* y.output sclp a.out $(PARSE)


