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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union { struct var_name {char name[100];char tr[10];struct node1* nd;} nam ; struct gen_code{char name[100];char tr[10];char fal[10];struct node1* nd;} gen; } YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
