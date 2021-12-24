#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
//1 задание
	char words[1000];
	int sign[11] = { 33, 34, 39, 40, 41, 44, 45, 59, 59, 63, 96 };
	cout << "Задание 1 - введите слова:";
	cin.getline(words, 1000, '.');

	cout << "Полученный текст:";
	for (int i = 0; i < strlen(words); i++)//strstrlenen-длина строки(заполненой)
	{
		cout << words[i];
	}
	cout << endl;

	
	//2 задание
	//убрать лишние пробелы
	for (int i = 0; i < strlen(words); i++)//проверка пробелов(программа проверяет знак после пробела, если это очередной пробел - происходит сдвиг влево, пока не останется один пробел)
	{
		if (int(words[i]) == 32)
		{
			while (words[i] == words[i + 1])
			{
				for (int j = i + 1; j < strlen(words); j++)
				{
					words[j] = words[j + 1];
				}
			}
		}
	}
	cout << "Задание 2 - отредактированный текст(без лишних пробелов): ";
	for (int i = 0; i < strlen(words); i++)
	{
		cout << words[i];
	}
	cout << endl;

	//2 убрать лишние знаки препинания 
	for (int i = 0; i < strlen(words); i++)//перебор текста
	{
		for (int j = 0; j < 10; j++)//перебор массива со знаками препинания
		{
			if (int(words[i]) == sign[j])//смотришь является ли знак -знаком препинания,не идет ли опять этот знак (иначе он убирается)
			{
				while (int(words[i]) == int(words[i + 1]))
				{
					for (int k = i + 1; k < strlen(words); k++)
					{
						words[k] = words[k + 1];
					}
				}
			}
		}
	}

	for (int i = 0; i < strlen(words); i++)//возня с точками
	{
		if (int(words[i]) == 46)//если многоточие - проскакивает,если две точки одну убирает
		{
			if (int(words[i]) == int(words[i + 1]) && int(words[i]) == int(words[i + 2]))
			{
				i += 3;
			}
			else
			{
				if (int(words[i]) == int(words[i + 1]))
				{
					for (int l = i + 1; l < strlen(words); l++)
					{
						words[l] = words[l + 1];
					}
				}
			}
		}
	}

	for (int i = 0; i < strlen(words); i++)//если больше точек - то сокращается до 3
	{
		if (int(words[i]) == 46)
		{
			if (int(words[i]) == int(words[i + 1]) && int(words[i]) == int(words[i + 2]) && int(words[i]) == int(words[i + 3]))
			{
				while (int(words[i + 3]) != 32)
				{
					for (int l = i + 1; l < strlen(words); l++)
					{
						words[l] = words[l + 1];
					}
				}
			}
		}
	}
	cout << "Задание 2 - отредактированный текст (без лишних знаков препинания): ";
	for (int i = 0; i < strlen(words); i++)
	{
		cout << words[i];
	}
	cout << endl;

	if (-33 < int(words[0]) && int(words[0]) < 0)//(-32)-(-1)-маленьк буквы (замена мал на болш)
	{
		words[0] = char(int(words[0]) - 32);
	}

	for (int i = 1; i < strlen(words); i++)//(замена болш на мал)
	{
		if (int(words[i]) < -32)
		{
			words[i] = char(int(words[i]) + 32);
		}
	}

	for (int i = 2; i < strlen(words); i++)//болш буквы полсе знаков (!?итп)
	{
		if ((int(words[i - 2]) == 33 || int(words[i - 2]) == 63 || int(words[i - 2]) == 46) && (-33 < int(words[i])) && (int(words[i]) < 0))
		{
			words[i] = char(int(words[i]) - 32);
		}
	}
	cout << "Задание 2 - окончательный вариант исправленного текста:";
	for (int i = 0; i < strlen(words); i++)
	{
		cout << words[i];
	}
	cout << endl;


	int lengthWord = 0;

	cout << "Задание 3 (вар 1) - слова последовательности в обратном порядке: ";
	for (int i = 0; i < strlen(words); i++)//перебор слов
	{
		if (int(words[i]) < 0 || (47 < int(words[i]) && int(words[i]) < 58))//смотрит если ли буквы или цифры,и добавляет 1 к длине слова если находит их
		{
			lengthWord += 1;
		}
		else
		{
			if (lengthWord > 0)//если после слова идет знак препенания - начинает выводить в обратном порядке 
			{
				for (int j = i - 1; j > i - lengthWord - 1; j--)
				{
					cout << words[j];
				}
			}
			cout << words[i];//выводит знак препенания
			lengthWord = 0;
		}

	}
	cout << endl;

	cout << "Задание 4 (вар 1) - замена во всех словах первой буквы соответствующей прописной буквой: ";
	cout << words[0];
	for (int i = 1; i < strlen(words); i++)//если пробел или мал -замена на болш
	{
		if (int(words[i - 1]) == 32 && int(words[i]) < 0 && -33 < int(words[i]))
		{
			cout << char(int(words[i]) - 32);
		}
		else
		{
			cout << words[i];
		}
	}
	cout << endl;


	return 0;
}