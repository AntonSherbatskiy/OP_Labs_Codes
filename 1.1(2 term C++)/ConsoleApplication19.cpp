#include "text_files.h"

int main()
{
	input_text("start_file.txt");                                              //Введення даних в основний файл
	cout << endl << "-------------START FILE-------------" << endl;			  
	print_file("start_file.txt");										       //Виведення рядків із основного файлу

	distribute_strings("start_file.txt", "first_file.txt", "second_file.txt"); //Розподіл рядків за їх парністю

	cout << "------------FIRST FILE--------------" << endl;				
	print_file("first_file.txt");											   //Виведення файлу із парними рядками

	cout << "------------SECOND FILE-------------" << endl;
	print_file("second_file.txt");											   //Виведення файлу з непарними рядками
		
	sort_lines("second_file.txt");											   //Лексичне сортування рядків
	cout << endl << "-----SECOND FILE AFTER SORTING------" << endl;				
	print_file("second_file.txt");											   //Виведення файлу із відсортованими рядками
}