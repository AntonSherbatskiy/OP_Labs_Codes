#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double sqrt_next, element = 0;

    cout << "Enter n:" << endl; cin >> n;

    if(n < 0)
    {
        cout << "Error" << endl;
        return 0;
    }

    for(int i = n; i>=1; i--)
    {
        sqrt_next = 3 * i;
        element = sqrt(element + sqrt_next);
        cout << "Expression with " << n - i + 1 << " elements = " << element << endl;
    }

    cout << "All expression = " << element << endl;
}
