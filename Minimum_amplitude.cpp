/* 
Problem Statement :-
Given an array nums, find the minimum amplitude you can get
after changing up to 3 elements. Amplitude is the range of the array
(basically difference between largest and smallest element)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {10, 10, 3, 4, 10};
    int n = nums.size();
    if(n <= 4)
    {
        return 0;
    }
    sort(nums.begin(), nums.end());
    
    /* After sorting you can only change three numbers from the subset
    {first three, last three} (6 numbers) */

    int ans = nums[n-1] - nums[0];
    int i = 0;
    int j = n-4;
    for(; j < n; i++, j++)
    {
        ans = min(ans, nums[j] - nums[i]);
    }
    cout << ans << endl;
    return 0;
}