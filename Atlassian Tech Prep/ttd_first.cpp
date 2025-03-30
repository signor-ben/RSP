#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    int it = 0;
    int start_interval = 0;
    int curr_interval = 0;

    vector<int> partitions;
    unordered_set<char> seen;

    while(it < s.size())
    {
        if(!seen.count(s[it]))
        {
            int last;
            for(int i = it;i<s.size();i++)
                if(s[i] == s[it])
                    last = i;
            seen.insert(s[it]);
            curr_interval = max(curr_interval,last);
            if(it == curr_interval)
            {
                partitions.push_back(curr_interval-start_interval+1);
                start_interval = it+1;
            }
            it++;
        }else
        {
            if(it == curr_interval)
            {
                partitions.push_back(curr_interval-start_interval+1);
                it++;
                start_interval = it;
            } else
                it++;
        }
    }

    return partitions;
}

void test(string s, vector<int> expected)
{
    vector<int> result = partitionLabels(s);
    if(result == expected)
        cout << "PASSED" << endl;
    else
    {
        cout << "FAILED" << endl;
        cout << "EXPECTED: ";
        for(int e : expected) cout << e;
        cout << "RETURNED: ";
        for(int e : result) cout << e;
        cout << endl;
    }
}

int main()
{
    test("ababcc",{4,2});
    test("ababcc",{3,2});

    return 0;
}