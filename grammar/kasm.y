%{
#include<cstdio>
#include<iostream>

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();

extern "C" void yyerror(const char *error)
{
    std::cout << error << std::endl;
    exit(-1);
}

extern "C" void yywrap(){}

extern "C" FILE *yyin;

%}
%token INT
%%
kasm:
    ;
%%
