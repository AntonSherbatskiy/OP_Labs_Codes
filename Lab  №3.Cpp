#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int i = 0;                                                              //змінна для номеру ітерації
    double e = pow(10, -8), sum = 0, x, numerator, denominator;  //x - вхідне значення, numerator - чисельник дробу, denominator - знаменник дробу

    cout << "Enter x: " << fixed << setprecision(10) << endl; cin >> x;      //вводимо значення змінної x

    double element = x;                                                     //ініціалізація елемента рекурентої формули
    numerator = pow(x, 2);

    while (fabs(element) > e)
    {
        sum += element;                                                      //знаходження суми
        i++;
        denominator = (i * 2) * ((i * 2) + 1);
        element *= numerator / denominator;
        cout << i << " Element = " << element << endl;
    }
    cout << "Sum = " << sum;
}
