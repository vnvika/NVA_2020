#pragma once
#include "stdafx.h"

#define IN_MAX_LEN_TEXT 1024*1024				//������������ ������ ��������� ���� = 1��
#define IN_CODE_ENDL '\n'						//������ ����� ������
#define FREE_SPACE ' '
#define SEPARATOR '|'
#define IN_CODE_QUOTE '\"'
#define IN_CODE_NULL  '\0'

#define MAX_LEN_BUFFER  2048
#define IN_CODE_NOT_DOUBLE_QUOTE	'\''


//������� �������� ������� ����������, ������ = ��� (Windows -1251) �������
//�������� IN::F -  ����������� ������, IN::T - ����������� ������, IN::I - ������������ ( �� �������), E - ���������, L - ��������, S - ������
// ���� 0 <- �������� < 256 - �� �������� ������ ��������


#define IN_CODE_TABLE {\
/*   0  |    1  |   2  |   3  |    4  |   5  |   6  |  7  |     8  |   9  |   A  |  B  |      C  |   D  |   E  |   F  | */\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::P, IN::N, IN::F,  IN::F, IN::F, IN::F, IN::F, /*0*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*1*/\
	IN::P, IN::S, IN::Q, IN::T,  IN::COM,IN::S,IN::S, IN::QQ,   IN::S, IN::S, IN::S, IN::S,  IN::S, IN::S, IN::T, IN::S, /*2*/\
	IN::T, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T,   IN::T, IN::T, IN::T, IN::S,  IN::S, IN::S, IN::S, IN::T, /*3*/\
	IN::T, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T,   IN::T, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T, /*4*/\
	IN::T, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T,   IN::T, IN::T, IN::T, IN::S,  IN::F, IN::S, IN::T, IN::T, /*5*/\
	IN::F, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T,   IN::T, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T, /*6*/\
	IN::T, IN::T, IN::T, IN::T,  IN::T, IN::T, IN::T, IN::T,   IN::T, IN::T, IN::T, IN::S,  IN::T, IN::S, IN::T, IN::T,/*7*/\
	\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*8*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*9*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*A*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*B*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*C*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*D*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F, /*E*/\
	IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F,   IN::F, IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F, IN::F  /*F*/\
}

namespace In
{
	struct InWord
	{
		char word[MAX_LEN_BUFFER];	// �����
		int line;		// ������ � �������� ������
		static int size;// ���������� ����
	};
	struct IN
	{
		/*
		S - ( ) [ ] # < > ! & * + - = , ;
		P - ������, ���������
		N - ����� ������
		F - �����������
		T - �����������
		I - ������������
		Q - "
		QQ - '
		COM - �����������
		*/
		enum { T = 1024, F = 2048, I = 4096, S, Q, P, N, QQ, K, COM };
		int size = 0;
		int lines = 1;
		int ignor = 0;
		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];	
		int code[256] = IN_CODE_TABLE;									//������� �������� I,T,F ����� ��������
		int positionArr;
		InWord* words;
	};

	struct Flags {
		bool flag_space = false;
		bool flag_expression = false;
		bool flag_literal = false;
		bool flag_separator = false;
		bool _literal = false;
	};

	IN getin(wchar_t infile[], std::ostream* stream);
	void addWord(InWord* words, char* word, int line);
	InWord* getWordsTable(std::ostream* stream, unsigned char* text, int* code, int textSize);
	void printTable(InWord* table);
}