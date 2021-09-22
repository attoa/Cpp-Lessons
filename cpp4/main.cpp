#include <locale>
#include <iostream>
using namespace std;


/*** ОБРАБОТКА СИМВОЛЬНЫХ МАССИВОВ-СТРОК. ФУНКЦИИ. ДИНАМИЧЕСКАЯ ПАМЯТЬ. ***/


// ПРОСТОЙ ПАЛИНДРОМ. 1. Выполнить проверку: является ли строка палиндромом (перевертышем) с учетом 
// всех символов, включая пробелы. 2. Реализовать проверку в виде функции.
// Пример простого палиндрома: «ААА 123 ххММхх 321 ААА»
/*
// Вариант без функции
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];				//Строка
	size_t len;					//Длина строки
	bool isPalindrome = true;	//Является ли строка палиндромом

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	//Определение длины строки
	for (len = 0; str[len] != '\0'; len++);

	for (int i = 0; i < len / 2 && isPalindrome; i++)
		if (str[i] != str[len - 1 - i])
			isPalindrome = false;

	isPalindrome ? cout << "Строка является палиндромом" 
		: cout << "Строка не является палиндромом";
	cout << endl;

	system("pause");
}
*/
/*
//Вариант с отдельной функцией
bool checkForPalindrome(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];	//Строка

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	checkForPalindrome(str) ? cout << "Строка является палиндромом"
		: cout << "Строка не является палиндромом";
	cout << endl;

	system("pause");
}

bool checkForPalindrome(const char str[])
{
	size_t len;		//Длина строки

	//Определение длины строки
	for (len = 0; str[len] != '\0'; len++);

	for (int i = 0; i < len / 2; i++)
		if (str[0 + i] != str[len - 1 - i])
			return false;

	return true;
}
*/


// ПОИСК СТРОКИ В МАССИВЕ. 
// Задан массив строк: char Name[][20] = {"String1", "String2", "String3", "String4"}. Программа 
// должна определять, содержится ли в этом массиве строка, дополнительно введенная пользователем.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	char Name[][20] = { "String1", "String2", "String3", "String4" };	//Массив строк
	char searchStr[100];		//Искомая строка
	bool isContained = false;	//Содержится в массиве искомая строка

	cout << "Искомая строка: ";
	cin.getline(searchStr, sizeof(Name));

	for (int i = 0; i < sizeof(Name) && !isContained; i++)
	{
		char* pName = Name[i];
		char* pSearchStr = searchStr;

		while (*pName != '\0' && *pSearchStr != '\0')
		{
			if (*pName == *pSearchStr)
				pSearchStr++;
			else
				pSearchStr = searchStr;

			pName++;
		}

		if (*pSearchStr == '\0')
			isContained = true;
	}

	isContained ? cout << "Введенная строка содержится в массиве"
		: cout << "Введенная строка не содержится в массиве";
	cout << endl;

	system("pause");
}
*/


// СПИСОК. Вводится список фамилий N работников и их стаж (фамилии должны быть размещены в массиве 
// строк, а значения стажа - в элементах целочисленного массива). Необходимо, чтобы программа 
// могла выполнять одно из трех действий: а) по введенной после заполнения справочника фамилии 
// работника определяла его стаж; б) по введенному стажу определяла перечень фамилий с таким 
// стажем; в) выводила список фамилий с наибольшим стажем.
/*
//Вариант без функций
void main()
{
	setlocale(LC_ALL, "Russian");

	const size_t SIZE = 6;	//Кол-во работников
	char surnames[SIZE][20] = { "Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Smirnov", "Popov" };
	int experiences[SIZE] = { 2, 4, 2, 3, 4, 8 };

	int actNum;		//Номер действия

	cout << "Действие: " << endl
		<< "1. Определить по введенной фамилии стаж работника" << endl
		<< "2. Определить по введенному стажу перечень фамилий с таким стажем" << endl
		<< "3. Вывести список фамилий с наибольшим стажем" << endl;

	cin >> actNum; getchar();

	switch (actNum)
	{
		case 1:
		{
			const size_t surnameLen = sizeof(surnames[0]);	//Максимальная длина фамилии
			char surname[surnameLen];	//Фамилия работника
			int workerNum;				//Номер работника в списке

			cout << "Фамилия работника: ";
			cin.getline(surname, surnameLen);

			//Перебор массива фамилий
			for (workerNum = 0; workerNum < SIZE; workerNum++)
			{
				bool isFound = true;	//Найдена ли фамилия в списке

				//Посимволное сравнение фамилии из списка и введенной фамилии
				for (int j = 0; j < surnameLen && surname[j] != '\0' && surnames[workerNum][j] != '\0'; j++)
					if (surname[j] != surnames[workerNum][j])
						isFound = false;

				if (isFound)
					break;
			}

			if (workerNum != SIZE)
				cout << "Стаж работника: " << experiences[workerNum] << endl;
			else
				cout << "Работник не найден" << endl;

			break;
		}
		case 2:
		{
			int experience;			//Стаж работника
			int workerNum;			//Номер работника в списке
			bool isFound = false;	//Найден ли стаж в списке

			cout << "Стаж работника: ";
			cin >> experience;

			//Перебор массива стажей
			for (workerNum = 0; workerNum < SIZE; workerNum++)
			{
				if (experience == experiences[workerNum])
				{
					cout << "Фамилия работника: " << surnames[workerNum] << endl;
					isFound = true;
				}
			}

			if (!isFound)
				cout << "Работник не найден" << endl;

			break;
		}
		case 3:
		{
			int averageExperience;		//Средний стаж работников
			int sumExperiences = 0;		//Сумма стажей работников

			for (int i = 0; i < SIZE; i++)
				sumExperiences += experiences[i];

			averageExperience = sumExperiences / SIZE;

			for (int i = 0; i < SIZE; i++)
				if (experiences[i] > averageExperience)
					cout << "Фамилия: " << surnames[i] << ", стаж: " << experiences[i] << endl;

			break;
		}
	}

	system("pause");
}
*/
/*
//Вариант с функциями
#define SURNLEN 20	//Максимальная длина фамилии
void printExpBySurname(const char surnames[][SURNLEN], const int experiences[], const size_t size, const char surname[]);
void printSurnamesByExp(const char surnames[][SURNLEN], const int experiences[], const size_t size, const int experience);
void printSurnamesWithMaxExp(const char surnames[][SURNLEN], const int experiences[], const size_t size);

void main()
{
	setlocale(LC_ALL, "Russian");

	const size_t SIZE = 6;	//Кол-во работников
	char surnames[SIZE][SURNLEN] = { "Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Smirnov", "Popov" };
	int experiences[SIZE] = { 2, 4, 2, 3, 4, 8 };

	int actNum;		//Номер действия
	
	cout << "Действие: " << endl
		<< "1. Определить по введенной фамилии стаж работника" << endl
		<< "2. Определить по введенному стажу перечень фамилий с таким стажем" << endl
		<< "3. Вывести список фамилий с наибольшим стажем" << endl;

	cin >> actNum; getchar();

	switch (actNum)
	{
		case 1:
		{
			char surname[SURNLEN];	//Фамилия работника

			cout << "Фамилия работника: ";
			cin.getline(surname, SURNLEN);

			printExpBySurname(surnames, experiences, SIZE, surname);

			break;
		}
		case 2:
		{
			int experience;			//Стаж работника

			cout << "Стаж работника: ";
			cin >> experience;

			printSurnamesByExp(surnames, experiences, SIZE, experience);

			break;
		}
		case 3:
		{
			printSurnamesWithMaxExp(surnames, experiences, SIZE);

			break;
		}
	}


	system("pause");
}

void printExpBySurname(const char surnames[][SURNLEN], const int experiences[], const size_t size, const char surname[])
{
	int workerNum;	//Номер работника в списке

	//Перебор массива фамилий
	for (workerNum = 0; workerNum < size; workerNum++)
	{
		bool isFound = true;	//Найдена ли фамилия в списке

		//Посимволное сравнение фамилии из списка и введенной фамилии
		for (int j = 0; j < SURNLEN && surname[j] != '\0' && surnames[workerNum][j] != '\0'; j++)
			if (surname[j] != surnames[workerNum][j])
				isFound = false;

		if (isFound)
			break;
	}

	if (workerNum != size)
		cout << "Стаж работника: " << experiences[workerNum] << endl;
	else
		cout << "Работник не найден" << endl;
}

void printSurnamesByExp(const char surnames[][SURNLEN], const int experiences[], const size_t size, const int experience)
{
	int workerNum;			//Номер работника в списке
	bool isFound = false;	//Найден ли стаж в списке

	//Перебор массива стажей
	for (workerNum = 0; workerNum < size; workerNum++)
	{
		if (experience == experiences[workerNum])
		{
			cout << "Фамилия работника: " << surnames[workerNum] << endl;
			isFound = true;
		}
	}

	if (!isFound)
		cout << "Работник не найден" << endl;
}

void printSurnamesWithMaxExp(const char surnames[][SURNLEN], const int experiences[], const size_t size)
{
	int averageExperience;		//Средний стаж работников
	int sumExperiences = 0;		//Сумма стажей работников

	for (int i = 0; i < size; i++)
		sumExperiences += experiences[i];

	averageExperience = sumExperiences / size;

	for (int i = 0; i < size; i++)
		if (experiences[i] > averageExperience)
			cout << "Фамилия: " << surnames[i] << ", стаж: " << experiences[i] << endl;
}
*/


// КЛЮЧ С '?’. 1. Программа должна проверять соответствие слова ключу, который содержит обычные 
// символы, а также может содержать один или несколько специальных символов '?’, которым в слове 
// может соответствовать любой символ (ровно один). Например слова: «символ», «буйвол» 
// соответствуют ключу «???вол». Лучше сделать так, чтобы программа многократно вводила слова и 
// проверяла их на соответствие однократно введенному ключу. 
// 2. Организуйте проверку соответствия в виде функции.
/*
// Вариант без функции
void main()
{
	setlocale(LC_ALL, "Russian");

	char key[100];	//Слово-ключ
	char word[100];	//Проверяемое слово

	cout << "Слово-ключ с '?': ";
	cin.getline(key, sizeof(key));

	do {
		cout << "Слово: ";
		cin.getline(word, sizeof(word));

		if (cin.eof())
			break;

		bool isMatch = true;

		for (int i = 0; isMatch; i++)
		{
			if (word[i] != key[i] && key[i] != '?')
				isMatch = false;
			if (key[i] == '\0' && word[i] == '\0')
				break;
		}

		isMatch ? cout << "Слово соответствует ключу" : cout << "Слово не соответствует ключу";
		cout << endl;

	} while (!cin.eof());

	system("pause");
}
*/
/*
//Вариант с функцией
bool checkWordToKey(const char* key, const char* word);

void main()
{
	setlocale(LC_ALL, "Russian");

	char key[100];	//Слово-ключ
	char word[100];	//Проверяемое слово

	cout << "Слово-ключ с '?': ";
	cin.getline(key, sizeof(key));

	do {
		cout << "Слово: ";
		cin.getline(word, sizeof(word));

		if (cin.eof())
			break;

		checkWordToKey(key, word) ? cout << "Слово соответствует ключу" 
			: cout << "Слово не соответствует ключу";
		cout << endl;

	} while (!cin.eof());

	system("pause");
}

bool checkWordToKey(const char* key, const char* word)
{
	for (int i = 0; ;i++)
	{
		if (word[i] != key[i] && key[i] != '?')
			return false;
		if (key[i] == '\0' && word[i] == '\0')
			return true;
	}
}
*/


// НАИБОЛЬШЕЕ ПОВТОРЕНИЕ СИМВОЛА. 1. Для заданной строки и введенного символа определить 
// максимальное количество его вхождений подряд в последовательность символов строки. 
// 2. Реализовать в виде функции.
/*
// Вариант без функции
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "aabbbcdeffffghhiiiiijjklmmeee@@";	//Строка
	char searchChar;		//Искомый символ
	int maxCharLen = 0;		//Максимальное число подряд идущих искомых символов в строке

	int currCharLen = 0;	//Текущее число подряд идущих искомых символов в строке

	cout << "Искомый символ: ";
	cin.get(searchChar);

	//Определение числа подряд идущих искомых символов
	for (int i = 0 ; str[i] != '\0'; i++)
	{
		if (str[i] == searchChar)
		{
			if (++currCharLen > maxCharLen)
				maxCharLen = currCharLen;
		}
		else
			currCharLen = 0;
	}

	maxCharLen ? cout << "Символ встречается в строке " << maxCharLen << " раз подряд"
		: cout << "Символ не встречается в строке";
	cout << endl;

	system("pause");
}
*/
/*
//Вариант с функцией
int getCharCountInRow(const char str[], const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "aabbbcdeffffghhiiiiijjklmmeee@@";	//Строка
	char searchChar;		//Искомый символ
	int maxCharLen = 0;		//Максимальное число подряд идущих искомых символов в строке

	cout << "Искомый символ: ";
	cin.get(searchChar);

	maxCharLen = getCharCountInRow(str, searchChar);

	maxCharLen ? cout << "Символ встречается в строке " << maxCharLen << " раз подряд"
		: cout << "Символ не встречается в строке";
	cout << endl;

	system("pause");
}

int getCharCountInRow(const char str[], const char c)
{
	int maxCharLen = 0;		//Максимальное число подряд идущих искомых символов в строке
	int currCharLen = 0;	//Текущее число подряд идущих искомых символов в строке

	//Определение текущего числа подряд идущих искомых символов
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			if (++currCharLen > maxCharLen)
				maxCharLen = currCharLen;
		}
		else
			currCharLen = 0;
	}

	return maxCharLen;
}
*/


// ДЛИННАЯ ЦЕПОЧКА. Определить максимальное число одинаковых подряд идущих символов строки. 
// Реализовать функцией.
/*
int countIdenticalCharInRow(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];		//Строка
	int maxCharLen;		//Максимальное число подряд идущих символов в строке

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	maxCharLen = countIdenticalCharInRow(str);

	cout << "Максимальное число подряд идущих символов: " << maxCharLen << endl;

	system("pause");
}

int countIdenticalCharInRow(const char str[])
{
	int maxCharLen = 1;		//Максимальное число подряд идущих символов в строке
	int currCharLen = 1;	//Текущее число подряд идущих символов в строке
	char prevChar = str[0];	//Предыдущий символ для сравнения с текущим в строке

	//Определение текущего числа подряд идущих искомых символов
	for (int i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == prevChar)
		{
			if (++currCharLen > maxCharLen)
				maxCharLen = currCharLen;
		}
		else
			currCharLen = 1;

		prevChar = str[i];
	}

	return maxCharLen;
}
*/


// СКОБКИ. Написать программу, проверяющюю правильность расстановки скобок (имеется ввиду 
// формальная правильность их открытия и закрытия, т.е. согласованность) в выражении, которое 
// вводится как текстовая строка. Например в выражении: (хххх)хх(ххх(хххх)хх)ххх — скобки 
// расставлены правильно, а в (ууууууу(ууу)ууууууу)уууу)ууууу(уууу — неправильно.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];	//Выражение
	int count = 0;	//Счетчик кол-ва открытых открывающих скобок

	cout << "Выражение: ";
	cin.getline(str, sizeof(str));

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;

		//Обнаружена закрывающая скобка без предшествующей открывающей
		if (count < 0)
			break;
	}

	count == 0 ? cout << "Скобки расставлены верно" : cout << "Скобки расставлены не верно";
	cout << endl;

	system("pause");
}
*/


// НАИБОЛЕЕ ГЛУБОКО ВЛОЖЕННЫЙ ТЕКСТ. 1. Из скобочного выражения, записанного в виде строки, 
// выделить текст в наиболее глубоко вложенных скобках. 2. Реализовать в виде функции, возвращающей 
// указатель на динамический массив, в который копируется выделенный текстовый фрагмент.
/*
// Вариант без функции
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "(aaa)bb(ccc(ddd)ee)fff(g)";	//Выражение
	char* deepestStr = nullptr;					//Наиболее глубоко вложенный текст

	int count = 0;		//Счетчик кол-ва открытых открывающих скобок
	int maxCount = 0;	//Максимальное значение счетчика

	int pos = 0;				//Позиция первого символа вложенного текста
	int len = 0;				//Длина вложенного текста
	bool toIncreaseLen = false;	//Увеличивать ли длину счетчика вложенного текста

	//Поиск наиболее глубоко вложенного текста
	for (int i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == '(' && ++count > maxCount)
		{
			maxCount = count;
			pos = i + 1;
			len = 0;
			toIncreaseLen = true;
		}
		else if (str[i] == ')')
		{
			count--;
			toIncreaseLen = false;
		}
		else if (toIncreaseLen)
			len++;
	}

	//Выделение памяти под массив вложенного текста
	deepestStr = new char[len + 1];

	//Заполнение массива
	for (int i = 0; i < len; i++)
		deepestStr[i] = str[pos + i];
	deepestStr[len] = '\0';

	cout << "Наиболее глубоко вложенный текст: " << deepestStr << endl;

	delete[] deepestStr;
	system("pause");
}
*/
/*
//Вариант с функцией
char* getDeepestStr(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "(aaa)bb(ccc(ddd)ee)fff(g)";	//Выражение
	char* deepestStr = getDeepestStr(str);		//Наиболее глубоко вложенный текст	

	cout << "Наиболее глубоко вложенный текст: " << deepestStr << endl;

	delete[] deepestStr;
	system("pause");
}

char* getDeepestStr(const char str[])
{
	char* deepestStr = nullptr;	//Наиболее глубоко вложенный текст

	int count = 0;		//Счетчик кол-ва открытых открывающих скобок
	int maxCount = 0;	//Максимальное значение счетчика

	int pos = 0;				//Позиция первого символа вложенного текста
	int len = 0;				//Длина вложенного текста
	bool toIncreaseLen = false;	//Увеличивать ли длину счетчика вложенного текста

	//Поиск наиболее глубоко вложенного текста
	for (int i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == '(' && ++count > maxCount)
		{
			maxCount = count;
			pos = i + 1;
			len = 0;
			toIncreaseLen = true;
		}
		else if (str[i] == ')')
		{
			count--;
			toIncreaseLen = false;
		}
		else if (toIncreaseLen)
			len++;
	}

	//Выделение памяти под массив вложенного текста
	deepestStr = new char[len + 1];

	//Заполнение массива
	for (int i = 0; i < len; i++)
		deepestStr[i] = str[pos + i];
	deepestStr[len] = '\0';

	return deepestStr;
}
*/


// АРИФМЕТИКА. Два целых числа вводятся как строки (в виде последовательности символов-цифр) 
// программа должна выполнить их сложение и получить результат в виде строки из символов-цифр.
/*
int charToInt(const char str[]);
char* intToChar(int n);

void main()
{
	setlocale(LC_ALL, "Russian");

	char n1[10], n2[10];	//Слагаемые
	char* sum = nullptr;	//Сумма

	cout << "Слагаемое 1: ";
	cin.getline(n1, sizeof(n1));

	cout << "Слагаемое 2: ";
	cin.getline(n2, sizeof(n2));

	sum = intToChar(charToInt(n1) + charToInt(n2));

	cout << "Сумма: " << sum << endl;

	delete[] sum;
	system("pause");
}

int charToInt(const char str[])
{
	int n = 0;	//Возвращаемое число

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n *= 10;
			n += str[i] - '0';
		}
	}

	return n;
}

char* intToChar(int n)
{
	int digits = n ? round(log10(n) + 0.5) : 1;	//Кол-во цифр в числе
	char* str = new char[digits + 1];			//Возвращаемая строка

	for (int i = digits - 1; i >= 0; i--)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	str[digits] = '\0';

	return str;
}
*/


// ВЫБРАКОВКА++. Статически размещенный целочисленный массив проинициализировать набором значений 
// разного знака. Написать функцию, которая будет отбирать в динамически созданный массив нужного 
// размера все положительные значения, возвращая указатель на этот массив, а также информацию о 
// количестве элементов, полученных в нем.
/*
int* selectPositive(const int arr[], const size_t sizeArr, size_t& sizeRes);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[20];			//Исходный массив
	int* result = nullptr;	//Массив положительных значений
	size_t sizeRes = 0;		//Кол-во элементов в результирующем массиве

	//Заполнение массива
	for (int& n : arr)
		n = rand() % 200 - 100;	

	cout << "Исходный массив: ";
	for (int& n : arr)
		cout << n << " ";
	cout << endl;

	result = selectPositive(arr, sizeof(arr) / sizeof(arr[0]), sizeRes);

	cout << "Массив положительных значений: ";
	for (int i = 0; i < sizeRes; i++)
		cout << result[i] << " ";
	cout << endl;

	delete[] result;
	system("pause");
}

int* selectPositive(const int arr[], const size_t sizeArr, size_t& sizeRes)
{
	int* result = nullptr;	//Массив положительных значений

	sizeRes = 0;

	//Подсчет кол-ва положительных элементов
	for (int i = 0; i < sizeArr; i++)
		if (arr[i] > 0)
			sizeRes++;

	result = new int[sizeRes];

	//Заполнение массива
	for (int i = 0, j = 0; i < sizeArr; i++)
		if (arr[i] > 0)
			result[j++] = arr[i];

	return result;
}
*/


// ПОИСК+ЗАМЕНА. Написать функцию, определяющую, содержится ли в массиве символов заданный символ. 
// Должна вернуть указатель на первый найденный элемент или NULL. Используя функцию заменить в 
// строке все символы '#' на символы '@'.
/*
char* findChar(char str[], const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char arr[] = "$#(*^%#!()&^##$|+";

	cout << "Исходный массив: " << endl << arr << endl;

	while (char* c = findChar(arr, '#'))
		*c = '@';

	cout << "Массив после замены: " << endl << arr << endl;

	system("pause");
}

char* findChar(char str[], const char c)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return &str[i];

	return nullptr;
}
*/


// РАСШИФРОВКА **. Строка, записанная заглавными буквами, зашифровывается путем замены каждой буквы 
// на ее порядковый номер в алфавите. При этом символ пробела заменяется на цифру 0. Полученная 
// цепочка цифр вводится в программу как текстовая строка. Программа должна определить количество 
// возможных расшифровок записи.

int decode(const char str[], const char decoded[] = new char[1]{ "" });
char* addChar(const char str[], const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char encoded[100];	//Зашифрованная цифрами строка
	int variants = 0;	//Количество возможных расшифровок

	cout << "Зашифрованная цифрами фраза: ";
	cin.getline(encoded, sizeof(encoded));

	cout << endl << "Варианты расшифровки: " << endl;

	variants = decode(encoded);

	cout << endl << "Всего вариантов: " << variants << endl;

	system("pause");
}

int decode(const char str[], const char decoded[])
{
	int count = 0;
	
	//Расшифровка
	if (*str >= '1' && *str <= '9')
	{
		//Перевод одной строковой цифры в значение кода ASCII соответствующей буквы
		char c1 = *str - '0' + 'A' - 1;

		count += decode(str + 1, addChar(decoded, c1));

		if (*(str + 1) != '\0')
		{
			//Перевод двух строковых цифр в значение кода ASCII соответствующей буквы
			char c2 = (*str - '0') * 10 + (*(str + 1) - '0') + 'A' - 1;

			if (c2 >= 'A' + 9 && c2 <= 'Z')
				count += decode(str + 2, addChar(decoded, c2));
		}
	}
	else if (*str == '0' && *(str + 1) != '\0')	//Пробел не в конце
	{
		count += decode(str + 1, addChar(decoded, '_'));
	}

	//Достигнут конец строки и расшифрованная строка не пустая
	else if (*str == '\0' && *decoded != '\0')
	{
		//Печать расшифрованной строки
		for (int i = 0; decoded[i] != '\0'; i++)
			cout << decoded[i];
		cout << endl;

		delete[] decoded;
		return 1;
	}

	return count;
}

//Функция добавления символа к строке
char* addChar(const char str[], const char c)
{
	char* strNew = nullptr;	//Новая строка
	size_t len;				//Длина исходной строки

	//Определение длины исходной строки
	for (len = 0; str[len] != '\0'; len++);

	strNew = new char[len + 2];

	//Заполнение новой строки
	for (int i = 0; i < len; i++)
		strNew[i] = str[i];
	strNew[len] = c;
	strNew[len + 1] = '\0';

	return strNew;
}