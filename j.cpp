/*
Question 1:

given an arrayy of ints num and an int target, return indices of two numbers such that they add up to target

Constraints:
nums: 2->10^4;
nums element: -10^9->10^9
target: -10^9->10^9
unsorted
assume only one pair

I/O:
nums = [1,4,3,5,6]
target = 11;
return {3,4}

nums = [-10,0,1,5]
target = -5
return {0,3}

Algorithm Design:
brute force:
go over each n in nums
    serach for another n

hashmap:
fill the map,
at each it map, check for target difference, if found, return two indices


Complexity:
Time: O(n)
Space: O(n)
*/


vector<int> sumToTarget(vector<int> nums, int target)
{
    unordered_map<int,int> map;
    // fill up map and search for target indices
    for (int i=0;i<nums.size();i++)
    {
        if(map.find(target-nums[i]) != map.end())
        {
            return {map[target-nums[i]], i};
        }
        map[nums[i]] = i;
    }

    return {};
}
/*
Testing:
nums = [1,4,3,5,6]
                ^
target = 11;
expected {3,4}

map:
1:0
4:1
3:2
5:3


return {3,4}

nums = [-10,0,1,5]
                ^
target = -5
expected {0,3}

map:
-10:0
0:1
1:2

return {0,3}

*/
----------------------------------------------------------------
/*
Question 2:

given an mxn 2d binary grid wheere 1 are islands and 0 ius water, return the number of islands
islands are 1 connected horizaontally and veritcally

m: 1->300
n: 1->300

I/O:
0 0 0 0
1 1 0 0
0 0 1 0

return 2;

1 1 1 1
1 1 0 0

return 1

0 0 0 
0 0 0
0 0 0

return 0;


Algorithm Design:

Graph, and connected components approach
run dfs on the grid to find number of components

flip bits when visited
at each 1 node, check neighbours, if tany are 1, then add them to the 

0 0 0 
0 0 0
0 0 1

island_ct++;


Time:
O(mn)
O(1)
*/

void dfs(vector<vector<int>>& grid, int i, int j)
{
    //flip the bit
    grid[i][j] = 0;

    if(grid[i][j-1] == 1)
    {
        
    }

}


int countOfIslands(vector<vector<int>> grid)
{
    int island_ct = 0;
    // go over every index in grid
    for(int i=0;i<grid.size();i++)
    {
        for (int j=0;j<grid[0].size();j++)
        {
            // if index is equal to 1(an island)
            if(grid[i][j] == 1)
            {
                island_ct++;
                dfs(grid, i, j);
            }
        }
    }

    return island_ct;
}

