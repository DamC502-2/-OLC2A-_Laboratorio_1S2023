// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 56 "parser.y"

yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase6::Interfaz & intr);

#line 50 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class Clase6::Interfaz & intr_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      intr (intr_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lDims: // lDims
      case symbol_kind::S_lRef: // lRef
        value.YY_MOVE_OR_COPY< atributos* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lDims: // lDims
      case symbol_kind::S_lRef: // lRef
        value.move< atributos* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lDims: // lDims
      case symbol_kind::S_lRef: // lRef
        value.copy< atributos* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lDims: // lDims
      case symbol_kind::S_lRef: // lRef
        value.move< atributos* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 363 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 369 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 375 "parser.cpp"
        break;

      case symbol_kind::S_s: // s
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 381 "parser.cpp"
        break;

      case symbol_kind::S_markIF2: // markIF2
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 387 "parser.cpp"
        break;

      case symbol_kind::S_markWhile1: // markWhile1
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 393 "parser.cpp"
        break;

      case symbol_kind::S_cond: // cond
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 399 "parser.cpp"
        break;

      case symbol_kind::S_operel: // operel
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 405 "parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 411 "parser.cpp"
        break;

      case symbol_kind::S_lDims: // lDims
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 417 "parser.cpp"
        break;

      case symbol_kind::S_lRef: // lRef
#line 118 "parser.y"
                 { yyoutput << yysym.value.template as < atributos* > (); }
#line 423 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, loc, intr));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_markIF2: // markIF2
      case symbol_kind::S_markWhile1: // markWhile1
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_lDims: // lDims
      case symbol_kind::S_lRef: // lRef
        yylhs.value.emplace< atributos* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // s: cond
#line 124 "parser.y"
        {
        yylhs.value.as < atributos* > () = yystack_[0].value.as < atributos* > (); 
        intr.gen->imprimir(QString::fromStdString("// verdadero"));
        intr.gen->imprimir(yystack_[0].value.as < atributos* > ()->EV + ":");
        intr.gen->imprimir(QString::fromStdString("// falso"));
        intr.gen->imprimir(yystack_[0].value.as < atributos* > ()->EF + ":");
 }
#line 699 "parser.cpp"
    break;

  case 3: // s: lSentencias
#line 131 "parser.y"
               {}
#line 705 "parser.cpp"
    break;

  case 4: // lSentencias: lSentencias sentencia
#line 134 "parser.y"
                                   { }
#line 711 "parser.cpp"
    break;

  case 5: // lSentencias: sentencia
#line 135 "parser.y"
                {}
#line 717 "parser.cpp"
    break;

  case 6: // sentencia: if
#line 138 "parser.y"
              { }
#line 723 "parser.cpp"
    break;

  case 7: // sentencia: while
#line 139 "parser.y"
            { }
#line 729 "parser.cpp"
    break;

  case 8: // sentencia: BREAK
#line 140 "parser.y"
            { // sentenica break
        // TODO: verificar la existencia de la etiqueta
        intr.gen->imprimir( QString( "goto ")+ intr.gen->peekEtqF() + " //break");
    }
#line 738 "parser.cpp"
    break;

  case 9: // sentencia: CONTINUE
#line 144 "parser.y"
               { // sentencia continue 
        // TODO: verificar la existencia de la etiqueta
        intr.gen->imprimir( QString( "goto ")+ intr.gen->peekEtqInicio() + " //continue");
    }
#line 747 "parser.cpp"
    break;

  case 10: // sentencia: asignacion
#line 148 "parser.y"
                 { }
#line 753 "parser.cpp"
    break;

  case 11: // sentencia: declaracion
#line 149 "parser.y"
                 { }
#line 759 "parser.cpp"
    break;

  case 12: // if: IF '(' cond ')' markIF '{' lSentencias '}' markIF2 else
#line 152 "parser.y"
                                                              {
                                                //gen(LSalidaIF)
                                        intr.gen->imprimir(yystack_[1].value.as < atributos* > ()->LSalida + ":") ;}
#line 767 "parser.cpp"
    break;

  case 13: // markIF: %empty
#line 157 "parser.y"
               { 
        // codigo marcador        
        //gen (cond.EV)        
        intr.gen->imprimir(yystack_[(0) - (-1)].value.as< atributos* > ()->EV + ":");
}
#line 777 "parser.cpp"
    break;

  case 14: // markIF2: %empty
#line 163 "parser.y"
                {
    //gen(goto LSalidaIF)
    //gen(cond.EF)
    auto etqSalidaIF = intr.gen->newLabel();
    intr.gen->imprimir("goto " + etqSalidaIF);
    intr.gen->imprimir( yystack_[(0) - (-5)].value.as< atributos* > ()->EF + ":" );
    atributos* mark = new atributos();
    mark->LSalida = etqSalidaIF; 
    yylhs.value.as < atributos* > () = mark; 

}
#line 793 "parser.cpp"
    break;

  case 15: // else: ELSE '{' lSentencias '}' else
#line 175 "parser.y"
                                    {}
#line 799 "parser.cpp"
    break;

  case 16: // else: ELSE if
#line 176 "parser.y"
              {}
#line 805 "parser.cpp"
    break;

  case 17: // else: %empty
#line 177 "parser.y"
             {}
#line 811 "parser.cpp"
    break;

  case 18: // while: WHILE markWhile1 '(' cond ')' markWhile2 '{' lSentencias '}'
#line 180 "parser.y"
                                                                    { 
    intr.gen->imprimir(yystack_[5].value.as < atributos* > ()->EF+":");
    intr.gen->popDisplay(); // pop display
 }
#line 820 "parser.cpp"
    break;

  case 19: // markWhile1: %empty
#line 185 "parser.y"
                   {
    intr.gen->imprimir("// inicio while");
    atributos* etqInicio = new atributos();    
    etqInicio->LInicio = intr.gen->newLabel(); 
    intr.gen->imprimir(etqInicio->LInicio + ":");    
    yylhs.value.as < atributos* > () = etqInicio; 
}
#line 832 "parser.cpp"
    break;

  case 20: // markWhile2: %empty
#line 194 "parser.y"
                   {
    atributos* cond = yystack_[(0) - (-1)].value.as< atributos* > ();
    atributos* Linicio = yystack_[(0) - (-3)].value.as< atributos* > ();    
    intr.gen->imprimir(cond->EV +":");
    intr.gen->pushDisplay( cond->EV, cond->EF, Linicio->LInicio);
    }
#line 843 "parser.cpp"
    break;

  case 21: // cond: cond OR markOR cond
#line 202 "parser.y"
                         { 
    atributos* cond = new atributos();
    cond->EV = yystack_[3].value.as < atributos* > ()->EV + ":\n" + yystack_[0].value.as < atributos* > ()->EV;
    cond->EF = yystack_[0].value.as < atributos* > ()->EF ;
    yylhs.value.as < atributos* > () = cond; 
    std::cout<<std::endl << "location:!!"
    << yystack_[2].location.begin.column << " " << yystack_[2].location
    <<" linea: " <<yystack_[2].location.begin.line << std::endl;


  }
#line 859 "parser.cpp"
    break;

  case 22: // cond: cond AND markAND cond
#line 213 "parser.y"
                        {
    atributos* cond = new atributos();
    cond->EV = yystack_[0].value.as < atributos* > ()->EV ;
    cond->EF = yystack_[3].value.as < atributos* > ()->EF + ":\n" + yystack_[0].value.as < atributos* > ()->EF; 
    yylhs.value.as < atributos* > () = cond; 
 }
#line 870 "parser.cpp"
    break;

  case 23: // cond: operel
#line 219 "parser.y"
         { yylhs.value.as < atributos* > () = yystack_[0].value.as < atributos* > (); }
#line 876 "parser.cpp"
    break;

  case 24: // markOR: %empty
#line 222 "parser.y"
               {
    intr.gen->imprimir( yystack_[(0) - (-1)].value.as< atributos* > ()->EF + ":" );
}
#line 884 "parser.cpp"
    break;

  case 25: // markAND: %empty
#line 226 "parser.y"
                {
    intr.gen->imprimir(yystack_[(0) - (-1)].value.as< atributos* > ()->EV + ":");
}
#line 892 "parser.cpp"
    break;

  case 26: // operel: expr EQ expr
#line 231 "parser.y"
                     {
    atributos* expr = new atributos();
    expr->EV = intr.gen->newLabel(); 
    expr->EF = intr.gen->newLabel(); 
    intr.gen->imprimir( "if " + yystack_[2].value.as < atributos* > ()->dir + " == " + yystack_[0].value.as < atributos* > ()->dir + " goto " + expr->EV );
    intr.gen->imprimir("goto " + expr->EF);
    yylhs.value.as < atributos* > () = expr; 
 }
#line 905 "parser.cpp"
    break;

  case 27: // operel: expr '<' expr
#line 239 "parser.y"
               { 
    /* if expr1.dir < expr2.dir goto L#
        goto L#    
    */
    atributos* expr = new atributos();
    expr->EV = intr.gen->newLabel(); 
    expr->EF = intr.gen->newLabel(); 
    intr.gen->imprimir( "if " + yystack_[2].value.as < atributos* > ()->dir + " < " + yystack_[0].value.as < atributos* > ()->dir + " goto " + expr->EV );
    intr.gen->imprimir("goto " + expr->EF);
    yylhs.value.as < atributos* > () = expr; 
 }
#line 921 "parser.cpp"
    break;

  case 28: // expr: expr SUMA expr
#line 252 "parser.y"
                     {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " + " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;
 }
#line 934 "parser.cpp"
    break;

  case 29: // expr: expr MENOS expr
#line 260 "parser.y"
                      { 
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " - " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;
    }
#line 947 "parser.cpp"
    break;

  case 30: // expr: expr '*' expr
#line 268 "parser.y"
                    {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " * " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;

     }
#line 961 "parser.cpp"
    break;

  case 31: // expr: expr '/' expr
#line 277 "parser.y"
                    {
        atributos* expr = new atributos();
        QString temp = intr.gen->newTempB(yystack_[2].value.as < atributos* > ()->isTemp, yystack_[0].value.as < atributos* > ()->isTemp);
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " / " + yystack_[0].value.as < atributos* > ()->dir);
        expr->isTemp = true; 
        expr->dir = temp; 
        yylhs.value.as < atributos* > () = expr;        
     }
#line 974 "parser.cpp"
    break;

  case 32: // expr: NUMERO
#line 285 "parser.y"
             {
        atributos* expr = new atributos();
        expr->dir = QString::fromStdString(yystack_[0].value.as < std::string > ());        
        yylhs.value.as < atributos* > () = expr; 
    }
#line 984 "parser.cpp"
    break;

  case 33: // expr: ID
#line 290 "parser.y"
         { 
        atributos* expr = new atributos();
        expr->dir = QString::fromStdString(yystack_[0].value.as < std::string > ());
        yylhs.value.as < atributos* > () = expr; 
    }
#line 994 "parser.cpp"
    break;

  case 34: // expr: '(' expr ')'
#line 295 "parser.y"
                   {
        yylhs.value.as < atributos* > () = yystack_[1].value.as < atributos* > (); 
    }
#line 1002 "parser.cpp"
    break;

  case 35: // expr: lRef ']'
#line 298 "parser.y"
               {
        auto temp = intr.gen->newTemp(); 
        intr.gen->imprimir(temp + " = " + yystack_[1].value.as < atributos* > ()->aux + " + " + yystack_[1].value.as < atributos* > ()->dir);
        auto temp2 = intr.gen->newTemp(); 
        intr.gen->imprimir( temp2 + "  = " + yystack_[1].value.as < atributos* > ()->id + "[" + temp  +"]"); 
        yylhs.value.as < atributos* > () = new atributos(); 
        yylhs.value.as < atributos* > ()->dir = temp2; 
    }
#line 1015 "parser.cpp"
    break;

  case 36: // declaracion: lDims ']'
#line 308 "parser.y"
                       {

    }
#line 1023 "parser.cpp"
    break;

  case 37: // lDims: lDims ',' expr DOT2 expr
#line 313 "parser.y"
                                {
    // añader min max
    // array arreglo [ 1..y, 1..z, 1..x[x] ...... ]
    intr.gen->tSimbolos->addDim(yystack_[4].value.as < atributos* > ()->id, yystack_[2].value.as < atributos* > ()->dir, yystack_[0].value.as < atributos* > ()->dir);
    yylhs.value.as < atributos* > () = yystack_[4].value.as < atributos* > (); 
}
#line 1034 "parser.cpp"
    break;

  case 38: // lDims: ARRAY ID '[' expr DOT2 expr
#line 320 "parser.y"
                               {
        // esta parte ID -> 
        auto ldim = new atributos();
        ldim->id = QString::fromStdString(yystack_[4].value.as < std::string > ());
        intr.gen->tSimbolos->addSimbolo(ldim->id, 
        new Simbolo(ldim->id, yystack_[4].location.begin.line, yystack_[4].location.begin.column ) );
        intr.gen->tSimbolos->addDim(ldim->id, yystack_[2].value.as < atributos* > ()->dir, yystack_[0].value.as < atributos* > ()->dir  );
        yylhs.value.as < atributos* > () = ldim;
 }
#line 1048 "parser.cpp"
    break;

  case 39: // lRef: lRef ',' expr
#line 331 "parser.y"
                      {
        // ID [2,3,4,5,6,6]
        auto temp = intr.gen->newTemp(); 
        intr.gen->imprimir(temp + " = " + yystack_[2].value.as < atributos* > ()->dir + " - 1 "); 
        auto temp2 = intr.gen->newTemp();
        intr.gen->imprimir(temp2 + " = " + temp + 
                " * " + intr.gen->tSimbolos->getTamDimF(yystack_[2].value.as < atributos* > ()->id, yystack_[2].value.as < atributos* > ()->dim ));
        intr.gen->imprimir(yystack_[2].value.as < atributos* > ()->aux + " = " + yystack_[2].value.as < atributos* > ()->aux + " + "+ temp2);
        yylhs.value.as < atributos* > () = yystack_[2].value.as < atributos* > (); 
        yylhs.value.as < atributos* > ()->dir = yystack_[0].value.as < atributos* > ()->dir; 
        yylhs.value.as < atributos* > ()->dim++;
    }
#line 1065 "parser.cpp"
    break;

  case 40: // lRef: ID '[' expr
#line 343 "parser.y"
                  {
        auto lRef = new atributos();
        lRef->id = QString::fromStdString(yystack_[2].value.as < std::string > ());
        lRef->aux = intr.gen->newTemp();
        lRef->dir = yystack_[0].value.as < atributos* > ()->dir; 
        lRef->dim = 1; 
        intr.gen->imprimir(lRef->aux + QString(" = 0") );
        yylhs.value.as < atributos* > () = lRef;
    }
#line 1079 "parser.cpp"
    break;

  case 41: // asignacion: ID '=' expr
#line 353 "parser.y"
                        {
    intr.gen->imprimir(QString::fromStdString(yystack_[2].value.as < std::string > ()) + QString(" = ") + yystack_[0].value.as < atributos* > ()->dir);
}
#line 1087 "parser.cpp"
    break;

  case 42: // asignacion: lRef ']' '=' expr
#line 356 "parser.y"
                       {
        auto temp = intr.gen->newTemp(); 
        intr.gen->imprimir(temp + " = " + yystack_[3].value.as < atributos* > ()->aux + " + " + yystack_[3].value.as < atributos* > ()->dir);
        intr.gen->imprimir(yystack_[3].value.as < atributos* > ()->id + "[" + temp + "] = " + yystack_[0].value.as < atributos* > ()->dir );        
    }
#line 1097 "parser.cpp"
    break;


#line 1101 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -63;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      25,   -63,    -9,     2,   -12,   -63,   -63,   -63,     7,    14,
      18,   -63,   -63,   -63,    17,   -63,   118,   -63,    36,    72,
     -63,     2,     2,    23,   106,    92,     2,     5,    30,   -63,
      -9,   -63,    94,   -63,   -63,     2,     2,     2,     2,     2,
       2,   -63,     2,    21,     2,    50,    50,   -63,   -63,    88,
       2,     2,    21,     2,     2,    70,    70,    50,    50,   -63,
     -63,     1,     2,    50,   -63,   122,   104,    52,   -63,     2,
      50,     4,   -63,     2,    50,    18,    44,    50,    62,    18,
     -63,    73,    46,   -63,    43,   -63,    18,   -63,    79,    46,
     -63
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    32,    33,     0,     0,    19,     8,     9,     0,     0,
       3,     5,     6,     7,     2,    23,     0,    11,     0,     0,
      10,     0,     0,    33,     0,     0,     0,     0,     0,     1,
       0,     4,     0,    24,    25,     0,     0,     0,     0,     0,
       0,    36,     0,    35,     0,    41,    40,    34,    35,     0,
       0,     0,     0,     0,     0,    28,    29,    26,    27,    30,
      31,     0,     0,    39,    13,     0,     0,    21,    22,     0,
      42,     0,    20,     0,    37,     0,     0,    38,     0,     0,
      14,     0,    17,    18,     0,    12,     0,    16,     0,    17,
      15
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -63,   -63,   -62,    -8,   -15,   -63,   -63,   -13,   -63,   -63,
     -63,   -23,   -63,   -63,   -63,    -2,   -63,   -63,     0,   -63
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     9,    10,    11,    12,    71,    82,    85,    13,    27,
      76,    14,    53,    54,    15,    16,    17,    18,    25,    20
  };

  const signed char
  Parser::yytable_[] =
  {
      19,    24,    31,    49,    26,     1,    23,    35,    36,    21,
      32,    28,    22,    78,    29,    39,    40,    81,     3,    45,
      46,    50,    30,    75,    88,    33,    34,    65,     1,     2,
      67,    68,    69,    55,    56,    57,    58,    59,    60,    62,
      61,     3,    63,     4,    22,     5,     6,     7,     8,    66,
       4,    51,     5,     6,     7,     8,    35,    36,    41,    42,
      70,    34,    86,    79,    39,    40,    30,    74,     4,    87,
      31,    77,    84,    31,     0,    32,    90,    30,    32,    32,
      31,    32,    80,    30,    39,    40,    32,     4,    32,     5,
       6,     7,     8,    83,    43,    44,    33,    34,     4,    89,
       5,     6,     7,     8,     4,    64,     5,     6,     7,     8,
      35,    36,    35,    36,    48,    44,    52,    44,    39,    40,
      39,    40,     0,    47,    35,    36,     0,     0,    37,    38,
      33,    34,    39,    40,     0,    73,     0,     0,     0,    72
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     3,    10,    26,    16,     3,     4,     6,     7,    18,
      10,     4,    21,    75,     0,    14,    15,    79,    16,    21,
      22,    16,     4,    19,    86,     8,     9,    50,     3,     4,
      53,    54,    31,    35,    36,    37,    38,    39,    40,    18,
      42,    16,    44,    25,    21,    27,    28,    29,    30,    51,
      25,    21,    27,    28,    29,    30,     6,     7,    22,    23,
      62,     9,    19,    19,    14,    15,     4,    69,    25,    84,
      78,    73,    26,    81,    -1,    75,    89,     4,    78,    79,
      88,    81,    20,     4,    14,    15,    86,    25,    88,    27,
      28,    29,    30,    20,    22,    23,     8,     9,    25,    20,
      27,    28,    29,    30,    25,    17,    27,    28,    29,    30,
       6,     7,     6,     7,    22,    23,    22,    23,    14,    15,
      14,    15,    -1,    17,     6,     7,    -1,    -1,    10,    11,
       8,     9,    14,    15,    -1,    31,    -1,    -1,    -1,    17
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     4,    16,    25,    27,    28,    29,    30,    33,
      34,    35,    36,    40,    43,    46,    47,    48,    49,    50,
      51,    18,    21,     4,    47,    50,    16,    41,     4,     0,
       4,    35,    50,     8,     9,     6,     7,    10,    11,    14,
      15,    22,    23,    22,    23,    47,    47,    17,    22,    43,
      16,    21,    22,    44,    45,    47,    47,    47,    47,    47,
      47,    47,    18,    47,    17,    43,    47,    43,    43,    31,
      47,    37,    17,    31,    47,    19,    42,    47,    34,    19,
      20,    34,    38,    20,    26,    39,    19,    36,    34,    20,
      39
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    32,    33,    33,    34,    34,    35,    35,    35,    35,
      35,    35,    36,    37,    38,    39,    39,    39,    40,    41,
      42,    43,    43,    43,    44,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    49,    49,    50,
      50,    51,    51
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,    10,     0,     0,     5,     2,     0,     9,     0,
       0,     4,     4,     1,     0,     0,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     2,     2,     5,     6,     3,
       3,     3,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "SUMA",
  "MENOS", "OR", "AND", "EQ", "'<'", "'>'", "';'", "'*'", "'/'", "'('",
  "')'", "'='", "'{'", "'}'", "'['", "']'", "','", "NEG", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "ARRAY", "DOT2", "$accept", "s",
  "lSentencias", "sentencia", "if", "markIF", "markIF2", "else", "while",
  "markWhile1", "markWhile2", "cond", "markOR", "markAND", "operel",
  "expr", "declaracion", "lDims", "lRef", "asignacion", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   124,   124,   131,   134,   135,   138,   139,   140,   144,
     148,   149,   152,   157,   163,   175,   176,   177,   180,   185,
     194,   202,   213,   219,   222,   226,   231,   239,   252,   260,
     268,   277,   285,   290,   295,   298,   308,   313,   320,   331,
     343,   353,   356
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1632 "parser.cpp"

#line 362 "parser.y"

void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

/*
suma(a,b)  
    return a + b / suma( a * b , 2 /c );

    if (a * suma(a,b))


Lsentencias -> if 
    | while 
    | assignacion

asignacion: mark id = expr   

E -> E  + E
    E .... E  temp = new Temp () // acumulador.push(newTemp)
    ID ( listaParametros) {
//LLAMADA
    <CODIGO DE PARAMETROS>
    acumulador.save() // codigo para guardar temporales en stack
    P = p + 1
    stack[p] = t1
    P = p + 1
    stack[p] = t2
    P = p + 1
    stack[p] = t3
    id()
    actulador.restore()// codigo para sacaar todo de stack 
    tN = stack[p] //return
    }


mark: {acumulador.reset() // quitar todos los temporales }

suma(a, b ) {
mark int a = suma(a,b) / resta(c,d) 
}
t1 = P + 1
t2 = stack[t1] //a 
t3 = P + 1
t4 = stack[t3] //b // acumulador = t1,t2,t3,t4

P = p + 1
stack[p] = t2
p = p + 1
stack[p] = t4

//acumulador.save
p = p + 1
stack[p] = t1
p = p + 1
stack[p] = t2
p = p + 1
stack[p] = t3
p = p + 1
stack[p] = t4
suma()
//acumulador.restore

t5 = P //return
t5 = stack [t5]
stack[p] = t4
p = p - 1
stack[p] = t2
p = p - 1
stack[p] = t2
p = p - 1
stack[p] = t1
p = p - 1
*/

