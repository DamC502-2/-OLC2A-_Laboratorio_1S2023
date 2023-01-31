/*comando   bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)
    para las definiciones de tokens
*/
%defines

/* indica el namespace que contiene al parser */
// %name-prefix="yy" ó 
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */

%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
%define parse.error verbose

%code requires 
{
    /* código  que se inserta al inicioo por lo regular son cabeceras*/
    #include<iostream> 
    #include<string> 
    #include "parserctx.hpp"

    /*
    Se pueden definir estructuras y tipos para los no terminales
    */

}
/* enlace con la función del retorno de simbolos */
%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx);
}


%token END 0;  //token de salida

/// %token<tipo> nombre+  
//cuidado con el orden
// %token <std::string> ID NUMERO
%token <std::string>  NUMERO ID
// token de tipo por defecto
    //token por ID
%token SUMA MENOS
    //token por texto
%token ';' '*' '/'

/*
forma alterna 
%token SUMA '+'
%token ID 'un_id'
*/
// precedencia

%left SUMA MENOS
%left '*' '/'

/* fin de la definción de tipos*/

/* La clase que envuele al parser se pasa por referencia 
del parser al escaner evitando crear variables globales

*/

%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* es posible hacer tipos personalizados para definir no terminales añadiendo lo siguiente
%union {
    std::string  cadenas;
}
*/

/*definicion de no terminales*/

%type<double> e;
%type<std::string>  s;

// printer
%printer { yyoutput << $$; } <*>;

/*
inicio de la grámatica
*/
%%
/* produccion inicial */

%start s;

s : e z {
    ctx.Salida = std::to_string($1);
    $$ = std::to_string($1);
    }
; 

e : e SUMA e {
    $$ = $1 + $3;
    }
 | e MENOS e {
    $$ = $1 - $3;
    } 
 | e '*' e {
    $$ = $1 * $3;
    } 
 | e '/' e {
    $$ = $1 / $3;
    } 
 | NUMERO {  $$ = std::stod($1); }
 ;
z : ';' 
    | %empty { /* epsilum */ }
    ;

%%
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

