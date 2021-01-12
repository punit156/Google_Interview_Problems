/*
Problem Statement :-
N guests are invited to a party. ith guest arrives at time S[i] and
leaves at E[i]. Given int arrays S and E, both of size n, return an 
integer denoting the minimum number of chairs you need such that 
everyone attending the party can sit down.

Eg :-
Input -
S = [1,2,6,5,3], E = [5,5,7,6,8]

Output - 
3

*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// Efficient approach --> O(n)
int main()
{
    vector<int> S = {1,2,2,6,5,3};
    vector<int> E = {5,5,4,7,6,8};
    int n = S.size();
    int ans = 0;

    map<int,int> hash;
    for(int i = 0; i < n; i++)
    {
        hash[S[i]]++;
        hash[E[i]]--;
    }

    int cur = 0;
    for(auto it : hash)
    {
        cur += it.second;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}
 /* O(nlogn) approach

bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
    // If times are same, prioritize -1 
}

int main()
{
    vector<int> S = {1,2,2,6,5,3};
    vector<int> E = {5,5,3,7,6,8};
    int n = S.size();
    int ans = 0;
    
    // First we make pairs of start/end times and 1/-1. 1 indicating
    // arrival and -1 indicating departure. 

    vector<pair<int,int>> times;
    for(int i = 0; i < n; i++)
    {
        times.push_back({S[i], 1});
        times.push_back({E[i], -1});
    }

    // Now we sort the pair array in ascending order based on time,
    // and if two times are same, we consider -1 before than 1, because,
    // if a person leaves at time 5, and another arrives at time 5, only
    // one chair will be occupied at time 5. 

    sort(times.begin(), times.end(), compare);
    int cur = 0;
    for(auto time : times)
    {
        cur += time.second;
        if(cur > ans)
        {
            ans = cur;
        }
    }

    cout << ans;
    return 0;
} */