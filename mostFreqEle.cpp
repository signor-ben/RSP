#include <bits/stdc++.h>

using namespace std;

vector<int> func(vector<int> nums)
{
    vector<int> counts;
    priority_queue<pair<int,int>> pq;
    unordered_map<int,int> mp;

    for(int num : nums)
        mp[num]++;

    for(auto pair : mp)
        pq.push({pair.second,pair.first});
    
    for(int i = 0;i<3;i++)
    {
        counts.push_back(pq.top().second);
        pq.pop();
    }

    return counts;
}


int main()
{
    vector<int> nums = {1,1,1,2,3,3,3,3,3,3,4,5,5,6,6,6,6,7,7,7,7,8,8,8,8,8,8,9,9,9};

    vector<int> freq = func(nums);

    for(int n : freq)
        cout << n << endl;

    return 0;
}