#include "text_files.h"

void input_text(const string name)					//�-��� ��� ���������� ����� � �������� ����
{
	ofstream file_out(name);						//��������� ����� ��� ������ ����� � ����

	if (file_out.is_open())							//�������� ����� �� ����������� ��������					
	{
		cout << "Start file is successfully opened!" << endl << endl;  
	}
	else
	{
		cout << "Error! Could not open the start file!" << endl;
		exit(0);
	}

	string line;							        //��������� ����� ��� ���������� ��������� �����						

	while (true)									//�������� ����� � ���� �� ��������� �����
	{
		cout << "Enter line(press ctrl + X to stop): ";
		getline(cin, line);							

		if ((int)line[0] != 24) { file_out << line << endl; }  //ʳ���� ��������, ���� ���� ������� ��������� ���������(ctrl + X)
		else { break; }
	}

	file_out.close();                              //�������� ����� 
}

void print_file(const string name)				   //�-��� ��� ��������� ����� � �������
{
	ifstream file_in(name);						   //³������� ����� � ����� �������

	if (!file_in.is_open()) { cout << "Error! Could not open the file!" << endl; exit(0); } //�������� ����� �� ����������� ��������
	
	string line;								   //��������� ����� ��� ���������� ��������� �����

	while (!file_in.eof())					       //������� ����� �� �����, ���� �������� �� ������� ���� �����	
	{
		getline(file_in, line);
		cout << line << endl;
	}

	file_in.close();                              //�������� �����
}

vector<string> create_linesArray(const string name)    //�-��� ��� ��������� ������ �����
{
	ifstream file_in(name);							   //³������� ����� � ����� �������

	if (!file_in.is_open()) { cout << "Error! Could not open the file!" << endl; }    //�������� �� ����������� �������� �����		

	vector<string> lines_array;						   //��������� ������ ��� ���������� ����� �� �����
	string line;									   //��������� ����� ��� ���������� ��������� �����

	while (!file_in.eof())							   //������� ����� �� ����� ���� �������� �� ������� ���� �����
	{
		getline(file_in, line);

		if (line == "") { continue; }				
		else { lines_array.push_back(line); }
	}

	file_in.close();                                  //�������� �����

	return lines_array;						
}

void distribute_strings(const string start_file, const string first_file, const string second_file) //�-��� ��� �������� �����
{
	ifstream start_file_in(start_file);			     //³������� ��������� ����� � ����� �������
	ofstream first_file_out(first_file),			 //³������� ����� �� ��������� �� ������� ������� � ����� ������ 
			 second_file_out(second_file);

	if (!start_file_in.is_open() || !first_file_out.is_open() || !second_file_out.is_open()) //�������� �� ����������� �������� �����
	{
		cout << "Error! File could not open, cannot distribute strings!";
		exit(0);
	}

	vector<string> lines_array = create_linesArray(start_file);			//��������� ������ ��� �������� �����

	for (int i = 0; i < lines_array.size(); i++)						//������� ����� �� ������
	{
		if (i % 2 == 0) { first_file_out << lines_array[i] << endl; }
		else { second_file_out << lines_array[i] << endl; }
	}

	start_file_in.close();											    //�������� �����
	first_file_out.close();
	second_file_out.close();
}

void sort_lines(const string name)    //�-��� ��� ���������� ���������� ����� �� ���������� ���������
{
	fstream file_out_in("second_file.txt", fstream::out | fstream::in);    //³������� ����� � ����� �������-������
	
	if (!file_out_in.is_open())		  //�������� �� ����������� �������� �����
	{
		cout << "Error! Could not open the file for sorting!" << endl;
		exit(0);
	} 

	vector<string> lines_array = create_linesArray(name);    //��������� ���������� ������ ��� ���������� �����

	int N;                           //����� ��� ���������� �-� �������� ����������
	cout << "Enter N(can`t be higher than " << lines_array.size() << " ): "; cin >> N;    //�������� �� ����������� ��������

	while (N > lines_array.size())
	{
		cout << "Attention! N can`t be higher than " << lines_array.size() << ". Enter again: "; cin >> N;
	}

	for (int i = 0; i < N - 1; i++)							//���������� ����� �� ������� ���������
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (lines_array[j] > lines_array[j + 1])
			{
				swap(lines_array[j], lines_array[j + 1]);
			}
		}
	}

	for (int i = 0; i < lines_array.size(); i++)            //����� ����� ����� � ����
	{
		file_out_in << lines_array[i] << endl;
	}

	file_out_in.close();                                    //�������� �����
}