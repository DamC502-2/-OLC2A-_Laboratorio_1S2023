/* se convierte con: flex --verbose Lexer.l*/
/* opcciones para encapsulamiento */

/*%option reentrant noyywrap nounput batch noinput*/

%option reentrant noyywrap nounput batch noinput
%option debug
/*%option outfile="lex.yy.cpp"*/
/*%option outfile="lexer.cpp" */
/*%option header-file="lexer.hpp"*/
/*opction para numero de lineas*/
%{

    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class Clase6::Interfaz & intr)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);

    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"
    #include <iostream>


    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí

%}


/* ============== INICIO DE SCANNER ==========  */


/* expresiones regulares */

DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+
ID  {LETRAS}({DIGITO}|{LETRAS}|"_")*

%%

%{
// inicia la lectura
    loc.step();
%}

    /* inicia la defincion de tokens   */



    /* caracteres ignorados */

"//"[^\n]*\n            ; /* comentarios de una linea */
    /* forma alternativa en otro ejemplos: \n       { yylloc->lines(yyleng); yylloc->step(); }
 fuente: https://stackoverflow.com/questions/9488254/bison-rec2c-get-current-line-number */
\n   { loc.lines(yyleng); loc.step(); } ;
[ \t\v\r\f]             ; /* caracteres en blanco */
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */

"+"     return Parser::symbol_type( token::SUMA, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );

    /* operaciones lógicas*/
"or"    return Parser::symbol_type( token::OR, loc );
"and"   return Parser::symbol_type( token::AND, loc );
"if"    return Parser::symbol_type( token::IF, loc );
"else"  return Parser::symbol_type( token::ELSE, loc );

"while"     return Parser::symbol_type( token::WHILE, loc );
"break"     return Parser::symbol_type( token::BREAK, loc );
"continue"  return Parser::symbol_type( token::CONTINUE, loc );

    /* operaciones relacionales */
"<"     return Parser::symbol_type( token_type('<'), loc );
">"     return Parser::symbol_type( token_type('>'), loc );
"=="    return Parser::symbol_type(token::EQ, loc );

"*"     return Parser::symbol_type( token_type('*'), loc );
"/"     return Parser::symbol_type( token_type('/'), loc );
"("     return Parser::symbol_type( token_type('('), loc );
")"     return Parser::symbol_type( token_type(')'), loc );
"="     return Parser::symbol_type( token_type('='), loc );

"{"     return Parser::symbol_type( token_type('{'), loc );
"}"     return Parser::symbol_type( token_type('}'), loc );
    /* arrays */
"["     return Parser::symbol_type( token_type('['), loc );
"]"     return Parser::symbol_type( token_type(']'), loc );
".."     return Parser::symbol_type( token::DOT2, loc );
","     return Parser::symbol_type(  token_type(','), loc );
"array"     return Parser::symbol_type( token::ARRAY, loc );


    /* TOKENS   if */
{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);

.  {std::cerr<<loc <<  ":"<< yytext <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */



%%


 // más código - normalmente para manejo de errores

