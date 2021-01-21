#pragma once
#include "stdafx.h"
#include "IT.h"
#include "LT.h"
#define ID_MAXSIZE			9						//макс число символов идентификатора
#define SCOPED_ID_MAXSIZE   (ID_MAXSIZE*2-1)		//макс число символов идентификатор + область видимости
#define MAXSIZE_TI			4096					//макс число количество строк в таблице идентификаторов
#define TI_INT_DEFAULT		0x00000000				//значение по умолчанию для integer
#define TI_STR_DEFAULT		0x00					//значение по умолчанию для sting
#define TI_SYM_DEFAULT		0x00					//значение по умолчанию для symbol;
#define TI_NULLIDX			0xffffffff				//нет элемента таблицы идентификаторов
#define STR_MAXSIZE			255						//максимальная длина строкового литерала
#define TI_INT_MAXSIZE		 2147483647				//максимальное значение для типа integer
#define TI_INT_MINSIZE		-2147483647				//минимальное значение для типа integer
#define MAX_PARAMS_COUNT	5			   			//максимальное количество параметров у функции
#define POW_PARAMS_CNT		2						//кол-во параметров у функции pow
#define RANDOM_PARAMS_CNT	1						//кол-во параметров у функции rand
#define LENGHT_PARAMS_CNT	1						//кол-во параметров у функции lenght
#define RANDOM_TYPE			IT::IDDATATYPE::INT
#define POW_TYPE			IT::IDDATATYPE::INT
#define LENGHT_TYPE			IT::IDDATATYPE::INT

namespace IT {
	enum IDDATATYPE { INT = 1, STR = 2, SYM = 3, PROC = 4, UNDEF };									//типы данных идентификаторов: числовой, строковый,символьный неопределенный
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5, Z = 6 };										//типы идентификаторов: V = переменная, F = функция, P =параметр, L =литерал, S = стандартная функция Z - знак
	enum STDFNC { F_POW, F_POWER, F_RANDOM, F_LENGTH, F_NOT_STD };									//стандартные функции

	static const IDDATATYPE POW_PARAMS[] = { IT::IDDATATYPE::INT, IT::IDDATATYPE::INT };			//параметры функции  
	static const IDDATATYPE RANDOM_PARAMS[] = { IT::IDDATATYPE::INT };								//параметры функции  			
	static const IDDATATYPE LENGHT_PARAMS[] = { IT::IDDATATYPE::STR };								//параметры функции length
	

	struct Entry	// строка таблицы идентификаторов
	{
		int			idxfirstLE;			// индекс первой строки в таблице лексем
		char	id[SCOPED_ID_MAXSIZE];		// индентификатор (автоматически усекается до ID_MAXSIZE)
		IDDATATYPE	iddatatype;			// тип данных
		IDTYPE		idtype;				// тип идентификатора

		union
		{
			int vint;					// значение integer
			struct
			{
				int len;							// количество символов в string
				char str[STR_MAXSIZE - 1];	// символы string
			} vstr;									// значение string
			char symbol;							//значение symbol
			struct
			{
				int count;					// количество параметров функции
				IDDATATYPE* types;			//типы параметров функции
			} params;
		} value;		// значение идентификатора

		Entry()							//конструктор без параметров
		{
			this->value.vint = TI_INT_DEFAULT;
			this->value.vstr.len = NULL;
			this->value.params.count = NULL;
			this->value.symbol = NULL;
		};
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype) //конструктор с параметрами
		{
			strncpy_s(this->id, id, SCOPED_ID_MAXSIZE - 1);
			this->idxfirstLE = idxLT;
			this->iddatatype = datatype;
			this->idtype = idtype;
		};
	};

	struct IdTable				// экземпляр таблицы идентификаторов
	{
		int maxsize;			// емкость таблицы идентификаторов < TI_MAXSIZE
		int size;				// текущий размер таблицы идентификаторов < maxsize
		Entry* table;			// массив строк таблицы идентификаторов
	};

	IdTable Create(int size);		// емкость таблицы идентификаторов < TI_MAXSIZE// создать таблицу идентификаторов

	void Add(				// добавить строку в таблицу идентификаторов
		IdTable& idtable,	// экземпляр таблицы идентификаторов
		Entry entry			// строка таблицы идентификаторов
	);
	int isId(				// возврат: номер строки (если есть), TI_NULLIDX (если нет)
		IdTable& idtable,	// экземпляр таблицы идентификаторов
		char id[SCOPED_ID_MAXSIZE]	// идентификатор
	);
	bool SetValue(IT::Entry* entry, char* value);	//задать значение идентификатора
	bool SetValue(IT::IdTable& idtable, int index, char* value);
	void makeOutWithIT(IT::IdTable& idtable);
}