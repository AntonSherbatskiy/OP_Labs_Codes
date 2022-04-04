#include "binary_files.h"

struct t_student;

void input_data(const string file_name)
{
	char mode;                                                                                     
	cout << "Press 'a' to append data or 'o' to overwrite or else to read data-> "; cin >> mode;
	mode = char(tolower(mode));

	fstream file_out;
	//���������� ������ �������� �����
	switch (mode)
	{
	case 'a':                                                       /* ����� ���������*/
		file_out.open(file_name, ios::app | ios::binary | ios::out);
		cout << "Append mode" << endl;
		break;
		  
	case 'o':                                                       /*����� ����������*/
		file_out.open(file_name, ios::binary | ios::out);
		cout << "Overwrite mode" << endl;
		break;

	default:                                                        /*��� ��� ����� ��������� - ����� �������*/
		cout << "Read mode" << endl << endl;
		return;
	}

	if(file_out.is_open())                                          /*�������� ����� �� ����������� ��������*/
	{
		cout << endl << "File is successfully opened!" << endl << endl;

		int quantity;                                               /*ʳ������ ��������*/
		t_student student{};										/*��������� ��`����*/
		cout << "Enter quantity of students-> "; cin >> quantity;
		cout << endl;

		cin.ignore();
		//�������� ����� ��� ��������
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
			//���������� ������ ����������� ��������
			for (size_t j = 0; j < strlen(student.group); j++)
			{
				if (isalpha(student.group[j]))
				{
					student.subdivision[j] = char(toupper(student.group[j])); 
				}
			}
			//����� �������� � ����
			file_out.write((char*)&student, sizeof(t_student));
			cin.ignore();
		}
		//�������� �����
		file_out.close();
	}
	else
	{
		cout << "Error! File is not opened!" << endl;  /*��������� ����������� �� ����� �� ��������, ���� ���� �� ��������*/
		exit(0);                                       
	}
}
//�-��� ��� ��������� ����� ��� ��������
void print_data(const string file_name)                        
{
	ifstream file_in(file_name, ios::binary);
	//��������� ��`����
	t_student student{}; 

	while (file_in.read((char*)&student, sizeof(t_student)))
	{
		student.print();
	}
	
	file_in.close();
}
//�-��� ��� ��������� ��������� ��������
void print_data(vector<t_student> min_av_students_vector)
{
	cout << "------------STUDENTS WITH MIN MARKS------------" << endl;

	for (const t_student& student : min_av_students_vector)
	{
		cout << "Subdivision " << student.subdivision << ": " << student.full_name << ", " << student.group << endl;
	}
}
//�-��� ��� ��������� ������ ��������
vector<t_student> create_students_vector(const string file_name)
{
	ifstream file_in(file_name, ios::binary);

	t_student student{};                
	vector<t_student> students_vector; /*��������� ������ ��������*/

	while (file_in.read((char*)&student, sizeof(t_student)))
	{	
		students_vector.push_back(student); /*��������� �������� � �����*/
	}

	file_in.close();

	return students_vector;
}
//�-��� ��� ��������� ������ ������
vector<t_student> create_min_av_vector(vector<t_student> students_vector)
{
	vector<string> subdivisions_vector;       /*��������� ������ ������*/
	vector<t_student> min_av_students_vector; /*��������� ������ �� ��������� ����� �������� � ������� ������*/
	t_student min_student{};

	for (size_t i = 0; i < students_vector.size(); i++) 
	{
		bool exist = false; /*����� ��� ���������� ��������� ������*/                                                

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
			subdivisions_vector.push_back(students_vector[i].subdivision); /*��������� ������ � ����� ���� ���� ���� � �����*/
		}
	}
	//��������� ������ ��������� ���� �������� �� ������� ������
	for (string i : subdivisions_vector)
	{
		float min = 100;

		for (const t_student& student : students_vector)
		{
			if(student.subdivision == i && student.av_rating < min)  /*������� � ���������, ���� �� ��������� ���*/
			{
				min = student.av_rating;
				min_student = student;
			}
		}

		min_av_students_vector.push_back(min_student); /*��������� �������� � �����*/
	}

	return min_av_students_vector;
}
//�-��� ��� �������� �������� � ����
void distribute_data(const string file_name, vector<t_student> students_vector)
{
	ofstream file_out(file_name, ios::binary);
	//��������� ������ �� ������������� �� ������� ��������
	vector<t_student> sorted_vector;
	float average;

	cout << endl << "Enter average mark for session: "; cin >> average;

	for (t_student student : students_vector)
	{
		if (string(student.study_form) == "day" && student.av_rating < average) /*���� ������� ��������� �� ����� ���� �� ������� ��� ����� �� ��������,*/
		{                                                                       /*��������� ����*/
			int course = NULL;

			for (char symbol : student.group)
			{
				if (isdigit(symbol)) /*���������� ����� ��������*/
				{
					course = symbol - '0';
					break;
				}
			}

			if (course == 4) /*���� ������� � ����������������, ������ ���� � �����*/
			{
				sorted_vector.push_back(student);
			}
		}
	}
	/*���������� ������ �������� �� �� ������*/
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
		file_out.write((char*)&student, sizeof(t_student)); /*����� �������� � ������ ����*/
	}

	file_out.close(); /*�������� �����*/	
}
//�������� ������� ��� ������������ ����� ����� ������� ����� � ������ ������
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