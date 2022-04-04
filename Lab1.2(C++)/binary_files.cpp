#include "binary_files.h"

struct t_student;

void input_data(const string file_name)
{
	char mode;                                                                                     
	cout << "Press 'a' to append data or 'o' to overwrite or else to read data-> "; cin >> mode;
	mode = char(tolower(mode));

	fstream file_out;
	//Визначення режиму відкриття файлу
	switch (mode)
	{
	case 'a':                                                       /* Режим додавання*/
		file_out.open(file_name, ios::app | ios::binary | ios::out);
		cout << "Append mode" << endl;
		break;
		  
	case 'o':                                                       /*Режим перезапису*/
		file_out.open(file_name, ios::binary | ios::out);
		cout << "Overwrite mode" << endl;
		break;

	default:                                                        /*При всіх інших значеннях - режим читання*/
		cout << "Read mode" << endl << endl;
		return;
	}

	if(file_out.is_open())                                          /*Перевірка файлу на правильність відкриття*/
	{
		cout << endl << "File is successfully opened!" << endl << endl;

		int quantity;                                               /*Кількість студентів*/
		t_student student{};										/*Створення об`єкту*/
		cout << "Enter quantity of students-> "; cin >> quantity;
		cout << endl;

		cin.ignore();
		//Введення даних про студента
		for (int i = 0; i < quantity; i++)
		{
			cout << "Enter full name-> ";
			gets_s(student.full_name);
			title(student.full_name);

			cout << "Enter date of birth('dd.mm.yyyy')-> ";
			gets_s(student.b_day);

			cout << "Enter study form-> ";
			gets_s(student.study_form);

			cout << "Enter group-> ";
			gets_s(student.group);

			cout << "Enter average rating-> ";
			cin >> student.av_rating;
			cout << endl;
			//Визначення потоку конкретного студента
			for (size_t j = 0; j < strlen(student.group); j++)
			{
				if (isalpha(student.group[j]))
				{
					student.subdivision[j] = char(toupper(student.group[j])); 
				}
			}
			//Запис студента у файл
			file_out.write((char*)&student, sizeof(t_student));
			cin.ignore();
		}
		//Закриття файлу
		file_out.close();
	}
	else
	{
		cout << "Error! File is not opened!" << endl;  /*Виведення повідомлення та вихід із програми, якщо файл не відкрився*/
		exit(0);                                       
	}
}
//Ф-ція для виведення даних про студентів
void print_data(const string file_name)                        
{
	ifstream file_in(file_name, ios::binary);
	//Створення об`єкту
	t_student student{}; 

	while (file_in.read((char*)&student, sizeof(t_student)))
	{
		student.print();
	}
	
	file_in.close();
}
//Ф-ція для виведення мінімальних студентів
void print_data(vector<t_student> min_av_students_vector)
{
	cout << "------------STUDENTS WITH MIN MARKS------------" << endl;

	for (const t_student& student : min_av_students_vector)
	{
		cout << "Subdivision " << student.subdivision << ": " << student.full_name << ", " << student.group << endl;
	}
}
//Ф-ція для створення масиву студентів
vector<t_student> create_students_vector(const string file_name)
{
	ifstream file_in(file_name, ios::binary);

	t_student student{};                
	vector<t_student> students_vector; /*Створення масиву студентів*/

	while (file_in.read((char*)&student, sizeof(t_student)))
	{	
		students_vector.push_back(student); /*Додавання студентів у масив*/
	}

	file_in.close();

	return students_vector;
}
//Ф-ція для створення масиву потоків
vector<t_student> create_min_av_vector(vector<t_student> students_vector)
{
	vector<string> subdivisions_vector;       /*Створення масиву потоків*/
	vector<t_student> min_av_students_vector; /*Створення масиву із мінімальним балом студента з кожного потоку*/
	t_student min_student{};

	for (size_t i = 0; i < students_vector.size(); i++) 
	{
		bool exist = false; /*Змінна для позначення існуючого потоку*/                                                

		for (size_t j = 0; j < subdivisions_vector.size(); j++)
		{
			if (subdivisions_vector[j] == students_vector[i].subdivision)
			{
				exist = true;
				break;
			}
		}

		if (!exist)
		{
			subdivisions_vector.push_back(students_vector[i].subdivision); /*Додавання потоку у масив якщо його немає у масиві*/
		}
	}
	//Створення масиву мінімальних балів студентів із кожного потоку
	for (string i : subdivisions_vector)
	{
		float min = 100;

		for (const t_student& student : students_vector)
		{
			if(student.subdivision == i && student.av_rating < min)  /*Студент є мінімальним, якщо має найменший бал*/
			{
				min = student.av_rating;
				min_student = student;
			}
		}

		min_av_students_vector.push_back(min_student); /*Додавання студентів у масив*/
	}

	return min_av_students_vector;
}
//Ф-ція для розподілу студентів у файл
void distribute_data(const string file_name, vector<t_student> students_vector)
{
	ofstream file_out(file_name, ios::binary);
	//Створення масиву із відсортованими по іменами студентів
	vector<t_student> sorted_vector;
	float average;

	cout << endl << "Enter average mark for session: "; cin >> average;

	for (t_student student : students_vector)
	{
		if (string(student.study_form) == "day" && student.av_rating < average) /*Якщо студент навчається на денній формі та середній бал менше за вказаний,*/
		{                                                                       /*визначаємо курс*/
			int course = NULL;

			for (char symbol : student.group)
			{
				if (isdigit(symbol)) /*Визначення курсу студента*/
				{
					course = symbol - '0';
					break;
				}
			}

			if (course == 4) /*Якщо студент є четверокурсником, додаємо його у масив*/
			{
				sorted_vector.push_back(student);
			}
		}
	}
	/*Сортування масиву студентів за їх іменем*/
	for (int i = 0; i < int(sorted_vector.size() - 1); i++)
	{
		for (int j = 0; j < int(sorted_vector.size() - i - 1); j++)
		{
			if (string(sorted_vector[j].full_name) > string(sorted_vector[j + 1].full_name))
			{
				swap(sorted_vector[j], sorted_vector[j + 1]); 
			}
		}
	}

	for (const t_student &student : sorted_vector)
	{
		file_out.write((char*)&student, sizeof(t_student)); /*Запис студентів у другий файл*/
	}

	file_out.close(); /*Закриття файлу*/	
}
//Допоміжна функція для перетворення першої літери кожного слова у верхній регістр
void title(char* full_name)                       
{
	full_name[0] = char(toupper(full_name[0]));

	for(size_t i = 2; i < strlen(full_name); i++)
	{
		if(full_name[i] != ' ' && full_name[i-1] == ' ')
		{
			full_name[i] = toupper(full_name[i]);
		}
	}
}