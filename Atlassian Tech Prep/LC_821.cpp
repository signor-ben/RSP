/*
string s and char c that occurs in s
return an int array of length s.size()
where answer[i] is the distance from i to the closest occurence of c in s using abs(i - j)

constraints:
s.size() = 1->10000
characters = lowercase english

inputs and outputs:

input: s = [aba]  c = b
return: [1,0,1]

input: s = [abccbad], c = c
return: [2,1,0,0,1,2,3]

input: s = "atlassian", c = a
return [0,1,1,0,1,2,1,0,1]

Algorithm Design:
brute force:
at every characters, run through array and keep a min of the distance between that character and char c
time complexity for brute force: O(n^2)

1 pass to find the position of all char c
2nd pass, check i with each pos of c
time comp: worst O(n^2) average O(n)
space comp: O(n)

BETTER SOLUTION
2 pass 
left to right, then right to left
store the last seen index of c
set sol[i] to the last seen dist left to right
do same right to left, but also min of the two


*/
#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_dist_to_c(string s, char c)
{
    vector<int> sol(s.size(),INT_MAX);

    int last_ind = -1;

    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == c)
            last_ind = i;
        if(last_ind != -1)
            sol[i] = abs(i-last_ind);

    }
    last_ind = -1;
    for(int i = s.size()-1;i>=0;i--)
    {
        if(s[i] == c)
            last_ind = i;
        if(last_ind != -1)
            sol[i] = min(sol[i],abs(i-last_ind));
    } 

    return sol;
}


void test(string s, char c, vector<int> expected)
{
    vector<int> actual = shortest_dist_to_c(s,c);

    if(actual == expected)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";

}

int main()
{
    test("aba", 'b', {1,0,1});
    test("abccbad", 'c', {2,1,0,0,1,2,3});
    test("atlassian", 'a', {0,1,1,0,1,2,1,0,1});

    return 0;
}