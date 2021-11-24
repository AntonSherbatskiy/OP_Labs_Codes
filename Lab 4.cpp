#include <iostream>
using namespace std;
int main()
{
    int n, prime = 2, element = 0;                                                 //prime - просте число
    bool prime_check;                                                              //prime_check - перевірка на простоту
    cout << "Enter n: " << endl; cin >> n;
    if(n < 0 || n == 0)
    {
        cout << "Error, it`s not allowed to use negative numbers or 0!" << endl;   //неможливо при < 0
        return 0;
    }
    while (element < n)
    {
        prime_check = true;                                                         //ініціалізація булевої змінної

            for (int i = 2; i * i <= prime; i++)
            {
                if (prime % i == 0)                                                  //перевірка на простоту
                prime_check = false;
            }
        if (prime_check == true)
        {
            cout << element + 1 << " element = " << prime << endl;
            element++;
        }
        prime++;
    }

}
