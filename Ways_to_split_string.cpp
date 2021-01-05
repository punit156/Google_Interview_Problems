/*
Problem Statement :-
Given a string S, we can Split S into 2 strings S1 and S2 such that,
S1 + S2 = S. Return the number of ways S can be split such that the 
number of unique characters between S1 and S2 are the same.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string S = "ababa";
    int n = S.size();
    vector<int> right (26,0);
    vector<int> left (26,0);
    int ans = 0;
    //Populating the right array with frequency of all chars from string
    for(char c : S)
    {
        right[c - 'a']++;
    }
    //Removing one from right and adding one to left and counting unique in both
    for(char c : S)
    {
        left[c - 'a']++;
        right[c - 'a']--;
        int left_unique = 0;
        int right_unique = 0;
        for(int i = 0; i < 26; i++)
        {
            if(left[i] > 0)
            {
                left_unique++;
            }
            if(right[i] > 0)
            {
                right_unique++;
            }
        }
        if(left_unique == right_unique)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}