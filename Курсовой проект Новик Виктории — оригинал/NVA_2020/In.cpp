#include "stdafx.h"
int In::InWord::size = 0;

namespace In {

	IN getin(wchar_t infile[], std::ostream* stream) {
		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];

		std::ifstream instream(infile);

		if (!instream.is_open())
			throw ERROR_THROW(102);

		IN in;
		int pos = 0;
		int com = 0;
		bool isLiteral = false;
		bool isComments = false;

		while (true)
		{
			unsigned char uch = instream.get();

			if (instream.eof())
				break;
			if (in.code[uch] == IN::Q)					// ������� 
				isLiteral = !isLiteral;
			if (in.code[uch] == IN::COM) {				// �����������
				if (com % 2 == 0)
				{
					isComments = !isComments;
					com++;
				}
				else {
					isComments = !isComments;
					com++;
				}

			}
			switch (in.code[uch])
			{
			case IN::N:									// ����� ������ 
				if (!isComments)
				{
					text[in.size++] = uch;
					in.lines++;
					pos = -1;
				}
				break;
			case IN::T: // ����������� ������ 
			case IN::P: // ������ ���� ���������
			case IN::S: // ������� 
			case IN::Q: // �������
			case IN::QQ: //��������� �������
				if (!isComments)
					text[in.size++] = uch;
				break;
			case IN::F: // ������������ ������ � �������� �����
				Log::WriteError(stream, Error::GetError(200, in.lines, pos));
				in.ignor++;
				break;
			case IN::I:// ������������ ������ 
				in.ignor++;
				break;
			}
			pos++;
		}
		text[in.size] = IN_CODE_NULL;
		in.text = text;
		instream.close(); // ������� ����� 
		return in;
	}
	void addWord(InWord* words, char* word, int line)					// �������� ����� � �������
	{
		if (*word == IN_CODE_NULL)
			return;
		words[words->size].line = line;
		strcpy_s(words[words->size].word, strlen(word) + 1, word);
		words->size++;
	}
	InWord* getWordsTable(std::ostream* stream, unsigned char* text, int* code, int textSize)
	{
		InWord* words = new InWord[LT_MAXSIZE];		//�����
		words->size = 0;
		int bufpos = 0;								// ������� � ������
		int line = 1;								// ����� ������ ��������� ����
		bool flagminus = false;
		bool flagplus;
		char buffer[MAX_LEN_BUFFER] = "";			// �����
		for (int i = 0; i < textSize; i++)			// ����������
		{
			switch (code[text[i]])
			{
			case IN::S:
			{
				if (text[i] == LEX_MINUS && isdigit(text[i + 1])
					|| text[i] == LEX_MINUS && words[words->size - 1].word[0] == '='
					|| (text[i] == LEX_MINUS && text[i + 1] == LEX_MINUS && line > words[words->size - 1].line))
				{
					if (*buffer != IN_CODE_NULL)
					{
						addWord(words, buffer, line);
						*buffer = IN_CODE_NULL;  bufpos = 0;
					}
					if (text[i + 1] == LEX_MINUS && words[words->size - 1].line > words[words->size - 2].line)
					{
						buffer[bufpos++] = ':';
						buffer[bufpos++] = text[i];
						buffer[bufpos] = IN_CODE_NULL;
						addWord(words, buffer, line);	// ����� ����� �������������� ��������
						*buffer = IN_CODE_NULL;
						bufpos = 0;
						i++;
						break;
					}
					if (isdigit(words[words->size - 1].word[strlen(words[words->size - 1].word) - 1])
						|| words[words->size - 1].word[0] == ')'
						|| isalpha(words[words->size - 1].word[strlen(words[words->size - 1].word) - 1])
						|| isalpha(text[i + 1])
						)
					{
						buffer[bufpos++] = text[i];
						buffer[bufpos] = IN_CODE_NULL;
						addWord(words, buffer, line);	// ����� ����� �������������� ��������
						*buffer = IN_CODE_NULL;
						bufpos = 0;
						break;
					}
					buffer[bufpos++] = text[i];
					buffer[bufpos] = IN_CODE_NULL;
					break;
				}
				if ((text[i] == LEX_PLUS && text[i + 1] == LEX_PLUS)
					|| (text[i] == LEX_STAR && text[i + 1] == LEX_STAR)
					|| (text[i] == LEX_DIRSLASH && text[i + 1] == LEX_DIRSLASH))
				{
					if (*buffer != IN_CODE_NULL)
					{
						addWord(words, buffer, line);
						*buffer = IN_CODE_NULL;  bufpos = 0;
					}
					buffer[bufpos++] = ':';
					buffer[bufpos++] = text[i];
					buffer[bufpos] = IN_CODE_NULL;
					addWord(words, buffer, line);	// ����� ����� �������������� ��������
					*buffer = IN_CODE_NULL;
					bufpos = 0;
					i++;
					break;
				}
				char letter[] = { (char)text[i], IN_CODE_NULL };
				addWord(words, buffer, line);	// ����� ����� �������������� ��������
				addWord(words, letter, line);	// ���� �������������� �������
				*buffer = IN_CODE_NULL;
				bufpos = 0;
				break;
			}
			case IN::N:											//����� ������
			case IN::P:											// ����������� � �������
				if (*buffer == '-' && strlen(buffer) == 1)
					break;
				else
				{
					addWord(words, buffer, line);
					*buffer = IN_CODE_NULL;
					bufpos = 0;
				}
				if (code[text[i]] == IN::N)
					line++;
				break;
			case IN::QQ:
			{
				addWord(words, buffer, line);
				*buffer = IN_CODE_NULL;
				bufpos = 0;
				buffer[bufpos++] = IN_CODE_NOT_DOUBLE_QUOTE;
				if (text[i + 1] == IN::N)
				{
					Log::WriteError(stream, Error::GetError(311, line, 0));
					break;
				}
				buffer[bufpos++] = text[++i];
				if (text[i + 1] != IN_CODE_NOT_DOUBLE_QUOTE)
				{
					Log::WriteError(stream, Error::GetError(312, line, 0));
					break;
				}
				buffer[bufpos++] = text[++i];
				buffer[bufpos] = IN_CODE_NULL;
				addWord(words, buffer, line);
				*buffer = IN_CODE_NULL;  bufpos = 0;
				break;
			}
			case IN::Q:		// ��������� �������
			{
				addWord(words, buffer, line);
				*buffer = IN_CODE_NULL;
				bufpos = 0;
				bool isltrlgood = true;
				// ���� ������� �� ������ - ������� ������ ����� ������ �������
				for (int j = i + 1; text[j] != IN_CODE_QUOTE; j++)
				{
					if (code[text[j]] == IN::N)
					{
						Log::WriteError(stream, Error::GetError(311, line, 0));
						isltrlgood = false; // ������� �� ������!
						break;
					}
				}
				if (isltrlgood)
				{
					buffer[bufpos++] = IN_CODE_QUOTE;
					for (int j = 1; ; j++)
					{
						if (j == 256 || i + j == textSize)
						{
							Log::WriteError(stream, Error::GetError(312, line, 0));
							break; // �������� ������ ��������(������ ���� �������)
						}
						buffer[bufpos++] = text[i + j];
						if (text[i + j] == IN_CODE_QUOTE) // ����������� �������
						{
							buffer[bufpos] = IN_CODE_NULL;
							addWord(words, buffer, line);
							i = i + j;
							break;
						}
					}
				} // literal good
				*buffer = IN_CODE_NULL;  bufpos = 0;
				break;
			}
			default:
				buffer[bufpos++] = text[i];
				buffer[bufpos] = IN_CODE_NULL;
			}
		}
		return words;
	}
	void printTable(InWord* table)								// ����� ������� �� �����
	{
		std::cout << "\n\n ------------------ ������� ���� ------------------" << std::endl;
		std::cout << std::setw(2) << "�"  << std::setw(2) << "������: "<< std::endl;
		for (int i = 0; i < table->size; i++)
			std::cout << std::setw(2) << i << std::setw(3) << table[i].line << " |  " << table[i].word << std::endl;
		std::cout << table->size;
	}
}