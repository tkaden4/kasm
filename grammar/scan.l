%{
#include<iostream>
#include"kasm.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}
%%
[ \t\n] ;
%%
