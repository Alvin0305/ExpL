%{
    int numChars = 0;
    int numWords = 0;
    int numLines = 0;    
%}

%%

\n      { numLines++; numWords++; }
" "     { numWords++; }
0       { return 0; }
.       { numChars++; }

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Number of lines: %d\n", numLines);
    printf("Number of Words: %d\n", numWords);
    printf("Number of Chars: %d\n", numChars);
    return 0;
}