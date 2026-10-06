/* Time Converter */
#include<iostream>
using namespace std;

class TimeConverter
{
    int hours, minutes, seconds;

public:

    void secondsToTime()
    {
        int total;

        cout << "Enter total seconds: ";
        cin >> total;

        hours = total / 3600;
        total = total % 3600;

        minutes = total / 60;
        seconds = total % 60;

        cout << "HH:MM:SS = "
             << hours << ":" << minutes << ":" << seconds;
    }

    void timeToSeconds()
    {
        int total;

        cout << "\nEnter Hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        total = (hours * 3600) + (minutes * 60) + seconds;

        cout << "Total seconds: " << total;
    }
};

int main()
{
    TimeConverter t;

    t.secondsToTime();
    t.timeToSeconds();

    return 0;
}
