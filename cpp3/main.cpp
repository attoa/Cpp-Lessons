#include <iostream>
#include <locale>
#include <vector>
#include "arrayfuncs.h"		//Файл базовых функций для работы с массивами
using namespace std;


/*** ЗАДАЧИ НА МАССИВЫ/ВЕКТОРЫ И ЦИКЛЫ ***/


// ИНВЕРСИЯ. Разместить элементы массива в обратном порядке.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[] = { 1,2,3,5,7,11,13,17,19,23 };	//Массив
	size_t size = sizeOfArray(arr);				//Размер массива
	
	printArray(arr);

	for (int i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
	}
	
	printArray(arr);

	system("pause");
}
*/


// УСЕЧЕННОЕ СРЕДНЕЕ. Найти среднее арифметическое тех элементов массива, которые не совпадают 
// ни с минимальным, ни с максимальным из его элементов. 
// Например, для массива int x[] = {5,7,3,-1,4,-1,7}; результат = (5+3+4)/3.0=4.0.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[10];	//Массив
	int min = 10,	//Минимальный элемент массива
		max = 0;	//Максимальный элемент массива

	int avgSum = 0,	//Сумма усеченных средних элементов
		avgNum = 0; //Кол-во усеченных средних элементов

	for (int& n : arr)
	{
		//Заполнение массива
		n = rand() % 10;

		//Поиск минимального и максимального элемента
		if (min > n) min = n;
		if (max < n) max = n;
	}

	cout << "Массив: ";
	printArray(arr);
	cout << "Минимальный элемент: " << min << endl;
	cout << "Максимальный элемент: " << max << endl;

	//Вычисление усеченного среднего
	for (int& n : arr)
	{
		if (n != min && n != max)
		{
			avgSum += n;
			avgNum++;
		}
	}

	cout << "Усеченное среднее: " << (float)avgSum / avgNum << endl;

	system("pause");
}
*/


// ДОХОДЫ. Вводятся уровни доходов за N месяцев. Нужно вывести номера месяцев, когда уровень 
// доходов был выше его среднего значения.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int N = 0;				//Кол-во месяцев
	vector<float> incomes;	//Массив доходов по месяцам

	float sum = 0,			//Сумма доходов для вычисления среднего
		  average;			//Среднее значение доходов

	for (int i = 0; !cin.eof(); i++)
	{
		float income;		//Вводимый доход
		cout << "Месяц " << i << ", доход: ";
		cin >> income;

		if (!cin.eof())
		{
			N++;
			incomes.push_back(income);
			sum += income;
		}
	}

	average = sum / N;

	cout << "Месяцы, когда уровень доходов был выше среднего (" << average << "):" << endl;
	for (int i = 0; i < incomes.size(); i++)
	{
		if (incomes[i] > average)
			cout << " " << i;
	}
	cout << endl;

	system("pause");
}
*/


// СЖАТИЕ. Удалить из массива все повторяющиеся элементы, оставив каждый элемент по одному разу.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[20];		//Исходный массив
	vector<int> arr2;	//Сжатый массив

	for (int i = 0; i < sizeOfArray(arr); i++)
	{		
		arr[i] = rand() % 10;	//Заполнение массива

		bool isExists = false;	//Существует ли уже текущий элемент в сжатом массиве

		//Поиск текущего элемента в сжатом массиве
		for (int j = 0; j < arr2.size() && !isExists; j++)
			if (arr2[j] == arr[i])
				isExists = true;

		//Добавление элемента в сжатый массив, если его еще не существует в нем
		if (!isExists)
			arr2.push_back(arr[i]);
	}

	cout << "Исходный массив" << endl;
	printArray(arr);
	cout << "Сжатый массив" << endl;
	printArray(arr2);

	system("pause");
}
*/


// ДНИ РОЖДЕНИЯ. Вводятся номера дней недели, на которые приходятся дни рождения N из Ваших 
// знакомых в этом году (0-воскр., 1-понедельник, .., 6-субб.). Определить: 
// а) количество дней рождений, приходящихся на каждый из дней недели;
// 6) номер дня недели, на который приходится максимальное число дней рождения.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int weekDays[7] = { 0,0,0,0,0,0,0 };	//Массив дней рождения по дням недели
	int maxDay = 0;							//День недели с максимальным числом дней рождения

	while (!cin.eof())
	{
		int weekDay;	//Номер дня недели
		cout << "Номер дня недели: ";
		cin >> weekDay;

		if (cin.eof())
			break;

		if (weekDay >= 0 && weekDay <= 6)
			weekDays[weekDay]++;
		else
			cerr << "Число должно быть в диапазоне от 0 до 6" << endl;
	}

	//Определение дня недели с максимальным числом дней рождения
	for (int i = 0; i < sizeOfArray(weekDays); i++)
		if (weekDays[i] > weekDays[maxDay])
			maxDay = i;

	printArray(weekDays);

	cout << "Номер дня недели с максимальным числом дней рождения: " << maxDay << endl;

	system("pause");
}
*/


// ДЛИННАЯ ЦЕПОЧКА НУЛЕЙ. Определить максимальное число подряд идущих нулей в числовом 
// целочисленном массиве.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[20];			//Массив
	int maxZeroLen = 0;		//Максимальное число подряд идущих нулей в массиве

	int currZeroLen = 0;	//Текущее число подряд идущих нулей в массиве

	for (int& n : arr)
	{
		//Заполнение массива
		n = rand() % 3;	

		//Определение текущего числа подряд идущих нулей
		if (n == 0)
		{
			if (++currZeroLen > maxZeroLen)
				maxZeroLen = currZeroLen;
		}			
		else
			currZeroLen = 0;
	}

	cout << "Массив: ";
	printArray(arr);
	cout << "Максимальное число подряд идущих нулей: " << maxZeroLen << endl;

	system("pause");
}
*/


// ФОРМИРОВАНИЕ УПОРЯДОЧЕННОГО МАССИВА ВСТАВКАМИ. Вводятся числа, которые нужно помешать в 
// достаточно большой, изначально не заполненный массив по возрастанию их значений, определяя 
// нужное место вставки нового числа в уже сформированную часть массива путем ее просмотра. 
// Предложить решение без использования адресной арифметики и с ее использованием.
/*
//Вариант без использования адресной арифметики
void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[100];		//Массив
	size_t filled = 0;	//Кол-во заполненных элементов массива

	while (!cin.eof())
	{
		int n;			//Вводимое число
		cout << "Число: ";
		cin >> n;

		if (cin.eof())
			break;

		//Добавление в массив
		arr[filled] = n;

		//Перемещение элемента вдоль массива
		for (int i = filled; i > 0 && arr[i] < arr[i - 1]; i--)
			swap(arr[i], arr[i - 1]);

		filled++;
	}

	cout << "Упорядоченный массив: ";
	for (int i = 0; i < filled; i++)
		cout << arr[i] << " ";
	cout << endl;

	system("pause");
}
*/
/*
//Вариант с использованием адресной арифметики
void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[100];		//Массив
	int* parr = arr;	//Указатель на элемент массива

	while (!cin.eof())
	{
		int n;			//Вводимое число
		cout << "Число: ";
		cin >> n;

		if (cin.eof())
			break;

		//Добавление нового элемента в массив
		*parr = n;

		//Перемещение элемента вдоль массива
		for (int* p = parr; p != arr && *p < *(p - 1); p--)
			swap(*p, *(p - 1));

		parr++;
	}

	cout << "Упорядоченный массив: ";
	for (int* p = arr; p != parr; p++)
		cout << *p << " ";
	cout << endl;

	system("pause");
}
*/


// УПОРЯДОЧЕНИЕ РАСХОДОВ. Известны суммы оплаты за электроэнергию за несколько месяцев. Необходимо 
// вывести список номеров месяцев по убыванию оплаты. 
// В одном из вариантов решения использовать адресную арифметику.
/*
//Вариант без использования адресной арифметики
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int costs[10];						//Массив расходов
	size_t size = sizeOfArray(costs);	//Размер массива

	//Заполнение массива
	for (int i = 0; i < size; i++)
		costs[i] = rand() % 1000;

	cout << "Расходы по месяцам: " << endl;
	printArray(costs);

	//Сортировка по убыванию
	for (int i = size - 1; i >= 0; i--)
		for (int j = i; j < size && costs[j] < costs[j + 1]; j++)
			swap(costs[j], costs[j + 1]);

	cout << "Расходы, упорядоченные по убыванию: " << endl;
	printArray(costs);

	system("pause");
}
*/
/*
//Вариант с использованием адресной арифметики
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int costs[10];						//Массив
	size_t size = sizeOfArray(costs);	//Размер массива

	//Заполнение массива
	for (int* p = costs; p != costs + size; p++)
		*p = rand() % 1000;

	cout << "Расходы по месяцам: " << endl;
	printArray(costs);

	//Сортировка по убыванию
	for (int* p = costs + size - 1; p != costs - 1; p--)
		for (int* pp = p; pp != costs + size && *pp < *(pp + 1); pp++)
			swap(*pp, *(pp + 1));

	cout << "Расходы, упорядоченные по убыванию: " << endl;
	printArray(costs);

	system("pause");
}
*/


// ТИХИЙ ДОМ. Заданы координаты (вдоль улицы) для N домов и M источников шума. Требуется найти дом, 
// наиболее удаленный от ближайшего к нему источника шума.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int houses[6],		//Массив координат домов
		noises[4];		//Массив координат источников шума

	int mostSilent = 0;	//Номер дома, наиболее удаленного от ближайшего к нему источника шума

	int maxDistance = 0;		//Максимальное расстояние между домом и источником шума
	const int streetLen = 10;	//Длина улицы

	//Заполнение массивов
	for (int& house : houses)
		house = rand() % streetLen;
	for (int& noise : noises)
		noise = rand() % streetLen;

	//Опредение самого тихого дома
	for (int i = 0; i < sizeOfArray(houses); i++)
	{
		int currMinDistance = streetLen;	//Минимальное расстояние для текущего дома

		//Определение расстояния между текущим домом и каждым источником шума
		for (int j = 0; j < sizeOfArray(noises); j++)
		{
			int distance = abs(houses[i] - noises[j]);

			if (distance < currMinDistance)
				currMinDistance = distance;
		}

		//Максимальное расстояние среди минимальных
		if (currMinDistance > maxDistance)
		{
			maxDistance = currMinDistance;
			mostSilent = i;
		}
	}

	cout << "Массив координат домов: " << endl;
	printArray(houses);
	cout << "Массив координат источников шума: " << endl;
	printArray(noises);

	cout << "№ самого тихого дома: " << mostSilent << " с коорд. " << houses[mostSilent] << endl;

	//Графическое отображение домов и источников шума в соответствии с их координатами
	cout << endl << "|";
	for (int coordinate = 0; coordinate < streetLen; coordinate++)
	{
		bool match = false;	//Совпадает ли коорд. на улице с коорд. какого-либо дома

		for (int& house : houses)
			if (house == coordinate)
				match = true;

		match ? cout << "O" : cout << " ";
	}
	cout << "|" << endl << "|";

	for (int coordinate = 0; coordinate < streetLen; coordinate++)
	{
		bool match = false;	//Совпадает ли коорд. на улице с коорд. какого-либо источника шума

		for (int& noise : noises)
			if (noise == coordinate)
				match = true;

		match ? cout << "*" : cout << " ";
	}
	cout << "|" << endl << endl;

	system("pause");
}
*/


// ДЛИТЕЛЬНОСТИ РАЗГОВОРОВ. Есть список длительностей телефонных разговоров, включающий номера 
// телефонов в виде длинных беззнаковых целых и длительности разговоров. Номера телефонов могут 
// повторяться. Определить суммарное время разговора с каждого из телефонных номеров.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	const size_t SIZE = 10;

	//Массив номеров и длительности разговоров
	unsigned long long calls[SIZE][2] = { { 89991000077, 6 }, { 89224242424, 5 },
										  { 88221155533, 9 }, { 81231999999, 2 }, 
										  { 89321111111, 5 }, { 88221155533, 11 },
										  { 89321111111, 6 }, { 86321888888, 7 }, 
										  { 89991000077, 5 }, { 89991000077, 10 } };

	//Итоговый массив номеров и суммарных длительностей разговоров
	vector<vector<unsigned long long>> durations;

	//Перебор номеров
	for (int i = 0; i < SIZE; i++)
	{
		bool isExists = false;	//Существует ли уже номер в итоговом массиве

		//Поиск номера в итоговом массиве
		for (int j = 0; j < durations.size() && !isExists; j++)
			if (calls[i][0] == durations[j][0])
				isExists = true;

		if (isExists)
			continue;

		unsigned long long duration = 0;	//Суммарная длительность для текущего номера

		//Подсчет суммарной длительности
		for (int j = i; j < SIZE; j++)
			if (calls[i][0] == calls[j][0])
				duration += calls[j][1];
		
		//Добавление номера в итоговый массив
		durations.push_back(vector<unsigned long long>{calls[i][0], duration});
	}

	cout << "Список разговоров: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << "тел: " << calls[i][0] << " минуты: " << calls[i][1] << endl;

	cout << endl << "Список суммарных длительностей разговоров: " << endl;
	for (int i = 0; i < durations.size(); i++)
		cout << "тел: " << durations[i][0] << " минуты: " << durations[i][1] << endl;

	system("pause");
}
*/


// АКТУАЛЬНЫЕ ТЕЛЕФОНЫ. Имеется список старых телефонов предприятий коммунального обслуживания. 
// Задан также список устаревших телефонов. Составить список телефонов, которые сохранились, 
// исключив устаревшие.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	//Список старых телефонов
	unsigned int old[] = { 444555, 132333, 499999, 134111, 155555, 232323, 477477 };

	//Список устаревших телефонов
	unsigned int outdated[] = { 444555, 134111, 155555, 588885, 511115 };

	//Список сохранившихся телефонов
	vector<unsigned int> actual;

	//Перебор списка старых телефонов
	for (int i = 0; i < sizeOfArray(old); i++)
	{
		bool isOutdated = false;	//Устаревший ли телефон

		//Поиск телефона в списке устаревших телефонов
		for (int j = 0; j < sizeOfArray(outdated) && !isOutdated; j++)
			if (old[i] == outdated[j])
				isOutdated = true;

		//Добавление телефона в список сохранившихся телефонов
		if (!isOutdated)
			actual.push_back(old[i]);
	}

	cout << "Спиок старых телефонов: " << endl;
	printArray(old);

	cout << endl << "Список устаревших телефонов: " << endl;
	printArray(outdated);

	cout << endl << "Список сохранившихся телефонов: " << endl;
	printArray(actual);

	system("pause");
}
*/


// ЛОТЕРЕЯ. В двумерном массиве P[i][j] содержатся прогнозы результатов розыгрыша с двумя 
// различными целочисленными результатами (со значениями) от 0 до 99, присланные его участниками, 
// где i — номер участника (i = 0, 1, .., N-1), а j - номер числового результата (j = 0, 1). 
// Программа должна провести розыгрыш, случайно выбрав в указанном диапазоне два числа r1, r2 
// (r1 != r2) и определить количество участников, угадавших 0, 1 или оба числа. Порядок следования 
// чисел в прогнозе значения не имеет.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	const size_t SIZE = 10000;	//Кол-во участников

	const int DOWNLIMIT = 0,	//Нижняя граница диапазона
			  UPLIMIT 	= 100;	//Верхняя граница диапазона

	int P[SIZE][2];	//Массив прогнозов участников

	int r1, r2;		//Отгадываемые числа

	//Кол-ва человек, угадавших 0, 1 или 2 числа
	int guessed0 = 0,
		guessed1 = 0,
		guessed2 = 0;

	//Генерация чисел
	r1 = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
	do
		r2 = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
	while (r1 == r2);

	for (int i = 0; i < SIZE; i++)
	{
		//Генерация прогнозов
		P[i][0] = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
		do
			P[i][1] = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
		while (P[i][0] == P[i][1]);

		int isGuessed = 0;	//Кол-во чисел, угаданных текущим участником

		if (P[i][0] == r1 || P[i][0] == r2)
			isGuessed++;
		if (P[i][1] == r1 || P[i][1] == r2)
			isGuessed++;

		switch (isGuessed)
		{
			case 0: guessed0++; break;
			case 1: guessed1++; break;
			case 2: guessed2++; break;
		}
	}

	cout << "Угадали 0 чисел: " << guessed0 << endl;
	cout << "Угадали 1 число: " << guessed1 << endl;
	cout << "Угадали 2 числа: " << guessed2 << endl;

	system("pause");
}
*/


// БЫСТРЫЙ ПОИСК.* Написать программу поиска значения dat в упорядоченном по возрастанию массиве 
// d[i] (i = 0, .., N-1) не прибегая к полному перебору его элементов (за счет использования 
// упорядоченности).
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int d[100];		//Массив упорядоченных по возрастанию чисел
	int dat;		//Искомое значение

	int position;				//Позиция искомого элемента в массиве
	int iterations = 0;			//Кол-во итераций, затраченных на поиск элемента

	size_t size = sizeOfArray(d);	//Размер массива

	//Заполнение массива идущими по возрастанию числами
	for (int i = 0; i < size; d[i++] = i);

	cout << "Число: ";
	cin >> dat;
	
	if (dat >= d[0] && dat <= d[size - 1])
	{
		//Поиск числа
		for (int left = 0, right = size - 1; ;iterations++)
		{
			int middle = left + (right - left) / 2;

			if (dat == d[middle])
			{
				position = middle;
				break;
			}

			if (dat > d[middle])
				left = middle;
			else
				right = middle;
		}
		cout << "Число найдено в позиции: " << position << " на итерации " << iterations << endl;
	}
	else
		cerr << "Число вне диапазона" << endl;

	system("pause");
}
*/


// ГИРИ.* Имеется набор гирь известного веса. Разложить гири по двум чашам весов так, чтобы разница 
// в весе оказалась минимальной. 

void main()
{
	setlocale(LC_ALL, "Russian");

	vector<unsigned int> weights;		//Массив весов гирь
	vector<unsigned int> bowl1, bowl2;	//Массивы весов на 1й и 2й чаше
	unsigned int sum1 = 0, sum2 = 0;	//Суммы весов на 1й и 2й чаше

	while (!cin.eof())
	{
		int weight;	//Вес гири
		cout << "Вес гири: ";
		cin >> weight;

		if (cin.eof())
			break;

		//Добавление в массив
		if (weight > 0)
			weights.push_back(weight);
		else
			cerr << "Вес должен быть положительным" << endl;
	}

	//Сортировка весов гирь по убыванию
	for (int i = 0; i < weights.size(); i++)
		for (int j = i; j > 0 && weights[j - 1] < weights[j]; j--)
			swap(weights[j - 1], weights[j]);

	//Распределение весов гирь по чашам
	for (unsigned int& weight : weights)
	{
		if (sum1 <= sum2)
		{
			bowl1.push_back(weight);
			sum1 += weight;
		}
		else
		{
			bowl2.push_back(weight);
			sum2 += weight;
		}
	}

	cout << "Веса гирь на 1й чаше: ";
	printArray(bowl1);
	cout << "Сумма = " << sum1 << endl;

	cout << "Веса гирь на 2й чаше: ";
	printArray(bowl2);
	cout << "Сумма = " << sum2 << endl;

	system("pause");
}