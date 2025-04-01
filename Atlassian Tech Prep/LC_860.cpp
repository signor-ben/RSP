/*
lemonade costs 5 
customers queueing to buy 1 at aatime
each will pay ith a 5 10 or 20
much give correct change
no hcange initially

given array bills representing to the bills of each customer
return true if possible
false otherwise


constraints:
bills.size() = 1->100000


I/O:

input: [10,5,20]
return: false

input: [5,10,5]
return: true

input: [5,5,5,10,5,20,10]
return: true

Algorithm Design:
every interaction we need to update bills we have
at each interaction, give change with the largest notes possible
run through array until either end or cant give change

Complexity Analysis:
Space: O(1)
Time: O(n)

*/
#include <bits/stdc++.h>
using namespace std;

bool lemonadeStand(const vector<int>& bills)
{
    vector<int> change(2,0);

    for(int n : bills)
    {
        if(n == 5) // paying with a 5
            change[0]++;
        else if (n == 10) // paying with a 10
        {
            if(change[0] > 0)
            {
                change[0]--;
                change[1]++;
            }else
                return false;
        }
        else // paying with a 20
        {
            if(change[1] > 0 && change[0] > 0)
            {
                change[1]--;
                change[0]--;
            } else if(change[0] >= 3)
                change[0] -= 3;
            else
                return false;
        }
    }

    return true;
}

void test(const vector<int>& bills, bool expected)
{
    bool actual = lemonadeStand(bills);
    if(actual == expected)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";
}


int main()
{
    test({10,5,20},false);
    test({5,10,5}, true);
    test({5,5,5,10,5,20,10}, true);

    return 0;
}
