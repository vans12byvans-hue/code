#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct student
{
	string surname;
	string name;
	string patron;
	int grade[4];
	double average;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введите количество студентов: ";
	cin >> n;
	student* students = new student[n];
	double groupSum = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите фамилию " << i + 1 << "-го студента: " << endl;
		cin >> students[i].surname;
		cout << "Введите имя " << i + 1 << "-го студента: " << endl;
		cin >> students[i].name;
		cout << "Введите отчество " << i + 1 << "-го студента: " << endl;
		cin >> students[i].patron;
		cout << "Введи 4 оценки студента через пробел или enter " << endl;
		students[i].average = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> students[i].grade[j];
			students[i].average += students[i].grade[j];
		}
		students[i].average /= 4.0;
		groupSum += students[i].average;
	}
	cout << "ФИО студента\t\tОценки" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << students[i].surname << " " << students[i].name << " " << students[i].patron << "\t";
		for (int j = 0; j < 4; j++)
		{
			cout << students[i].grade[j] << " ";
		}
		cout << endl;
	}
	cout << "Средний балл каждого студента:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << students[i].surname << " - " << students[i].average << endl;
	}
	double groupAvg = groupSum / n;
	cout << "Студенты со средним баллом выше среднего (" << groupAvg << "):" << endl;
	for (int i = 0; i < n; i++)
	{
		if (students[i].average > groupAvg)
		{
			cout << students[i].surname << " " << students[i].name << " " << students[i].patron << endl;
		}
	}
	cout << "Список задолжников:" << endl;
	for (int i = 0; i < n; i++)
	{
		bool debtor = false;
		for (int j = 0; j < 4; j++)
		{
			if (students[i].grade[j] <= 2) debtor = true;
		}
		if (debtor) cout << students[i].surname << " " << students[i].name << " " << students[i].patron << endl;
	}
	cout << "Список отличников:" << endl;
	for (int i = 0; i < n; i++)
	{
		bool excellent = true;
		for (int j = 0; j < 4; j++)
		{
			if (students[i].grade[j] != 5) excellent = false;
		}
		if (excellent) cout << students[i].surname << " " << students[i].name << " " << students[i].patron << endl;
	}
	return 0;
}
