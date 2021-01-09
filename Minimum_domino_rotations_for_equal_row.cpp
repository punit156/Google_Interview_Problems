/*
Problem Statement :-
In a row of dominoes, A[i] and B[i] represent the top and bottom halves
of the ith domino. (A domino is a tile with two numbers from 1-6 - one
on each half of the tile).
We may rotate the ith domino, so that A[i] and B[i] swap values.
Return the minimum number of rotations so that all values in A are
the same, or all values in B are the same.

It it cannot be done, return -1.

Ex:-
Input - 
A = {2,1,2,4,2,2}, B = {5,2,6,2,3,2}

Output = 2.

We just need to flip index 1 and 3 to make all elements same in A.

*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A = {2,1,2,4,2,2};
    vector<int> B = {5,3,6,2,3,2};

    /* The logic here is that, we will make 6 iterations (1-6) across all
    elements of both arrays. During let's say 1st iteration, we will try
    to see if we can find 1's at all indexes, it can be in either A or B,
    or both. Even if for a single index we can't find a 1, it means,
    we have to skip that entire iteration, and move on to 2's.

    Goal here is that in order to make all elements of either A or B same,
    there has to be one number present across all indexes either in A or
    in B. Even if a single index is missed, then we move on to next number.
    */

    int n = A.size();
    int ans = INT_MAX;

    for(int i = 1; i <= 6; i++)
    {
        bool found = true;
        int a = 0;
        int b = 0;
        for(int j = 0; j < n; j++)
        {
            if(A[j] == i && B[j] == i)
            {
                continue;
            }
            else if(A[j] == i)
            {
                a++;
            }
            else if(B[j] == i)
            {
                b++;
            }
            else
            {
                found = false;
                break;
            }
        }
        if(found)
        {
            ans = min(ans, min(a,b));
        }
    }
    if(ans != INT_MAX)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
    return 0;
}