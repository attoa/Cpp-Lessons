#include <locale>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


/*** ЗАДАЧИ: ФУНКЦИИ + УКАЗАТЕЛИ + ДИНАМИЧЕСКОЕ ВЫДЕЛЕНИЕ / ОСВОБОЖДЕНИЕ ПАМЯТИ. ***/


// ТРАНСПОНИРОВАНИЕ
// Написать функцию void transp(float X[][MAXN], int N) или void transp(float* X, int MaxN, int N) 
// меняющую местами элементы двумерного массива (количества строк и столбцов равны), симметрично 
// расположенные по отношению к главной диагонали.
/*
//Вариант с передачей массива в функцию
#define MAXN 5
void transp(float X[][MAXN], int N);

void main()
{
	setlocale(LC_ALL, "Russian");

	float matrix[][MAXN] = { { 1.1, 1.2, 1.3, 1.4, 1.5 },
							 { 3.3, 3.4, 3.5, 3.6, 3.7 },
							 { 5.5, 5.6, 5.7, 5.8, 5.9 },
							 { 7.7, 7.9, 8.1, 8.3, 8.5 },
							 { 9.9, 9.9, 9.9, 9.9, 9.9 } };

	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	transp(matrix, MAXN);

	cout << endl << "Транспонированная матрица: " << endl;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	system("pause");
}

void transp(float X[][MAXN], int N)
{
	for (int i = 0; i < MAXN; i++)
		for (int j = i + 1; j < N; j++)
			swap(X[i][j], X[j][i]);
}
*/
/*
//Вариант с передачей указателя в функцию
#define MAXN 5
void transp(float* X, int MaxN, int N);

void main()
{
	setlocale(LC_ALL, "Russian");

	float matrix[][MAXN] = { { 1.1, 1.2, 1.3, 1.4, 1.5 },
							 { 3.3, 3.4, 3.5, 3.6, 3.7 },
							 { 5.5, 5.6, 5.7, 5.8, 5.9 },
							 { 7.7, 7.9, 8.1, 8.3, 8.5 },
							 { 9.9, 9.9, 9.9, 9.9, 9.9 } };

	cout << "Исходная матрица: " << endl;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	transp(&matrix[0][0], MAXN, MAXN);

	cout << endl << "Транспонированная матрица: " << endl;
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

	system("pause");
}

void transp(float* X, int MaxN, int N)
{
	for (int i = 0; i < MaxN; i++)
		for (int j = i + 1; j < N; j++)
			swap(X[i * N + j], X[j * MaxN + i]);
}
*/


// НАИБОЛЬШИЙ СВЕРХУ
// Написать функцию, вычисляющую наибольший из элементов массива int Z[15][15] среди тех, которые 
// размещены над главной диагональю в области n * n элементов. Рассмотреть варианты: 
// int Xmax(int X[][MAXN], int n); или int Xmax(int* X, int n, int MaxN). 
// Еще: вместо двумерного массива попробовать использовать vector<vector<int>> Z(15).
/*
//Вариант с передачей массива в функцию
#define MAXN 15
int Xmax(int X[][MAXN], int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int Z[MAXN][MAXN];	//Массив
	int n;				//Размер области поиска

	//Заполнение и печать массива
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			Z[i][j] = rand() % 100;
			cout << setw(3) << Z[i][j];
		}
		cout << endl;
	}

	do
	{
		cout << "Размер области поиска (от 1 до 0): ";
		cin >> n;
	} while (n < 1 || n > MAXN / 2);

	cout << "Наибольший элемент: " << Xmax(Z, n) << endl;

	system("pause");
}

int Xmax(int X[][MAXN], int n)
{
	int max = 0;	//Значение наибольшего элемента массива

	for (int i = 0; i < n; i++)
		for (int j = MAXN - 1; j > MAXN - 1 - n; j--)
			if (X[i][j] > max)
				max = X[i][j];

	return max;
}
*/
/*
//Вариант с передачей указателя в функцию
#define MAXN 15
int Xmax(int* X, int n, int MaxN);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int Z[MAXN][MAXN];	//Массив
	int n;				//Размер области поиска

						//Заполнение и печать массива
	for (int i = 0; i < MAXN; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			Z[i][j] = rand() % 100;
			cout << setw(3) << Z[i][j];
		}
		cout << endl;
	}

	do
	{
		cout << "Размер области поиска (от 1 до 0): ";
		cin >> n;
	} while (n < 1 || n > MAXN / 2);

	cout << "Наибольший элемент: " << Xmax(&Z[0][0], n, MAXN) << endl;

	system("pause");
}

int Xmax(int* X, int n, int MaxN)
{
	int max = 0;	//Значение наибольшего элемента массива

	for (int i = 0; i < n; i++)
		for (int j = MaxN - 1; j > MaxN - 1 - n; j--)
			if (X[MaxN * i + j] > max)
				max = X[MaxN * i + j];

	return max;
}
*/
/*
//Вариант с передачей вектора в функцию
int Xmax(vector<vector<int>> X, int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	const size_t MAXN = 15;			//Размер массива
	vector<vector<int>> Z(MAXN);	//Массив
	int n;							//Размер области поиска

	//Заполнение и печать массива
	for (int i = 0; i < Z.size(); i++)
	{
		Z[i] = vector<int>(MAXN);

		for (int j = 0; j < Z[0].size(); j++)
		{
			Z[i][j] = rand() % 100;
			cout << setw(3) << Z[i][j];
		}
		cout << endl;
	}

	do
	{
		cout << "Размер области поиска (от 1 до 0): ";
		cin >> n;
	} while (n < 1 || n > Z.size() / 2);

	cout << "Наибольший элемент: " << Xmax(Z, n) << endl;

	system("pause");
}

int Xmax(vector<vector<int>> X, int n)
{
	int max = 0;	//Значение наибольшего элемента массива

	for (int i = 0; i < n; i++)
		for (int j = X.size() - 1; j > X.size() - 1 - n; j--)
			if (X[i][j] > max)
				max = X[i][j];

	return max;
}
*/


// УДАЛЕНИЕ ЧАСТИ СТРОКИ
// Написать функцию, удаляющую из терминальной строки заданное количество символов, начиная 
// с символа с заданным номером. Замечание: терминальный символ удаляться не должен.
/*
void cut(char* str, const int from, const int num);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];	//Строка
	int from;		//Номер первого удаляемого символа
	int num;		//Кол-во удаляемых символов

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	cout << "Номер первого удаляемого символа: ";
	cin >> from;

	cout << "Кол-во удаляемых символов: ";
	cin >> num;

	cut(str, from, num);

	cout << "Результат: " << str << endl;

	system("pause");
}

void cut(char* str, const int from, const int num)
{
	size_t len;		//Длина строки

	//Определение длины строки
	for (len = 0; str[len] != '\0'; len++);

	if (from > len)
		return;

	//Сдвиг указателя на первый удаляемый символ
	str += from;

	if (from + num > len)
		*str = '\0';
	
	//Копирование части строки
	while (*str)
		*str++ = *(str + num);
}
*/


// ЧАСТЬ СТРОКИ
// Написать функцию, возвращающую копию части исходной строки, начиная с символа с заданным 
// номером, включающую заданное количество символов + терминальный. Указание: копию части строки 
// разместить в динамически выделенной памяти.
/*
char* sub(char* str, const int from, const int num);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100] = "qwerty";			//Исходная строка
	char* subStr = nullptr;	//Подстрока
	
	int from = 2;		//Номер первого символа подстроки
	int num = 20;		//Кол-во символов подстроки

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	cout << "Номер первого символа подстроки: ";
	cin >> from;

	cout << "Кол-во символов подстроки: ";
	cin >> num;

	subStr = sub(str, from, num);

	cout << "Подстрока: " << subStr << endl;

	delete[] subStr;
	system("pause");
}

char* sub(char* str, const int from, const int num)
{
	char* subStr = new char[num + 1];	//Подстрока
	size_t len;							//Длина исходной строки

	//Определение длины исходной строки
	for (len = 0; str[len] != '\0'; len++);

	if (from < len)
	{
		//Заполнение подстроки
		for (int i = 0; i < num && str[i] != '\0'; i++)
			subStr[i] = str[from + i];
		subStr[num] = '\0';
	}
	else
		subStr[0] = '\0';

	return subStr;
}
*/


// РЕКУРСИЯ
// Написать функцию, рекурсивно вычисляющую для заданного n значение Fn из последовательности 
// Фибоначчи Fn + 1 = Fn + Fn-1 (F1 = F0 = 1). Дополнительно предложить вариант, когда для 
// предотвращения повторного рекурсивного вычисления некоторых уже встречавшихся членов 
// последовательности используется их накопление / извлечение из созданного динамического массива.
/*
//Вариант с рекурсией
int fibonacci(const int n);

void main()
{
	setlocale(LC_ALL, "Russian");

	int n, fn;

	cout << "n: ";
	cin >> n;

	fn = fibonacci(n);

	cout << "Число Фибоначчи F(" << n << ") = " << fn << endl;

	system("pause");
}

int fibonacci(const int n)
{
	if (n == 0) return 0;
	if (n == 1)	return 1;
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}
*/
/*
//Вариант с накоплением
int fibonacci(const int n);

void main()
{
	setlocale(LC_ALL, "Russian");

	int n, fn;

	cout << "n: ";
	cin >> n;

	fn = fibonacci(n);

	cout << "Число Фибоначчи F(" << n << ") = " << fn << endl;

	system("pause");
}

int fibonacci(const int n)
{
	int* nums = new int[n + 1];
	int res;

	nums[0] = 0;
	nums[1] = 1;

	for (int i = 2; i <= n; i++)
		nums[i] = nums[i - 1] + nums[i - 2];

	res = nums[n];

	delete[] nums;
	return res;
}
*/


// РАСПРЕДЕЛЕНИЕ
// Передать функции указатель на статический массив, заполненный числовыми данными. 
// (а) Функция формирует и возвращает массив из двух указателей, ссылающихся на два динамических 
// массива. В первый должны быть помещены все отрицательные, во второй - все положительные числа.
// Размеры этих массивов также возвращаются функцией. 
// (б) Функция заполняет и возвращает структуру, поля которой хранят в себе указатели на эти два 
// динамических массива, а также их размеры. Предусмотреть освобождение памяти в отдельной функции. 
// (в) Функция заполняет и возвращает структуру с двумя векторами.
/*
//Вариант с массивом указателей
int** allocation(const int* arr, const size_t size, size_t& sizePos, size_t& sizeNeg);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[10];				//Исходный массив
	int** arrAlloc = nullptr;	//Массив указателей на распределенные массивы

	size_t sizePos = 0,			//Размер положительного массива
		   sizeNeg = 0;			//Размер отрицательного массива

	//Заполнение и печать массива
	cout << "Исходный массив: " << endl;
	for (int& n : arr)
	{
		n = rand() % 200 - 100;
		cout << n << " ";
	}

	arrAlloc = allocation(arr, sizeof(arr) / sizeof(arr[0]), sizePos, sizeNeg);

	cout << endl << "Положительный массив: " << endl;
	for (int i = 0; i < sizePos; i++)
		cout << arrAlloc[0][i] << " ";

	cout << endl << "Отрицательный массив: " << endl;
	for (int i = 0; i < sizeNeg; i++)
		cout << arrAlloc[1][i] << " ";
	cout << endl;

	delete[] arrAlloc[0];
	delete[] arrAlloc[1];
	delete[] arrAlloc;
	system("pause");
}

int** allocation(const int* arr, const size_t size, size_t& sizePos, size_t& sizeNeg)
{
	int** arrAlloc = new int*[2];	//Массив указателей
	int* arrPos = nullptr;			//Массив положительных значений
	int* arrNeg = nullptr;			//Массив отрицательных значений
	
	//Подсчет размеров массивов
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			sizeNeg++;
		else if (arr[i] > 0)
			sizePos++;
	}

	arrPos = new int[sizePos];
	arrNeg = new int[sizeNeg];
	arrAlloc[0] = arrPos;
	arrAlloc[1] = arrNeg;

	//Заполнение массивов
	for (int i = 0, p = 0, n = 0; i < size; i++)
	{
		if (arr[i] < 0)
			arrNeg[n++] = arr[i];
		else if (arr[i] > 0)
			arrPos[p++] = arr[i];
	}

	return arrAlloc;
}
*/
/*
//Вариант со структурой с указателями
struct AllocatedArrs {
	int* arrPos = nullptr;	//Массив положительных значений
	int* arrNeg = nullptr;	//Массив отрицательных значений

	size_t sizePos = 0,		//Размер положительного массива
		   sizeNeg = 0;		//Размер отрицательного массива
};

AllocatedArrs* allocation(const int* arr, const size_t size);
void clear(AllocatedArrs* allocated);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[10];						//Исходный массив
	AllocatedArrs* allocated = nullptr;	//Структура с распределенными массивами

	//Заполнение и печать массива
	cout << "Исходный массив: " << endl;
	for (int& n : arr)
	{
		n = rand() % 200 - 100;
		cout << n << " ";
	}

	allocated = allocation(arr, sizeof(arr) / sizeof(arr[0]));

	cout << endl << "Положительный массив: " << endl;
	for (int i = 0; i < allocated->sizePos; i++)
		cout << allocated->arrPos[i] << " ";

	cout << endl << "Отрицательный массив: " << endl;
	for (int i = 0; i < allocated->sizeNeg; i++)
		cout << allocated->arrNeg[i] << " ";
	cout << endl;

	clear(allocated);
	system("pause");
}

AllocatedArrs* allocation(const int* arr, const size_t size)
{
	AllocatedArrs* allocated = new AllocatedArrs();

	//Подсчет размеров массивов
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			allocated->sizeNeg++;
		else if (arr[i] > 0)
			allocated->sizePos++;
	}

	allocated->arrPos = new int[allocated->sizePos];
	allocated->arrNeg = new int[allocated->sizeNeg];

	//Заполнение массивов
	for (int i = 0, p = 0, n = 0; i < size; i++)
	{
		if (arr[i] < 0)
			allocated->arrNeg[n++] = arr[i];
		else if (arr[i] > 0)
			allocated->arrPos[p++] = arr[i];
	}

	return allocated;
}

void clear(AllocatedArrs* allocated)
{
	delete[] allocated->arrPos;
	delete[] allocated->arrNeg;
	delete allocated;
}
*/
/*
//Вариант со структурой с векторами
struct AllocatedVects {
	vector<int> vectPos;	//Вектор положительных значений
	vector<int> vectNeg;	//Вектор отрицательных значений
};

AllocatedVects* allocation(const int* arr, const size_t size);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[10];							//Исходный массив
	AllocatedVects* allocated = nullptr;	//Структура с распределенными массивами

	//Заполнение и печать массива
	cout << "Исходный массив: " << endl;
	for (int& n : arr)
	{
		n = rand() % 200 - 100;
		cout << n << " ";
	}

	allocated = allocation(arr, sizeof(arr) / sizeof(arr[0]));

	cout << endl << "Положительный массив: " << endl;
	for (int& n : allocated->vectPos)
		cout << n << " ";

	cout << endl << "Отрицательный массив: " << endl;
	for (int& n : allocated->vectNeg)
		cout << n << " ";
	cout << endl;

	delete allocated;
	system("pause");
}

AllocatedVects* allocation(const int* arr, const size_t size)
{
	AllocatedVects* allocated = new AllocatedVects();

	//Заполнение векторов
	for (int i = 0, p = 0, n = 0; i < size; i++)
	{
		if (arr[i] < 0)
			allocated->vectNeg.push_back(arr[i]);
		else if (arr[i] > 0)
			allocated->vectPos.push_back(arr[i]);
	}

	return allocated;
}
*/


// ДЛИТЕЛЬНОСТЬ РАЗГОВОРОВ (ТЕЛЕФОНЫ)
// Есть таблица длительностей телефонных разговоров, включающий номера абонентов и длительности 
// разговоров, выполненная в виде массива структур struct TRec { int phone; float dt };. Номера 
// телефонов могут повторяться. Определить суммарное время разговора с каждого из телефонных номеров. 
// Выполнить обработку в функции, результат вернуть в виде таблицы без повторений телефонных номеров 
// в динамически созданным массиве или же векторе структур наименьшей возможной длины.
/*
//Вариант с динамическим массивом
struct TRec {
	int phone;
	float dt;
};

TRec* countCallsDurations(TRec* calls, const size_t size, size_t& sizeDur);

void main()
{
	setlocale(LC_ALL, "Russian");

	//Массив номеров и длительностей разговоров
	TRec calls[] = {
		{ 1000077, 6 }, { 4242424, 5 },
		{ 1155533, 9 }, { 1999999, 2 },
		{ 1111111, 5 }, { 1155533, 11 },
		{ 1111111, 6 }, { 1888888, 7 },
		{ 1000077, 5 }, { 1000077, 10 }
	};

	size_t sizeDur = 0; //Размер итогового массива

	//Итоговый массив номеров и суммарных длительностей разговоров
	TRec* durations = countCallsDurations(calls, sizeof(calls) / sizeof(calls[0]), sizeDur);

	cout << "Список разговоров: " << endl;
	for (TRec& call : calls)
		cout << "тел: " << call.phone << " минуты: " << call.dt << endl;

	cout << endl << "Список суммарных длительностей разговоров: " << endl;
	for (int i = 0; i < sizeDur; i++)
		cout << "тел: " << durations[i].phone << " минуты: " << durations[i].dt << endl;

	delete[] durations;
	system("pause");
}

TRec* countCallsDurations(TRec* calls, const size_t size, size_t& sizeDur)
{
	TRec* durations = nullptr;	//Итоговый массив

	size_t filled = 0;			//Текущее кол-во заполненных элементов в итоговом массиве

	sizeDur = 0;

	//Подсчет размера итогового массива
	for (int i = 0; i < size; i++)
	{
		bool isRepeated = false;	//Повторяется ли номер после текущего в исходном массиве

		for (int j = i + 1; j < size && !isRepeated; j++)
			if (calls[i].phone == calls[j].phone)
				isRepeated = true;

		if (!isRepeated)
			sizeDur++;
	}

	durations = new TRec[sizeDur];

	//Перебор номеров
	for (int i = 0; i < size; i++)
	{
		bool isExists = false;	//Существует ли уже номер в итоговом массиве

		//Поиск номера в итоговом массиве
		for (int j = 0; j < filled && !isExists; j++)
			if (calls[i].phone == durations[j].phone)
				isExists = true;

		if (isExists)
			continue;

		float duration = 0;		//Суммарная длительность для текущего номера

		//Подсчет суммарной длительности
		for (int j = i; j < size; j++)
			if (calls[i].phone == calls[j].phone)
				duration += calls[j].dt;

		//Добавление номера в итоговый массив
		durations[filled++] = TRec{ calls[i].phone, duration };
	}

	return durations;
}
*/
/*
//Вариант с вектором
struct TRec { 
	int phone; 
	float dt;
};

vector<TRec>* countCallsDurations(TRec* calls, const size_t size);

void main()
{
	setlocale(LC_ALL, "Russian");

	//Массив номеров и длительностей разговоров
	TRec calls[] = {
		{ 1000077, 6 }, { 4242424, 5 },
		{ 1155533, 9 }, { 1999999, 2 },
		{ 1111111, 5 }, { 1155533, 11 },
		{ 1111111, 6 }, { 1888888, 7 },
		{ 1000077, 5 }, { 1000077, 10 }
	};

	//Итоговый массив номеров и суммарных длительностей разговоров
	vector<TRec>* durations = countCallsDurations(calls, sizeof(calls) / sizeof(calls[0]));

	cout << "Список разговоров: " << endl;
	for (TRec& call : calls)
		cout << "тел: " << call.phone << " минуты: " << call.dt << endl;

	cout << endl << "Список суммарных длительностей разговоров: " << endl;
	for (TRec& call : *durations)
		cout << "тел: " << call.phone << " минуты: " << call.dt << endl;

	delete durations;
	system("pause");
}

vector<TRec>* countCallsDurations(TRec* calls, const size_t size)
{
	vector<TRec>* durations = new vector<TRec>;	//Итоговый массив

	//Перебор номеров
	for (int i = 0; i < size; i++)
	{
		bool isExists = false;	//Существует ли уже номер в итоговом массиве

		//Поиск номера в итоговом массиве
		for (int j = 0; j < durations->size() && !isExists; j++)
			if (calls[i].phone == (*durations)[j].phone)
				isExists = true;

		if (isExists)
			continue;

		float duration = 0;		//Суммарная длительность для текущего номера

		//Подсчет суммарной длительности
		for (int j = i; j < size; j++)
			if (calls[i].phone == calls[j].phone)
				duration += calls[j].dt;

		//Добавление номера в итоговый массив
		durations->push_back(TRec{ calls[i].phone, duration });
	}

	return durations;
}
*/


// ПАЛИНДРОМ-РЕКУРСИЯ
// Написать рекурсивную функцию, проверяющую, является ли заданная строка палиндромом, если при 
// сравнении все пробелы игнорируются (сложный палиндром). 
// Например, строка «А РОЗА УПАЛА НА ЛАПУ АЗОРА» - сложный палиндром.
/*
bool checkForComplPalindrome(char* pstart, char* pend);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];	//Строка
	size_t len;		//Длина строки

	cout << "Строка: ";
	cin.getline(str, sizeof(str));

	//Определение длины строки
	for (len = 0; str[len] != '\0'; len++);

	checkForComplPalindrome(str, str + len - 1) 
		? cout << "Строка является сложным палиндромом"
		: cout << "Строка не является сложным палиндромом";
	cout << endl;

	system("pause");
}

bool checkForComplPalindrome(char* pstart, char* pend)
{
	if (*pstart == ' ') pstart++;
	if (*pend == ' ') pend--;

	if (*pstart != *pend)
		return false;

	if (pstart == pend || pstart - pend == -1)
		return true;

	return checkForComplPalindrome(++pstart, --pend);
}
*/


// СИНТЕЗ*
// Между цифрами 1 2 3 4 5 6 7 8 9 можно не ставить знак операции или же ставить знак + или -. 
// Для заданного целого M нужно так расставить знаки операций, чтобы после вычисления получилось 
// значение M. Например, для M = 12 ответ: 12+3+4-5+6-7+8-9.
/*
int trace(const int* digits, const int M, char* signs, int i = 0, int res = 0);

void main()
{
	setlocale(LC_ALL, "Russian");

	int digits[] = { 1,2,3,4,5,6,7,8,9 };
	char signs[] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
	int M = 12;		//Заданный результат
	int variants;	//Кол-во вариантов расстановки

	cout << "M: ";
	cin >> M;

	variants = trace(digits, M, signs);

	variants ? cout << endl << "Всего вариантов: " << variants << endl
		: cout << endl << "Нет вариантов" << endl;

	system("pause");
}

int trace(const int* digits, const int M, char* signs, int i, int res)
{
	const int imax = 8;
	int variants = 0;	
		
	for (int d = 0, n = 0; d + i <= imax; d++)	//d - кол-во цифр, объединяемых в число
	{
		n = n * 10 + digits[i + d];				//Объединение цифр в число (1,2,3 -> 123)

		signs[i] = '+';
		if (d > 0) signs[i + d] = '_';

		variants += trace(digits, M, signs, i + d + 1, res + n);

		if (i > 0)	//Не добавлять '-' перед первой цифрой
		{
			signs[i] = '-';
			if (d > 0) signs[i + d] = '_';

			variants += trace(digits, M, signs, i + d + 1, res - n);
		}
	}
	
	if (i > imax && res == M)
	{
		//Печать цифр и знаков
		for (int j = 0; j <= imax; j++)
		{
			if (signs[j] != '_' && j > 0)
				cout << signs[j];
			cout << digits[j];
		}
		cout << " = " << res << endl;

		return 1;
	}

	return variants;
}
*/


// ПУТЬ*
// Функции передается двумерная таблица символов, в которой символом '#' помечены «стенки лабиринта», 
// а символом пробела - проходы. Функция должна, начиная с заданного свободного элемента (входа в 
// лабиринт) рекурсивно построить траекторию выхода из лабиринта, реализуя правило «правой руки» 
// и помечая пройденный путь символами '*'. Начальное и конечное состояние таблицы вывести в 
// консольное окно.

#define SIZE 8

struct Point {
	int x = -1;
	int y = -1;
};

enum DIRECTION:short { UP, RIGHT, DOWN, LEFT };

void walk(char map[][SIZE], const Point exit, const Point current, const DIRECTION direction = UP);

void main()
{
	setlocale(LC_ALL, "Russian");

	char map[SIZE][SIZE] = {
		{ '#', '#', '#', ' ', '#', '#', '#', '#' },
		{ '#', ' ', '#', ' ', ' ', ' ', ' ', '#' },
		{ '#', ' ', '#', '#', ' ', '#', ' ', '#' },
		{ '#', ' ', ' ', '#', ' ', '#', '#', '#' },
		{ '#', '#', ' ', '#', ' ', ' ', '#', '#' },
		{ '#', ' ', ' ', '#', '#', ' ', ' ', '#' },
		{ '#', '#', ' ', ' ', ' ', ' ', '#', '#' },
		{ '#', '#', '#', ' ', '#', '#', '#', '#' },
	};

	const Point entrance{ 7, 3 },	//Точка входа
				exit{ 0, 3 };		//Точка выхода

	cout << "Карта" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << map[i][j];
		cout << endl;
	}

	walk(map, exit, entrance);

	cout << endl << "Путь" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << map[i][j];
		cout << endl;
	}

	system("pause");
}

void walk(char map[][SIZE], const Point exit, const Point current, const DIRECTION direction)
{
	if (map[current.x][current.y] != '*')
		map[current.x][current.y] = '*';

	//Достигнута точка выхода
	if (current.y == exit.y && current.x == exit.x)
		return;
	
	Point next = current;					//Следующая точка маршрута
	DIRECTION nextDirection = direction;	//Следующее направление

	switch (direction) {
	case UP: {
		//Справа стена или граница
		if (map[current.x][current.y + 1] == '#' || current.y + 1 == SIZE)
		{
			//Спереди стена или граница
			if (map[current.x - 1][current.y] == '#' || current.x - 1 < 0)
			{
				nextDirection = LEFT;	//Поворот налево*
			}
			else
			{
				next = { current.x - 1, current.y };	//Ход вперед*
			}
		}
		else
		{
			//Поворот и ход вправо*
			nextDirection = RIGHT;
			next = { current.x, current.y + 1 };
		}

		break;
	}
	case RIGHT: {
		//Снизу стена или граница
		if (map[current.x + 1][current.y] == '#' || current.x + 1 == SIZE)
		{
			//Справа стена или граница
			if (map[current.x][current.y + 1] == '#' || current.y + 1 == SIZE)
			{
				nextDirection = UP;		//Поворот налево*
			}
			else
			{
				next = { current.x, current.y + 1 };	//Ход вперед*
			}
		}
		else
		{
			//Поворот и ход вправо*
			nextDirection = DOWN;
			next = { current.x + 1, current.y };
		}

		break;
	}
	case DOWN: {
		//Слева стена или граница
		if (map[current.x][current.y - 1] == '#' || current.y - 1 < 0)
		{
			//Снизу стена или граница
			if (map[current.x + 1][current.y] == '#' || current.x + 1 == SIZE)
			{
				nextDirection = RIGHT;	//Поворот налево*
			}
			else
			{
				next = { current.x + 1, current.y };	//Ход вперед*
			}
		}
		else
		{
			//Поворот и ход вправо*
			nextDirection = LEFT;
			next = { current.x, current.y - 1 };
		}

		break;
	}
	case LEFT: {
		//Сверху стена или граница
		if (map[current.x - 1][current.y] == '#' || current.x - 1 < 0)
		{
			//Слева стена или граница
			if (map[current.x][current.y - 1] == '#' || current.y - 1 == 0)
			{
				nextDirection = DOWN;	//Поворот налево*
			}
			else
			{
				next = { current.x, current.y - 1 };	//Ход вперед*
			}
		}
		else
		{
			//Поворот и ход вправо*
			nextDirection = UP;
			next = { current.x - 1, current.y };
		}

		break;
	}
	}
	// *Относительно указанного в direction
	
	walk(map, exit, next, nextDirection);
}

/*
// Вариант не по правилу правой руки, с ветвящейся рекурсией
#define SIZE 8

struct Point {
	int x = -1;
	int y = -1;
};

void walk(char map[][SIZE], const Point exit, const Point current, vector<Point> path = {});

void main()
{
	setlocale(LC_ALL, "Russian");

	char map[SIZE][SIZE] = {
		{ '#', '#', '#', ' ', '#', '#', '#', '#' },
		{ '#', ' ', '#', ' ', ' ', ' ', ' ', '#' },
		{ '#', ' ', '#', '#', ' ', '#', ' ', '#' },
		{ '#', ' ', ' ', '#', ' ', '#', '#', '#' },
		{ '#', '#', ' ', '#', ' ', ' ', '#', '#' },
		{ '#', ' ', ' ', '#', '#', ' ', ' ', '#' },
		{ '#', '#', ' ', ' ', ' ', ' ', '#', '#' },
		{ '#', '#', '#', ' ', '#', '#', '#', '#' },
	};

	const Point entrance{ 7, 3 },	//Точка входа
				exit{ 0, 3 };		//Точка выхода

	cout << "Карта" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << map[i][j];
		cout << endl;
	}

	walk(map, exit, entrance);

	cout << endl << "Путь" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			cout << map[i][j];
		cout << endl;
	}

	system("pause");
}

void walk(char map[][SIZE], const Point exit, const Point current, vector<Point> path)
{
	Point prev = path.size() ? path.back() : Point{};	//Предыдущая точка маршрута
	Point next;											//Следующая точка маршрута

	//Добавление точки в маршрут
	path.push_back(current);

	//Достигнута точка выхода
	if (current.y == exit.y && current.x == exit.x)
	{
		for (Point& s : path)
			map[s.x][s.y] = '*';

		return;
	}

	//Ход вправо
	next = { current.x, current.y + 1 };
	if (next.y < SIZE && map[next.x][next.y] != '#' && next.y != prev.y)
		walk(map, exit, next, path);

	//Ход вперед
	next = { current.x - 1, current.y };
	if (next.x >= 0 && map[next.x][next.y] != '#' && next.x != prev.x)
		walk(map, exit, next, path);

	//Ход влево
	next = { current.x, current.y - 1 };
	if (next.y >= 0 && map[next.x][next.y] != '#' && next.y != prev.y)
		walk(map, exit, next, path);

	//Ход назад
	next = { current.x + 1, current.y };
	if (next.x < SIZE && map[next.x][next.y] != '#' && next.x != prev.x)
		walk(map, exit, next, path);
}
*/
