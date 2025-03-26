#include <bits/stdc++.h>

using namespace std;


string timeConversion(string s) 
{
    string hours = s.substr(0,2);
    string minutesSeconds = s.substr(2,6);

    if(s[8] == 'A')
    {
        if(hours == "12")
            hours = "00";
    } else
    {
        if(hours != "12")
            hours = to_string(stoi(hours)+12);
    }

    return hours + minutesSeconds;
}


int main() 
{
    string s = "12:23:01AM";

    cout << timeConversion(s) << endl;


    return 0;
}