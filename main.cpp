#include <iostream>
#include <string>
using namespace std;

int quantityWords(string text);                 //Функція для знаходження кількості слів у введеному рядку
void cutString(string& text, string *array);    //Функція для виділення слів із введеного рядка
void sortWords(string* array, int size);        //Функція для сортування слів за їх першою літерою
void outputWords(string array[], int size);     //Функція для виведення відсортованих слів
void deleteWords(string* array, int size);

int main()
{
    string text;                                //Змінна для збереження введеного рядка
    cout << "Enter string:" << endl;
    getline(cin, text);                 //Введеняня рядка

    int quantity = quantityWords(text);    //Змінна для збереження кількості слів
    string words[quantity];                    //Рядковий масив для збереження введених слів

    cutString(text, words);                 //Виділяємо кожне слово із рядка
    sortWords(words, quantity);                //Сортуємо масив слів
    cout << endl;
    outputWords(words, quantity);              //Виводимо масив слів

    cout << endl;

    deleteWords(words, quantity);
}

int quantityWords(string text)
{
    int quantity = 1, pos = text.find(' ', 0); //Кількість слів у рядку та поточна позиція пробілу

    while(pos != -1)                                  //Рахуємо пробіли, поки вони вони наявні у рядку
    {
        quantity++;
        pos = text.find(' ', pos + 1);         //Переміщення позиції пробілу
    }
    return quantity;
}

void cutString(string& text, string *array)
{
    int pos = 0, prePos = 0;                       //Позиції попереднього та поточного пробілів

    string subStr;                                 //Створення підрядка

    pos = text.find(' ', pos);
    subStr = text.substr(prePos, pos - prePos); //Виділення першого слова у рядку

    array[0] = subStr;                             //Копіювання виділеного слова у масив

    for(int i = 1; pos != -1; i++)                 //Виділення наступних слів
    {
        prePos = pos;                              //Переміщення позиції пробілу(попередня позиція = поточній)
        pos = text.find(' ', pos + 1);      //Знаходження поточної позиції пробілу у рядку
        subStr = text.substr(prePos + 1, pos - prePos - 1); //Виділення поточного слова, розділеного пробілами
        array[i] = subStr;                         //Копіювання знайденого підрядка(поточного слова) у масив
    }
}
void sortWords(string *array, int size)
{
    string temp;                                   //Змінна для збереження проміжного елементу

    for(int i = 1; i < size; i++)                  //Сортування слів за збільшенням коду першою літери(бульбашкою)
    {
        for(int j = 0; j < size - i; j++)
        {
            if(array[j] > array[j + 1])            //Якщо ASCII код першої літери пешого слова більший за код
            {                                      //літери другого слова, виконуємо сортування
                temp = array[j+1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}
void outputWords(string array[], int size)
{

    cout << "Sorted string:" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << endl;                  //Виведення відсортованих слів
    }

    string text1 = "";
    cout << endl << endl;

    for(int i = 0; i < size; i++)
    {
        text1 += array[i];
    }
    cout << text1;
}

void deleteWords(string* array, int size)
{
    int k;
    cin >> k;

    string newWords[size-k];

    for(int i = 0; i < size-k; i++)
    {
        newWords[i] = array[i];
    }

    delete [] array;

    array = newWords;

    for(int i = 0; i < size-k; i++)
    {
        cout << array[i] << endl;
    }
}

