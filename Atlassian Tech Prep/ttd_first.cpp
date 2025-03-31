#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    unordered_map<char, int> lastOccurrence;
    vector<int> result;

    // Step 1: Store last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
        lastOccurrence[s[i]] = i;
    }

    // Step 2: Merge partitions in one pass
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        end = max(end, lastOccurrence[s[i]]);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    return result;
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
        cout << " RETURNED: ";
        for(int e : result) cout << e;
        cout << endl;
    }
}

int main()
{
    test("ababcc",{4,2});
    test("ababcbacadefegdehijhklij", {9,7,8});
    test("eccbbbbdec",{10});
    test("xabababab",{1,8});

    return 0;
}