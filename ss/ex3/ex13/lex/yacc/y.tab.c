#ifndef lint
static char const 
yyrcsid[] = "$FreeBSD: src/usr.bin/yacc/skeleton.c,v 1.28 2000/01/17 02:04:06 bde Exp $";
#endif
#include <stdlib.h>
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYLEX yylex()
#define YYEMPTY -1
#define yyclearin (yychar=(YYEMPTY))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING() (yyerrflag!=0)
static int yygrowstack();
#define YYPREFIX "yy"
#line 2 "calc.yacc"
#include <stdio.h>

int regs[26];
int base;

#line 23 "y.tab.c"
#define YYERRCODE 256
#define DIGIT 257
#define LETTER 258
#define UMINUS 259
const short yylhs[] = {                                        -1,
    0,    0,    0,    1,    1,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    3,    3,
};
const short yylen[] = {                                         2,
    0,    3,    3,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    2,
};
const short yydefred[] = {                                      1,
    0,    0,   17,    0,    0,    0,    0,    0,    0,    3,
    0,   15,   14,    0,    2,    0,    0,    0,    0,    0,
    0,    0,   18,    0,    6,    0,    0,    0,    0,    7,
    8,    9,
};
const short yydgoto[] = {                                       1,
    7,    8,    9,
};
const short yysindex[] = {                                      0,
  -40,   -7,    0,  -55,  -38,  -38,    1,  -29, -247,    0,
  -38,    0,    0,   22,    0,  -38,  -38,  -38,  -38,  -38,
  -38,  -38,    0,  -29,    0,   51,   60,  -20,  -20,    0,
    0,    0,
};
const short yyrindex[] = {                                      0,
    0,    0,    0,    2,    0,    0,    0,    9,   -9,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   10,    0,   -6,   14,    5,   13,    0,
    0,    0,
};
const short yygindex[] = {                                      0,
    0,   65,    0,
};
#define YYTABLESIZE 220
const short yytable[] = {                                       6,
   16,    6,   10,   13,    5,   11,    5,   22,   17,   23,
   15,   15,   20,   18,   10,   19,   22,   21,    4,    5,
    0,   20,   11,   12,    0,    0,   21,   16,   16,    0,
    0,   16,   16,   16,   13,   16,    0,   16,   15,   15,
    0,    0,   10,   15,   15,   10,   15,   10,   15,   10,
   11,   12,    0,   11,   12,   11,    0,   11,   22,   17,
    0,    0,   25,   20,   18,    0,   19,    0,   21,   13,
   14,    0,    0,    0,    0,   24,    0,    0,    0,    0,
   26,   27,   28,   29,   30,   31,   32,   22,   17,    0,
    0,    0,   20,   18,   16,   19,   22,   21,    0,    0,
    0,   20,   18,    0,   19,    0,   21,    0,    0,    0,
    0,    0,    0,    0,   16,    0,    0,   13,    0,    0,
    0,    0,    0,    0,    0,   15,    0,    0,   10,    0,
    0,    0,    0,    0,    0,    0,   11,   12,    0,    0,
    0,    0,    0,    0,    0,   16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,    4,    3,   12,
};
const short yycheck[] = {                                      40,
   10,   40,   10,   10,   45,   61,   45,   37,   38,  257,
   10,   10,   42,   43,   10,   45,   37,   47,   10,   10,
   -1,   42,   10,   10,   -1,   -1,   47,   37,   38,   -1,
   -1,   41,   42,   43,   41,   45,   -1,   47,   37,   38,
   -1,   -1,   38,   42,   43,   41,   45,   43,   47,   45,
   38,   38,   -1,   41,   41,   43,   -1,   45,   37,   38,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,    5,
    6,   -1,   -1,   -1,   -1,   11,   -1,   -1,   -1,   -1,
   16,   17,   18,   19,   20,   21,   22,   37,   38,   -1,
   -1,   -1,   42,   43,  124,   45,   37,   47,   -1,   -1,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  257,  258,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 259
#if YYDEBUG
const char * const yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"DIGIT","LETTER","UMINUS",
};
const char * const yyrule[] = {
"$accept : list",
"list :",
"list : list stat '\\n'",
"list : list error '\\n'",
"stat : expr",
"stat : LETTER '=' expr",
"expr : '(' expr ')'",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '-' expr",
"expr : LETTER",
"expr : number",
"number : DIGIT",
"number : number DIGIT",
};
#endif
#ifndef YYSTYPE
typedef int YYSTYPE;
#endif
#if YYDEBUG
#include <stdio.h>
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH 10000
#endif
#endif
#define YYINITSTACKSIZE 200
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short *yyss;
short *yysslim;
YYSTYPE *yyvs;
int yystacksize;
#line 111 "calc.yacc"
main()
{
 return(yyparse());
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}
#line 193 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack()
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;
    i = yyssp - yyss;
    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :
      (short *)malloc(newsize * sizeof *newss);
    if (newss == NULL)
        return -1;
    yyss = newss;
    yyssp = newss + i;
    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :
      (YYSTYPE *)malloc(newsize * sizeof *newvs);
    if (newvs == NULL)
        return -1;
    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab

#ifndef YYPARSE_PARAM
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG void
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif	/* ANSI-C/C++ */
#else	/* YYPARSE_PARAM */
#ifndef YYPARSE_PARAM_TYPE
#define YYPARSE_PARAM_TYPE void *
#endif
#if defined(__cplusplus) || __STDC__
#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else	/* ! ANSI-C/C++ */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;
#endif	/* ANSI-C/C++ */
#endif	/* ! YYPARSE_PARAM */

int
yyparse (YYPARSE_PARAM_ARG)
    YYPARSE_PARAM_DECL
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate])) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
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
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
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
#if defined(lint) || defined(__GNUC__)
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#if defined(lint) || defined(__GNUC__)
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 3:
#line 26 "calc.yacc"
{
           yyerrok;
         }
break;
case 4:
#line 32 "calc.yacc"
{
           printf("%d\n",yyvsp[0]);
         }
break;
case 5:
#line 37 "calc.yacc"
{
           regs[yyvsp[-2]] = yyvsp[0];
         }
break;
case 6:
#line 44 "calc.yacc"
{
           yyval = yyvsp[-1];
         }
break;
case 7:
#line 49 "calc.yacc"
{
           yyval = yyvsp[-2] * yyvsp[0];
         }
break;
case 8:
#line 54 "calc.yacc"
{
           yyval = yyvsp[-2] / yyvsp[0];
         }
break;
case 9:
#line 59 "calc.yacc"
{
           yyval = yyvsp[-2] % yyvsp[0];
         }
break;
case 10:
#line 64 "calc.yacc"
{
           yyval = yyvsp[-2] + yyvsp[0];
         }
break;
case 11:
#line 70 "calc.yacc"
{
           yyval = yyvsp[-2] - yyvsp[0];
         }
break;
case 12:
#line 75 "calc.yacc"
{
           yyval = yyvsp[-2] & yyvsp[0];
         }
break;
case 13:
#line 80 "calc.yacc"
{
           yyval = yyvsp[-2] | yyvsp[0];
         }
break;
case 14:
#line 86 "calc.yacc"
{
           yyval = -yyvsp[0];
         }
break;
case 15:
#line 91 "calc.yacc"
{
           yyval = regs[yyvsp[0]];
         }
break;
case 17:
#line 100 "calc.yacc"
{
           yyval = yyvsp[0];
           base = (yyvsp[0]==0) ? 8 : 10;
         }
break;
case 18:
#line 105 "calc.yacc"
{
           yyval = base * yyvsp[-1] + yyvsp[0];
         }
break;
#line 479 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
