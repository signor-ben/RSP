#include <bits/stdc++.h>
using namespace std;

/*
frequency of max value
given array od ints, find max val in the segment from each index to 
the highest index element, inclusve, then find how many times that int 
occurs in the segment. create a return array with one val for each query:
the number of times the max val occurs at a segment starting at that 
index

input:
numbers =  [5,4,5,3,2]
queries = [1,2,3,4,5]

output:
[2,1,1,1,1]


*/

vector<int> maxValFrequency(vector<int> nums, vector<int> queries)
{
    vector<int> sol;
    vector<int> freq(nums.size(), 0);
    pair<int,int> maxAndFreq = {INT_MIN,0};


    for(int i = nums.size()-1;i>=0;i--)
    {
        if(nums[i] > maxAndFreq.first)
        {
            maxAndFreq.first = nums[i];
            maxAndFreq.second = 1;
            freq[i] = maxAndFreq.second;
        } else if (nums[i] == maxAndFreq.first) 
        {
            maxAndFreq.second++;
            freq[i] = maxAndFreq.second;
        } else
        {
            freq[i] = maxAndFreq.second;
        }
    }


    for(int query : queries)
        sol.push_back(freq[query-1]);

    return sol;
}   



int main()
{
    vector<int> numbers =  {5,4,5,3,2};
    vector<int> queries = {1,2,3,4,5};

    vector<int> sol = maxValFrequency(numbers, queries);

    for(int n : sol)
        cout << n << endl;

    return 0;
}
