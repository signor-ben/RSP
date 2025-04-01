#include <bits/stdc++.h>
using namespace std;

string rankTeams(vector<string>& votes) {
    unordered_map<char,vector<int>> team_votes;
    vector<char> teams;

    for (char c : votes[0]) 
        team_votes[c] = vector<int>(votes[0].size(), 0);  // Resize each team's vector to the size of the votes

    for(string vote : votes)
        for(int i = 0;i<vote.size();i++)
            team_votes[vote[i]][i]++;
        
    for(char c : votes[0])
        teams.push_back(c);

    sort(teams.begin(),teams.end(), [&team_votes](char a, char b)
    {
        for (int i = 0; i < team_votes[a].size(); i++) {
            if (team_votes[a][i] != team_votes[b][i]) {
                return team_votes[a][i] > team_votes[b][i];  // Sort by vote count at position i
            }
        }
        return a < b;  // Alphabetical order if vote counts are tied
    });

    string sol;
    for(char c : teams)
        sol += c;

    return sol;
}


int main()
{   
    vector<string> votes1 = {"WXYZ","XYZW"};
    cout << rankTeams(votes1) << endl;

    return 0;
}