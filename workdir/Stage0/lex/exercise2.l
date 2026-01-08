%{
    #include <stdio.h>

    int numInts = 0;
    int numFloats = 0;
%}

digit           [0-9]
num             {digit}+
float_num       {num}\.{num}

%% 

{float_num}     { numFloats++; }
{num}           { numInts++; }
"\n"            { return 1; }
[ \t]           { }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();

    printf("Number of ints: %d\n", numInts);
    printf("Number of floats: %d\n", numFloats);
    return 0;
}