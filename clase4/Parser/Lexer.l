/* se convierte con: flex --verbose Lexer.l*/
/* opcciones para encapsulamiento */

/*%option reentrant noyywrap nounput batch noinput*/
%option reentrant noyywrap nounput batch noinput
%option debug
/*%option outfile="lex.yy.cpp"*/
/*%option outfile="lexer.cpp" */
/*%option header-file="lexer.hpp"*/
%{

    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class Clase3::Interfaz & intr)
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

[ \t\v\r\n\f]             ; /* caracteres en blanco */
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */

"+"     return Parser::symbol_type( token::SUMA, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );
"Dim"   return Parser::symbol_type( token::DIM, loc);
"as"    return Parser::symbol_type( token::AS, loc);
"Imprimir"  return Parser::symbol_type( token::IMPR, loc);
"Integer"    return Parser::symbol_type( token::INT, loc);
"String"   return Parser::symbol_type( token::STR , loc);
"Float"   return Parser::symbol_type( token::FLO , loc);



    /* defincion clásica / para caracteres especiales */
";"     return Parser::symbol_type( token_type(';'), loc );
","     return Parser::symbol_type( token_type(','), loc );
"*"     return Parser::symbol_type( token_type('*'), loc );
"/"     return Parser::symbol_type( token_type('/'), loc );
"("     return Parser::symbol_type( token_type('('), loc );
")"     return Parser::symbol_type( token_type(')'), loc );
"="     return Parser::symbol_type( token_type('='), loc );
"{"     return Parser::symbol_type( token_type('{'), loc );
"}"     return Parser::symbol_type( token_type('}'), loc );



    /* TOKENS   if */
{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);

.  {std::cerr<<loc <<  ":"<< yytext <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */



%%


 // más código - normalmente para manejo de errores

