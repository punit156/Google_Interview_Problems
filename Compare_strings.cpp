/*
Problem Statement :-
One string is strictly smaller than another when the frequency of 
occurrence of the smallest character in the string is less than the 
frequency of occurrence of smallest character in the comparison string.
For eg :-
String "abcd" is smaller than "aaa", because (a->1) < (a->3).
String "bbccd" is smaller than "zzz" because (b->2) < (z->3).

Given two strings A - "abcd,aabd,bcdf" and B - "bbb, cc", return an
array of integers C, such that C[j] shows how many strings in A, are
strictly smaller than B[j].
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
    string A = "abcd,aabc,bd";
    string B = "aaa,aa";
    vector<int> A_arr;
    vector<int> ans;
    int i = 0;
    int n = A.size();
    int m = B.size();
    while(i < n)
    {
        map<char,int> hash;
        while(i < n && A[i] != ',')
        {
            hash[A[i]]++;
            i++;
        }
        i++;
        auto it = hash.begin();
        A_arr.push_back(it->second);

        /* A_arr will only store the frequencies of smallest characters
        of each string in A */
    }
    int j = 0;
    sort(A_arr.begin(), A_arr.end());
    n = A_arr.size();
    /*  Repeat the process for B, and start populating ans array 
        after comparing with A_arr values */
    while(j < m)
    {
        map<char, int> hash;
        while(j < m && B[j] != ',')
        {
            hash[B[j]]++;
            j++;
        }
        j++;
        auto it = hash.begin();
        int k = 0;
        while(k < n && A_arr[k] < it->second)
        {
            k++;
        }
        ans.push_back(k);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}