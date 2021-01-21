#pragma once
#include "IT.h"
#include "LT.h"
#include "stdafx.h"

#define TYPE_INTEGER	"integer"
#define TYPE_STRING		"string"
#define TYPE_SYMBOL		"symbol"
#define RANDOM			"random"
#define TYPE_VOID		"void"
#define MAIN			"main"
#define POW				"pow"
#define LENGHT			"lenght"

#define ISTYPE(str) ( !strcmp(str, TYPE_INTEGER) || !strcmp(str, TYPE_STRING) )

namespace Lex
{
	struct LEX
	{
		LT::LexTable lextable;
		IT::IdTable	idtable;
		LEX() {}
	};
	struct Graph
	{
		char lexema;
		FST::FST graph;
	};
	IT::Entry* getEntry		// ��������� � ���������� ������ ��
	(
		Lex::LEX& tables,						// �� + ��
		char lex,								// �������
		char* id,								// �������������
		char* idtype,							// ���������� (���)
		bool isParam,							// ������� ��������� �������
		bool isFunc,							// ������� �������
		Log::LOG log,							// ��������
		int line,								// ������ � �������� ������
		bool& rc_err							// ���� ������(�� ������)
	);

	struct ERROR_S									// ��� ���������� ��� throw ERROR_THROW | ERROR_THROW_IN
	{
		int id;
		char message[ERROR_MAXSIZE_MESSAGE];			// ���������			
		struct
		{
			short line = -1;						//����� ������ (0, 1, 2, ...)
			short col = -1;						    //����� ������� � ������(0, 1, 2, ...)
		} position;
	};

	bool analyze(LEX& tables, In::IN& in, Log::LOG& log, Parm::PARM& parm);
	int getIndexInLT(LT::LexTable& lextable, int itTableIndex);					// ������ ������ ������� � ������� ������
};