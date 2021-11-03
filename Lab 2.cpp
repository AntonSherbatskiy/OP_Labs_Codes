#include <iostream>
using namespace std;

int main()
{
    int time, time_divide;
    string col;

    cout << "Enter the time after the start of the traffic light: " << endl;
    cin >> time;

    time_divide = time % 6;

    if(time_divide > 4 && time_divide <=6)
        col = "Red";
    else if(time_divide > 3 && time_divide <= 4)
        col = "Yellow";
    else if(time_divide >= 0 && time_divide <= 3)
        col = "Green";

    cout << col << endl;
}
