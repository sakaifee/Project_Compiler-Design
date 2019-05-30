%{
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


int icc=0;//Intermediate code counter
void insert_icg(char *op,char *arg1,char *arg2,char *result);
int flag=0;

void icg_opt_fold(int j);
void icg_opt_prop();
int ifd=0;//Label
int eld=20;
char typeStack[10][100];
int typeStack_top = 0;
char type[10];
char count=0;
int nxt=1;//printed next once
int c=0;//Temp var count
int q;
extern int countn;
struct node1{ struct node1*left;struct node1*right;char* token;};
struct node1* mknode(struct node1 *left,struct node1 *right, char *token);

%}
%union { struct var_name {char name[100];char tr[10];struct node1* nd;} nam ; struct gen_code{char name[100];char tr[10];char fal[10];struct node1* nd;} gen; } 
%token <nam> IF ELSE INT FLOAT CHAR DO WHILE
%token VOID INCLUDE RETURN 
%token <nam> LE GE LT GT EQ NE NUM AND OR TR FL STRLT ID printff scanff
%type <gen> B C
%type <nam> relop Q T F E assign Arg P I M R TER N G U S EL WH
%start P
%left '+' '-' '*' '/'
%right '=' '^'


%%


P : I M ID {insert_type_table();} '('{add('t');} R ')'{add('t');} '{'{add('t');} S { /*printf("Label next:\n");*/}  U '}'{$$.nd = mknode(NULL,$12.nd,"start");/*printf("#######################################################################################\n");*/printf("\t\t\tSyntax Tree\n");/*\n###################\n");*/
printtree($$.nd);
//printf("\n\n");
add('t');};
I : I I | INCLUDE {add('H');} ;
M : INT{insert_type();} | FLOAT{insert_type();}| CHAR{insert_type();} | VOID{insert_type();} ;
R : R ','{add('t');} R | M N TER | N TER;

TER : ';'{add('t');} | ;
N : ID{insert_type_table();} G | '*'{add_ptr();} N ; 
G : '['{add('t');} NUM {add('n');}']' G |  '['ID ']' G | '['{add('t');} ']' G |  ;

U : RETURN NUM {add('n');} ';'{add('t');printf("Return\t%s\n",$2.name);		insert_icg("return",$2.name,"","");}
    | RETURN ID ';' {add('t');printf("Return\t%s\n",$2.name);				insert_icg("return",$2.name,"","");}
    | ;

S :	IF{add('k');} '(' C ')'{printf("\nLabel\t%s:\n",$4.tr);
	insert_icg("if",$4.name,"",$4.tr);
	insert_icg("ifFalse",$4.name,"",$4.fal);
	insert_icg("Label","","",$4.tr);}'{'{addTo('{',"Punctuations");} S '}'{addTo('}',"Punctuations");
	pop();
	printf("goto next\n");
	printf("\nLabel\t%s:\n",$4.fal);
	}
	EL{$$.nd=mknode($4.nd,$9.nd,"IF");
	strcpy($$.name,"IF");
	}
	|assign {$$.nd=$1.nd;}
	|M ID TER {$$.nd=mknode(NULL,NULL,"definition"); int i=sym_search($2.name);if(i!=-1)
	{if(strcmp($1.name,"int")==0){addTo('i',$2.name);}
	else if(strcmp($1.name,"float")==0)addTo('f',$2.name);
	else addTo('c',$2.name);}
	else{printf("Variable already defined, error at line no: %d\n",yylineno);exit(0);}}
	|S S {$$.nd=mknode($1.nd,$2.nd,"statement");strcpy($$.name,"STATEMENT");}
	|printff  {add('f');} '(' STRLT ')'';' {$$.nd = mknode(NULL,NULL,"printf");}
	|scanff {add('f');}'('STRLT ',''&'ID')' ';'{$$.nd = mknode(NULL,NULL,"scanf");}
	|{$$.nd=mknode(NULL,NULL,"EPSILON");};
	|DO {add('k');
	sprintf($1.tr,"L%d",c);
	insert_icg("Label","","",$1.tr);} '{'{addTo('{',"Punctuations");} 			S'}'{addTo('}',"Punctuations"); flag=1;} WH 
	;
	
EL: ELSE{add('k');insert_icg("Label","","",$$.tr);} '{'{addTo('{',"Punctuations");} S '}' {
	$$=$5;addTo('}',"Punctuations");
	pop();
	printf("goto next\n");
	printf("\n");}| {printf("goto next\n");
	printf("\n");
	};

WH: WHILE {add('k');} '('C')'';'
    {insert_icg("if",$4.name,"",$4.tr);insert_icg("ifFalse",$4.name,"",$4.fal);};

Arg : STRLT ;

C : C AND B {sprintf($$.name,"t%d",c);c+=1;
	insert_icg($2.name,$1.name,$2.name,$$.name);}
  | C OR B {sprintf($$.name,"t%d",c);c+=1;
	insert_icg($2.name,$1.name,$2.name,$$.name);}
  | NE B {sprintf($$.name,"t%d",c);c+=1;
	insert_icg("NEG",$2.name,"",$$.name);}
  | B{$$.nd=$1.nd; strcpy($$.tr,$1.tr);strcpy($$.fal,$1.fal);strcpy($$.name,$1.name);};


assign :  ID '='{add('o');} E ';'{$1.nd = mknode(NULL,NULL,$1.name);
	  $$.nd=mknode($1.nd,$4.nd,"=");
	  strcpy($$.name,"=");add('t');
	  int i=search($1.name);
	  int j=search($4.name);
	  if(i!=0&&j!=0) 
	  {
	  type_check($1.name,$4.name);
	  printf("= \t %s\t %s \n",$4.name,$1.name);insert_icg("=",$4.name,"",$1.name);}
	  else {printf("Variable not declared at line no: %d\n", yylineno);
	  exit(0);}} |ID '(' Arg ')' ';'{add('t');};

B : 	E relop E {$$.nd=mknode($1.nd,$3.nd,$2.name);
   	int i=search($1.name);
   	int j=search($3.name);
   	if(i!=0&&j!=0){
   	printf("if %s %s %s goto L%d else goto L%d\n",$1.name,$2.name,$3.name,ifd,eld);
	sprintf($$.name,"t%d",c);c+=1;			//here
	insert_icg($2.name,$1.name,$3.name,$$.name);
   sprintf($$.tr,"L%d",ifd);
   sprintf($$.fal,"L%d",eld);ifd++;eld++;}   
   else{printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}   
   | ID '=' {add('o');} E{int i=search($1.name);
 	int j=search($4.name);
 	if(i!=0&&j!=0)
 	{
 	printf("if %s!=0 goto L%d else goto L%d\n",$1.name,ifd,eld);
	sprintf($$.name,"%s = %s",$1.name,$4.name);	//here
	insert_icg("=",$1.name,"",$4.name);
 	sprintf($$.tr,"L%d",ifd);
	sprintf($$.fal,"L%d",eld);ifd++;eld++;} 
	else{printf(" Variable not declared at line no: %d\n", yylineno);
	exit(0);}} 
	| FL{printf("if False  goto L%d\n",eld);
	strcpy($$.name,$1.name);	//here
	sprintf($$.tr,"L%d",ifd);
	sprintf($$.fal,"L%d",eld);ifd++;eld++;} 
	| TR {printf("if True  goto L%d\n",ifd);
	strcpy($$.name,$1.name); 	//here
	sprintf($$.tr,"L%d",ifd);
	sprintf($$.fal,"L%d",eld);ifd++;eld++;} 
	| ID {int i=search($1.name);
	if(i!=0)
	{
	printf("if %s!=0  goto L%d else goto L%d\n",$1.name,ifd,eld);
	strcpy($$.name,$1.name);	//here
	sprintf($$.tr,"L%d",ifd);
	sprintf($$.fal,"L%d",eld);ifd++;eld++;}    
	else {printf(" Variable not declared at line no: %d\n", yylineno);
	exit(0);} }
	| NUM {add('n');
	printf("if %s!=0  goto L%d else goto L%d\n",$1.name,ifd,eld);
	strcpy($$.name,$1.name);	//here
	sprintf($$.tr,"L%d",ifd);
	sprintf($$.fal,"L%d",eld);ifd++;eld++;} ;

E :	E '+'{add('o');} E {$$.nd=mknode($1.nd,$4.nd,"+");strcpy($$.name,"+");
	int i=search($1.name);
	int j=search($4.name);
	sprintf($$.name,"t%d",c);c++;
	addTo(temptype($1.name,$4.name),$$.name);
	if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","+",$1.name,$4.name,$$.name);	insert_icg("+",$1.name,$4.name,$$.name);}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}


	| E '-' {add('o');}E { $$.nd=mknode($1.nd,$4.nd,"-");
	strcpy($$.name,"-");
	int i=search($1.name);
	int j=search($4.name);
	sprintf($$.name,"t%d",c);c++;
	addTo(temptype($1.name,$4.name),$$.name);
	if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","-",$1.name,$4.name,$$.name); 	insert_icg("-",$1.name,$4.name,$$.name);}
	else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}
	| F{$$.nd=$1.nd;};
	
F :	 F '*'{add('o');} F {$$.nd=mknode($1.nd,$4.nd,"*");
	 strcpy($$.name,"*");
	 int i=search($1.name);
	 int j=search($4.name);
	 sprintf($$.name,"t%d",c);c++;
	 addTo(temptype($1.name,$4.name),$$.name);
	 if(i!=0 && j!=0) {printf("%s\t%s\t%s\t%s\n","*",$1.name,$4.name,$$.name);	insert_icg("*",$1.name,$4.name,$$.name);}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}

	| F '/' {add('o');}F {$$.nd=mknode($1.nd,$4.nd,"/");strcpy($$.name,"/"); 
	int i=search($1.name);
	int j=search($4.name);
	sprintf($$.name,"%d",c);
	strcat($$.name,"t");c++;
	addTo(temptype($1.name,$4.name),$$.name);
	if(i!=0 && j!=0) 
	{
	printf("%s\t%s\t%s\t%s\n","/",$1.name,$4.name,$$.name);				insert_icg("/",$1.name,$4.name,$$.name);
	}
	 else {printf(" Variable not declared at line no: %d\n", yylineno);
	 exit(0);}}

	| T {$$.nd=$1.nd;};
	
T :	T '^'{add('o');} T {$$.nd=mknode($1.nd,$4.nd,"^");
	strcpy($$.name,"^");
	int i=search($1.name);
	int j=search($4.name);
	sprintf($$.name,"%d",c);
	strcat($$.name,"t");c++;
	addTo(temptype($1.name,$4.name),$$.name);
	if(i!=0 && j!=0) {
	printf("%s\t%s\t%s\t%s\n","^",$1.name,$4.name,$$.name); 			insert_icg("+",$1.name,$4.name,$$.name);}
	else {printf(" Variable not declared at line no: %d\n", yylineno);exit(0);}}

	| Q {$$.nd=$1.nd;};
	
Q : '('{add('t');} E ')'{add('t'); $$=$3;} | ID {insert_type_table();} G {$$.nd=mknode(NULL,NULL,$1.name);strcpy($$.name,$1.name);}| NUM{add('n');}{$$.nd=mknode(NULL,NULL,$1.name);
	strcpy($$.name,$1.name);} ;


relop : LE {add('r');/*$$.name=$1.name;*/} | GE {add('r');/*$$.name=$1.name;*/}| LT {add('r');/*$$.name=$1.name;*/} | GT {add('r');/*$$.name=$1.name;*/}| EQ {add('r');/*$$.name=$1.name;*/};



%%
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

