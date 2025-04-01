/*
for 2 strings s and t, we say t divides s if and only if s = t+T+t+t...

fiven 2 stings str1 and str2, return the largest string x such that it divides both str 1 and 2
if no string, return string

str length: 1 -> 1000
both english uppercase

str1 = "ABABAB"
str2 = "ABAB"

return "AB"


str1 = "TEST"
str2 = "ATLASSIAN"

return ""

str1 = "ABCABCABCABC"
str2 = "ABCABC"

return "ABCABC"


design idea:
iterate over both strings at the same time, compare chars


actual answer:
check if str1+str2 == str2+str1
    if not then return ""
    if yes then return the substr from either of them from 0 to the gcd of the 2 strings sizes

*/

#include <bits/stdc++.h>
using namespace std;

string GCD_of_strings(string str1, string str2)
{
    if(str1+str2 != str2+str1)
        return "";

    return str1.substr(0,gcd(str1.size(),str2.size()));
}



void test(string str1, string str2, string out)
{
    string test_string = GCD_of_strings(str1,str2);

    if(test_string == out)
        cout << "PASSED\n";
    else
    {
        cout << "FAILED" << endl;
        cout << "TEST OUTPUT: " << test_string << endl;
    }
}

int main()
{
    test("ABABAB","AB","AB");
    test("TEST","ATLASSIAN","");
    test("ABCABCABCABC","ABCABC", "ABCABC");
    test("LEET","CODE","");

    return 0;
}