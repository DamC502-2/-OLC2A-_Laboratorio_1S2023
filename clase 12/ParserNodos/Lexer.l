/* se convierte con: flex --verbose Lexer.l*/
/* opcciones para encapsulamiento */

/*%option reentrant noyywrap nounput batch noinput*/

%option reentrant noyywrap nounput batch noinput
%option debug
/* prefijo para tener scanner indendienes*/
%option prefix="yyN"
/*%option outfile="lex.yy.cpp"*/
/*%option outfile="lexer.cpp" */
/*%option header-file="lexer.hpp"*/
/*opction para numero de lineas*/
%{

    // definicion del tipo de funcion del retorno de simbolos
    // yy::ParserN ¿Por qué?
    // yy es el namespace de parser
    // ParserN es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yyN::ParserN::symbol_type yylex(yyscan_t yyscanner, yyN::location& loc, class Compilador::Interfaz & intr)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);

    // defincion de caracter EOF
    #define yyterminate() return ParserN::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"
    #include <iostream>


    using namespace yyN;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yyN::ParserN::token token;
    typedef yyN::ParserN::token_type token_type;
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

"+"     return ParserN::symbol_type( token::SUMA, loc );
"-"     return ParserN::symbol_type( token::MENOS, loc );

    /* operaciones lógicas*/
"or"    return ParserN::symbol_type( token::OR, loc );
"and"   return ParserN::symbol_type( token::AND, loc );
"if"    return ParserN::symbol_type( token::IF, loc );
"else"  return ParserN::symbol_type( token::ELSE, loc );

"while"     return ParserN::symbol_type( token::WHILE, loc );
"break"     return ParserN::symbol_type( token::BREAK, loc );
"continue"  return ParserN::symbol_type( token::CONTINUE, loc );



"Print"  return ParserN::symbol_type( token::PRINT, loc );
"Function"  return ParserN::symbol_type( token::FUNCTION, loc );
"return"  return ParserN::symbol_type( token::RETURN, loc );
"Dim" return ParserN::symbol_type(token::DIM, loc );
"As"  return ParserN::symbol_type(token::AS, loc );

"Void"  return ParserN::make_VOID(yytext, loc );
"Integer"  return ParserN::make_INT(yytext, loc );
"ByRef"  return ParserN::make_BYREF(yytext, loc );
"ByVal"  return ParserN::make_BYVAL(yytext, loc );

    /* operaciones relacionales */
"<"     return ParserN::symbol_type( token_type('<'), loc );
">"     return ParserN::symbol_type( token_type('>'), loc );
"=="    return ParserN::symbol_type(token::EQ, loc );

"*"     return ParserN::symbol_type( token_type('*'), loc );
"/"     return ParserN::symbol_type( token_type('/'), loc );
"("     return ParserN::symbol_type( token_type('('), loc );
")"     return ParserN::symbol_type( token_type(')'), loc );
"="     return ParserN::symbol_type( token_type('='), loc );

"{"     return ParserN::symbol_type( token_type('{'), loc );
"}"     return ParserN::symbol_type( token_type('}'), loc );

";"     return ParserN::symbol_type( token_type(';'), loc );
","     return ParserN::symbol_type( token_type(','), loc );



    /* TOKENS   if */
{ID}  return ParserN::make_ID(yytext, loc);
{NUMERO} return ParserN::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return ParserN::make_STRING (yytext, loc);

.  {std::cerr<<loc <<  ":"<< yytext <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return ParserN::make_END(loc);} */



%%


 // más código - normalmente para manejo de errores

