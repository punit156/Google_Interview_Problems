/*
Problem Statement :-
Given a string representing time in hh:mm. Some digits might be blank
represented by '?'. Replace '?' such that resulting time is maximum.
Maximum time is 23:59, minimum is 00:00.


Example :-
1) 
    Input - "?4:5?"
    Output - "14:59"

2)
    Input - "??:??"
    Output - "23:59"

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string time = "??:23";
    if(time[0] == '?' && time[1] == '?')
    {
        time[0] = '2';
        time[1] = '3';
    }
    else if(time[0] == '?')
    {
        if(time[1] >= '0' && time[1] <= '3')
        {
            time[0] = '2';
        }
        else
        {
            time[0] = '1';
        }
    }
    else if(time[1] == '?')
    {
        if(time[0] == '2')
        {
            time[1] = '3';
        }
        else
        {
            time[1] = '9';
        }
    }
    if(time[3] == '?')
    {
        time[3] = '5';
    }
    if(time[4] == '?')
    {
        time[4] = '9';
    }
    cout << time;
    return 0;
}