#include <iostream>
#include <locale>
using namespace std;


/*** ЗАДАЧИ НА ЦИКЛЫ ***/


// ВКЛАД. Как увеличится вклад S, положенный пол A процентов годовых, за N месяцев при помесячном 
// начислении процентов?
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	float S;	//Размер вклада
	int   A;	//Процент годовых
	int	  N;	//Кол-во месяцев

	float S1;	//Конечный размер вклада

	cout << "Размер вклада: ";		cin >> S;
	cout << "Процент годовых: ";	cin >> A;
	cout << "Кол-во месяцев: ";		cin >> N;

	S1 = S;

	//За целое кол-во лет
	for (int i = 0; i < N / 12; i++)
		S1 += S1 / 100 * A;

	//За оставшееся кол-во месяцев
	S1 += S1 / 100.0 * (N % 12) * A / 12;

	cout << "Вклад увеличится на " << S1 - S << " и составит " << S1 << endl;

	system("pause");
}
*/


// ПОГОДА. Вводятся значения температуры по дням наблюдений до момента ввода Ctrl+z. Определить: 
// а) количество введенных температур; б) максимальную из них; в) минимальное значение среди 
// положительных температур; д) среднее среди отрицательных температур.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int   num = 0;		//Кол-во введенных температур
	float max;			//Максимальная из них
	float minPos = 0;	//Минимальная среди положительных температур
	float avrNeg = 0;	//Средняя среди отрицательных температур

	//Для вычисления средней среди отрицательных
	int   numNeg = 0;	//Кол-во отрицательных температур
	float sumNeg = 0;	//Сумма отрицательных температур 

	while (!cin.eof())
	{
		float t;	//Значение температуры
		cout << "Значение температуры: ";
		cin >> t;

		if (cin.eof())
			break;

		//Кол-во введенных температур
		num++;

		//Максимальная из них
		if (num == 1 || max < t)
			max = t;

		//Минимальная среди положительных
		if (t > 0 && (minPos > t || minPos == 0))
			minPos = t;

		//Для средней среди отрицательных
		if (t < 0)
		{
			numNeg++;
			sumNeg += t;
		}
	}	

	//Если кол-во введенных температур не 0
	if (num)
	{
		if (numNeg)
			avrNeg = sumNeg / numNeg;

		cout << "Кол-во введенных температур: " << num << endl;
		cout << "Максимальная из них: " << max << endl;

		cout << "Минимальная среди положительных: ";
		if (minPos) cout << minPos << endl;
		else cout << "--" << endl;

		cout << "Средняя среди отрицательных: ";
		if (numNeg) cout << avrNeg << endl;
		else cout << "--" << endl;
	}

	system("pause");
}
*/


// ПЕРЕВЕРНУТОЕ ЧИСЛО. Сформировать в отдельной переменной значение целого числа, все десятичные 
// цифры которого расположены в обратном порядке по отношению к цифрам введенного натурального 
// числа N. Финальные нули числа N в "перевернутом" числе - опустить.
// При написании программы массивы не использовать.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	long long N;		//Исходное число
	long long M = 0;	//Перевернутое число

	cout << "Число: ";
	cin >> N;

	while (N > 0)
	{
		M *= 10;
		M += N % 10;
		N /= 10;
	}

	cout << M << endl;

	system("pause");
}
*/


// ЦЕНЫ. Определить пределы колебания цен на масло в N торговых точках города. Цены должны вводиться.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int   N = 0;		//Кол-во торговых точек
	float maxPrice = 0;	//Максимальная цена
	float minPrice = 0;	//Минимальная цена

	while (!cin.eof())
	{
		float price;	//Вводимая цена
		cout << "Цена: ";
		cin >> price;

		if (cin.eof())
			break;

		N++;

		if (price > maxPrice)
			maxPrice = price;

		if (price < minPrice || minPrice == 0)
			minPrice = price;
	}

	if (N)
	{
		cout << "Кол-во торговых точек: " << N << endl;
		cout << "Максимальная цена: " << maxPrice << endl;
		cout << "Минимальная цена: " << minPrice << endl;
	}

	system("pause");
}
*/


// НАИМЕНЬШАЯ / НАИБОЛЬШАЯ ЦИФРА. Для каждого вводимого положительного целого числа определить: 
// а) наименьшую десятичную цифру в его записи; б) наибольшую цифру в разрядах с нечетными номерами.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	while (!cin.eof())
	{
		int N;		//Вводимое число
		cout << "Число: ";
		cin >> N;

		if (cin.eof())
			break;

		if (N <= 0)
		{
			cerr << "Число должно быть положительным" << endl;
			continue;
		}

		int minDigit	= 9;	//Наименьшая десятичная цифра
		int maxDigitOdd = 0;	//Наибольшая цифра в нечетных разрядах
		bool isOdd = true;		//Нечетный ли разряд текущей цифры

		while (N > 0)
		{
			int currDigit = N % 10;	//Текущая цифра

			if (currDigit < minDigit)
				minDigit = currDigit;

			if (isOdd && currDigit > maxDigitOdd)
				maxDigitOdd = currDigit;

			N /= 10;
			isOdd = !isOdd;
		}

		cout << "Наименьшая десятичная цифра: " << minDigit << endl;
		cout << "Наибольшая цифра в нечетных разрядах: " << maxDigitOdd << endl;
	}

	system("pause");
}
*/


// ЛОТЕРЕЯ. Для заданных в программе результатов розыгрыша лотереи, состоящей в определении двух 
// различных чисел r1, r2 (r1 != r2), а также для присланных многими участниками лотереи прогнозов 
// p1, p2 (p1 != p2) определить количество человек, угадавших 0, 1 или 2 числа. Считать, что 
// порядок следования чисел p1, p2 в прогнозе участника значения не имеет.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	//Отгадываемые числа
	int r1 = 2,
		r2 = 4;	

	//Кол-ва человек, угадавших 0, 1 или 2 числа
	int guessed0 = 0,
		guessed1 = 0,
		guessed2 = 0;

	while (!cin.eof())
	{
		int p1, p2;		//Прогнозы участников
		cout << "p1 и p2: ";
		cin >> p1 >> p2;

		if (cin.eof())
			break;

		if (p1 == p2)
		{
			cerr << "Числа должны быть различны" << endl;
			continue;
		}

		int isGuessed = 0;	//Кол-во чисел, угаданных текущим участником

		if (p1 == r1 || p1 == r2)
			isGuessed++;
		if (p2 == r1 || p2 == r2)
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


// СОМНОЖИТЕЛИ. Представить любое целое положительное N в виде произведения простых сомножителей 
// (которые делятся на 1 и на себя). Пример: 12 = 1*2*2*3.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	while (!cin.eof())
	{
		int N;		//Вводимое число
		cout << "Число: ";
		cin >> N;

		if (cin.eof())
			break;

		if (N <= 0)
		{
			cerr << "Число должно быть положительным" << endl;
			continue;
		}

		int quotient = N;	//Частное от деления на сомножитель

		cout << "=" << 1;

		//Поиск сомножителей
		for (int factor = 2; factor < N / 2; factor++)
		{
			while (quotient % factor == 0)
			{
				cout << "*" << factor;
				quotient /= factor;
			}
		}

		//Если число оказалось простым
		if (quotient == N)
			cout << "*" << N;

		cout << endl;
	}

	system("pause");
}
*/


// РОСТ КУРСА. Вводятся значения курса валюты за N дней. Определить долю (или процент) количества 
// дней, когда наблюдалось возрастание курса валюты. Определить также длину самого продолжительного 
// участка роста.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int N = 0;			//Кол-во дней
	int growthDays = 0;	//Кол-во дней возрастания курса валюты
	int maxLength  = 0;	//Длина самого продолжительного участка роста

	float ratePrev = 0;	//Курс валюты в предыдущий день
	int currLength = 0;	//Текущая длина участка роста

	while (!cin.eof())
	{
		float rate;		//Курс валюты
		cout << "Курс валюты: ";
		cin >> rate;

		if (cin.eof())
			break;

		if (rate <= 0)
		{
			cerr << "Число должно быть положительным" << endl;
			continue;
		}

		N++;

		if (N == 1)
		{
			ratePrev = rate;
			continue;
		}

		if (rate > ratePrev)
		{
			growthDays++;
			currLength++;

			if (currLength > maxLength)
				maxLength = currLength;
		}
		else
			currLength = 0;

		ratePrev = rate;
	}

	cout << "Процент дней возрастания курса валюты: " << 100 / N * growthDays << endl;		 
	cout << "Длина самого продолжительного участка роста: " << maxLength << endl;

	system("pause");
}
*/


// ЗАДАЧА Л.ЭЙЛЕРА. Господин N купил лошадей и быков на 1770 талеров. За каждую лошадь он уплатил 
// по 31 талеру, за каждого быка по 21 талеру. Сколько лошадей и быков купил господин N?

void main()
{
	setlocale(LC_ALL, "Russian");

	const int sum = 1770,		//Суммарная стоимость
			  horsePrice = 31,	//Стоимость 1 лошади
			  bullPrice  = 21;	//Стоимость 1 быка

	for (int horseNum = 1; horseNum * horsePrice < sum; horseNum++)
	{
		int bullSum = sum - horseNum * horsePrice;	//Суммарная стоимость быков

		//Если суммарная стоимость быков кратна стоимости 1 быка
		if (bullSum % bullPrice == 0)
			cout << horseNum << " лошадей и " << bullSum / bullPrice << " быков" << endl;
	}

	system("pause");
}