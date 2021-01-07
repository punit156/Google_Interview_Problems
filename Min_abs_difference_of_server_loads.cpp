/*
Problem Statement :-
Given an array of integers nums, indicating the amount of load a process
will cause on a server. You have two servers, try to balance the load
on each, in other words, try to distribute the processes such that the
absolute difference between the server loads in minimum. Return the 
absolute difference.

For eg :-
1) nums = [1,2,3,4,5]
Output = 1.  Server 1 = [1,3,4], Server 2 = [2,5]

https://www.geeksforgeeks.org/minimum-absolute-difference-of-server-loads/

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {10,10,9,9,2};
    int n = nums.size();

    /* The idea here is to make this into a 0/1 Knapsack problem. See
    link above. Best case scenario is each server gets exactly half of 
    total load. If not half, as close to half as possible. Find the 
    total sum first */

    int sum = 0;
    for(auto num : nums)
    {
        sum += num;
    }
    int half = sum / 2;
    vector<vector<int>> dp (n+1, vector<int>(half + 1));
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= half; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(nums[i-1] > j)
            {
                /* If current value is greater than total, don't pick it */
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                int pick = nums[i-1] + dp[i-1][j - nums[i-1]];
                int leave = dp[i-1][j];
                dp[i][j] = max(pick, leave);
            }
        }
    }
    int server_1 = dp[n][half];
    int server_2 = sum - server_1;
    cout << abs(server_1 - server_2);
    return 0;
}