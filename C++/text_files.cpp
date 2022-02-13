#include "text_files.h"

void input_text(const string name)					//Ф-ція для збереження рядків в основний файл
{
	ofstream file_out(name);						//Створення змінної для запису рядків у файл

	if (file_out.is_open())							//Перевірка файлу на правильність відкриття					
	{
		cout << "Start file is successfully opened!" << endl << endl;  
	}
	else
	{
		cout << "Error! Could not open the start file!" << endl;
		exit(0);
	}

	string line;							        //Створення змінної для збереження поточного рядка						

	while (true)									//Введення рядків у файл за допомогою циклу
	{
		cout << "Enter line(press ctrl + X to stop): ";
		getline(cin, line);							

		if ((int)line[0] != 24) { file_out << line << endl; }  //Кінець введення, якщо буде введено необхідну комбінацію(ctrl + X)
		else { break; }
	}

	file_out.close();                              //Закриття файлу 
}

void print_file(const string name)				   //Ф-ція для виведення рядків у консоль
{
	ifstream file_in(name);						   //Відкриття файлу у режимі читання

	if (!file_in.is_open()) { cout << "Error! Could not open the file!" << endl; exit(0); } //Перевірка файлу на правильність відкриття
	
	string line;								   //Створення змінної для збереження поточного рядка

	while (!file_in.eof())					       //Читання рядків із файлу, поки покажчик не досягне кінця файлу	
	{
		getline(file_in, line);
		cout << line << endl;
	}

	file_in.close();                              //Закриття файлу
}

vector<string> create_linesArray(const string name)    //Ф-ція для створення масиву рядків
{
	ifstream file_in(name);							   //Відкриття файлу у режимі читання

	if (!file_in.is_open()) { cout << "Error! Could not open the file!" << endl; }    //Перевірка на правильність відкриття файлу		

	vector<string> lines_array;						   //Створення масиву для збереження рядків із файлу
	string line;									   //Створення змінної для збереження поточного рядка

	while (!file_in.eof())							   //Читання рядків із файлу поки покажчик не досягне кінця файлу
	{
		getline(file_in, line);

		if (line == "") { continue; }				
		else { lines_array.push_back(line); }
	}

	file_in.close();                                  //Закриття файлу

	return lines_array;						
}

void distribute_strings(const string start_file, const string first_file, const string second_file) //Ф-ція для розподілу рядків
{
	ifstream start_file_in(start_file);			     //Відкриття головного файлу у режимі читання
	ofstream first_file_out(first_file),			 //Відкриття файлів із непарними та парними рядками у режимі запису 
			 second_file_out(second_file);

	if (!start_file_in.is_open() || !first_file_out.is_open() || !second_file_out.is_open()) //Перевірка на правильність відкриття файлів
	{
		cout << "Error! File could not open, cannot distribute strings!";
		exit(0);
	}

	vector<string> lines_array = create_linesArray(start_file);			//Створення масиву для розподілу рядків

	for (int i = 0; i < lines_array.size(); i++)						//Розподіл рядків по файлам
	{
		if (i % 2 == 0) { first_file_out << lines_array[i] << endl; }
		else { second_file_out << lines_array[i] << endl; }
	}

	start_file_in.close();											    //Закриття файлів
	first_file_out.close();
	second_file_out.close();
}

void sort_lines(const string name)    //Ф-ція для лексичного сортування рядків за алгоритмом бульбашки
{
	fstream file_out_in("second_file.txt", fstream::out | fstream::in);    //Відкриття файлу у режимі читання-запису
	
	if (!file_out_in.is_open())		  //Перевірка на правильність відкриття файлу
	{
		cout << "Error! Could not open the file for sorting!" << endl;
		exit(0);
	} 

	vector<string> lines_array = create_linesArray(name);    //Створення допоміжного масиву для сортування рядків

	int N;                           //Змінна для збереження к-ті елементів сортування
	cout << "Enter N(can`t be higher than " << lines_array.size() << " ): "; cin >> N;    //Перевірка на правильність введення

	while (N > lines_array.size())
	{
		cout << "Attention! N can`t be higher than " << lines_array.size() << ". Enter again: "; cin >> N;
	}

	for (int i = 0; i < N - 1; i++)							//Сортування рядків за методом бульбашки
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (lines_array[j] > lines_array[j + 1])
			{
				swap(lines_array[j], lines_array[j + 1]);
			}
		}
	}

	for (int i = 0; i < lines_array.size(); i++)            //Запис нових рядків у файл
	{
		file_out_in << lines_array[i] << endl;
	}

	file_out_in.close();                                    //Закриття файлу
}