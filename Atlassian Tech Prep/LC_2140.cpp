/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0)
and make a decision whether to solve or skip each question. 
Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions.
If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2] , [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.
 
[[4,1],[10,4],[1,1],[3,2],[6,1]]

DP Array = [4,10,10,10,11]
*/
#include <bits/stdc++.h>
using namespace std;


int max_Score(vector<vector<int>>& questions)
{
    int size = questions.size();
    vector<int> dp(size,0);

    // fill up the dp array iteratively
    for(int i = size-1;i>=0;i--)
    {
        int points = questions[i][0];
        int skip = (1+i < size) ? dp[i+1] : 0;
        int solve = points;
        int next_ind = i + questions[i][1] + 1;

        if(next_ind < size)
            solve += dp[next_ind];
            
        dp[i] = max(skip,solve);
    }

    return dp[0];
}



void test(vector<vector<int>>& questions, int exp_max)
{
    int score = max_Score(questions);

    if(score == exp_max)
        cout << "PASSED\n";
    else
        cout << "FAILED\n";
}


int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};

    test(questions, 5);

    return 0;
}