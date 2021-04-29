#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
	string full_name;		// Фамилия Имя Отчество
	char sex;				// Пол: M/W
	int age;				// Возраст
	string city;			// Город
	int exam;				// средний балл егэ
	string certificate;     // наличие аттестата
	float certificateValue;   // ср. балл аттестата
};

struct VolleyballPlayers
{
	string full_name;		// Фамилия Имя Отчество
	char sex;				// Пол: M/W
	int age;				// Возраст
	char clothingSize;		// размер одежды
	string dischargePresence;	// наличие разряда
	int courseNumber;       // номер курса (1-6)
};

void ReadingFile() {

}

int Applicants2()
{
	Student *student = new Student[10];
	ifstream database("students.txt");
	if (!database.is_open())
		cout << "Error!";
	else
	{

		for (int i = 0; i < 9; i++)
		{
			database.ignore();
			getline(database, student[i].full_name, '\n');
			database >> student[i].sex;
			database >> student[i].age;
			database.ignore();
			getline(database, student[i].city, '\n');
			database >> student[i].exam;
			database.ignore();
			getline(database, student[i].certificate, '\n');
			database >> student[i].certificateValue;
		}
		database.close(); // Закрываем файл
		cout << "----------------\n" << "Students under the age of 18:" << endl;
		int temp = 0;
		for (int i = 0; i < 9; i++) // Проходим по всем студентам
		{
			if (student[i].age < 18) // Фильтруем данные по необходимому признаку
			{
				cout << student[i].full_name << '\n';
				cout << student[i].sex << '\n';
				cout << student[i].age << " - under the age of 18" << '\n';
				cout << student[i].city << '\n';
				cout << student[i].exam << '\n';
				cout << student[i].certificate << '\n';
				cout << student[i].certificateValue << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;


		cout << "----------------\n" << "Students with a GPA greater than 85:" << endl;
		temp = 0;
		for (int i = 0; i < 9; i++) // Проходим по всем студентам
		{
			if (student[i].exam > 85) // Фильтруем данные по необходимому признаку
			{
				cout << student[i].full_name << '\n';
				cout << student[i].sex << '\n';
				cout << student[i].age << '\n';
				cout << student[i].city << '\n';
				cout << student[i].exam << " - GPA greater than 85" << '\n';
				cout << student[i].certificate << '\n';
				cout << student[i].certificateValue << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;

		cout << "----------------\n" << "Nonresident students:" << endl;
		temp = 0;
		for (int i = 0; i < 9; i++) // Проходим по всем студентам
		{
			if (student[i].city != "Saint Petersburg") // Фильтруем данные по необходимому признаку
			{
				cout << student[i].full_name << '\n';
				cout << student[i].sex << '\n';
				cout << student[i].age << '\n';
				cout << student[i].city << " - Nonresident students" << '\n';
				cout << student[i].exam << '\n';
				cout << student[i].certificate << '\n';
				cout << student[i].certificateValue << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;

		cout << "----------------\n" << "Students with honors:" << endl;
		temp = 0;
		for (int i = 0; i < 9; i++) // Проходим по всем студентам
		{
			if (student[i].certificateValue == 5) // Фильтруем данные по необходимому признаку
			{
				cout << student[i].full_name << '\n';
				cout << student[i].sex << '\n';
				cout << student[i].age << '\n';
				cout << student[i].city << '\n';
				cout << student[i].exam << '\n';
				cout << student[i].certificate << '\n';
				cout << student[i].certificateValue << " - Students with honors" << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;


		delete[] student; // Освобождаем динамическую память 
	}
	return 1;
}

int Volleyball5()
{
	VolleyballPlayers *volleyballPlayers = new VolleyballPlayers[10];
	ifstream database("volleyballPlayers.txt");
	if (!database.is_open())
		cout << "Error!";
	else
	{

		for (int i = 0; i < 10; i++)
		{
			database.ignore();
			getline(database, volleyballPlayers[i].full_name, '\n');
			database >> volleyballPlayers[i].sex;
			database >> volleyballPlayers[i].age;
			database >> volleyballPlayers[i].clothingSize;
			database.ignore();
			getline(database, volleyballPlayers[i].dischargePresence, '\n');
			database >> volleyballPlayers[i].courseNumber;
		}
		database.close(); // Закрываем файл
		cout << "----------------\n" << "Who has a volleyball category:" << endl;
		int temp = 0;
		for (int i = 0; i < 10; i++) // Проходим по всем студентам
		{
			if (volleyballPlayers[i].dischargePresence == "true") // Фильтруем данные по необходимому признаку
			{
				cout << volleyballPlayers[i].full_name << '\n';
				cout << volleyballPlayers[i].sex << '\n';
				cout << volleyballPlayers[i].age << '\n';
				cout << volleyballPlayers[i].clothingSize << '\n';
				cout << volleyballPlayers[i].dischargePresence << " - volleyball category" << '\n';
				cout << volleyballPlayers[i].courseNumber << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;


		cout << "----------------\n" << "Women's team:" << endl;
		temp = 0;
		for (int i = 0; i < 10; i++) // Проходим по всем студентам
		{
			if (volleyballPlayers[i].sex == 'W') // Фильтруем данные по необходимому признаку
			{
				cout << volleyballPlayers[i].full_name << '\n';
				cout << volleyballPlayers[i].sex << " - woman" << '\n';
				cout << volleyballPlayers[i].age << '\n';
				cout << volleyballPlayers[i].clothingSize << '\n';
				cout << volleyballPlayers[i].dischargePresence << '\n';
				cout << volleyballPlayers[i].courseNumber << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;

		int courseK = 0;
		cout << "Enter course (1-6): ";
		cin >> courseK;

		cout << "----------------\n" << "Students K course:" << endl;
		temp = 0;
		for (int i = 0; i < 10; i++) // Проходим по всем студентам
		{
			if (volleyballPlayers[i].courseNumber == courseK) // Фильтруем данные по необходимому признаку
			{
				cout << volleyballPlayers[i].full_name << '\n';
				cout << volleyballPlayers[i].sex << '\n';
				cout << volleyballPlayers[i].age << '\n';
				cout << volleyballPlayers[i].clothingSize << '\n';
				cout << volleyballPlayers[i].dischargePresence << '\n';
				cout << volleyballPlayers[i].courseNumber << " - Students "<< courseK <<" course:" << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;

		cout << "----------------\n" << "Men with clothing sizes larger than M:" << endl;
		temp = 0;
		for (int i = 0; i < 10; i++) // Проходим по всем студентам
		{
			if (volleyballPlayers[i].sex == 'M' && volleyballPlayers[i].clothingSize != 'S' && volleyballPlayers[i].clothingSize != 'M') // Фильтруем данные по необходимому признаку
			{
				cout << volleyballPlayers[i].full_name << '\n';
				cout << volleyballPlayers[i].sex << '\n';
				cout << volleyballPlayers[i].age << '\n';
				cout << volleyballPlayers[i].clothingSize << " - clothing sizes larger than M" << '\n';
				cout << volleyballPlayers[i].dischargePresence << '\n';
				cout << volleyballPlayers[i].courseNumber << '\n';
				cout << "\n";
				temp++;
			}
		}
		if (temp == 0) // Если ни одной записи не найдено 
			cout << "No records were found" << endl;


		delete[] volleyballPlayers; // Освобождаем динамическую память 
	}
	return 1;
}


int main()
{
	int number = 0;
	
	do {
		cout << "####################" << endl;
		cout << "Select task (1-2):";
		cin >> number;
		if (number == 1) {
			Applicants2(); // задание №2
		}
		else if (number == 2) {
			Volleyball5(); // задание №5
		}
		else {
			cout << "Wrong number";
		}
	} while (number < 2);

	system("pause");

	return 0;
}