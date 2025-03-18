#include <bits/stdc++.h>
using namespace std;
/*
given two sorted arrays, merge them to form a single,
sorted array with all items (non-descreasing)

1 < int[n] < 5 * 10^5


input:
a = [1,2,3]
b = [2,5,5]

out:
[1,2,2,3,5,5]

*/

vector<int> mergeArrays(vector<int> a,vector<int> b)
{
    vector<int> merged;
    int ait = 0;
    int bit = 0;
    while(ait < a.size() && bit < b.size())
    {
        if(a[ait] <= b[bit])
        {
            merged.push_back(a[ait]);
            ait++;
        } else
        {
            merged.push_back(b[bit]);
            bit++;
        }
    }

    for(;ait < a.size();ait++)
        merged.push_back(a[ait]);
    for(;bit < b.size();bit++)
        merged.push_back(b[bit]);

    return merged;
}

// time: O(n+m) 
// space: O(n+m)

int main()
{
    vector<int> a = {1,2,3};
    vector<int> b = {2,5,5};

    vector<int> sol = mergeArrays(a,b);

    for(int n : sol)
        cout << n << endl;

    return -1;
}