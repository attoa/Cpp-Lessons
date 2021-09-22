#include <iostream>
#include <locale>
using namespace std;


/*** ������ �� ����� ***/


// �����. ��� ���������� ����� S, ���������� ��� A ��������� �������, �� N ������� ��� ���������� 
// ���������� ���������?
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	float S;	//������ ������
	int   A;	//������� �������
	int	  N;	//���-�� �������

	float S1;	//�������� ������ ������

	cout << "������ ������: ";		cin >> S;
	cout << "������� �������: ";	cin >> A;
	cout << "���-�� �������: ";		cin >> N;

	S1 = S;

	//�� ����� ���-�� ���
	for (int i = 0; i < N / 12; i++)
		S1 += S1 / 100 * A;

	//�� ���������� ���-�� �������
	S1 += S1 / 100.0 * (N % 12) * A / 12;

	cout << "����� ���������� �� " << S1 - S << " � �������� " << S1 << endl;

	system("pause");
}
*/


// ������. �������� �������� ����������� �� ���� ���������� �� ������� ����� Ctrl+z. ����������: 
// �) ���������� ��������� ����������; �) ������������ �� ���; �) ����������� �������� ����� 
// ������������� ����������; �) ������� ����� ������������� ����������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int   num = 0;		//���-�� ��������� ����������
	float max;			//������������ �� ���
	float minPos = 0;	//����������� ����� ������������� ����������
	float avrNeg = 0;	//������� ����� ������������� ����������

	//��� ���������� ������� ����� �������������
	int   numNeg = 0;	//���-�� ������������� ����������
	float sumNeg = 0;	//����� ������������� ���������� 

	while (!cin.eof())
	{
		float t;	//�������� �����������
		cout << "�������� �����������: ";
		cin >> t;

		if (cin.eof())
			break;

		//���-�� ��������� ����������
		num++;

		//������������ �� ���
		if (num == 1 || max < t)
			max = t;

		//����������� ����� �������������
		if (t > 0 && (minPos > t || minPos == 0))
			minPos = t;

		//��� ������� ����� �������������
		if (t < 0)
		{
			numNeg++;
			sumNeg += t;
		}
	}	

	//���� ���-�� ��������� ���������� �� 0
	if (num)
	{
		if (numNeg)
			avrNeg = sumNeg / numNeg;

		cout << "���-�� ��������� ����������: " << num << endl;
		cout << "������������ �� ���: " << max << endl;

		cout << "����������� ����� �������������: ";
		if (minPos) cout << minPos << endl;
		else cout << "--" << endl;

		cout << "������� ����� �������������: ";
		if (numNeg) cout << avrNeg << endl;
		else cout << "--" << endl;
	}

	system("pause");
}
*/


// ������������ �����. ������������ � ��������� ���������� �������� ������ �����, ��� ���������� 
// ����� �������� ����������� � �������� ������� �� ��������� � ������ ���������� ������������ 
// ����� N. ��������� ���� ����� N � "������������" ����� - ��������.
// ��� ��������� ��������� ������� �� ������������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	long long N;		//�������� �����
	long long M = 0;	//������������ �����

	cout << "�����: ";
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


// ����. ���������� ������� ��������� ��� �� ����� � N �������� ������ ������. ���� ������ ���������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int   N = 0;		//���-�� �������� �����
	float maxPrice = 0;	//������������ ����
	float minPrice = 0;	//����������� ����

	while (!cin.eof())
	{
		float price;	//�������� ����
		cout << "����: ";
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
		cout << "���-�� �������� �����: " << N << endl;
		cout << "������������ ����: " << maxPrice << endl;
		cout << "����������� ����: " << minPrice << endl;
	}

	system("pause");
}
*/


// ���������� / ���������� �����. ��� ������� ��������� �������������� ������ ����� ����������: 
// �) ���������� ���������� ����� � ��� ������; �) ���������� ����� � �������� � ��������� ��������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	while (!cin.eof())
	{
		int N;		//�������� �����
		cout << "�����: ";
		cin >> N;

		if (cin.eof())
			break;

		if (N <= 0)
		{
			cerr << "����� ������ ���� �������������" << endl;
			continue;
		}

		int minDigit	= 9;	//���������� ���������� �����
		int maxDigitOdd = 0;	//���������� ����� � �������� ��������
		bool isOdd = true;		//�������� �� ������ ������� �����

		while (N > 0)
		{
			int currDigit = N % 10;	//������� �����

			if (currDigit < minDigit)
				minDigit = currDigit;

			if (isOdd && currDigit > maxDigitOdd)
				maxDigitOdd = currDigit;

			N /= 10;
			isOdd = !isOdd;
		}

		cout << "���������� ���������� �����: " << minDigit << endl;
		cout << "���������� ����� � �������� ��������: " << maxDigitOdd << endl;
	}

	system("pause");
}
*/


// �������. ��� �������� � ��������� ����������� ��������� �������, ��������� � ����������� ���� 
// ��������� ����� r1, r2 (r1 != r2), � ����� ��� ���������� ������� ����������� ������� ��������� 
// p1, p2 (p1 != p2) ���������� ���������� �������, ��������� 0, 1 ��� 2 �����. �������, ��� 
// ������� ���������� ����� p1, p2 � �������� ��������� �������� �� �����.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	//������������ �����
	int r1 = 2,
		r2 = 4;	

	//���-�� �������, ��������� 0, 1 ��� 2 �����
	int guessed0 = 0,
		guessed1 = 0,
		guessed2 = 0;

	while (!cin.eof())
	{
		int p1, p2;		//�������� ����������
		cout << "p1 � p2: ";
		cin >> p1 >> p2;

		if (cin.eof())
			break;

		if (p1 == p2)
		{
			cerr << "����� ������ ���� ��������" << endl;
			continue;
		}

		int isGuessed = 0;	//���-�� �����, ��������� ������� ����������

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

	cout << "������� 0 �����: " << guessed0 << endl;
	cout << "������� 1 �����: " << guessed1 << endl;
	cout << "������� 2 �����: " << guessed2 << endl;

	system("pause");
}
*/


// �����������. ����������� ����� ����� ������������� N � ���� ������������ ������� ������������ 
// (������� ������� �� 1 � �� ����). ������: 12 = 1*2*2*3.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	while (!cin.eof())
	{
		int N;		//�������� �����
		cout << "�����: ";
		cin >> N;

		if (cin.eof())
			break;

		if (N <= 0)
		{
			cerr << "����� ������ ���� �������������" << endl;
			continue;
		}

		int quotient = N;	//������� �� ������� �� �����������

		cout << "=" << 1;

		//����� ������������
		for (int factor = 2; factor < N / 2; factor++)
		{
			while (quotient % factor == 0)
			{
				cout << "*" << factor;
				quotient /= factor;
			}
		}

		//���� ����� ��������� �������
		if (quotient == N)
			cout << "*" << N;

		cout << endl;
	}

	system("pause");
}
*/


// ���� �����. �������� �������� ����� ������ �� N ����. ���������� ���� (��� �������) ���������� 
// ����, ����� ����������� ����������� ����� ������. ���������� ����� ����� ������ ���������������� 
// ������� �����.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	int N = 0;			//���-�� ����
	int growthDays = 0;	//���-�� ���� ����������� ����� ������
	int maxLength  = 0;	//����� ������ ���������������� ������� �����

	float ratePrev = 0;	//���� ������ � ���������� ����
	int currLength = 0;	//������� ����� ������� �����

	while (!cin.eof())
	{
		float rate;		//���� ������
		cout << "���� ������: ";
		cin >> rate;

		if (cin.eof())
			break;

		if (rate <= 0)
		{
			cerr << "����� ������ ���� �������������" << endl;
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

	cout << "������� ���� ����������� ����� ������: " << 100 / N * growthDays << endl;		 
	cout << "����� ������ ���������������� ������� �����: " << maxLength << endl;

	system("pause");
}
*/


// ������ �.������. �������� N ����� ������� � ����� �� 1770 �������. �� ������ ������ �� ������� 
// �� 31 ������, �� ������� ���� �� 21 ������. ������� ������� � ����� ����� �������� N?

void main()
{
	setlocale(LC_ALL, "Russian");

	const int sum = 1770,		//��������� ���������
			  horsePrice = 31,	//��������� 1 ������
			  bullPrice  = 21;	//��������� 1 ����

	for (int horseNum = 1; horseNum * horsePrice < sum; horseNum++)
	{
		int bullSum = sum - horseNum * horsePrice;	//��������� ��������� �����

		//���� ��������� ��������� ����� ������ ��������� 1 ����
		if (bullSum % bullPrice == 0)
			cout << horseNum << " ������� � " << bullSum / bullPrice << " �����" << endl;
	}

	system("pause");
}