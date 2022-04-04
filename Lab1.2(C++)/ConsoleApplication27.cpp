#include "binary_files.h"

int main()
{
	input_data("students_DB.txt"); /*Введення інформації у перший файл*/

	cout << "-------------------DATABASE-------------------" << endl; 
	print_data("students_DB.txt"); /*Виведення інформації з першого файлу*/

	vector<t_student> students_vector = create_students_vector("students_DB.txt");    /*Створення масиву студентів*/
	vector<t_student> min_av_students_vector = create_min_av_vector(students_vector); /*Створення масиву студентів із мінімальними балами*/

	print_data(min_av_students_vector); /*Виведення студентів із мінімальними балами*/

	distribute_data("sorted_DB.txt", students_vector); /*Розподіл студентів у інший файл*/

	cout << endl << "------------------SORTED LIST------------------" << endl;
	print_data("sorted_DB.txt"); /*Виведення відсортованого списку студентів*/
}