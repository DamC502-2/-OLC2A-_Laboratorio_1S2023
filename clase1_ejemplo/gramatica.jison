%{
    // se ejecuta al principio
    // se hacen importaciones

%}
// modo lexico - scanner
%lex

%options case-insensitive

%% 

//tokens 

//se ignoran
[\r\t]+     //blancos o vacíos
\s+         //espacio blanco

//abecedario

"("     return 'PAR_ABRE';
")"     return 'PAR_CIERRA';
"a"     return 'A';

<<EOF>> return 'EOF';
.  { console.log( yylloc.first_line, 
yylloc.first_column, "Caracter no reconocido: ", yytext )};

/lex

%start S

%%

/*
S -> L 
L -> ( L )
| a
BNF ( ( ( a ) ) ) 
*/

S : L EOF { console.log($1); }
    ;
// $$ : $1 $2 $3 
L : PAR_ABRE L PAR_CIERRA { $$ = $2 + 1;}
    | A { $$ = 0; }
    ; 





