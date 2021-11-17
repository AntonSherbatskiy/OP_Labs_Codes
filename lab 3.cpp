#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n = 0;                                                              //змінна для номеру ітерації
    double eps = pow(10, -8), sum = 0, x, denominator;             //x - вхідне значення, denominator - знаменник дробу

    cout << "Enter x: " << fixed << setprecision(10) << endl; cin >> x;     //вводимо значення змінної x

    double element = x;                                                     //ініціалізація елемента рекурентної формули

    while (fabs(element) > eps)
    {
        sum += element;                                                      //знаходження суми
        n++;
        denominator = (n * 2) * ((n * 2) + 1);                               //знаходження знаменника елемента
        element = (element * x * x) / denominator;                           //знаходження наступних елементів виразу
        cout << n << " Element = " << element << endl;
        cout << sum << endl;
    }

    cout << "Sum: " << sum;
}



