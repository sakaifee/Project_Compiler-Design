/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "lex.yy.c"
void yyerror(const char*);
int yylex();
int yywrap();
void insert_type();
void add(char);
int sym_search(char *);
int search(char *);
void addTo(char i,char *n);
void FOO();
void add_ptr();
void pop();
void insert_type_table();
char temptype(char *,char*);
void type_check(char *,char*);
void printtree(struct node1*);
struct node{ int val;} x;
struct dataType{
	char * id_name;
	char * data_type;
	char * type;
	int line_no;
	}symbolTable[20];

struct tripleaddresscode{
       char* op;
       char* arg1;
       char* arg2;
       char* result;
        }icg[30];


int icc=0;/*Intermediate code counter*/
void insert_icg(char *op,char *arg1,char *arg2,char *result);
int flag=0;

void icg_opt_fold(int j);
void icg_opt_prop();
int ifd=0;/*Label*/
int eld=20;
char typeStack[10][100];
int typeStack_top = 0;
char type[10];
char count=0;
int nxt=1;/*printed next once*/
int c=0;/*Temp var count*/
int q;
extern int countn;
struct node1{ struct node1*left;struct node1*right;char* token;};
struct node1* mknode(struct node1 *left,struct node1 *right, char *token);

#line 58 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { struct var_name {char name[100];char tr[10];struct node1* nd;} nam ; struct gen_code{char name[100];char tr[10];char fal[10];struct node1* nd;} gen; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 86 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define IF 257
#define ELSE 258
#define INT 259
#define FLOAT 260
#define CHAR 261
#define DO 262
#define WHILE 263
#define VOID 264
#define INCLUDE 265
#define RETURN 266
#define LE 267
#define GE 268
#define LT 269
#define GT 270
#define EQ 271
#define NE 272
#define NUM 273
#define AND 274
#define OR 275
#define TR 276
#define FL 277
#define STRLT 278
#define ID 279
#define printff 280
#define scanff 281
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   20,   21,   22,   23,   24,    0,   10,   10,   11,   11,
   11,   11,   25,   12,   12,   12,   13,   13,   26,   14,
   27,   14,   28,   29,   15,   15,   30,   15,   15,   31,
   16,   16,   16,   32,   33,   34,   35,   17,   17,   17,
   17,   36,   17,   37,   17,   17,   38,   39,   40,   17,
   41,   42,   18,   18,   43,   19,    9,    2,    2,    2,
    2,   44,    8,    8,    1,   45,    1,    1,    1,    1,
    1,   46,    7,   47,    7,    7,   48,    6,   49,    6,
    6,   50,    5,    5,   51,    4,   52,    4,   53,    4,
    3,    3,    3,    3,    3,
};
static const YYINT yylen[] = {                            2,
    0,    0,    0,    0,    0,   15,    2,    1,    1,    1,
    1,    1,    0,    4,    3,    2,    1,    0,    0,    3,
    0,    3,    0,    0,    6,    4,    0,    4,    0,    0,
    4,    3,    0,    0,    0,    0,    0,   12,    1,    3,
    2,    0,    6,    0,    9,    0,    0,    0,    0,    8,
    0,    0,    6,    0,    0,    6,    1,    3,    3,    2,
    1,    0,    5,    5,    3,    0,    4,    1,    1,    1,
    1,    0,    4,    0,    4,    1,    0,    4,    0,    4,
    1,    0,    4,    1,    0,    4,    0,    3,    0,    2,
    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    8,    0,    0,    9,   10,   11,   12,    0,    0,    1,
    0,    2,    0,   19,   21,    0,    0,    0,    0,    0,
    0,    3,   13,   17,   16,    0,   20,   22,   15,    0,
    0,    0,    0,    0,    4,    0,    0,   24,    0,    0,
   26,    0,   28,   34,   47,    0,   42,   44,   39,    0,
    0,    0,    0,    0,   62,    0,    0,    0,    0,    0,
    0,   25,    0,   48,    0,   57,    0,    0,    0,   40,
    0,    0,    0,    0,   69,   68,    0,   85,   61,    0,
   84,    0,    0,    0,    0,   89,   87,    0,    0,    0,
    0,   30,    0,    6,   60,   90,   66,    0,    0,    0,
    0,   35,   82,   77,   79,   91,   92,   93,   94,   95,
   72,   74,    0,    0,   63,   64,    0,    0,    0,   32,
    0,   88,    0,   58,   59,    0,    0,    0,    0,    0,
    0,    0,   49,   43,    0,   31,    0,   86,   36,    0,
   78,   80,   73,   75,    0,    0,    0,   55,   50,    0,
    0,    0,   45,   37,    0,    0,    0,   51,   38,    0,
    0,   56,   52,    0,    0,   53,
};
static const YYINT yydgoto[] = {                          2,
   79,   80,  113,   81,   82,   83,   84,   49,   67,    8,
   50,   17,   25,   18,   27,   72,   60,  159,  149,   11,
   13,   30,   40,   61,   31,   19,   20,   33,   42,   34,
  119,   53,  126,  147,  156,   57,   58,   54,   85,  145,
  161,  164,  152,   65,  121,  130,  131,  128,  129,  127,
   99,   98,   96,
};
static const YYINT yysindex[] = {                      -258,
    0,    0, -146,    0,    0,    0,    0, -258, -254,    0,
    4,    0,  -36,    0,    0,  -34,  -27,    8,    3,  -34,
    8,    0,    0,    0,    0, -192,    0,    0,    0,  -19,
  -36,   28, -177,   30,    0,   87,    3,    0,    3, -154,
    0,   48,    0,    0,    0,   51,    0,    0,    0, -130,
 -154,    3,  115,   33,    0, -116,  123,  124,    8, -154,
  -97,    0,  -40,    0,  -39,    0,  139,  -95,  -93,    0,
 -189,   61,  -35,    0,    0,    0,  126,    0,    0,  -23,
    0,   94,  -38,   50, -154,    0,    0,   57,  130,  152,
  150,    0,  136,    0,    0,    0,    0,    3,  -39,  -35,
  -35,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -39,  -89,    0,    0,  140,  162,  143,    0,
  -39,    0,   91,    0,    0,   80,  -39,  -39,  -39,  -39,
  -39,   66,    0,    0,  -75,    0,   66,    0,    0,   94,
    0,    0,    0,    0,  -58,  165, -154,    0,    0,  149,
  -83,  173,    0,    0,  -40,  -43,  -14,    0,    0,  157,
   95,    0,    0, -154,  -50,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0, -131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   76,  -25,    0,
   76,    0,    0,    0,    0,  -91,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  176,  -21,    0,  -21, -115,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -113,  -21,    0,    0,    0,    0,    0,    0, -122, -112,
   96,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    7,    0,    0,  -12,    0,    0,    0,
    0,   17,   40,    0,   97,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   -2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -4,    0,    0,    0,    0,    5,    0,    0,   27,
    0,    0,    0,    0,    0,    0,   97,    0,    0,    0,
    0,    0,    0,    0,    0, -114,    0,    0,    0,    0,
    0,    0,    0,   97,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -45,   64,    0,    0,   93,   32,  -33,    0,    0,  226,
   58,  196,   -6,   31,   26,    0,   37,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 321
static const YYINT yytable[] = {                         78,
   78,   27,   18,  104,   78,   15,    1,   15,  105,   46,
   54,    5,   41,   22,   29,   29,   23,  102,   29,   29,
   29,   29,   29,   29,   10,   29,  160,   95,   70,   87,
   87,   88,   87,   29,   87,  133,   65,   29,   29,   29,
   29,  154,   29,   12,   29,   67,   21,   71,   89,   89,
   28,   89,   70,   89,  124,  125,   29,   81,   81,   81,
    9,   81,   41,   81,   43,  123,   24,   83,   83,   83,
   16,   83,   29,   83,  166,   81,   51,   62,   87,  132,
   76,   87,   76,   92,   76,   83,   32,  137,   16,   93,
   56,   29,  111,   26,  112,   38,  143,  144,   76,  111,
   89,  112,   44,   35,    4,    5,    6,   45,  111,    7,
  112,   55,    4,    5,    6,  115,   18,    7,    1,   18,
   37,  114,   39,  122,   46,   47,   48,    7,    7,    7,
   23,  138,    7,  111,   18,  112,   18,   18,   18,   18,
   52,   18,   54,   18,   54,   54,   54,   54,   59,   54,
   46,   54,    5,   41,   63,   64,   18,   18,   18,  141,
  142,   66,   68,   69,   54,   54,   54,   44,   71,    4,
    5,    6,   45,   44,    7,    4,    5,    6,   45,   89,
    7,   23,   90,  151,   91,   94,   97,  103,  116,   46,
   47,   48,  117,  118,  120,   46,   47,   48,  134,  135,
  165,  136,  139,  146,  148,  150,   44,  153,    4,    5,
    6,   45,  155,    7,  158,  162,   14,  163,  157,  140,
   33,   46,    4,    5,    6,    3,   36,    7,   46,   47,
   48,   73,   74,   86,    0,   75,   76,   74,   77,   87,
   75,   76,   14,   77,   14,   29,   29,   29,   29,   29,
  100,  101,   29,   29,   87,   87,   87,   87,   87,  100,
  101,   70,   70,    0,   29,   29,   29,   29,   29,   65,
   65,   29,   29,   89,   89,   89,   89,   89,   67,   67,
   71,   71,    0,   81,   81,   81,   81,   81,    0,    0,
   81,   81,    0,   83,   83,   83,   83,   83,    0,    0,
   83,   83,    0,    0,    0,    0,   76,   76,   76,   76,
   76,    0,    0,   76,   76,    0,  106,  107,  108,  109,
  110,
};
static const YYINT yycheck[] = {                         40,
   40,   93,  125,   42,   40,   42,  265,   42,   47,  125,
  125,  125,  125,   41,   21,   41,   44,   41,   44,   41,
   42,   43,   44,   45,  279,   47,   41,   73,   41,   42,
   43,   65,   45,   59,   47,  125,   41,   59,   41,   42,
   43,  125,   45,   40,   47,   41,   16,   41,   42,   43,
   20,   45,   59,   47,  100,  101,   59,   41,   42,   43,
    3,   45,   37,   47,   39,   99,   59,   41,   42,   43,
   13,   45,   94,   47,  125,   59,   40,   52,   91,  113,
   41,   94,   43,  273,   45,   59,  279,  121,   31,  279,
   40,   94,   43,   91,   45,  273,  130,  131,   59,   43,
   94,   45,  257,  123,  259,  260,  261,  262,   43,  264,
   45,   61,  259,  260,  261,   59,   41,  264,  265,   44,
   93,   85,   93,   98,  279,  280,  281,  259,  260,  261,
   44,   41,  264,   43,  257,   45,  259,  260,  261,  262,
   93,  264,  257,  266,  259,  260,  261,  262,  279,  264,
  266,  266,  266,  266,   40,  123,  279,  280,  281,  128,
  129,  278,   40,   40,  279,  280,  281,  257,  266,  259,
  260,  261,  262,  257,  264,  259,  260,  261,  262,   41,
  264,  273,  278,  147,  278,  125,   61,   94,   59,  279,
  280,  281,   41,   44,   59,  279,  280,  281,   59,   38,
  164,   59,  123,  279,  263,   41,  257,   59,  259,  260,
  261,  262,   40,  264,  258,   59,   41,  123,  155,  127,
  125,  125,  259,  260,  261,    0,   31,  264,  279,  280,
  281,  272,  273,  273,   -1,  276,  277,  273,  279,  279,
  276,  277,  279,  279,  279,  267,  268,  269,  270,  271,
  274,  275,  274,  275,  267,  268,  269,  270,  271,  274,
  275,  274,  275,   -1,  267,  268,  269,  270,  271,  274,
  275,  274,  275,  267,  268,  269,  270,  271,  274,  275,
  274,  275,   -1,  267,  268,  269,  270,  271,   -1,   -1,
  274,  275,   -1,  267,  268,  269,  270,  271,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,  267,  268,  269,  270,
  271,   -1,   -1,  274,  275,   -1,  267,  268,  269,  270,
  271,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
#define YYUNDFTOKEN 337
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'",0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"IF","ELSE","INT","FLOAT","CHAR","DO","WHILE",
"VOID","INCLUDE","RETURN","LE","GE","LT","GT","EQ","NE","NUM","AND","OR","TR",
"FL","STRLT","ID","printff","scanff",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : P",
"$$1 :",
"$$2 :",
"$$3 :",
"$$4 :",
"$$5 :",
"P : I M ID $$1 '(' $$2 R ')' $$3 '{' $$4 S $$5 U '}'",
"I : I I",
"I : INCLUDE",
"M : INT",
"M : FLOAT",
"M : CHAR",
"M : VOID",
"$$6 :",
"R : R ',' $$6 R",
"R : M N TER",
"R : N TER",
"TER : ';'",
"TER :",
"$$7 :",
"N : ID $$7 G",
"$$8 :",
"N : '*' $$8 N",
"$$9 :",
"$$10 :",
"G : '[' $$9 NUM $$10 ']' G",
"G : '[' ID ']' G",
"$$11 :",
"G : '[' $$11 ']' G",
"G :",
"$$12 :",
"U : RETURN NUM $$12 ';'",
"U : RETURN ID ';'",
"U :",
"$$13 :",
"$$14 :",
"$$15 :",
"$$16 :",
"S : IF $$13 '(' C ')' $$14 '{' $$15 S '}' $$16 EL",
"S : assign",
"S : M ID TER",
"S : S S",
"$$17 :",
"S : printff $$17 '(' STRLT ')' ';'",
"$$18 :",
"S : scanff $$18 '(' STRLT ',' '&' ID ')' ';'",
"S :",
"$$19 :",
"$$20 :",
"$$21 :",
"S : DO $$19 '{' $$20 S '}' $$21 WH",
"$$22 :",
"$$23 :",
"EL : ELSE $$22 '{' $$23 S '}'",
"EL :",
"$$24 :",
"WH : WHILE $$24 '(' C ')' ';'",
"Arg : STRLT",
"C : C AND B",
"C : C OR B",
"C : NE B",
"C : B",
"$$25 :",
"assign : ID '=' $$25 E ';'",
"assign : ID '(' Arg ')' ';'",
"B : E relop E",
"$$26 :",
"B : ID '=' $$26 E",
"B : FL",
"B : TR",
"B : ID",
"B : NUM",
"$$27 :",
"E : E '+' $$27 E",
"$$28 :",
"E : E '-' $$28 E",
"E : F",
"$$29 :",
"F : F '*' $$29 F",
"$$30 :",
"F : F '/' $$30 F",
"F : T",
"$$31 :",
"T : T '^' $$31 T",
"T : Q",
"$$32 :",
"Q : '(' $$32 E ')'",
"$$33 :",
"Q : ID $$33 G",
"$$34 :",
"Q : NUM $$34",
"relop : LE",
"relop : GE",
"relop : LT",
"relop : GT",
"relop : EQ",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 257 "parser.y"
int main()
{
	extern int yylineno;
	x.val=10;
	/*printf("#######################################################################################\n");
	printf("\t\t\tIntermediate code\n");
	printf("#######################################################################################\n");*/
	yyparse();
	
	//printf("\nParsing is Successful\n");	
	/*printf("#######################################################################################\n");
	printf("\t\t\tSymbol Table\n");
	printf("#######################################################################################\n");	
	printf("\nsymbol \t type  \t identify \t line number\n");
	printf("_______________________________________________________________________________________\n");

	for(i=0;i<count;i++){
		printf("%s\t%s\t%s\t%d\t\n",symbolTable[i].id_name,symbolTable[i].data_type,symbolTable[i].type,symbolTable[i].line_no);
		
	}*/
	int i=0;
	printf("\n\n");
	for(i=0;i<icc;i++){
		printf("%s\t%s\t%s\t%s\n",icg[i].op,icg[i].arg1,icg[i].arg2,icg[i].result);
	}	
	
	icg_opt_prop();
	
	
	printf("\n\n");
	printf("Optimized code\n");
	for(i=0;i<icc;i++){
		printf("%s\t%s\t%s\t%s\n",icg[i].op,icg[i].arg1,icg[i].arg2,icg[i].result);
	}	

	for(i=0;i<icc;i++){	
		icg_opt_fold(i);
	}

	printf("\n\n");
	printf("Optimized code1\n");
	for(i=0;i<icc;i++){
		printf("%s\t%s\t%s\t%s\n",icg[i].op,icg[i].arg1,icg[i].arg2,icg[i].result);
	}
	
	for(i=0;i<count;i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
	return 0;
}
void yyerror(const char* s)
{
	printf("Not accepted\n");
	exit(0);
}
//insert the type into symboltable
void insert_type(){

	
	strcpy(type,yytext);
	//printf("hey");
	q=search(type);
	//printf("qval=%d",q);
	if(q==0){
		
		symbolTable[count].id_name=strdup(yytext);
		symbolTable[count].data_type=strdup("N/A");
		symbolTable[count].line_no = countn;
		symbolTable[count].type=strdup("KEYWORD\t");
		count++;
	}
	
	
}

struct node1* mknode(struct node1 *left, struct node1 *right, char *token)
{
	
  struct node1 *newnode = (struct node1 *)malloc(sizeof(struct node1));
  char *newstr = (char *)malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}
void pop()
{
	int i;
	//printf("count %d\n",count);
	int temp=count-1;
	for(i=temp;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,"{")!=0)
		{
			//printf("$$\n");
			count=count-1;;
		}
		else
		{
			count=count-1;
			break;
		}
	}	
	

}
//add declaration of data to symboltable
void addTo(char i,char *n)
{
	if(i=='i')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="int";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='f')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="float";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='c')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="char";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='{')
	{
			symbolTable[count].id_name=strdup("{");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}
	else if(i=='}')
	{
			symbolTable[count].id_name=strdup("}");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}


}
char temptype(char* one,char* two)
{
		int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if((strcmp(onetype,"float")==0) || (strcmp(twotype,"float")==0))
		return 'f';
	else
		return 'i';
}
void insert_type_table(){
	
		q=search(yytext);
	
		if(q==0){
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("IDENTIFIER");
			count++;
		}
	
	
}
void type_check(char* one, char* two)
{
	int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if(strcmp(onetype,twotype)>0){ printf("type error at lineno %d\n",yylineno);exit(0);}
}
//ADD the recent parsed string into symboltable
void add(char c)
{
	q=search(yytext);
	if(q==0){
		if(c=='H')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c=='t')
		{	
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Punctuation");
			count++;
		}
		else if(c=='o')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Operator");
			count++;
		}
		else if(c=='r')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Rel Op\t");
			count++;
		}
		else if(c=='k')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("KEYWORD\t");
			count++;
		}
		else if(c=='n')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("int");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("NUMBER\t");
			count++;
		}
	else if(c=='f')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("FUNCTION\t");
			count++;
		}
	}
}
int  sym_search(char *type)
{
	int i;
	for(i=count -1 ;i>=0&&(strcmp(symbolTable[i].id_name,"{")!=0);i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	
	}
	return 0;
}
//Search in the Symbol table whether the parsed String is present in Symbol table already
int  search(char *type)
{
	int i;
	for(i=count -1 ;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	
	}
	return 0;
}
void add_ptr(){
	strcat(type,"*");
}


void printtree(struct node1 *tree) 
{ 
  int i; 
  if (tree->left || tree->right) 
    printf("("); 
  printf(" %s ", tree->token); 
  if (tree->left) 
    printtree(tree->left); 
  if (tree->right) 
    printtree(tree->right); 
  if (tree->left || tree->right) 
    printf(")"); 
} 

void insert_icg(char *op,char *arg1,char *arg2,char *result)
{
	icg[icc].op = strdup(op);
	icg[icc].arg1 = strdup(arg1);
	icg[icc].arg2 = strdup(arg2);
	icg[icc].result = strdup(result);
	icc+=1;
}

void icg_opt_prop()
{
	int i,j;
	
	for(i=0;i<icc;i++)
	{
		if(strcmp(icg[i].op,"=")==0)
		{
			for(j=i+1;j<icc;j++)
			{
				if(strcmp(icg[j].arg1,icg[i].result)==0)
				{
					strcpy(icg[j].arg1,icg[i].arg1);
				}

				if(strcmp(icg[j].arg2,icg[i].result)==0)
				{
					strcpy(icg[j].arg2,icg[i].arg1);
				}
				icg_opt_fold(j);
					
			}
		}	
	}
}

void icg_opt_fold(int j)
{
	int a1,a2,ans;
	if(isdigit(icg[j].arg1[0])!=0 && isdigit(icg[j].arg2[0])!=0){
					//icg[j].op=strdup("=");
					a1=atoi(icg[j].arg1);a2=atoi(icg[j].arg2);
					if(strcmp(icg[j].op,"*")==0)
					{
						if((strcmp(icg[j].arg1,"0")==0) || (strcmp(icg[j].arg2,"0")==0))
						{
							icg[j].op=strdup("=");
							icg[j].arg1=strdup("0");
							icg[j].arg2=strdup("");				
						}
						else 
						{
							if(strcmp(icg[j].arg1,"1")==0)
							{
								icg[j].op=strdup("=");
								strcpy(icg[j].arg1,icg[j].arg2);
								icg[j].arg2=strdup("");
							}
							if(strcmp(icg[j].arg2,"1")==0)
							{
								icg[j].op=strdup("=");
								icg[j].arg2=strdup("");
							}
							else{
								ans=a1*a2;
								//itoa(ans,ansch,10);
								icg[j].op=strdup("=");
								icg[j].arg2=strdup("");
								sprintf(icg[j].arg1,"%d",ans);
							}
						} 
					}
					else if(strcmp(icg[j].op,"+")==0){
						if(strcmp(icg[j].arg1,"0")==0)
						{
							icg[j].op=strdup("=");
							strcpy(icg[j].arg1,icg[j].arg2);
							icg[j].arg2=strdup("");
						}
						if(strcmp(icg[j].arg2,"0")==0)
						{
							icg[j].op=strdup("=");
							icg[j].arg2=strdup("");
						}
						else{
							ans=a1+a2;
							icg[j].op=strdup("=");
							//itoa(ans,ansch,10);
							icg[j].arg2=strdup("");
							sprintf(icg[j].arg1,"%d",ans);
						}				
					}
					else if(strcmp(icg[j].op,"-")==0){
						if(strcmp(icg[j].arg1,"0")==0)
						{
							icg[j].op=strdup("=");
							sprintf(icg[j].arg1,"-%s",icg[j].arg2);
							icg[j].arg2=strdup("");
						}
						if(strcmp(icg[j].arg2,"0")==0)
						{
							icg[j].op=strdup("=");
							icg[j].arg2=strdup("");
						}
						else{
							ans=a1-a2;
							icg[j].op=strdup("=");
							//itoa(ans,ansch,10);
							icg[j].arg2=strdup("");
							sprintf(icg[j].arg1,"%d",ans);
						}				
					}
					else if(strcmp(icg[j].op,"/")==0){
						if(strcmp(icg[j].arg2,"1")==0)
						{
							icg[j].op=strdup("=");
							icg[j].arg2=strdup("");
						}
						else{
							ans=a1/a2;
							//itoa(ans,ansch,10);
							icg[j].op=strdup("=");
							icg[j].arg2=strdup("");
							sprintf(icg[j].arg1,"%d",ans);
						}					
					}
					else if(strcmp(icg[j].op,"^")==0){
						if(strcmp(icg[j].arg2,"1")==0)
						{
							icg[j].op=strdup("=");
							icg[j].arg2=strdup("");
						}
						else if(strcmp(icg[j].arg2,"0")==0)
						{
							icg[j].op=strdup("=");
							icg[j].arg1=strdup("1");
							icg[j].arg2=strdup("");
						}
						else if(strcmp(icg[j].arg1,"0")==0)
						{
							icg[j].op=strdup("=");
							icg[j].arg1=strdup("0");
							icg[j].arg2=strdup("");
						}
						else{
							ans=a1^a2;
							icg[j].op=strdup("=");
							//itoa(ans,ansch,10);
							icg[j].arg2=strdup("");
							sprintf(icg[j].arg1,"%d",ans);
						}
					}
				}
}

#line 932 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 72 "parser.y"
	{insert_type_table();}
break;
case 2:
#line 72 "parser.y"
	{add('t');}
break;
case 3:
#line 72 "parser.y"
	{add('t');}
break;
case 4:
#line 72 "parser.y"
	{add('t');}
break;
case 5:
#line 72 "parser.y"
	{ /*printf("Label next:\n");*/}
break;
case 6:
#line 72 "parser.y"
	{yyval.nam.nd = mknode(NULL,yystack.l_mark[-3].nam.nd,"start");/*printf("#######################################################################################\n");*/printf("\t\t\tSyntax Tree\n");/*\n###################\n");*/
printtree(yyval.nam.nd);
/*printf("\n\n");*/
add('t');}
break;
case 8:
#line 76 "parser.y"
	{add('H');}
break;
case 9:
#line 77 "parser.y"
	{insert_type();}
break;
case 10:
#line 77 "parser.y"
	{insert_type();}
break;
case 11:
#line 77 "parser.y"
	{insert_type();}
break;
case 12:
#line 77 "parser.y"
	{insert_type();}
break;
case 13:
#line 78 "parser.y"
	{add('t');}
break;
case 17:
#line 80 "parser.y"
	{add('t');}
break;
case 19:
#line 81 "parser.y"
	{insert_type_table();}
break;
case 21:
#line 81 "parser.y"
	{add_ptr();}
break;
case 23:
#line 82 "parser.y"
	{add('t');}
break;
case 24:
#line 82 "parser.y"
	{add('n');}
break;
case 27:
#line 82 "parser.y"
	{add('t');}
break;
case 30:
#line 84 "parser.y"
	{add('n');}
break;
case 31:
#line 84 "parser.y"
	{add('t');printf("Return\t%s\n",yystack.l_mark[-2].nam.name);		insert_icg("return",yystack.l_mark[-2].nam.name,"","");}
break;
case 32:
#line 85 "parser.y"
	{add('t');printf("Return\t%s\n",yystack.l_mark[-1].nam.name);				insert_icg("return",yystack.l_mark[-1].nam.name,"","");}
break;
case 34:
#line 88 "parser.y"
	{add('k');}
break;
case 35:
#line 88 "parser.y"
	{printf("\nLabel\t%s:\n",yystack.l_mark[-1].gen.tr);
	insert_icg("if",yystack.l_mark[-1].gen.name,"",yystack.l_mark[-1].gen.tr);
	insert_icg("ifFalse",yystack.l_mark[-1].gen.name,"",yystack.l_mark[-1].gen.fal);
	insert_icg("Label","","",yystack.l_mark[-1].gen.tr);}
break;
case 36:
#line 91 "parser.y"
	{addTo('{',"Punctuations");}
break;
case 37:
#line 91 "parser.y"
	{addTo('}',"Punctuations");
	pop();
	printf("goto next\n");
	printf("\nLabel\t%s:\n",yystack.l_mark[-6].gen.fal);
	}
break;
case 38:
#line 96 "parser.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-8].gen.nd,yystack.l_mark[-3].nam.nd,"IF");
	strcpy(yyval.nam.name,"IF");
	}
break;
case 39:
#line 99 "parser.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
break;
case 40:
#line 100 "parser.y"
	{yyval.nam.nd=mknode(NULL,NULL,"definition"); int i=sym_search(yystack.l_mark[-1].nam.name);if(i!=-1)
	{if(strcmp(yystack.l_mark[-2].nam.name,"int")==0){addTo('i',yystack.l_mark[-1].nam.name);}
	else if(strcmp(yystack.l_mark[-2].nam.name,"float")==0)addTo('f',yystack.l_mark[-1].nam.name);
	else addTo('c',yystack.l_mark[-1].nam.name);}
	else{printf("Variable already defined, error at line no: %d\n",yylineno);exit(0);}}
break;
case 41:
#line 105 "parser.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-1].nam.nd,yystack.l_mark[0].nam.nd,"statement");strcpy(yyval.nam.name,"STATEMENT");}
break;
case 42:
#line 106 "parser.y"
	{add('f');}
break;
case 43:
#line 106 "parser.y"
	{yyval.nam.nd = mknode(NULL,NULL,"printf");}
break;
case 44:
#line 107 "parser.y"
	{add('f');}
break;
case 45:
#line 107 "parser.y"
	{yyval.nam.nd = mknode(NULL,NULL,"scanf");}
break;
case 46:
#line 108 "parser.y"
	{yyval.nam.nd=mknode(NULL,NULL,"EPSILON");}
break;
case 47:
#line 109 "parser.y"
	{add('k');
	sprintf(yystack.l_mark[0].nam.tr,"L%d",c);
	insert_icg("Label","","",yystack.l_mark[0].nam.tr);}
break;
case 48:
#line 111 "parser.y"
	{addTo('{',"Punctuations");}
break;
case 49:
#line 111 "parser.y"
	{addTo('}',"Punctuations"); flag=1;}
break;
case 51:
#line 114 "parser.y"
	{add('k');insert_icg("Label","","",yyval.nam.tr);}
break;
case 52:
#line 114 "parser.y"
	{addTo('{',"Punctuations");}
break;
case 53:
#line 114 "parser.y"
	{
	yyval.nam=yystack.l_mark[-1].nam;addTo('}',"Punctuations");
	pop();
	printf("goto next\n");
	printf("\n");}
break;
case 54:
#line 118 "parser.y"
	{printf("goto next\n");
	printf("\n");
	}
break;
case 55:
#line 122 "parser.y"
	{add('k');}
break;
case 56:
#line 123 "parser.y"
	{insert_icg("if",yystack.l_mark[-2].gen.name,"",yystack.l_mark[-2].gen.tr);insert_icg("ifFalse",yystack.l_mark[-2].gen.name,"",yystack.l_mark[-2].gen.fal);}
break;
case 58:
#line 127 "parser.y"
	{sprintf(yyval.gen.name,"t%d",c);c+=1;
	insert_icg(yystack.l_mark[-1].nam.name,yystack.l_mark[-2].gen.name,yystack.l_mark[-1].nam.name,yyval.gen.name);}
break;
case 59:
#line 129 "parser.y"
	{sprintf(yyval.gen.name,"t%d",c);c+=1;
	insert_icg(yystack.l_mark[-1].nam.name,yystack.l_mark[-2].gen.name,yystack.l_mark[-1].nam.name,yyval.gen.name);}
break;
case 60:
#line 131 "parser.y"
	{sprintf(yyval.gen.name,"t%d",c);c+=1;
	insert_icg("NEG",yystack.l_mark[0].gen.name,"",yyval.gen.name);}
break;
case 61:
#line 133 "parser.y"
	{yyval.gen.nd=yystack.l_mark[0].gen.nd; strcpy(yyval.gen.tr,yystack.l_mark[0].gen.tr);strcpy(yyval.gen.fal,yystack.l_mark[0].gen.fal);strcpy(yyval.gen.name,yystack.l_mark[0].gen.name);}
break;
case 62:
#line 136 "parser.y"
	{add('o');}
break;
case 63:
#line 136 "parser.y"
	{yystack.l_mark[-4].nam.nd = mknode(NULL,NULL,yystack.l_mark[-4].nam.name);
	  yyval.nam.nd=mknode(yystack.l_mark[-4].nam.nd,yystack.l_mark[-1].nam.nd,"=");
	  strcpy(yyval.nam.name,"=");add('t');
	  int i=search(yystack.l_mark[-4].nam.name);
	  int j=search(yystack.l_mark[-1].nam.name);
	  if(i!=0&&j!=0) 
	  {
	  type_check(yystack.l_mark[-4].nam.name,yystack.l_mark[-1].nam.name);
	  printf("= \t %s\t %s \n",yystack.l_mark[-1].nam.name,yystack.l_mark[-4].nam.name);insert_icg("=",yystack.l_mark[-1].nam.name,"",yystack.l_mark[-4].nam.name);}
	  else {printf("Variable not declared at line no: %d\n", yylineno);
	  exit(0);}}
break;
case 64:
#line 146 "parser.y"
	{add('t');}
break;
case 65:
#line 148 "parser.y"
	{yyval.gen.nd=mknode(yystack.l_mark[-2].nam.nd,yystack.l_mark[0].nam.nd,yystack.l_mark[-1].nam.name);
   	int i=search(yystack.l_mark[-2].nam.name);
   	int j=search(yystack.l_mark[0].nam.name);
   	if(i!=0&&j!=0){
   	printf("if %s %s %s goto L%d else goto L%d\n",yystack.l_mark[-2].nam.name,yystack.l_mark[-1].nam.name,yystack.l_mark[0].nam.name,ifd,eld);
	sprintf(yyval.gen.name,"t%d",c);c+=1;			/*here*/
	insert_icg(yystack.l_mark[-1].nam.name,yystack.l_mark[-2].nam.name,yystack.l_mark[0].nam.name,yyval.gen.name);
   sprintf(yyval.gen.tr,"L%d",ifd);
   sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}   
   else{printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
break;
case 66:
#line 158 "parser.y"
	{add('o');}
break;
case 67:
#line 158 "parser.y"
	{int i=search(yystack.l_mark[-3].nam.name);
 	int j=search(yystack.l_mark[0].nam.name);
 	if(i!=0&&j!=0)
 	{
 	printf("if %s!=0 goto L%d else goto L%d\n",yystack.l_mark[-3].nam.name,ifd,eld);
	sprintf(yyval.gen.name,"%s = %s",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name);	/*here*/
	insert_icg("=",yystack.l_mark[-3].nam.name,"",yystack.l_mark[0].nam.name);
 	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;} 
	else{printf(" Variable not declared at line no: %d\n", yylineno);
	exit(0);}}
break;
case 68:
#line 169 "parser.y"
	{printf("if False  goto L%d\n",eld);
	strcpy(yyval.gen.name,yystack.l_mark[0].nam.name);	/*here*/
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}
break;
case 69:
#line 173 "parser.y"
	{printf("if True  goto L%d\n",ifd);
	strcpy(yyval.gen.name,yystack.l_mark[0].nam.name); 	/*here*/
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}
break;
case 70:
#line 177 "parser.y"
	{int i=search(yystack.l_mark[0].nam.name);
	if(i!=0)
	{
	printf("if %s!=0  goto L%d else goto L%d\n",yystack.l_mark[0].nam.name,ifd,eld);
	strcpy(yyval.gen.name,yystack.l_mark[0].nam.name);	/*here*/
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}    
	else {printf(" Variable not declared at line no: %d\n", yylineno);
	exit(0);} }
break;
case 71:
#line 186 "parser.y"
	{add('n');
	printf("if %s!=0  goto L%d else goto L%d\n",yystack.l_mark[0].nam.name,ifd,eld);
	strcpy(yyval.gen.name,yystack.l_mark[0].nam.name);	/*here*/
	sprintf(yyval.gen.tr,"L%d",ifd);
	sprintf(yyval.gen.fal,"L%d",eld);ifd++;eld++;}
break;
case 72:
#line 192 "parser.y"
	{add('o');}
break;
case 73:
#line 192 "parser.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"+");strcpy(yyval.nam.name,"+");
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"t%d",c);c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","+",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);	insert_icg("+",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
break;
case 74:
#line 201 "parser.y"
	{add('o');}
break;
case 75:
#line 201 "parser.y"
	{ yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"-");
	strcpy(yyval.nam.name,"-");
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"t%d",c);c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","-",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name); 	insert_icg("-",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);}
	else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
break;
case 76:
#line 209 "parser.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
break;
case 77:
#line 211 "parser.y"
	{add('o');}
break;
case 78:
#line 211 "parser.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"*");
	 strcpy(yyval.nam.name,"*");
	 int i=search(yystack.l_mark[-3].nam.name);
	 int j=search(yystack.l_mark[0].nam.name);
	 sprintf(yyval.nam.name,"t%d",c);c++;
	 addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	 if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","*",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);	insert_icg("*",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
break;
case 79:
#line 220 "parser.y"
	{add('o');}
break;
case 80:
#line 220 "parser.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"/");strcpy(yyval.nam.name,"/"); 
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"%d",c);
	strcat(yyval.nam.name,"t");c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) 
	{
	printf("%s\t%s\t%s\t%s\n","/",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);				insert_icg("/",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);
	}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);
	 exit(0);}}
break;
case 81:
#line 233 "parser.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
break;
case 82:
#line 235 "parser.y"
	{add('o');}
break;
case 83:
#line 235 "parser.y"
	{yyval.nam.nd=mknode(yystack.l_mark[-3].nam.nd,yystack.l_mark[0].nam.nd,"^");
	strcpy(yyval.nam.name,"^");
	int i=search(yystack.l_mark[-3].nam.name);
	int j=search(yystack.l_mark[0].nam.name);
	sprintf(yyval.nam.name,"%d",c);
	strcat(yyval.nam.name,"t");c++;
	addTo(temptype(yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name),yyval.nam.name);
	if(i!=0 && j!=0) {
	printf("%s\t%s\t%s\t%s\n","^",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name); 			insert_icg("+",yystack.l_mark[-3].nam.name,yystack.l_mark[0].nam.name,yyval.nam.name);}
	else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
break;
case 84:
#line 246 "parser.y"
	{yyval.nam.nd=yystack.l_mark[0].nam.nd;}
break;
case 85:
#line 248 "parser.y"
	{add('t');}
break;
case 86:
#line 248 "parser.y"
	{add('t'); yyval.nam=yystack.l_mark[-1].nam;}
break;
case 87:
#line 248 "parser.y"
	{insert_type_table();}
break;
case 88:
#line 248 "parser.y"
	{yyval.nam.nd=mknode(NULL,NULL,yystack.l_mark[-2].nam.name);strcpy(yyval.nam.name,yystack.l_mark[-2].nam.name);}
break;
case 89:
#line 248 "parser.y"
	{add('n');}
break;
case 90:
#line 248 "parser.y"
	{yyval.nam.nd=mknode(NULL,NULL,yystack.l_mark[-1].nam.name);
	strcpy(yyval.nam.name,yystack.l_mark[-1].nam.name);}
break;
case 91:
#line 252 "parser.y"
	{add('r');/*$$.name=$1.name;*/}
break;
case 92:
#line 252 "parser.y"
	{add('r');/*$$.name=$1.name;*/}
break;
case 93:
#line 252 "parser.y"
	{add('r');/*$$.name=$1.name;*/}
break;
case 94:
#line 252 "parser.y"
	{add('r');/*$$.name=$1.name;*/}
break;
case 95:
#line 252 "parser.y"
	{add('r');/*$$.name=$1.name;*/}
break;
#line 1573 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
