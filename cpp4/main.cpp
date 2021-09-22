#include <locale>
#include <iostream>
using namespace std;


/*** ��������� ���������� ��������-�����. �������. ������������ ������. ***/


// ������� ���������. 1. ��������� ��������: �������� �� ������ ����������� (������������) � ������ 
// ���� ��������, ������� �������. 2. ����������� �������� � ���� �������.
// ������ �������� ����������: ���� 123 ������ 321 ����
/*
// ������� ��� �������
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];				//������
	size_t len;					//����� ������
	bool isPalindrome = true;	//�������� �� ������ �����������

	cout << "������: ";
	cin.getline(str, sizeof(str));

	//����������� ����� ������
	for (len = 0; str[len] != '\0'; len++);

	for (int i = 0; i < len / 2 && isPalindrome; i++)
		if (str[i] != str[len - 1 - i])
			isPalindrome = false;

	isPalindrome ? cout << "������ �������� �����������" 
		: cout << "������ �� �������� �����������";
	cout << endl;

	system("pause");
}
*/
/*
//������� � ��������� ��������
bool checkForPalindrome(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];	//������

	cout << "������: ";
	cin.getline(str, sizeof(str));

	checkForPalindrome(str) ? cout << "������ �������� �����������"
		: cout << "������ �� �������� �����������";
	cout << endl;

	system("pause");
}

bool checkForPalindrome(const char str[])
{
	size_t len;		//����� ������

	//����������� ����� ������
	for (len = 0; str[len] != '\0'; len++);

	for (int i = 0; i < len / 2; i++)
		if (str[0 + i] != str[len - 1 - i])
			return false;

	return true;
}
*/


// ����� ������ � �������. 
// ����� ������ �����: char Name[][20] = {"String1", "String2", "String3", "String4"}. ��������� 
// ������ ����������, ���������� �� � ���� ������� ������, ������������� ��������� �������������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	char Name[][20] = { "String1", "String2", "String3", "String4" };	//������ �����
	char searchStr[100];		//������� ������
	bool isContained = false;	//���������� � ������� ������� ������

	cout << "������� ������: ";
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

	isContained ? cout << "��������� ������ ���������� � �������"
		: cout << "��������� ������ �� ���������� � �������";
	cout << endl;

	system("pause");
}
*/


// ������. �������� ������ ������� N ���������� � �� ���� (������� ������ ���� ��������� � ������� 
// �����, � �������� ����� - � ��������� �������������� �������). ����������, ����� ��������� 
// ����� ��������� ���� �� ���� ��������: �) �� ��������� ����� ���������� ����������� ������� 
// ��������� ���������� ��� ����; �) �� ���������� ����� ���������� �������� ������� � ����� 
// ������; �) �������� ������ ������� � ���������� ������.
/*
//������� ��� �������
void main()
{
	setlocale(LC_ALL, "Russian");

	const size_t SIZE = 6;	//���-�� ����������
	char surnames[SIZE][20] = { "Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Smirnov", "Popov" };
	int experiences[SIZE] = { 2, 4, 2, 3, 4, 8 };

	int actNum;		//����� ��������

	cout << "��������: " << endl
		<< "1. ���������� �� ��������� ������� ���� ���������" << endl
		<< "2. ���������� �� ���������� ����� �������� ������� � ����� ������" << endl
		<< "3. ������� ������ ������� � ���������� ������" << endl;

	cin >> actNum; getchar();

	switch (actNum)
	{
		case 1:
		{
			const size_t surnameLen = sizeof(surnames[0]);	//������������ ����� �������
			char surname[surnameLen];	//������� ���������
			int workerNum;				//����� ��������� � ������

			cout << "������� ���������: ";
			cin.getline(surname, surnameLen);

			//������� ������� �������
			for (workerNum = 0; workerNum < SIZE; workerNum++)
			{
				bool isFound = true;	//������� �� ������� � ������

				//����������� ��������� ������� �� ������ � ��������� �������
				for (int j = 0; j < surnameLen && surname[j] != '\0' && surnames[workerNum][j] != '\0'; j++)
					if (surname[j] != surnames[workerNum][j])
						isFound = false;

				if (isFound)
					break;
			}

			if (workerNum != SIZE)
				cout << "���� ���������: " << experiences[workerNum] << endl;
			else
				cout << "�������� �� ������" << endl;

			break;
		}
		case 2:
		{
			int experience;			//���� ���������
			int workerNum;			//����� ��������� � ������
			bool isFound = false;	//������ �� ���� � ������

			cout << "���� ���������: ";
			cin >> experience;

			//������� ������� ������
			for (workerNum = 0; workerNum < SIZE; workerNum++)
			{
				if (experience == experiences[workerNum])
				{
					cout << "������� ���������: " << surnames[workerNum] << endl;
					isFound = true;
				}
			}

			if (!isFound)
				cout << "�������� �� ������" << endl;

			break;
		}
		case 3:
		{
			int averageExperience;		//������� ���� ����������
			int sumExperiences = 0;		//����� ������ ����������

			for (int i = 0; i < SIZE; i++)
				sumExperiences += experiences[i];

			averageExperience = sumExperiences / SIZE;

			for (int i = 0; i < SIZE; i++)
				if (experiences[i] > averageExperience)
					cout << "�������: " << surnames[i] << ", ����: " << experiences[i] << endl;

			break;
		}
	}

	system("pause");
}
*/
/*
//������� � ���������
#define SURNLEN 20	//������������ ����� �������
void printExpBySurname(const char surnames[][SURNLEN], const int experiences[], const size_t size, const char surname[]);
void printSurnamesByExp(const char surnames[][SURNLEN], const int experiences[], const size_t size, const int experience);
void printSurnamesWithMaxExp(const char surnames[][SURNLEN], const int experiences[], const size_t size);

void main()
{
	setlocale(LC_ALL, "Russian");

	const size_t SIZE = 6;	//���-�� ����������
	char surnames[SIZE][SURNLEN] = { "Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Smirnov", "Popov" };
	int experiences[SIZE] = { 2, 4, 2, 3, 4, 8 };

	int actNum;		//����� ��������
	
	cout << "��������: " << endl
		<< "1. ���������� �� ��������� ������� ���� ���������" << endl
		<< "2. ���������� �� ���������� ����� �������� ������� � ����� ������" << endl
		<< "3. ������� ������ ������� � ���������� ������" << endl;

	cin >> actNum; getchar();

	switch (actNum)
	{
		case 1:
		{
			char surname[SURNLEN];	//������� ���������

			cout << "������� ���������: ";
			cin.getline(surname, SURNLEN);

			printExpBySurname(surnames, experiences, SIZE, surname);

			break;
		}
		case 2:
		{
			int experience;			//���� ���������

			cout << "���� ���������: ";
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
	int workerNum;	//����� ��������� � ������

	//������� ������� �������
	for (workerNum = 0; workerNum < size; workerNum++)
	{
		bool isFound = true;	//������� �� ������� � ������

		//����������� ��������� ������� �� ������ � ��������� �������
		for (int j = 0; j < SURNLEN && surname[j] != '\0' && surnames[workerNum][j] != '\0'; j++)
			if (surname[j] != surnames[workerNum][j])
				isFound = false;

		if (isFound)
			break;
	}

	if (workerNum != size)
		cout << "���� ���������: " << experiences[workerNum] << endl;
	else
		cout << "�������� �� ������" << endl;
}

void printSurnamesByExp(const char surnames[][SURNLEN], const int experiences[], const size_t size, const int experience)
{
	int workerNum;			//����� ��������� � ������
	bool isFound = false;	//������ �� ���� � ������

	//������� ������� ������
	for (workerNum = 0; workerNum < size; workerNum++)
	{
		if (experience == experiences[workerNum])
		{
			cout << "������� ���������: " << surnames[workerNum] << endl;
			isFound = true;
		}
	}

	if (!isFound)
		cout << "�������� �� ������" << endl;
}

void printSurnamesWithMaxExp(const char surnames[][SURNLEN], const int experiences[], const size_t size)
{
	int averageExperience;		//������� ���� ����������
	int sumExperiences = 0;		//����� ������ ����������

	for (int i = 0; i < size; i++)
		sumExperiences += experiences[i];

	averageExperience = sumExperiences / size;

	for (int i = 0; i < size; i++)
		if (experiences[i] > averageExperience)
			cout << "�������: " << surnames[i] << ", ����: " << experiences[i] << endl;
}
*/


// ���� � '?�. 1. ��������� ������ ��������� ������������ ����� �����, ������� �������� ������� 
// �������, � ����� ����� ��������� ���� ��� ��������� ����������� �������� '?�, ������� � ����� 
// ����� ��������������� ����� ������ (����� ����). �������� �����: �������, ������� 
// ������������� ����� �???���. ����� ������� ���, ����� ��������� ����������� ������� ����� � 
// ��������� �� �� ������������ ���������� ���������� �����. 
// 2. ����������� �������� ������������ � ���� �������.
/*
// ������� ��� �������
void main()
{
	setlocale(LC_ALL, "Russian");

	char key[100];	//�����-����
	char word[100];	//����������� �����

	cout << "�����-���� � '?': ";
	cin.getline(key, sizeof(key));

	do {
		cout << "�����: ";
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

		isMatch ? cout << "����� ������������� �����" : cout << "����� �� ������������� �����";
		cout << endl;

	} while (!cin.eof());

	system("pause");
}
*/
/*
//������� � ��������
bool checkWordToKey(const char* key, const char* word);

void main()
{
	setlocale(LC_ALL, "Russian");

	char key[100];	//�����-����
	char word[100];	//����������� �����

	cout << "�����-���� � '?': ";
	cin.getline(key, sizeof(key));

	do {
		cout << "�����: ";
		cin.getline(word, sizeof(word));

		if (cin.eof())
			break;

		checkWordToKey(key, word) ? cout << "����� ������������� �����" 
			: cout << "����� �� ������������� �����";
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


// ���������� ���������� �������. 1. ��� �������� ������ � ���������� ������� ���������� 
// ������������ ���������� ��� ��������� ������ � ������������������ �������� ������. 
// 2. ����������� � ���� �������.
/*
// ������� ��� �������
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "aabbbcdeffffghhiiiiijjklmmeee@@";	//������
	char searchChar;		//������� ������
	int maxCharLen = 0;		//������������ ����� ������ ������ ������� �������� � ������

	int currCharLen = 0;	//������� ����� ������ ������ ������� �������� � ������

	cout << "������� ������: ";
	cin.get(searchChar);

	//����������� ����� ������ ������ ������� ��������
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

	maxCharLen ? cout << "������ ����������� � ������ " << maxCharLen << " ��� ������"
		: cout << "������ �� ����������� � ������";
	cout << endl;

	system("pause");
}
*/
/*
//������� � ��������
int getCharCountInRow(const char str[], const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "aabbbcdeffffghhiiiiijjklmmeee@@";	//������
	char searchChar;		//������� ������
	int maxCharLen = 0;		//������������ ����� ������ ������ ������� �������� � ������

	cout << "������� ������: ";
	cin.get(searchChar);

	maxCharLen = getCharCountInRow(str, searchChar);

	maxCharLen ? cout << "������ ����������� � ������ " << maxCharLen << " ��� ������"
		: cout << "������ �� ����������� � ������";
	cout << endl;

	system("pause");
}

int getCharCountInRow(const char str[], const char c)
{
	int maxCharLen = 0;		//������������ ����� ������ ������ ������� �������� � ������
	int currCharLen = 0;	//������� ����� ������ ������ ������� �������� � ������

	//����������� �������� ����� ������ ������ ������� ��������
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


// ������� �������. ���������� ������������ ����� ���������� ������ ������ �������� ������. 
// ����������� ��������.
/*
int countIdenticalCharInRow(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];		//������
	int maxCharLen;		//������������ ����� ������ ������ �������� � ������

	cout << "������: ";
	cin.getline(str, sizeof(str));

	maxCharLen = countIdenticalCharInRow(str);

	cout << "������������ ����� ������ ������ ��������: " << maxCharLen << endl;

	system("pause");
}

int countIdenticalCharInRow(const char str[])
{
	int maxCharLen = 1;		//������������ ����� ������ ������ �������� � ������
	int currCharLen = 1;	//������� ����� ������ ������ �������� � ������
	char prevChar = str[0];	//���������� ������ ��� ��������� � ������� � ������

	//����������� �������� ����� ������ ������ ������� ��������
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


// ������. �������� ���������, ����������� ������������ ����������� ������ (������� ����� 
// ���������� ������������ �� �������� � ��������, �.�. ���������������) � ���������, ������� 
// �������� ��� ��������� ������. �������� � ���������: (����)��(���(����)��)��� � ������ 
// ����������� ���������, � � (�������(���)�������)����)�����(���� � �����������.
/*
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[100];	//���������
	int count = 0;	//������� ���-�� �������� ����������� ������

	cout << "���������: ";
	cin.getline(str, sizeof(str));

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			count++;
		else if (str[i] == ')')
			count--;

		//���������� ����������� ������ ��� �������������� �����������
		if (count < 0)
			break;
	}

	count == 0 ? cout << "������ ����������� �����" : cout << "������ ����������� �� �����";
	cout << endl;

	system("pause");
}
*/


// �������� ������� ��������� �����. 1. �� ���������� ���������, ����������� � ���� ������, 
// �������� ����� � �������� ������� ��������� �������. 2. ����������� � ���� �������, ������������ 
// ��������� �� ������������ ������, � ������� ���������� ���������� ��������� ��������.
/*
// ������� ��� �������
void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "(aaa)bb(ccc(ddd)ee)fff(g)";	//���������
	char* deepestStr = nullptr;					//�������� ������� ��������� �����

	int count = 0;		//������� ���-�� �������� ����������� ������
	int maxCount = 0;	//������������ �������� ��������

	int pos = 0;				//������� ������� ������� ���������� ������
	int len = 0;				//����� ���������� ������
	bool toIncreaseLen = false;	//����������� �� ����� �������� ���������� ������

	//����� �������� ������� ���������� ������
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

	//��������� ������ ��� ������ ���������� ������
	deepestStr = new char[len + 1];

	//���������� �������
	for (int i = 0; i < len; i++)
		deepestStr[i] = str[pos + i];
	deepestStr[len] = '\0';

	cout << "�������� ������� ��������� �����: " << deepestStr << endl;

	delete[] deepestStr;
	system("pause");
}
*/
/*
//������� � ��������
char* getDeepestStr(const char str[]);

void main()
{
	setlocale(LC_ALL, "Russian");

	char str[] = "(aaa)bb(ccc(ddd)ee)fff(g)";	//���������
	char* deepestStr = getDeepestStr(str);		//�������� ������� ��������� �����	

	cout << "�������� ������� ��������� �����: " << deepestStr << endl;

	delete[] deepestStr;
	system("pause");
}

char* getDeepestStr(const char str[])
{
	char* deepestStr = nullptr;	//�������� ������� ��������� �����

	int count = 0;		//������� ���-�� �������� ����������� ������
	int maxCount = 0;	//������������ �������� ��������

	int pos = 0;				//������� ������� ������� ���������� ������
	int len = 0;				//����� ���������� ������
	bool toIncreaseLen = false;	//����������� �� ����� �������� ���������� ������

	//����� �������� ������� ���������� ������
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

	//��������� ������ ��� ������ ���������� ������
	deepestStr = new char[len + 1];

	//���������� �������
	for (int i = 0; i < len; i++)
		deepestStr[i] = str[pos + i];
	deepestStr[len] = '\0';

	return deepestStr;
}
*/


// ����������. ��� ����� ����� �������� ��� ������ (� ���� ������������������ ��������-����) 
// ��������� ������ ��������� �� �������� � �������� ��������� � ���� ������ �� ��������-����.
/*
int charToInt(const char str[]);
char* intToChar(int n);

void main()
{
	setlocale(LC_ALL, "Russian");

	char n1[10], n2[10];	//���������
	char* sum = nullptr;	//�����

	cout << "��������� 1: ";
	cin.getline(n1, sizeof(n1));

	cout << "��������� 2: ";
	cin.getline(n2, sizeof(n2));

	sum = intToChar(charToInt(n1) + charToInt(n2));

	cout << "�����: " << sum << endl;

	delete[] sum;
	system("pause");
}

int charToInt(const char str[])
{
	int n = 0;	//������������ �����

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
	int digits = n ? round(log10(n) + 0.5) : 1;	//���-�� ���� � �����
	char* str = new char[digits + 1];			//������������ ������

	for (int i = digits - 1; i >= 0; i--)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	str[digits] = '\0';

	return str;
}
*/


// ����������++. ���������� ����������� ������������� ������ ������������������� ������� �������� 
// ������� �����. �������� �������, ������� ����� �������� � ����������� ��������� ������ ������� 
// ������� ��� ������������� ��������, ��������� ��������� �� ���� ������, � ����� ���������� � 
// ���������� ���������, ���������� � ���.
/*
int* selectPositive(const int arr[], const size_t sizeArr, size_t& sizeRes);

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[20];			//�������� ������
	int* result = nullptr;	//������ ������������� ��������
	size_t sizeRes = 0;		//���-�� ��������� � �������������� �������

	//���������� �������
	for (int& n : arr)
		n = rand() % 200 - 100;	

	cout << "�������� ������: ";
	for (int& n : arr)
		cout << n << " ";
	cout << endl;

	result = selectPositive(arr, sizeof(arr) / sizeof(arr[0]), sizeRes);

	cout << "������ ������������� ��������: ";
	for (int i = 0; i < sizeRes; i++)
		cout << result[i] << " ";
	cout << endl;

	delete[] result;
	system("pause");
}

int* selectPositive(const int arr[], const size_t sizeArr, size_t& sizeRes)
{
	int* result = nullptr;	//������ ������������� ��������

	sizeRes = 0;

	//������� ���-�� ������������� ���������
	for (int i = 0; i < sizeArr; i++)
		if (arr[i] > 0)
			sizeRes++;

	result = new int[sizeRes];

	//���������� �������
	for (int i = 0, j = 0; i < sizeArr; i++)
		if (arr[i] > 0)
			result[j++] = arr[i];

	return result;
}
*/


// �����+������. �������� �������, ������������, ���������� �� � ������� �������� �������� ������. 
// ������ ������� ��������� �� ������ ��������� ������� ��� NULL. ��������� ������� �������� � 
// ������ ��� ������� '#' �� ������� '@'.
/*
char* findChar(char str[], const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char arr[] = "$#(*^%#!()&^##$|+";

	cout << "�������� ������: " << endl << arr << endl;

	while (char* c = findChar(arr, '#'))
		*c = '@';

	cout << "������ ����� ������: " << endl << arr << endl;

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


// ����������� **. ������, ���������� ���������� �������, ��������������� ����� ������ ������ ����� 
// �� �� ���������� ����� � ��������. ��� ���� ������ ������� ���������� �� ����� 0. ���������� 
// ������� ���� �������� � ��������� ��� ��������� ������. ��������� ������ ���������� ���������� 
// ��������� ����������� ������.

int decode(const char str[], const char decoded[] = new char[1]{ "" });
char* addChar(const char str[], const char c);

void main()
{
	setlocale(LC_ALL, "Russian");

	char encoded[100];	//������������� ������� ������
	int variants = 0;	//���������� ��������� �����������

	cout << "������������� ������� �����: ";
	cin.getline(encoded, sizeof(encoded));

	cout << endl << "�������� �����������: " << endl;

	variants = decode(encoded);

	cout << endl << "����� ���������: " << variants << endl;

	system("pause");
}

int decode(const char str[], const char decoded[])
{
	int count = 0;
	
	//�����������
	if (*str >= '1' && *str <= '9')
	{
		//������� ����� ��������� ����� � �������� ���� ASCII ��������������� �����
		char c1 = *str - '0' + 'A' - 1;

		count += decode(str + 1, addChar(decoded, c1));

		if (*(str + 1) != '\0')
		{
			//������� ���� ��������� ���� � �������� ���� ASCII ��������������� �����
			char c2 = (*str - '0') * 10 + (*(str + 1) - '0') + 'A' - 1;

			if (c2 >= 'A' + 9 && c2 <= 'Z')
				count += decode(str + 2, addChar(decoded, c2));
		}
	}
	else if (*str == '0' && *(str + 1) != '\0')	//������ �� � �����
	{
		count += decode(str + 1, addChar(decoded, '_'));
	}

	//��������� ����� ������ � �������������� ������ �� ������
	else if (*str == '\0' && *decoded != '\0')
	{
		//������ �������������� ������
		for (int i = 0; decoded[i] != '\0'; i++)
			cout << decoded[i];
		cout << endl;

		delete[] decoded;
		return 1;
	}

	return count;
}

//������� ���������� ������� � ������
char* addChar(const char str[], const char c)
{
	char* strNew = nullptr;	//����� ������
	size_t len;				//����� �������� ������

	//����������� ����� �������� ������
	for (len = 0; str[len] != '\0'; len++);

	strNew = new char[len + 2];

	//���������� ����� ������
	for (int i = 0; i < len; i++)
		strNew[i] = str[i];
	strNew[len] = c;
	strNew[len + 1] = '\0';

	return strNew;
}