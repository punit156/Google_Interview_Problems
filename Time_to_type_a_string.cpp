/*
Problem Statement :-
You have a special keyboard with all letters in a single row, whose
arrangement will be given by the string keyboard of length 26. Initially
your finger is at index 0. The time taken to move your finger from 
index i to index j is abs(i-j).

Given a string text, return the time taken to type string text.

Eg:-
Input - 
Keyboard = "abcdefghijklmnopqrstuvwxyz"
text = "cba"

Output = 4

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string keyboard = "abcdefghijklmnopqrstuvwxyz";
    string text = "zazaza";
    unordered_map<char, int> hash;
    for(int i = 0; i < 26; i++)
    {
        hash[keyboard[i]] = i;
    }
    int prev = 0;
    int ans = 0;
    for(auto c : text)
    {
        ans += abs(hash[c] - prev);
        prev = hash[c];
    }
    cout << ans;
    return 0;
}