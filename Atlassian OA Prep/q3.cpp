#include <bits/stdc++.h>
using namespace std;

/*
a flower has only 2 types of bouqeuts
1: three roses and costs p dollars
2: one cosmo and one rose and costs q dollars


flowers are grown in a single row, ie array
0 = rose
1 = cosmo
any bouquet must be fromed from consectuive flowers
given a binary string reprenting the garden row, and the cost p and q,
find the maximum possible revenue, dont need all the flowers to be used.


input: "001101011"
p = 5
q = 10
output: 30 (there are no rose bouquets but there are 3 cosmo bouquets)

input: "1110101111"
p = 8
q = 10
output: can make 2 roses and 1 cosmo, so 26 in total

input: "111010111"
p = 5
q = 10
output: can make 2 roses and 1 cosmo OR 2 cosmos and 1 rose
cosmo is more expensive, so output is 25

*/

/*
idea:
preference the more expensive bouquet
loop through array and find all of that and remove the values as we find it
then loop again and look for any remaining of the other bouquet

if equal price, find the one that has the highest frequency
*/


int profitableBouquet(int p, int q, string s)
{
    int cost = 0;
    string rose = "000";
    string cosmos1 = "01";
    string cosmos2 = "10";

    if(p>q) // rose more expensive
    {
        for(int i = 0;i+2<s.size();i++) // find all roses first
        {
            if(s.substr(i, 3) == rose)
            {
                cost += p;
                s.erase(i,3);
                i -= 3;
                if(i<0) i = 0;
            }
        }
        for(int i = 0;i+1<s.size();i++) // find all cosmos
        {
            if(s.substr(i, 2) == cosmos1 || s.substr(i, 2) == cosmos2)
            {
                cost += q;
                s.erase(i,2);
                i -= 2;
                if(i<0) i = 0;
            }
        }
    }else if (q>p) // cosmos more expensive
    {
        for(int i = 0;i+1<s.size();i++) // find all cosmos first
        {
            if(s.substr(i, 2) == cosmos1 || s.substr(i, 2) == cosmos2)
            {
                cost += q;
                s.erase(i,2);
                i -= 2;
                if(i<0) i = 0;
            }
        }
        for(int i = 0;i+2<s.size();i++) // find all roses 
        {
            if(s.substr(i, 3) == rose)
            {
                cost += p;
                s.erase(i,3);
                i -= 3;
                if(i<0) i = 0;
            }
        }
    }else // equal price
    {
        // 2 cases, removing roses 1st is better, or removing cosmos first is better
        int cost2;
        string temp = s;

        // case 1
        for(int i = 0;i+2<s.size();i++) // find all roses first
        {
            if(s.substr(i, 3) == rose)
            {
                cost += p;
                s.erase(i,3);
                i -= 3;
                if(i<0) i = 0;
            }
        }
        for(int i = 0;i+1<s.size();i++) // find all cosmos
        {
            if(s.substr(i, 2) == cosmos1 || s.substr(i, 2) == cosmos2)
            {
                cost += q;
                s.erase(i,2);
                i -= 2;
                if(i<0) i = 0;
            }
        }

        // case 2
        for(int i = 0;i+1<temp.size();i++) // find all cosmos first
        {
            if(temp.substr(i, 2) == cosmos1 || temp.substr(i, 2) == cosmos2)
            {
                cost2 += q;
                temp.erase(i,2);
                i -= 2;
                if(i<0) i = 0;
            }
        }
        for(int i = 0;i+2<temp.size();i++) // find all roses 
        {
            if(temp.substr(i, 3) == rose)
            {
                cost2 += p;
                temp.erase(i,3);
                i -= 3;
                if(i<0) i = 0;
            }
        }

        cost = max(cost,cost2);
    }

    return cost;
}


int main()
{
    string s = "1110101111";
    int p = 8;
    int q = 10;


    int cost = profitableBouquet(p,q,s);

    cout << cost << endl;
    return 0;
}



