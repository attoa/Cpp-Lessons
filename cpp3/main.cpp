#include <iostream>
#include <locale>
#include <vector>
#include "arrayfuncs.h"		//���� ������� ������� ��� ������ � ���������
using namespace std;


/*** ������ �� �������/������� � ����� ***/


// ��������. ���������� �������� ������� � �������� �������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[] = { 1,2,3,5,7,11,13,17,19,23 };	//������
	size_t size = sizeOfArray(arr);				//������ �������
	
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


// ��������� �������. ����� ������� �������������� ��� ��������� �������, ������� �� ��������� 
// �� � �����������, �� � ������������ �� ��� ���������. 
// ��������, ��� ������� int x[] = {5,7,3,-1,4,-1,7}; ��������� = (5+3+4)/3.0=4.0.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[10];	//������
	int min = 10,	//����������� ������� �������
		max = 0;	//������������ ������� �������

	int avgSum = 0,	//����� ��������� ������� ���������
		avgNum = 0; //���-�� ��������� ������� ���������

	for (int& n : arr)
	{
		//���������� �������
		n = rand() % 10;

		//����� ������������ � ������������� ��������
		if (min > n) min = n;
		if (max < n) max = n;
	}

	cout << "������: ";
	printArray(arr);
	cout << "����������� �������: " << min << endl;
	cout << "������������ �������: " << max << endl;

	//���������� ���������� ��������
	for (int& n : arr)
	{
		if (n != min && n != max)
		{
			avgSum += n;
			avgNum++;
		}
	}

	cout << "��������� �������: " << (float)avgSum / avgNum << endl;

	system("pause");
}
*/


// ������. �������� ������ ������� �� N �������. ����� ������� ������ �������, ����� ������� 
// ������� ��� ���� ��� �������� ��������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int N = 0;				//���-�� �������
	vector<float> incomes;	//������ ������� �� �������

	float sum = 0,			//����� ������� ��� ���������� ��������
		  average;			//������� �������� �������

	for (int i = 0; !cin.eof(); i++)
	{
		float income;		//�������� �����
		cout << "����� " << i << ", �����: ";
		cin >> income;

		if (!cin.eof())
		{
			N++;
			incomes.push_back(income);
			sum += income;
		}
	}

	average = sum / N;

	cout << "������, ����� ������� ������� ��� ���� �������� (" << average << "):" << endl;
	for (int i = 0; i < incomes.size(); i++)
	{
		if (incomes[i] > average)
			cout << " " << i;
	}
	cout << endl;

	system("pause");
}
*/


// ������. ������� �� ������� ��� ������������� ��������, ������� ������ ������� �� ������ ����.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[20];		//�������� ������
	vector<int> arr2;	//������ ������

	for (int i = 0; i < sizeOfArray(arr); i++)
	{		
		arr[i] = rand() % 10;	//���������� �������

		bool isExists = false;	//���������� �� ��� ������� ������� � ������ �������

		//����� �������� �������� � ������ �������
		for (int j = 0; j < arr2.size() && !isExists; j++)
			if (arr2[j] == arr[i])
				isExists = true;

		//���������� �������� � ������ ������, ���� ��� ��� �� ���������� � ���
		if (!isExists)
			arr2.push_back(arr[i]);
	}

	cout << "�������� ������" << endl;
	printArray(arr);
	cout << "������ ������" << endl;
	printArray(arr2);

	system("pause");
}
*/


// ��� ��������. �������� ������ ���� ������, �� ������� ���������� ��� �������� N �� ����� 
// �������� � ���� ���� (0-�����., 1-�����������, .., 6-����.). ����������: 
// �) ���������� ���� ��������, ������������ �� ������ �� ���� ������;
// 6) ����� ��� ������, �� ������� ���������� ������������ ����� ���� ��������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int weekDays[7] = { 0,0,0,0,0,0,0 };	//������ ���� �������� �� ���� ������
	int maxDay = 0;							//���� ������ � ������������ ������ ���� ��������

	while (!cin.eof())
	{
		int weekDay;	//����� ��� ������
		cout << "����� ��� ������: ";
		cin >> weekDay;

		if (cin.eof())
			break;

		if (weekDay >= 0 && weekDay <= 6)
			weekDays[weekDay]++;
		else
			cerr << "����� ������ ���� � ��������� �� 0 �� 6" << endl;
	}

	//����������� ��� ������ � ������������ ������ ���� ��������
	for (int i = 0; i < sizeOfArray(weekDays); i++)
		if (weekDays[i] > weekDays[maxDay])
			maxDay = i;

	printArray(weekDays);

	cout << "����� ��� ������ � ������������ ������ ���� ��������: " << maxDay << endl;

	system("pause");
}
*/


// ������� ������� �����. ���������� ������������ ����� ������ ������ ����� � �������� 
// ������������� �������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[20];			//������
	int maxZeroLen = 0;		//������������ ����� ������ ������ ����� � �������

	int currZeroLen = 0;	//������� ����� ������ ������ ����� � �������

	for (int& n : arr)
	{
		//���������� �������
		n = rand() % 3;	

		//����������� �������� ����� ������ ������ �����
		if (n == 0)
		{
			if (++currZeroLen > maxZeroLen)
				maxZeroLen = currZeroLen;
		}			
		else
			currZeroLen = 0;
	}

	cout << "������: ";
	printArray(arr);
	cout << "������������ ����� ������ ������ �����: " << maxZeroLen << endl;

	system("pause");
}
*/


// ������������ �������������� ������� ���������. �������� �����, ������� ����� �������� � 
// ���������� �������, ���������� �� ����������� ������ �� ����������� �� ��������, ��������� 
// ������ ����� ������� ������ ����� � ��� �������������� ����� ������� ����� �� ���������. 
// ���������� ������� ��� ������������� �������� ���������� � � �� ��������������.
/*
//������� ��� ������������� �������� ����������
void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[100];		//������
	size_t filled = 0;	//���-�� ����������� ��������� �������

	while (!cin.eof())
	{
		int n;			//�������� �����
		cout << "�����: ";
		cin >> n;

		if (cin.eof())
			break;

		//���������� � ������
		arr[filled] = n;

		//����������� �������� ����� �������
		for (int i = filled; i > 0 && arr[i] < arr[i - 1]; i--)
			swap(arr[i], arr[i - 1]);

		filled++;
	}

	cout << "������������� ������: ";
	for (int i = 0; i < filled; i++)
		cout << arr[i] << " ";
	cout << endl;

	system("pause");
}
*/
/*
//������� � �������������� �������� ����������
void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[100];		//������
	int* parr = arr;	//��������� �� ������� �������

	while (!cin.eof())
	{
		int n;			//�������� �����
		cout << "�����: ";
		cin >> n;

		if (cin.eof())
			break;

		//���������� ������ �������� � ������
		*parr = n;

		//����������� �������� ����� �������
		for (int* p = parr; p != arr && *p < *(p - 1); p--)
			swap(*p, *(p - 1));

		parr++;
	}

	cout << "������������� ������: ";
	for (int* p = arr; p != parr; p++)
		cout << *p << " ";
	cout << endl;

	system("pause");
}
*/


// ������������ ��������. �������� ����� ������ �� �������������� �� ��������� �������. ���������� 
// ������� ������ ������� ������� �� �������� ������. 
// � ����� �� ��������� ������� ������������ �������� ����������.
/*
//������� ��� ������������� �������� ����������
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int costs[10];						//������ ��������
	size_t size = sizeOfArray(costs);	//������ �������

	//���������� �������
	for (int i = 0; i < size; i++)
		costs[i] = rand() % 1000;

	cout << "������� �� �������: " << endl;
	printArray(costs);

	//���������� �� ��������
	for (int i = size - 1; i >= 0; i--)
		for (int j = i; j < size && costs[j] < costs[j + 1]; j++)
			swap(costs[j], costs[j + 1]);

	cout << "�������, ������������� �� ��������: " << endl;
	printArray(costs);

	system("pause");
}
*/
/*
//������� � �������������� �������� ����������
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int costs[10];						//������
	size_t size = sizeOfArray(costs);	//������ �������

	//���������� �������
	for (int* p = costs; p != costs + size; p++)
		*p = rand() % 1000;

	cout << "������� �� �������: " << endl;
	printArray(costs);

	//���������� �� ��������
	for (int* p = costs + size - 1; p != costs - 1; p--)
		for (int* pp = p; pp != costs + size && *pp < *(pp + 1); pp++)
			swap(*pp, *(pp + 1));

	cout << "�������, ������������� �� ��������: " << endl;
	printArray(costs);

	system("pause");
}
*/


// ����� ���. ������ ���������� (����� �����) ��� N ����� � M ���������� ����. ��������� ����� ���, 
// �������� ��������� �� ���������� � ���� ��������� ����.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int houses[6],		//������ ��������� �����
		noises[4];		//������ ��������� ���������� ����

	int mostSilent = 0;	//����� ����, �������� ���������� �� ���������� � ���� ��������� ����

	int maxDistance = 0;		//������������ ���������� ����� ����� � ���������� ����
	const int streetLen = 10;	//����� �����

	//���������� ��������
	for (int& house : houses)
		house = rand() % streetLen;
	for (int& noise : noises)
		noise = rand() % streetLen;

	//��������� ������ ������ ����
	for (int i = 0; i < sizeOfArray(houses); i++)
	{
		int currMinDistance = streetLen;	//����������� ���������� ��� �������� ����

		//����������� ���������� ����� ������� ����� � ������ ���������� ����
		for (int j = 0; j < sizeOfArray(noises); j++)
		{
			int distance = abs(houses[i] - noises[j]);

			if (distance < currMinDistance)
				currMinDistance = distance;
		}

		//������������ ���������� ����� �����������
		if (currMinDistance > maxDistance)
		{
			maxDistance = currMinDistance;
			mostSilent = i;
		}
	}

	cout << "������ ��������� �����: " << endl;
	printArray(houses);
	cout << "������ ��������� ���������� ����: " << endl;
	printArray(noises);

	cout << "� ������ ������ ����: " << mostSilent << " � �����. " << houses[mostSilent] << endl;

	//����������� ����������� ����� � ���������� ���� � ������������ � �� ������������
	cout << endl << "|";
	for (int coordinate = 0; coordinate < streetLen; coordinate++)
	{
		bool match = false;	//��������� �� �����. �� ����� � �����. ������-���� ����

		for (int& house : houses)
			if (house == coordinate)
				match = true;

		match ? cout << "O" : cout << " ";
	}
	cout << "|" << endl << "|";

	for (int coordinate = 0; coordinate < streetLen; coordinate++)
	{
		bool match = false;	//��������� �� �����. �� ����� � �����. ������-���� ��������� ����

		for (int& noise : noises)
			if (noise == coordinate)
				match = true;

		match ? cout << "*" : cout << " ";
	}
	cout << "|" << endl << endl;

	system("pause");
}
*/


// ������������ ����������. ���� ������ ������������� ���������� ����������, ���������� ������ 
// ��������� � ���� ������� ����������� ����� � ������������ ����������. ������ ��������� ����� 
// �����������. ���������� ��������� ����� ��������� � ������� �� ���������� �������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	const size_t SIZE = 10;

	//������ ������� � ������������ ����������
	unsigned long long calls[SIZE][2] = { { 89991000077, 6 }, { 89224242424, 5 },
										  { 88221155533, 9 }, { 81231999999, 2 }, 
										  { 89321111111, 5 }, { 88221155533, 11 },
										  { 89321111111, 6 }, { 86321888888, 7 }, 
										  { 89991000077, 5 }, { 89991000077, 10 } };

	//�������� ������ ������� � ��������� ������������� ����������
	vector<vector<unsigned long long>> durations;

	//������� �������
	for (int i = 0; i < SIZE; i++)
	{
		bool isExists = false;	//���������� �� ��� ����� � �������� �������

		//����� ������ � �������� �������
		for (int j = 0; j < durations.size() && !isExists; j++)
			if (calls[i][0] == durations[j][0])
				isExists = true;

		if (isExists)
			continue;

		unsigned long long duration = 0;	//��������� ������������ ��� �������� ������

		//������� ��������� ������������
		for (int j = i; j < SIZE; j++)
			if (calls[i][0] == calls[j][0])
				duration += calls[j][1];
		
		//���������� ������ � �������� ������
		durations.push_back(vector<unsigned long long>{calls[i][0], duration});
	}

	cout << "������ ����������: " << endl;
	for (int i = 0; i < SIZE; i++)
		cout << "���: " << calls[i][0] << " ������: " << calls[i][1] << endl;

	cout << endl << "������ ��������� ������������� ����������: " << endl;
	for (int i = 0; i < durations.size(); i++)
		cout << "���: " << durations[i][0] << " ������: " << durations[i][1] << endl;

	system("pause");
}
*/


// ���������� ��������. ������� ������ ������ ��������� ����������� ������������� ������������. 
// ����� ����� ������ ���������� ���������. ��������� ������ ���������, ������� �����������, 
// �������� ����������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	//������ ������ ���������
	unsigned int old[] = { 444555, 132333, 499999, 134111, 155555, 232323, 477477 };

	//������ ���������� ���������
	unsigned int outdated[] = { 444555, 134111, 155555, 588885, 511115 };

	//������ ������������� ���������
	vector<unsigned int> actual;

	//������� ������ ������ ���������
	for (int i = 0; i < sizeOfArray(old); i++)
	{
		bool isOutdated = false;	//���������� �� �������

		//����� �������� � ������ ���������� ���������
		for (int j = 0; j < sizeOfArray(outdated) && !isOutdated; j++)
			if (old[i] == outdated[j])
				isOutdated = true;

		//���������� �������� � ������ ������������� ���������
		if (!isOutdated)
			actual.push_back(old[i]);
	}

	cout << "����� ������ ���������: " << endl;
	printArray(old);

	cout << endl << "������ ���������� ���������: " << endl;
	printArray(outdated);

	cout << endl << "������ ������������� ���������: " << endl;
	printArray(actual);

	system("pause");
}
*/


// �������. � ��������� ������� P[i][j] ���������� �������� ����������� ��������� � ����� 
// ���������� �������������� ������������ (�� ����������) �� 0 �� 99, ���������� ��� �����������, 
// ��� i � ����� ��������� (i = 0, 1, .., N-1), � j - ����� ��������� ���������� (j = 0, 1). 
// ��������� ������ �������� ��������, �������� ������ � ��������� ��������� ��� ����� r1, r2 
// (r1 != r2) � ���������� ���������� ����������, ��������� 0, 1 ��� ��� �����. ������� ���������� 
// ����� � �������� �������� �� �����.
/*
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	const size_t SIZE = 10000;	//���-�� ����������

	const int DOWNLIMIT = 0,	//������ ������� ���������
			  UPLIMIT 	= 100;	//������� ������� ���������

	int P[SIZE][2];	//������ ��������� ����������

	int r1, r2;		//������������ �����

	//���-�� �������, ��������� 0, 1 ��� 2 �����
	int guessed0 = 0,
		guessed1 = 0,
		guessed2 = 0;

	//��������� �����
	r1 = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
	do
		r2 = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
	while (r1 == r2);

	for (int i = 0; i < SIZE; i++)
	{
		//��������� ���������
		P[i][0] = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
		do
			P[i][1] = rand() % (UPLIMIT - DOWNLIMIT) + DOWNLIMIT;
		while (P[i][0] == P[i][1]);

		int isGuessed = 0;	//���-�� �����, ��������� ������� ����������

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

	cout << "������� 0 �����: " << guessed0 << endl;
	cout << "������� 1 �����: " << guessed1 << endl;
	cout << "������� 2 �����: " << guessed2 << endl;

	system("pause");
}
*/


// ������� �����.* �������� ��������� ������ �������� dat � ������������� �� ����������� ������� 
// d[i] (i = 0, .., N-1) �� �������� � ������� �������� ��� ��������� (�� ���� ������������� 
// ���������������).
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int d[100];		//������ ������������� �� ����������� �����
	int dat;		//������� ��������

	int position;				//������� �������� �������� � �������
	int iterations = 0;			//���-�� ��������, ����������� �� ����� ��������

	size_t size = sizeOfArray(d);	//������ �������

	//���������� ������� ������� �� ����������� �������
	for (int i = 0; i < size; d[i++] = i);

	cout << "�����: ";
	cin >> dat;
	
	if (dat >= d[0] && dat <= d[size - 1])
	{
		//����� �����
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
		cout << "����� ������� � �������: " << position << " �� �������� " << iterations << endl;
	}
	else
		cerr << "����� ��� ���������" << endl;

	system("pause");
}
*/


// ����.* ������� ����� ���� ���������� ����. ��������� ���� �� ���� ����� ����� ���, ����� ������� 
// � ���� ��������� �����������. 

void main()
{
	setlocale(LC_ALL, "Russian");

	vector<unsigned int> weights;		//������ ����� ����
	vector<unsigned int> bowl1, bowl2;	//������� ����� �� 1� � 2� ����
	unsigned int sum1 = 0, sum2 = 0;	//����� ����� �� 1� � 2� ����

	while (!cin.eof())
	{
		int weight;	//��� ����
		cout << "��� ����: ";
		cin >> weight;

		if (cin.eof())
			break;

		//���������� � ������
		if (weight > 0)
			weights.push_back(weight);
		else
			cerr << "��� ������ ���� �������������" << endl;
	}

	//���������� ����� ���� �� ��������
	for (int i = 0; i < weights.size(); i++)
		for (int j = i; j > 0 && weights[j - 1] < weights[j]; j--)
			swap(weights[j - 1], weights[j]);

	//������������� ����� ���� �� �����
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

	cout << "���� ���� �� 1� ����: ";
	printArray(bowl1);
	cout << "����� = " << sum1 << endl;

	cout << "���� ���� �� 2� ����: ";
	printArray(bowl2);
	cout << "����� = " << sum2 << endl;

	system("pause");
}