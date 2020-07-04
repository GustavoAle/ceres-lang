number  [0-9]
alpha   [a-zA-Z]
hex     [a-fA-F0-9]
octa    [0-7]
bin     [0-1]
exp     [Ee][+-]?{number}+

%{
#include <string.h>
#include <include/ast.h>
#include <include/tokens.h>
#include <include/symbols.h>
#include <include/compiler.h>

#include <compiler.tab.h>
%}

%%

"/*"        { parse_comment_block(); }

"__asm"     { return ASM; }
"auto"      { return AUTO; }
"bool"      { return BOOL; }
"break"     { return BREAK; }
"byte"      { return BYTE; }
"class"     { return CLASS; }
"const"     { return CONST; }
"double"    { return DOUBLE; }
"else"      { return ELSE; }
"float"     { return FLOAT;}
"for"       { return FOR; }
"fun"       { return FUNCTION; }
"function"  { return FUNCTION; }
"if"        { return IF; }
"int"       { return INT; }
"local"     { return LOCAL; }
"long"      { return LONG; }
"loop"      { return LOOP; }
"mem"       { return POINTER; }
"pointer"   { return POINTER; }
"protected" { return PROTECTED; }
"public"    { return PUBLIC; }
"reg"       { return REGISTER; }
"register"  { return REGISTER; }
"return"    { return RETURN; }
"scope"     { return SCOPE; }
"shared"    { return SHARED; }
"signed"    { return SIGNED; }
"sizeof"    { return SIZEOF; }
"static"    { return STATIC; }
"sub"       { return SUB; }
"tuple"     { return TUPLE; }
"type"      { return TYPE; }
"unsigned"  { return UNSIGNED; }
"var"       { return AUTO; }
"while"     { return WHILE; }

 /* treat identifiers @TBI */
{alpha}({number}|{alpha})* {
    yylval.symbol_name = strdup(yytext);
    return IDENTIFIER;
}

 /* treat string surronded by double quote */
(\")[^(\")\n]*(\") {
    yylval.string_value = strdup(yytext);
    return STRING_LITERAL;
}

 /* treat char constant */
(\')[^(\')\n](\') {
    yylval.long_value = *(yytext+1);
    return LONG_CONSTANT;
}

 /* ignore white spaces and tabs */
[ \t] ;

 /* treat hexadecimal constants */
[0'][xX]{hex}+ {
    yylval.long_value = strtol(yytext+2,NULL,16);
    return LONG_CONSTANT;
}

 /* treat binary constants */
[0']b{bin}+ {
    yylval.long_value = strtol(yytext+2,NULL,2);
    return LONG_CONSTANT;
}

 /* treat octal constants */
[0']{octa}+ {
    yylval.long_value = strtol(yytext+1,NULL,8);
    return LONG_CONSTANT;
}

 /* treat long constants */
{number}+ {
    yylval.long_value = strtol(yytext,NULL,10);
    return LONG_CONSTANT;
}

 /* treat double constants */
{number}*(\.){number}+{exp}?"L" {
    yylval.double_value = strtod(yytext,NULL);
    return DOUBLE_CONSTANT;
}

{number}+(\.){number}*{exp}?"L" {
    yylval.double_value = strtod(yytext,NULL);
    return DOUBLE_CONSTANT;
}

 /* treat float constants */
{number}*(\.){number}+{exp}? {
    yylval.float_value = strtof(yytext,NULL);
    return FLOAT_CONSTANT;
}

{number}+(\.){number}*{exp}? {
    yylval.float_value = strtof(yytext,NULL);
    return FLOAT_CONSTANT;
}

 /** Bitwise assign */
">>="       { return ARSH_OP; } 
"<<="       { return ALSH_OP; }
"&="        { return AAND_OP; }
"|="        { return AOR_OP;  }
"^="        { return AXOR_OP; }
">>"        { return RSH_OP;  }
"<<"        { return LSH_OP;  }

 /** Relational */
"=="        { return EQ_OP;   }
"!="        { return NE_OP;   }
">="        { return GE_OP;   }
"<="        { return LE_OP;   }

 /** Arithmetic assing */
"+="        { return AADD_OP; }
"-="        { return ASUB_OP; }
"/="        { return ADIV_OP; }
"*="        { return AMUL_OP; }
"%="        { return AMOD_OP; }
"++"        { return INC_OP;  }
"--"        { return DEC_OP;  }

 /** Logical */
"&&"        { return LAND_OP; } 
"||"        { return LOR_OP;  }

 /** Multi-purpose operators */ 
"="         { return ('='); }
"+"         { return ('+'); }     
"-"         { return ('-'); }
"/"         { return ('/'); }
"*"         { return ('*'); }
"%"         { return ('%'); }

"&"         { return ('&'); }
"|"         { return ('|'); }
"^"         { return ('^'); }

";"         { return (';'); }
":"         { return (':'); }
"."         { return ('.'); }
","         { return (','); }


"<"         { return ('<'); }
">"         { return ('>'); }

"$"         { return ('$'); }
"#"         { return ('#'); }
"@"         { return ('@'); }

"["         { return ('['); }
"]"         { return (']'); }

 /** This guys messes with the linter, 
 so I'll leave them here*/
"("         { return ('('); }
")"         { return (')'); }
"{"         { return ('{'); }
"}"         { return ('}'); }
"?"         { return ('?'); }

[ \t\n] ;

%%
