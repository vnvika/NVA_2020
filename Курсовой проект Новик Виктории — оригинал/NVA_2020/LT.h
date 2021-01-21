#pragma once
#include "stdafx.h"
#include "IT.h"

#define LEX_SEPARATORS				'S'	// разделители
#define	LEX_ID_TYPE    				't'	// типы данных		
#define	LEX_STDFUNC    				'p'	// стандартные библиотеки		
#define	LEX_ID						'i'	// идентификаторы		
#define	LEX_LITERAL					'l'	// литералы		
#define	LEX_FUNCTION				'f'	// function		
#define	LEX_MAIN					'm'	// main		
#define	LEX_SEPARATOR				';'	// разделитель инструкций
#define	LEX_COMMA					','	// разделитель параметров 		
#define	LEX_LEFTBRACE				'{'	// начало блока		
#define	LEX_BRACELET				'}'	// конец блока		
#define	LEX_SQ_LBRACELET			'['	// начало блока		
#define	LEX_SQ_RBRACELET			']'	// конец блока		
#define	LEX_LEFTHESIS				'('	// начало списка параметров		
#define	LEX_RIGHTTHESIS				')'	// конец списка параметров		
#define	LEX_PLUS					'+'	// сложение	
#define	LEX_MINUS					'-'	// вычитание
#define	LEX_STAR					'*'	// умножение
#define LEX_DIRSLASH				'/'	// деление
#define LEX_PROCENT					'%'	// остаток от делени€
#define	LEX_EQUAL					'='	// присваивание				
#define LEX_IS						'?'	// is
#define LEX_NOT_DOUBLE_QUOTE		'\''// отрицательный идентификатор
#define LEX_WHILE					'c'	// while
#define LEX_ISTRUE					'r'	// ложный блок
#define LEX_ISFALSE					'w'	// истинный блок
#define LEX_DO						'd'	// do
#define LEX_WRITE					'o'	// вывод
#define LEX_NEWLINE					'^'	// вывод с переводом строки
#define LEX_RETURN					'e'	// выход из функции
#define LEX_VOID					'g'	// void
#define LEX_TYPE					'n'	// объ€влени€ переменных
#define LEX_MORE					'>'	// проверка на больше
#define LEX_LESS					'<'	// проверка на меньше
#define LEX_EQUALS					'&'	// проверка на равенство
#define LEX_SUBST					'@'	// вызов функции в польской записи 
#define LEX_NOTEQUALS				'!'	// проверка на неравенство
#define	LEXEMA_FIXSIZE				 1	        //размер лексемы
#define	LT_MAXSIZE					 4096	    //максимальное количество строк в “Ћ
#define	NULLDX_TI					 0xffffffff	//нет элемента “»

namespace LT {
	struct Entry	// строка таблицы лексем
	{
		unsigned char lexema;	// лексема
		int sn;							// номер строки в исходном тексте
		int idxTI;						// индекс в таблице идентификаторов или LT_TI_NULLIDX

		Entry();
		Entry(unsigned char lexema, int snn, int idxti = NULLDX_TI);

	};

	struct LexTable						// экземпл€р таблицы лексем
	{
		int maxsize;					// емкость таблицы лексем < LT_MAXSIZE
		int size;						// текущий размер таблицы лексем < maxsize
		Entry* table;					// массив строк таблицы лексем
	};

	LexTable Create(		// создать таблицу лексем
		int size			// емкость таблицы лексем < LT_MAXSIZE
	);

	void Add(				// добавить строку в таблицу лексем
		LexTable& lextable,	// экземпл€р таблицы лексем
		Entry entry			// строка таблицы лексем
	);

	Entry GetEntry(			// получить строку таблицы лексем
		LexTable& lextable,	// экземпл€р таблицы лексем
		int n				// номер получаемой строки
	);

	void Delete(LexTable& lextable);	// удалить таблицу лексем (освободить пам€ть)

	Entry writeEntry(					// заполнить строку таблицы лексем
		Entry& entry,
		unsigned char lexema,
		int indx,
		int line
	);
	
	void makeOutWithLTFILE(std::ostream* stream, LT::LexTable& table);
	void makeOutWithLT(LT::LexTable& table);
}