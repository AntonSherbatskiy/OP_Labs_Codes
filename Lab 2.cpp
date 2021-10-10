#include <iostream>

using namespace std;

int main()
{
    float time;

    cout << "Enter the time after the start of the traffic light: " << endl;
    cin >> time;
    while (time > 6)
    {
        time -= 6;
    }
    if (time > 4 && time <= 6)
    {
        cout << "Green" << endl;
    }
    else if (time > 3 && time <= 4)
    {
        cout << "Yellow" << endl;
    }
    else if (time > 0 && time <= 3)
    {
        cout << "Red" << endl;
    }



}
