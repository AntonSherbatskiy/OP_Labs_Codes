#include <iostream>
#include <cstring>
using namespace std;

void outputWords(string*, int);          //Функція для виведення масиву слів
void sortWords(string*, int);            //Функція для сортування масиву слів
void fillWords(string*, char*, int&);    //Функція для заповнення масиву рядками

int main()
{
    string* words = new string[100];     //Створення динамічного масиву для збереження слів
    char wordsArray[500];                //Створення масиву для збереження вхідних даних(слів із пробілами)
    cout << "Enter string: " << endl;
    gets(wordsArray);

    int counter = 0;                     //Допоміжна змінна для позначення останнього індексу елемента у масиві слів
    fillWords(words, wordsArray, counter);                  //Заповнення масиву слів

    cout << endl << "Words(not sorted): " << endl;
    outputWords(words, counter);                               //Виведення невідсортованих елементів(проміжні дані)

    sortWords(words, counter);                                 //Сортування слів за першою літерою

    cout << endl << "Words(sorted): " << endl;

    outputWords(words, counter); delete [] words;              //Виведення відсортованого рядка
}

void fillWords(string* words, char* symbols, int &counter)
{
    char* str;                                          //Створення допоміжної змінної для збереження слова у рядку
    str = strtok(symbols, " ");                  //Виділення слова із рядка
    counter = 0;
    while(str != NULL)                                 //Виділення та збереження слів із рядка у масив слів
    {
        words[counter] = str;
        counter++;
        str = strtok(NULL, " ");           //Перехід до наступного слова
    }
}
void sortWords(string* words, int counter)
{
    string temp;                            //Створення проміжної змінної для збереження проміжного елементу сортування
    for(int i = 1; i < counter; i++)
    {

        for(int j = 0; j < counter - i; j++)      //Сортування слів за алфавітом методом бульбашки
        {
            if(words[j] > words[j + 1])
            {
                temp = words[j + 1];
                words[j + 1] = words[j];
                words[j] = temp;
            }
        }
    }
}
void outputWords(string* words, int counter)
{
    for(int i = 0; i < counter; i++)
    {
        cout << words[i] << endl;                 //Виведення елементів масиву слів
    }
}
