/*
Problem Statement :-
We have a list of points on a plane. Find the K closest points to the 
origin (0,0).

Ex :-
Input = [[1,3], [-2,2]], K = 1

Output = [[-2,2]]

*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> points = {{1,3}, {-2,2}, {0,0}};
    int K = 2;
    vector<vector<int>> ans;
    
    // Min Queue
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i = 0; i < points.size(); i++)
    {
        int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        pq.push({dist,i});
    }

    while(K > 0)
    {
        auto temp = pq.top();
        pq.pop();
        ans.push_back(points[temp.second]);
        K--;
    }

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "," << ans[i][1] << endl;
    }
    return 0;
}