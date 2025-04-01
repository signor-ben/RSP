/*
int array nums
return length of longest strictly increasing subsequence

so subSEQUENCE not subarray


constraints:
what numbers: -10000 -> 10000
how many in array: 1->2500

input: [1,2,3,4,0,0,5]
output: 5

input: [5,5,5,5,5]
output: 1

input: [7,6,5,4,8,5,4,3]
output: 2

input: [3,5,0,1,2]
output: 3

input: {0,1,0,3,2,3}
output: 4


idea:
DP approach
so make a dp table that represent the LIS at each index i

iterate over the array with i =1 and j=0
for each i, iterate over every j up to i
check if nums[j] is less than nums[i]
if so, try to update dp[i] with a new max
do this for every and, then the final i will be the maximum


complexity analysis:
space: O(n)
time: O(n^2)

*/
#include <bits/stdc++.h>

using namespace std;

int longest_inc_subseq(vector<int>& nums)
{
    vector<int> dp(nums.size(), 1);
//  [0,1,0,3,2,3] 
//  [1,1,1,1,1,1]
    int maximum = 1;

    for(int i = 1;i<nums.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i] > nums[j])
                dp[i] = max(dp[i],dp[j]+1);
        }
        maximum = max(maximum,dp[i]);
    }

    return maximum;
}



void test(vector<int> nums, int expected_res)
{
    int test_res = longest_inc_subseq(nums);

    if(test_res == expected_res)
        cout << "PASS\n";
    else
        cout << "FAIL\n" << "OUTPUT: " << test_res << endl;
}


int main()
{
    test({1,2,3,4,0,0,5},5);
    test({5,5,5,5,5,5},1);
    test({7,6,5,4,8,5,4,3},2);
    test({3,5,0,1,2},3);
    test({0,1,0,3,2,3},4);

    return 0;
}


