#pragma once
#include "stdafx.h"
#define SEPSTREMP  "\n;------------------------------\n"
#define SEPSTR(x)  "\n;----------- " + string(x) + " ------------\n"


#define BEGIN ".586\n"\
".model flat, stdcall\n"\
"includelib libucrt.lib\n"\
"includelib kernel32.lib\n"\
"includelib \"..\\Debug\\NVAlib.lib\"\n"\
"ExitProcess PROTO:DWORD \n"\
".stack 4096\n"

#define END "call system_pause"\
				"\npush 0"\
				"\ncall ExitProcess"\
				"\nSOMETHINGWRONG:"\
				"\npush offset null_division"\
				"\ncall outstrline\n"\
				"call system_pause"\
				"\npush -1"\
				"\ncall ExitProcess"\
				"\nEXIT_OVERFLOW:"\
				"\npush offset overflow"\
				"\ncall outstrline\n"\
				"call system_pause"\
				"\npush -2"\
				"\ncall ExitProcess"\
				"\nmain ENDP\nend main"


#define EXTERN "\n outnum PROTO : DWORD\n"\
"\n outstr PROTO : DWORD\n"\
"\n outstrline PROTO : DWORD\n"\
"\n outnumline PROTO : DWORD\n"\
"\n system_pause PROTO \n"\
"\n random PROTO  : DWORD\n"\
"\n lenght PROTO  : DWORD\n"\
"\n power PROTO : DWORD, : DWORD\n"


#define ITENTRY(x)  lex.idtable.table[lex.lextable.table[x].idxTI]
#define LEXEMA(x)   lex.lextable.table[x].lexema


namespace Gener
{
	bool CodeGeneration(Lex::LEX& tables, Parm::PARM& parm, Log::LOG& log);
};