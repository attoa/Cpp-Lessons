#include <locale>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


/*** ОБРАБОТКА СТРОК. МАКСИМАЛЬНО ИСПОЛЬЗУЙТЕ ФУНКЦИИ ИЗ <cstring> И МЕТОДЫ ИЗ string ***/


// СРАВНЕНИЕ СТРОК. Вводить пары терминальных строк, сравнивать их: а) по длине; б) по алфавиту.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	char str1[100], str2[100];	//Строки
	size_t len1, len2;			//Длины строк
	int comp;					//Результат сравнения по алфавиту

	do {
		cout << "Строка 1: ";
		cin.getline(str1, sizeof(str1));
		if (cin.eof()) break;

		cout << "Строка 2: ";
		cin.getline(str2, sizeof(str2));
		if (cin.eof()) break;

		len1 = strlen(str1);
		len2 = strlen(str2);
		comp = strcmp(str1, str2);

		if (len1 > len2) cout << "Строка 1 длиннее";
		else if (len1 < len2) cout << "Строка 2 длиннее";
		else cout << "Длины строк равны";
		cout << endl;

		if (comp > 0) cout << "Строка 1 по алфавиту больше";
		else if (comp < 0) cout << "Строка 2 по алфавиту больше";
		else cout << "Строки по алфавиту равны";
		cout << endl << endl;
	} while (!cin.eof());

	system("pause");
}
*/


// УДАЛЕНИЕ СИМВОЛА. Удалить из строки все вхождения заданного символа, используя функции или 
// методы обработки строк. Два варианта: а) строку хранить в char S[...]; б) хранить как string.
/*
//Вариант с массивом char
void main()
{
	setlocale(LC_ALL, "Russian");

	char s[100];	//Строка
	char c;			//Удаляемый символ

	cout << "Строка: ";
	cin.getline(s, sizeof(s));

	cout << "Удаляемый символ: ";
	cin.get(c);

	while (const char* ps = strchr(s, c))	//Пока возвращается указатель на удаляемый символ
	{
		char temp[100];				//Временная строка

		strncpy(temp, s, ps - s);	//Скопировать во временную строку часть строки до символа
		temp[ps - s] = '\0';		//Для корректной работы strcat()

		strcat(temp, ps + 1);		//Объединить временную строку и часть строки после символа

		strcpy(s, temp);			//Скопировать в исходную строку временную строку
	}

	cout << "Итоговая строка: " << s << endl;

	system("pause");
}
*/
/*
//Вариант со string
void main()
{
	setlocale(LC_ALL, "Russian");

	string s;	//Строка
	char c;		//Удаляемый символ

	cout << "Строка: ";
	getline(cin, s);

	cout << "Удаляемый символ: ";
	cin.get(c);

	while (const size_t pos = s.find(c))
	{
		if (pos == string::npos) break;

		s.erase(pos, 1);	//Удалить 1 символ из позиции pos
	}

	cout << "Итоговая строка: " << s << endl;

	system("pause");
}
*/


// ПРОСТОЙ ПАЛИНДРОМ. Используя свою функцию инвертирования строки символов и стандартные средства 
// сравнения строк, написать функцию, выполняющую проверку: является ли строка палиндромом 
// (перевертышем) с учетом всех символов, включая пробелы. Пример строки - простого палиндрома: 
// AAA 123 xxMMxx 321 AAA. Сделать вторую реализацию, используя string.
/*
//Вариант с массивом char
void invert(char* istr, char* str);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100],	//Исходная строка
		istr[100];	//Инвертированная строка

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	invert(istr, str);

	strcmp(str, istr) == 0
		? cout << "Строка является палиндромом" << endl
		: cout << "Строка не является палиндромом" << endl;

	system("pause");
}

void invert(char* istr, char* str)
{
	char* piend = istr + strlen(str);	//Указатель на конец инвертированной строки
	char* pstart = str;					//Указатель на начало исходной строки
	
	*piend-- = '\0';

	while (*pstart)
		*piend-- = *pstart++;
}
*/
/*
//Вариант со string
string invert(string str);

void main()
{
	setlocale(LC_ALL, "Russian");

	string str,		//Исходная строка
		  istr;		//Инвертированная строка

	cout << "Строка: ";
	getline(cin, str);

	istr = invert(str);

	str == istr
		? cout << "Строка является палиндромом" << endl
		: cout << "Строка не является палиндромом" << endl;

	system("pause");
}

string invert(string str)
{
	string istr;	//Инвертированная строка

	while (str.length())			//Пока длина копии исходной строки не 0
	{
		istr.push_back(str.back());	//Вставить в инверт. строку последний символ исходной строки
		str.pop_back();				//Удалить последний символ исходной строки
	}

	return istr;
}
*/


// ПОИСК СТРОКИ В МАССИВЕ. С использованием функций обработки строк выяснить, какие из строк 
// массива char Name[][20] = { "...","...","...","...","..." }
// а) начинаются с набора символов; б) содержат набор символов; в) заканчиваются на набор символов, 
// содержащихся в строке, введенной пользователем. Оформить в виде функции.
/*
#define LEN 20
void findStrInArray(const char name[][LEN], const size_t size, const char* charSet);

void main()
{
	setlocale(LC_ALL, "Russian");

	char name[][LEN] = { "lorem", "ipsum", "dolor", "sit", "amet", "meget" };	//Массив
	const size_t size = sizeof(name) / sizeof(name[0]);							//Размер массива
	char charSet[LEN];															//Набор символов

	//Печать массива
	cout << "Массив строк: " << endl;
	for (int i = 0; i < size; i++)
		cout << i << " " << name[i] << endl;
	cout << endl;

	cout << "Набор символов: ";
	cin.getline(charSet, sizeof(charSet));
	cout << endl;

	findStrInArray(name, size, charSet);

	system("pause");
}

void findStrInArray(const char name[][LEN], const size_t size, const char* charSet)
{
	bool startedWithCharSet = false,	//Есть ли строки, начинающиеся с набора символов
		 containedCharSet = false,		//Есть ли строки, содержащие набор символов
		 endedWithCharSet = false;		//Есть ли строки, заканчивающиеся на набор символов

	for (int i = 0; i < size; i++)
	{
		if (const char* p = strstr(name[i], charSet))	//Указатель на символ подстроки не nullptr
		{
			if (p == name[i])
			{
				startedWithCharSet = true;
				cout << "Строка " << i << " начинается с набора символов" << endl;
			}

			containedCharSet = true;
			cout << "Строка " << i << " содержит набор символов" << endl;

			if (p - name[i] + strlen(charSet) == strlen(name[i]))
			{
				endedWithCharSet = true;
				cout << "Строка " << i << " заканчивается на набор символов" << endl;
			}
		}
	}

	if (!startedWithCharSet)
		cout << "Нет строк, начинающихся с набора символов" << endl;
	if (!containedCharSet)
		cout << "Нет строк, содержащих набор символов" << endl;
	if (!endedWithCharSet)
		cout << "Нет строк, заканчивающихся на набор символов" << endl;

	cout << endl;
}
*/


// ФУНКЦИЯ СЛИЯНИЯ. Написать свою функцию char* strcatnew(char* s1, char* s2) безопасного слияния 
// строк, аналогичную стандартной функции char* strcat(char* s1, char* s2), но с динамическим 
// выделением области памяти под объединенную строку.
/*
char* strcatnew(char* s1, char* s2);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str1[100], str2[100];	//Объединяемые строки
	char* str = nullptr;		//Объединенная строка

	cout << "Строка 1: ";
	cin.getline(str1, sizeof(str1));

	cout << "Строка 2: ";
	cin.getline(str2, sizeof(str2));

	str = strcatnew(str1, str2);

	cout << "Объединенная строка: " << endl << str << endl;

	delete[] str;
	system("pause");
}

char* strcatnew(char* s1, char* s2)
{
	char* s = new char[strlen(s1) + strlen(s2) + 1];
	char* ps = s;

	while (*s1)	*ps++ = *s1++;
	while (*s2)	*ps++ = *s2++;
	*ps = '\0';

	return s;
}
*/


// СКЛЕЙКА СЛОВ. Пользователь вводит через <Enter> отдельные слова. Ваша функция должна склеивать
// их через пробелы в одну динамически размещаемую в памяти строку типа: а) char*; б) string.
/*
//Вариант с char*
char* wordcat(char* str, char* word);

void main()
{
	setlocale(LC_ALL, "Russian");

	char word[50];	//Вводимое слово
	char* str = "";	//Объединенная строка

	do {
		cout << "Слово: ";
		cin.getline(word, sizeof(word));

		if (!cin.eof())
			str = wordcat(str, word);

	} while (!cin.eof());

	cout << str << endl;

	delete[] str;
	system("pause");
}

char* wordcat(char* str, char* word)
{
	char* newstr = new char[strlen(str) + strlen(word) + 2];
	*newstr = '\0';		//Для корректной работы strcat()

	if (strlen(str))	//Если строка не пустая
	{
		strcat(newstr, str);
		strcat(newstr, " ");
	}
	strcat(newstr, word);

	return newstr;
}
*/
/*
//Вариант со string
string wordcat(string& str, string& word);

void main()
{
	setlocale(LC_ALL, "Russian");

	string word;	//Вводимое слово
	string str;		//Объединенная строка

	do {
		cout << "Слово: ";
		getline(cin, word);

		if (!cin.eof())
			str = wordcat(str, word);

	} while (!cin.eof());

	cout << str << endl;

	system("pause");
}

string wordcat(string& str, string& word)
{
	return str.length() ? str + " " + word : word;
}
*/


// КОПИРОВАНИЕ ДО ПОМЕТКИ. Для каждой из вводимых строк, содержащих символ '#', с помощью своей
// функции выделять и добавлять в вектор указателей указатели на динамически созданные копии
// их начальных частей до символа - пометки '#'.
/*
char* select(const char* str);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];		//Строка
	vector<char*> pstr;	//Вектор подстрок

	do {
		cout << "Строка: ";
		cin.getline(str, sizeof(str));

		if (!cin.eof())
			pstr.push_back(select(str));

	} while (!cin.eof());

	cout << endl;

	//Печать подстрок
	for (char* p : pstr)
		cout << p << endl;

	//Освобождение памяти
	for (char* p : pstr)
		delete[] p;
	system("pause");
}

char* select(const char* str)
{
	const char* p = strchr(str, '#');	//Указатель на символ '#' в строке

	//Если в строке нет символа, возврат пустой строки
	if (!p)
		return new char[1]{ "" };

	const size_t len = p - str + 1;		//Длина строки до символа '#'
	char* copy = new char[len];			//Копия части строки

	*copy = '\0';					//Для корректной работы strncat()
	strncat(copy, str, len - 1);	//Копирование части строки

	return copy;
}
*/


// РАЗДЕЛЕНИЕ. Программа вводит N строк, состоящих из набранных через дефис пар: слово-перевод.
// Программа должна с помощью своей функции выделять эти составные части и сохранять их в массиве 
// или векторе структур с полями указателей на char: W для слов и T для их переводов.
/*
struct Word {
	char* w = nullptr;
	char* t = nullptr;
};

Word devide(const char* str);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];		//Вводимая строка
	vector<Word> dict;	//Словарь

	do {
		cout << "Слово и перевод: ";
		cin.getline(str, sizeof(str));

		if (!cin.eof())
			dict.push_back(devide(str));

	} while (!cin.eof());

	//Печать словаря
	cout << endl << "Слово - Перевод" << endl;
	for (Word& w : dict)
		cout << w.w << " - " << w.t << endl;

	//Освобождение памяти
	for (Word& w : dict)
	{
		delete[] w.w;
		delete[] w.t;
	}
	system("pause");
}

Word devide(const char* str)
{
	const char* p = strchr(str, '-');	//Указатель на символ '-'

	//Если в строке нет символа, возврат структуры с пустыми строками
	if (!p)
		return Word{ new char[1] {""},  new char[1] {""} };

	const size_t wlen = p - str + 1;	//Длина строки до символа '-'

	char* word = new char[wlen];					//Слово
	char* trsl = new char[strlen(str) - wlen + 1];	//Перевод

	*word = '\0';					//Для корректной работы strncat()
	strncat(word, str, wlen - 1);	//Копирование слова

	*trsl = '\0';					//Для корректной работы strcat()
	strcat(trsl, ++p);				//Копирование перевода

	return Word{ word, trsl };
}
*/


// ПОИСК СЛОВА. Написать функцию проверки наличия слова в строке, как отдельного слова (a не как 
// части другого слова). Строка может содержать заданный набор разделителей.
/*
bool findWord(char* str, char* word, char* delimiters);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing \"elit\", sed do eiusmod \
		tempor incididunt ut labore et dolore 'magna' aliqua. Leo duis ut diam quam 'nulla' \
		porttitor? Massa eget egestas \"purus\" viverra accumsan in.";

	char word[] = "in";			//Искомое слово

	char delims[] = " '\",.?";	//Разделители

	findWord(str, word, delims)
		? cout << "Слово содержится в строке" << endl
		: cout << "Слово не содержится в строке" << endl;

	system("pause");
}

bool findWord(char* str, char* word, char* delims)
{
	//Перебор слов строки
	for (char* wordstr = strtok(str, delims); wordstr; wordstr = strtok(NULL, delims))
		if (strcmp(wordstr, word) == 0)		//Слово из строки равно искомому слову
			return true;

	return false;
}
*/


// ПОМЕТКИ. Удалить из строки все слова, помеченные вначале специальным символом '#'.
/*
char* delwords(char* str, const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "Lorem ipsum #dolor sit #amet, #consectetur adipiscing elit, #sed do eiusmod.";
	char* newstr = nullptr;

	cout << "Исходная строка: " << endl;
	cout << str << endl << endl;

	newstr = delwords(str, '#');

	cout << "Строка после удаления помеченных слов: " << endl;
	cout << newstr << endl << endl;

	delete[] newstr;
	system("pause");
}

char* delwords(char* str, const char c)
{
	char* temp = new char[strlen(str)];	//Строка с удаленными словами максимальной длины
	char* newstr = nullptr;				//Строка с удаленными словами фактической длины

	*temp = '\0';	//Для корректной работы strcat()

	//Перебор слов исходной строки
	for (char* word = strtok(str, " "); word; word = strtok(NULL, " "))
	{
		if (*word != c)		//Слово не начинается с символа-пометки
		{
			if (strlen(temp))
				strcat(temp, " ");	//Добавить пробел
			strcat(temp, word);		//Добавить слово
		}
	}

	newstr = new char[strlen(temp) + 1];	//Выделить память под фактическую длину строки
	strcpy(newstr, temp);					//Копировать строку
	delete[] temp;

	return newstr;
}
*/


// ПРОСТАЯ АРИФМЕТИКА. Вводится строка из двух целых чисел, записанных в символьном представлении, 
// соединенных знаками '+' или '-'. Программа должна получить результат в виде строки из 
// символов-цифр, используя конвертацию функциями strtol(...); sprintf(...);
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[22];		//Строка
	char result[12];	//Результат
	char* end;			//Указатель на нераспозн. часть строки функцией strtol() (для опред-я s2)
	long s1, s2;		//Целые числа из строки

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	s1 = strtol(str, &end, 10);
	s2 = strtol(end, &end, 10);

	sprintf(result, "%d", s1 + s2);

	cout << "Результат: " << result << endl;

	system("pause");
}
*/

// УПОРЯДОЧЕНИЕ СПИСКА ФАМИЛИЙ. Вводится список из N фамилий: а) память должна захватываться
// динамически под каждую, а указатели - размещаться в векторе указателей; б) фамилии
// сохраняются в виде объектов string в векторе. Нужно упорядочить фамилии по алфавиту.
/*
//Вариант с указателями
void main()
{
	setlocale(LC_ALL, "Russian");

	vector<char*> surnames;		//Вектор фамилий

	while (true)
	{
		char buffer[100];		//Буфер для хранения вводимой фамилии
		cout << "Фамилия: ";
		cin.getline(buffer, sizeof(buffer));
		if (cin.eof()) break;

		//Копирование введенной фамилии в динамическую память
		char* psurname = new char[strlen(buffer) + 1];
		strcpy(psurname, buffer);

		surnames.push_back(psurname);
	}

	//Сортировка вектора (вставками)
	for (int i = 0; i < surnames.size(); i++)
		for (int j = i; j > 0 && strcmp(surnames[j - 1], surnames[j]) > 0; j--)
			swap(surnames[j], surnames[j - 1]);

	//Печать вектора
	cout << endl << "Список фамилий: " << endl;
	for (char* s : surnames)
		cout << s << endl;
	cout << endl;

	//Освобождение памяти
	for (char* s : surnames)
		delete[] s;
	system("pause");
}
*/
/*
// Вариант со string
void main()
{
	setlocale(LC_ALL, "Russian");

	vector<string> surnames;	//Вектор фамилий

	while (true)
	{
		string surname;			//Вводимая фамилия

		cout << "Фамилия: ";
		getline(cin, surname);
		if (cin.eof()) break;

		surnames.push_back(surname);
	}

	//Сортировка вектора (вставками)
	for (int i = 0; i < surnames.size(); i++)
		for (int j = i; j > 0 && surnames[j - 1] > surnames[j]; j--)
			swap(surnames[j], surnames[j - 1]);

	//Печать вектора
	cout << endl << "Список фамилий: " << endl;
	for (string& s : surnames)
		cout << s << endl;
	cout << endl;
	
	system("pause");
}
*/

// РАЗБОР АРИФМЕТИЧЕСКОГО ВЫРАЖЕНИЯ. В виде строки вводится синтаксически правильное бесскобочное
// арифметическое выражение (числа - только целые), начинающееся с числа. Программа должна
// выполнить его разборку на входящие в его состав слова - числа и стоящие между ними знаки 
// операций. (Используйте измененный алгоритм разборки строки на слова).

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];			//Строка-выражение
	char* pstr = str;		//Указатель на текущий символ строки

	vector<char*> nums;		//Вектор слов-чисел
	vector<char> opers;		//Вектор операторов

	cout << "Выражение: ";
	cin.getline(str, sizeof(str));

	//Разбор строки
	while (true)
	{
		const size_t len = strcspn(pstr, "+-*/");	//Длина числа (кол-во символов до оператора)
		char* num = new char[len + 1];				//Слово-число

		//Копирование слова-числа
		strncpy(num, pstr, len);	
		num[len] = '\0';

		nums.push_back(num);				//Добавление числа в вектор

		if (len == strlen(pstr)) break;		//Оператор не найден (strcspn() вернула длину строки)

		opers.push_back(*(pstr + len));		//Добавление оператора в вектор

		pstr += len + 1;					//Сдвиг указателя на символ после оператора
	}

	//Печать чисел
	cout << "Числа: ";
	for (char* n : nums)
		cout << n << " ";
	cout << endl;

	//Печать операторов
	cout << "Операторы: ";
	for (char o : opers)
		cout << o << " ";
	cout << endl;

	//Освобождение памяти
	for (char* n : nums)
		delete[] n;
	system("pause");
}