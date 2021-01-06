/*
Problem Statement :-
Array X is greater than array Y, if the first non-matching element in 
both arrays has a greater value in X than in Y.
For eg :- 
X = [1,2,4,3,5]
Y = [1,2,3,4,5]

Here X > Y, because X[2] > Y[2] (First non-matching element).

Write a function that, given an array A of N integers and an integer
K, returns the largest contiguous subarray of length K from all the 
contiguous subarrays of length K.

For eg:-
Given A = [1,4,3,2,5], and K = 4, the function should return [4,3,2,5]

My approach might not be optimal, because the primary goal was
correctness and not optimality.

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int K = 0;

void answer(int start_index, int end_index, vector<int> A)
{
    vector<int> ans(K);
    auto start = A.begin() + start_index;
    auto end = A.begin() + end_index;
    copy(start, end, ans.begin());
    
    /* After this statement our 'ans' vector contains the subarray
    starting from start_index and ending at end_index (size K). */

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> A = {6,5,4,6,6,6,7,4,3};
    int k = 3;
    int n = A.size();
    map<int,vector<int>> orig;
    K = k;
// Finding the largest element in the array
// I stopped at n-k+1, because beyond that our subarray would exceed K
    for(int i = 0; i < n- k + 1; i++)
    {
        orig[A[i]].push_back(i);
    }
    auto it = orig.rbegin();
    int ret = it->second[0];
    if(it->second.size() == 1)
    {
        /* If there is only one largest element (no duplicates),
        that's our answer.*/

        /* ret is the starting index, and (ret + k) is ending index
        as we have k elements */

        answer(ret, ret+k, A);
        return 0;
    }
    int i = 1;
// Finding the second largest, third largest, and so on.
    while(i < k)
    {
        map<int, vector<int>> hash;
        /* it->second contains all the array indices that have same 
        value. */

        /* Since we had multiple values in it->second, now we need to
        check the next element(elem + 1) in all k-sized subarrays and repeat the process,
        till we find a unique value. */
    
        for(auto elem : it->second)
        {
            hash[A[elem+1]].push_back(elem+1);
        }

        orig = hash;
        it = orig.rbegin(); //rbegin will give the largest element in map
        if(it->second.size() == 1)
        {
            /* whenever we find solution, we have to subtract (i) from
            current index to find the starting point of subarray. */

            answer(it->second[0] - i, it->second[0] - i + k, A);
            return 0;
        }
        i++;
    }
    if(i == k)
    {
        answer(ret, ret + k, A);
    }
}