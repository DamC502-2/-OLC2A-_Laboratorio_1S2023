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


// Take the name prefix into account.
#define yylex   yyNlex



#include "parser.hpp"


// Unqualified %code blocks.
#line 82 "parserN.y"

yyN::ParserN::symbol_type yylex(void* yyscanner, yyN::location& loc, class Compilador::Interfaz & intr);

#line 52 "parser.cpp"


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
#if YYNDEBUG

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

#else // !YYNDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYNDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yyN {
#line 144 "parser.cpp"

  /// Build a parser object.
  ParserN::ParserN (void *scanner_yyarg, yyN::location& loc_yyarg, class Compilador::Interfaz & intr_yyarg)
#if YYNDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      intr (intr_yyarg)
  {}

  ParserN::~ParserN ()
  {}

  ParserN::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  ParserN::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  ParserN::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  ParserN::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  ParserN::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  ParserN::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  ParserN::symbol_kind_type
  ParserN::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  ParserN::stack_symbol_type::stack_symbol_type ()
  {}

  ParserN::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< AbsExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lExprLlamada: // lExprLlamada
        value.YY_MOVE_OR_COPY< NT_LExprLLamada* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lParams: // lParams
        value.YY_MOVE_OR_COPY< NT_LParams* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lSentenciasG: // lSentenciasG
      case symbol_kind::S_lSentencias: // lSentencias
        value.YY_MOVE_OR_COPY< NT_LSentencias* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BYREF: // BYREF
      case symbol_kind::S_BYVAL: // BYVAL
      case symbol_kind::S_tipoFuncion: // tipoFuncion
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

  ParserN::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.move< AbsExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lExprLlamada: // lExprLlamada
        value.move< NT_LExprLLamada* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lParams: // lParams
        value.move< NT_LParams* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lSentenciasG: // lSentenciasG
      case symbol_kind::S_lSentencias: // lSentencias
        value.move< NT_LSentencias* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BYREF: // BYREF
      case symbol_kind::S_BYVAL: // BYVAL
      case symbol_kind::S_tipoFuncion: // tipoFuncion
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  ParserN::stack_symbol_type&
  ParserN::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.copy< AbsExpr* > (that.value);
        break;

      case symbol_kind::S_lExprLlamada: // lExprLlamada
        value.copy< NT_LExprLLamada* > (that.value);
        break;

      case symbol_kind::S_lParams: // lParams
        value.copy< NT_LParams* > (that.value);
        break;

      case symbol_kind::S_lSentenciasG: // lSentenciasG
      case symbol_kind::S_lSentencias: // lSentencias
        value.copy< NT_LSentencias* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BYREF: // BYREF
      case symbol_kind::S_BYVAL: // BYVAL
      case symbol_kind::S_tipoFuncion: // tipoFuncion
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  ParserN::stack_symbol_type&
  ParserN::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_s: // s
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        value.move< AbsExpr* > (that.value);
        break;

      case symbol_kind::S_lExprLlamada: // lExprLlamada
        value.move< NT_LExprLLamada* > (that.value);
        break;

      case symbol_kind::S_lParams: // lParams
        value.move< NT_LParams* > (that.value);
        break;

      case symbol_kind::S_lSentenciasG: // lSentenciasG
      case symbol_kind::S_lSentencias: // lSentencias
        value.move< NT_LSentencias* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BYREF: // BYREF
      case symbol_kind::S_BYVAL: // BYVAL
      case symbol_kind::S_tipoFuncion: // tipoFuncion
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
  ParserN::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYNDEBUG
  template <typename Base>
  void
  ParserN::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 449 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 455 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 461 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 467 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 473 "parser.cpp"
        break;

      case symbol_kind::S_BYREF: // BYREF
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 479 "parser.cpp"
        break;

      case symbol_kind::S_BYVAL: // BYVAL
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 485 "parser.cpp"
        break;

      case symbol_kind::S_s: // s
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 491 "parser.cpp"
        break;

      case symbol_kind::S_lSentenciasG: // lSentenciasG
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < NT_LSentencias* > (); }
#line 497 "parser.cpp"
        break;

      case symbol_kind::S_lSentencias: // lSentencias
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < NT_LSentencias* > (); }
#line 503 "parser.cpp"
        break;

      case symbol_kind::S_sentencia: // sentencia
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 509 "parser.cpp"
        break;

      case symbol_kind::S_funcion: // funcion
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 515 "parser.cpp"
        break;

      case symbol_kind::S_lParams: // lParams
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < NT_LParams* > (); }
#line 521 "parser.cpp"
        break;

      case symbol_kind::S_tipoFuncion: // tipoFuncion
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 527 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_var: // declaracion_var
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 533 "parser.cpp"
        break;

      case symbol_kind::S_asignacion: // asignacion
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 539 "parser.cpp"
        break;

      case symbol_kind::S_if: // if
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 545 "parser.cpp"
        break;

      case symbol_kind::S_else: // else
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 551 "parser.cpp"
        break;

      case symbol_kind::S_while: // while
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 557 "parser.cpp"
        break;

      case symbol_kind::S_cond: // cond
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 563 "parser.cpp"
        break;

      case symbol_kind::S_operel: // operel
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 569 "parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < AbsExpr* > (); }
#line 575 "parser.cpp"
        break;

      case symbol_kind::S_lExprLlamada: // lExprLlamada
#line 152 "parserN.y"
                 { yyoutput << yysym.value.template as < NT_LExprLLamada* > (); }
#line 581 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  ParserN::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  ParserN::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  ParserN::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYNDEBUG
  std::ostream&
  ParserN::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  ParserN::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  ParserN::debug_level_type
  ParserN::debug_level () const
  {
    return yydebug_;
  }

  void
  ParserN::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYNDEBUG

  ParserN::state_type
  ParserN::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  ParserN::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  ParserN::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  ParserN::operator() ()
  {
    return parse ();
  }

  int
  ParserN::parse ()
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
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_funcion: // funcion
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion: // asignacion
      case symbol_kind::S_if: // if
      case symbol_kind::S_else: // else
      case symbol_kind::S_while: // while
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_operel: // operel
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< AbsExpr* > ();
        break;

      case symbol_kind::S_lExprLlamada: // lExprLlamada
        yylhs.value.emplace< NT_LExprLLamada* > ();
        break;

      case symbol_kind::S_lParams: // lParams
        yylhs.value.emplace< NT_LParams* > ();
        break;

      case symbol_kind::S_lSentenciasG: // lSentenciasG
      case symbol_kind::S_lSentencias: // lSentencias
        yylhs.value.emplace< NT_LSentencias* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_BYREF: // BYREF
      case symbol_kind::S_BYVAL: // BYVAL
      case symbol_kind::S_tipoFuncion: // tipoFuncion
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
#line 160 "parserN.y"
        { //se añade la raiz a la interfaz
        intr.raiz = new NT_S(yystack_[0].value.as < AbsExpr* > ());                 
        yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > ();
      
 }
#line 876 "parser.cpp"
    break;

  case 3: // s: lSentenciasG
#line 165 "parserN.y"
                { //se añade la raiz a la interfaz
    intr.raiz = new NT_S(yystack_[0].value.as < NT_LSentencias* > ()); 
    yylhs.value.as < AbsExpr* > () = nullptr; }
#line 884 "parser.cpp"
    break;

  case 4: // lSentenciasG: lSentenciasG funcion
#line 170 "parserN.y"
                                   { yystack_[1].value.as < NT_LSentencias* > ()->addNodo(yystack_[0].value.as < AbsExpr* > ());
                                    yylhs.value.as < NT_LSentencias* > () = yystack_[1].value.as < NT_LSentencias* > (); }
#line 891 "parser.cpp"
    break;

  case 5: // lSentenciasG: funcion
#line 172 "parserN.y"
              { auto lSentencias = new NT_LSentencias();
                    lSentencias->addNodo(yystack_[0].value.as < AbsExpr* > ());
                    yylhs.value.as < NT_LSentencias* > () = lSentencias;
               }
#line 900 "parser.cpp"
    break;

  case 6: // lSentencias: lSentencias sentencia
#line 178 "parserN.y"
                                   { yystack_[1].value.as < NT_LSentencias* > ()->addNodo(yystack_[0].value.as < AbsExpr* > ());
                                    yylhs.value.as < NT_LSentencias* > () = yystack_[1].value.as < NT_LSentencias* > (); }
#line 907 "parser.cpp"
    break;

  case 7: // lSentencias: sentencia
#line 180 "parserN.y"
                { auto lSentencias = new NT_LSentencias();
                    lSentencias->addNodo(yystack_[0].value.as < AbsExpr* > ());
                    yylhs.value.as < NT_LSentencias* > () = lSentencias;
                    }
#line 916 "parser.cpp"
    break;

  case 8: // sentencia: if
#line 186 "parserN.y"
              {  yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > (); }
#line 922 "parser.cpp"
    break;

  case 9: // sentencia: while
#line 187 "parserN.y"
            { yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > (); }
#line 928 "parser.cpp"
    break;

  case 10: // sentencia: BREAK
#line 188 "parserN.y"
            { // sentenica break
        // TODO: verificar la existencia de la etiqueta
        yylhs.value.as < AbsExpr* > () = new NT_Continue();
    }
#line 937 "parser.cpp"
    break;

  case 11: // sentencia: CONTINUE
#line 192 "parserN.y"
               { // sentencia continue 
        // TODO: verificar la existencia de la etiqueta
        yylhs.value.as < AbsExpr* > () = new NT_Break();
        
    }
#line 947 "parser.cpp"
    break;

  case 12: // sentencia: asignacion ';'
#line 197 "parserN.y"
                     { yylhs.value.as < AbsExpr* > () = yystack_[1].value.as < AbsExpr* > (); }
#line 953 "parser.cpp"
    break;

  case 13: // sentencia: declaracion_var ';'
#line 198 "parserN.y"
                          { yylhs.value.as < AbsExpr* > () = yystack_[1].value.as < AbsExpr* > ();}
#line 959 "parser.cpp"
    break;

  case 14: // sentencia: RETURN ';'
#line 199 "parserN.y"
                  { new NT_Return(nullptr); }
#line 965 "parser.cpp"
    break;

  case 15: // sentencia: RETURN expr ';'
#line 200 "parserN.y"
                       { yylhs.value.as < AbsExpr* > () = new NT_Return(yystack_[1].value.as < AbsExpr* > ()); }
#line 971 "parser.cpp"
    break;

  case 16: // sentencia: ID '(' lExprLlamada ')' ';'
#line 201 "parserN.y"
                                  { yylhs.value.as < AbsExpr* > () = new  NT_LLamada(yystack_[4].value.as < std::string > (), yystack_[2].value.as < NT_LExprLLamada* > ()); }
#line 977 "parser.cpp"
    break;

  case 17: // sentencia: ID '(' ')' ';'
#line 202 "parserN.y"
                      {yylhs.value.as < AbsExpr* > () =  new NT_LLamada(yystack_[3].value.as < std::string > (), nullptr); }
#line 983 "parser.cpp"
    break;

  case 18: // funcion: FUNCTION ID '(' lParams ')' tipoFuncion '{' lSentencias '}'
#line 205 "parserN.y"
                                                                       {
    // NT_Funcion( id, tipo_retorno, parametros, sentencias )
    yylhs.value.as < AbsExpr* > () = new NT_Funcion( yystack_[7].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[5].value.as < NT_LParams* > (), yystack_[1].value.as < NT_LSentencias* > () );
}
#line 992 "parser.cpp"
    break;

  case 19: // funcion: FUNCTION ID '(' ')' tipoFuncion '{' lSentencias '}'
#line 209 "parserN.y"
                                                       {
    yylhs.value.as < AbsExpr* > () = new NT_Funcion( yystack_[6].value.as < std::string > (), yystack_[3].value.as < std::string > (), nullptr , yystack_[1].value.as < NT_LSentencias* > () );
}
#line 1000 "parser.cpp"
    break;

  case 20: // lParams: lParams ',' BYVAL ID AS INT
#line 214 "parserN.y"
                                     { yystack_[5].value.as < NT_LParams* > ()->addParam(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), yystack_[3].value.as < std::string > ());
                                        yylhs.value.as < NT_LParams* > () = yystack_[5].value.as < NT_LParams* > ();  }
#line 1007 "parser.cpp"
    break;

  case 21: // lParams: lParams ',' BYREF ID AS INT
#line 216 "parserN.y"
                                  { yystack_[5].value.as < NT_LParams* > ()->addParam(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), yystack_[3].value.as < std::string > ());
                                    yylhs.value.as < NT_LParams* > () = yystack_[5].value.as < NT_LParams* > ();  }
#line 1014 "parser.cpp"
    break;

  case 22: // lParams: BYREF ID AS INT
#line 218 "parserN.y"
                      { auto params = new NT_LParams();
                        params->addParam(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), yystack_[3].value.as < std::string > ());
                        yylhs.value.as < NT_LParams* > () = params;
                        }
#line 1023 "parser.cpp"
    break;

  case 23: // lParams: BYVAL ID AS INT
#line 222 "parserN.y"
                      { auto params = new NT_LParams();
                        params->addParam(yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > (), yystack_[3].value.as < std::string > ());
                        yylhs.value.as < NT_LParams* > () = params;
                        }
#line 1032 "parser.cpp"
    break;

  case 24: // tipoFuncion: AS INT
#line 228 "parserN.y"
                     { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();  }
#line 1038 "parser.cpp"
    break;

  case 25: // tipoFuncion: AS VOID
#line 229 "parserN.y"
              { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1044 "parser.cpp"
    break;

  case 26: // declaracion_var: DIM ID AS INT
#line 232 "parserN.y"
                               {
    yylhs.value.as < AbsExpr* > () = new NT_Decla( yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > () ); 
}
#line 1052 "parser.cpp"
    break;

  case 27: // asignacion: ID '=' expr
#line 237 "parserN.y"
                        {
    yylhs.value.as < AbsExpr* > () = new NT_Asig(yystack_[2].value.as < std::string > (), yystack_[0].value.as < AbsExpr* > ());
}
#line 1060 "parser.cpp"
    break;

  case 28: // if: IF '(' cond ')' '{' lSentencias '}' else
#line 244 "parserN.y"
                                             {
    yylhs.value.as < AbsExpr* > () = new NT_If(yystack_[5].value.as < AbsExpr* > (), yystack_[2].value.as < NT_LSentencias* > (), yystack_[0].value.as < AbsExpr* > ());
    }
#line 1068 "parser.cpp"
    break;

  case 29: // else: ELSE '{' lSentencias '}' else
#line 249 "parserN.y"
                                    { yylhs.value.as < AbsExpr* > () = new NT_else(yystack_[2].value.as < NT_LSentencias* > (), yystack_[0].value.as < AbsExpr* > ()); }
#line 1074 "parser.cpp"
    break;

  case 30: // else: ELSE if
#line 250 "parserN.y"
              {  yylhs.value.as < AbsExpr* > () = new NT_else(yystack_[0].value.as < AbsExpr* > ());  }
#line 1080 "parser.cpp"
    break;

  case 31: // else: %empty
#line 251 "parserN.y"
             {  yylhs.value.as < AbsExpr* > () = nullptr; }
#line 1086 "parser.cpp"
    break;

  case 32: // while: WHILE '(' cond ')' '{' lSentencias '}'
#line 254 "parserN.y"
                                              { 
    yylhs.value.as < AbsExpr* > () = new NT_While( yystack_[4].value.as < AbsExpr* > (), yystack_[1].value.as < NT_LSentencias* > ());
 }
#line 1094 "parser.cpp"
    break;

  case 33: // cond: cond OR cond
#line 259 "parserN.y"
                  {     
    yylhs.value.as < AbsExpr* > () = new NT_Or(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > ());
  }
#line 1102 "parser.cpp"
    break;

  case 34: // cond: cond AND cond
#line 262 "parserN.y"
                 {
    yylhs.value.as < AbsExpr* > () = new NT_And(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > ());    
 }
#line 1110 "parser.cpp"
    break;

  case 35: // cond: operel
#line 265 "parserN.y"
         { yylhs.value.as < AbsExpr* > () = yystack_[0].value.as < AbsExpr* > (); }
#line 1116 "parser.cpp"
    break;

  case 36: // operel: expr EQ expr
#line 269 "parserN.y"
                     {
    yylhs.value.as < AbsExpr* > () = new NT_Operel(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > (), QString("=="));

 }
#line 1125 "parser.cpp"
    break;

  case 37: // operel: expr '<' expr
#line 273 "parserN.y"
               { 
    yylhs.value.as < AbsExpr* > () = new NT_Operel(yystack_[2].value.as < AbsExpr* > (), yystack_[0].value.as < AbsExpr* > (), QString("<"));
    
 }
#line 1134 "parser.cpp"
    break;

  case 38: // expr: expr SUMA expr
#line 279 "parserN.y"
                     {
    yylhs.value.as < AbsExpr* > () = new NT_Sum(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());
 }
#line 1142 "parser.cpp"
    break;

  case 39: // expr: expr MENOS expr
#line 282 "parserN.y"
                      { 
        yylhs.value.as < AbsExpr* > () = new NT_Resta(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());
    }
#line 1150 "parser.cpp"
    break;

  case 40: // expr: expr '*' expr
#line 285 "parserN.y"
                    {
        yylhs.value.as < AbsExpr* > () = new NT_Multi(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());

     }
#line 1159 "parser.cpp"
    break;

  case 41: // expr: expr '/' expr
#line 289 "parserN.y"
                    {
        yylhs.value.as < AbsExpr* > () = new NT_Div(yystack_[2].value.as < AbsExpr* > (),yystack_[0].value.as < AbsExpr* > ());
     }
#line 1167 "parser.cpp"
    break;

  case 42: // expr: NUMERO
#line 292 "parserN.y"
             {
        yylhs.value.as < AbsExpr* > () = new T_Num_e(QString::fromStdString(yystack_[0].value.as < std::string > ()));
    }
#line 1175 "parser.cpp"
    break;

  case 43: // expr: ID
#line 295 "parserN.y"
         { 
        yylhs.value.as < AbsExpr* > () = new T_ID_e(QString::fromStdString(yystack_[0].value.as < std::string > ()));
    }
#line 1183 "parser.cpp"
    break;

  case 44: // expr: '(' expr ')'
#line 298 "parserN.y"
                   {
        yylhs.value.as < AbsExpr* > () = yystack_[1].value.as < AbsExpr* > ();     
    }
#line 1191 "parser.cpp"
    break;

  case 45: // expr: ID '(' ')'
#line 301 "parserN.y"
                   {
        yylhs.value.as < AbsExpr* > () = new NT_LLamada( yystack_[2].value.as < std::string > (), nullptr ); 
     }
#line 1199 "parser.cpp"
    break;

  case 46: // expr: ID '(' lExprLlamada ')'
#line 304 "parserN.y"
                               {
        yylhs.value.as < AbsExpr* > () = new NT_LLamada( yystack_[3].value.as < std::string > (), yystack_[1].value.as < NT_LExprLLamada* > () ); 
     }
#line 1207 "parser.cpp"
    break;

  case 47: // lExprLlamada: lExprLlamada ',' expr
#line 309 "parserN.y"
                                    { yystack_[2].value.as < NT_LExprLLamada* > ()->addExpr(yystack_[0].value.as < AbsExpr* > ());
                                        yylhs.value.as < NT_LExprLLamada* > () = yystack_[2].value.as < NT_LExprLLamada* > (); }
#line 1214 "parser.cpp"
    break;

  case 48: // lExprLlamada: expr
#line 311 "parserN.y"
            { yylhs.value.as < NT_LExprLLamada* > () = new NT_LExprLLamada(); 
                yylhs.value.as < NT_LExprLLamada* > ()->addExpr(yystack_[0].value.as < AbsExpr* > ()); }
#line 1221 "parser.cpp"
    break;


#line 1225 "parser.cpp"

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
  ParserN::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  ParserN::yytnamerr_ (const char *yystr)
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
  ParserN::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // ParserN::context.
  ParserN::context::context (const ParserN& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  ParserN::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
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
  ParserN::yy_syntax_error_arguments_ (const context& yyctx,
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
  ParserN::yysyntax_error_ (const context& yyctx) const
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


  const signed char ParserN::yypact_ninf_ = -70;

  const signed char ParserN::yytable_ninf_ = -1;

  const short
  ParserN::yypact_[] =
  {
       7,   -70,    -7,    39,    25,    44,    10,   -70,     5,   -70,
     132,    97,   120,    50,   -70,   -70,    39,    39,    39,    39,
      39,    39,    39,    39,   -70,   134,    -5,   -70,    24,    51,
     -70,   108,   108,   134,   134,   -70,   -70,   -70,    39,    40,
      68,    75,     4,   134,    59,    62,    79,    81,    40,    90,
     -70,   -70,    26,    55,    64,    96,   124,   125,   -11,   140,
     141,   -70,   -70,   154,   117,     2,   -70,   123,   137,   -70,
     -70,   -70,   -70,    26,   131,   133,   115,    39,    39,    39,
     136,   -70,   138,   -70,   -70,   -70,   -70,    45,   128,   130,
     152,    17,   134,    77,   146,   135,   -70,   -70,   -70,   -70,
     -70,   153,   149,   150,   -70,   -70,    26,    26,    58,    73,
     147,   -70,    83,   -70,    26,   -70,    86,   147,   -70
  };

  const signed char
  ParserN::yydefact_[] =
  {
       0,    42,    43,     0,     0,     0,     3,     5,     2,    35,
       0,     0,     0,     0,     1,     4,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    48,     0,    44,     0,    33,
      34,    38,    39,    36,    37,    40,    41,    46,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,     0,     0,     7,     0,     0,     8,
       9,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,    14,     0,    19,     6,    13,    12,     0,     0,     0,
       0,     0,    27,     0,     0,     0,    15,    18,    21,    20,
      17,     0,     0,     0,    26,    16,     0,     0,     0,     0,
      31,    32,     0,    28,     0,    30,     0,    31,    29
  };

  const short
  ParserN::yypgoto_[] =
  {
     -70,   -70,   -70,   -69,   -62,   165,   -70,   126,   -70,   -70,
      60,    56,   -70,   -15,   -70,    -3,    99
  };

  const signed char
  ParserN::yydefgoto_[] =
  {
       0,     5,     6,    65,    66,     7,    42,    45,    67,    68,
      69,   113,    70,     8,     9,    10,    26
  };

  const signed char
  ParserN::yytable_[] =
  {
      12,    29,    30,    84,    87,    76,    58,    77,    25,    11,
       1,     2,    37,    16,    17,    31,    32,    33,    34,    35,
      36,    48,    83,     3,    59,    84,    60,    61,    62,    13,
      58,    38,    63,    64,   101,    43,     4,   108,   109,     4,
      49,    39,     1,     2,    14,   116,    84,    84,    59,    58,
      60,    61,    62,    38,    84,     3,    63,    64,    40,    41,
      17,    82,    58,    93,    94,    97,    28,    59,    44,    60,
      61,    62,    46,    25,    92,    63,    64,    58,   110,    47,
      59,    52,    60,    61,    62,    16,    17,    71,    63,    64,
      58,    50,    51,   111,   102,    59,    72,    60,    61,    62,
       1,     2,   114,    63,    64,    59,   117,    53,    59,    54,
      60,    61,    62,     3,    24,    73,    63,    64,     1,     2,
       1,     2,    22,    23,    56,    57,    18,    19,    74,    75,
      81,     3,    90,     3,    22,    23,    85,    27,    18,    19,
      18,    19,    20,    21,    18,    19,    22,    23,    22,    23,
      86,    96,    22,    23,    16,    17,    78,    79,    80,    88,
      98,    89,    99,   103,    95,   100,   105,   104,   106,   107,
     112,    15,   115,   118,    55,    91
  };

  const signed char
  ParserN::yycheck_[] =
  {
       3,    16,    17,    65,    73,    16,     4,    18,    11,    16,
       3,     4,    17,     8,     9,    18,    19,    20,    21,    22,
      23,    17,    20,    16,    22,    87,    24,    25,    26,     4,
       4,    36,    30,    31,    17,    38,    29,   106,   107,    29,
      36,    17,     3,     4,     0,   114,   108,   109,    22,     4,
      24,    25,    26,    36,   116,    16,    30,    31,    34,    35,
       9,    64,     4,    78,    79,    20,    16,    22,    28,    24,
      25,    26,     4,    76,    77,    30,    31,     4,    20,     4,
      22,    19,    24,    25,    26,     8,     9,    32,    30,    31,
       4,    32,    33,    20,    17,    22,    32,    24,    25,    26,
       3,     4,    19,    30,    31,    22,    20,    28,    22,    28,
      24,    25,    26,    16,    17,    19,    30,    31,     3,     4,
       3,     4,    14,    15,    34,    35,     6,     7,     4,     4,
      13,    16,    17,    16,    14,    15,    13,    17,     6,     7,
       6,     7,    10,    11,     6,     7,    14,    15,    14,    15,
      13,    13,    14,    15,     8,     9,    16,    16,     4,    28,
      32,    28,    32,    17,    28,    13,    13,    32,    19,    19,
      23,     6,   112,   117,    48,    76
  };

  const signed char
  ParserN::yystos_[] =
  {
       0,     3,     4,    16,    29,    38,    39,    42,    50,    51,
      52,    16,    52,     4,     0,    42,     8,     9,     6,     7,
      10,    11,    14,    15,    17,    52,    53,    17,    16,    50,
      50,    52,    52,    52,    52,    52,    52,    17,    36,    17,
      34,    35,    43,    52,    28,    44,     4,     4,    17,    36,
      32,    33,    19,    28,    28,    44,    34,    35,     4,    22,
      24,    25,    26,    30,    31,    40,    41,    45,    46,    47,
      49,    32,    32,    19,     4,     4,    16,    18,    16,    16,
       4,    13,    52,    20,    41,    13,    13,    40,    28,    28,
      17,    53,    52,    50,    50,    28,    13,    20,    32,    32,
      13,    17,    17,    17,    32,    13,    19,    19,    40,    40,
      20,    20,    23,    48,    19,    47,    40,    20,    48
  };

  const signed char
  ParserN::yyr1_[] =
  {
       0,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    42,    42,
      43,    43,    43,    43,    44,    44,    45,    46,    47,    48,
      48,    48,    49,    50,    50,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    53,    53
  };

  const signed char
  ParserN::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     2,     2,     2,     3,     5,     4,     9,     8,
       6,     6,     4,     4,     2,     2,     4,     3,     8,     5,
       2,     0,     7,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     4,     3,     1
  };


#if YYNDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const ParserN::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "SUMA",
  "MENOS", "OR", "AND", "EQ", "'<'", "'>'", "';'", "'*'", "'/'", "'('",
  "')'", "'='", "'{'", "'}'", "NEG", "IF", "ELSE", "WHILE", "BREAK",
  "CONTINUE", "PRINT", "AS", "FUNCTION", "DIM", "RETURN", "INT", "VOID",
  "BYREF", "BYVAL", "','", "$accept", "s", "lSentenciasG", "lSentencias",
  "sentencia", "funcion", "lParams", "tipoFuncion", "declaracion_var",
  "asignacion", "if", "else", "while", "cond", "operel", "expr",
  "lExprLlamada", YY_NULLPTR
  };
#endif


#if YYNDEBUG
  const short
  ParserN::yyrline_[] =
  {
       0,   160,   160,   165,   170,   172,   178,   180,   186,   187,
     188,   192,   197,   198,   199,   200,   201,   202,   205,   209,
     214,   216,   218,   222,   228,   229,   232,   237,   244,   249,
     250,   251,   254,   259,   262,   265,   269,   273,   279,   282,
     285,   289,   292,   295,   298,   301,   304,   309,   311
  };

  void
  ParserN::yy_stack_print_ () const
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
  ParserN::yy_reduce_print_ (int yyrule) const
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
#endif // YYNDEBUG


} // yyN
#line 1771 "parser.cpp"

#line 314 "parserN.y"

void yyN::ParserN::error(const yyN::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

/*
nodos 
if 
*/
