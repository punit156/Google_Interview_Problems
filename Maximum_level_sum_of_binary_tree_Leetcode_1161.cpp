/*
Problem Statement :-
Given root of a binary tree, root's level is 1, and so on. Find the 
smallest level x, such that sum of nodes at that level is maximum.

Leetcode 1161.
*/
#include <iostream>
#include <bits/stdc++.h>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }
};

int main()
{
    TreeNode* root;
    int maxi = INT_MIN;
    int ans = 1;
    int h = 1;
    int cur = 0;
    queue <TreeNode*> Q;
    Q.push(root);
    Q.push(NULL);
    while(!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        if(temp == NULL)
        {
            if(cur > maxi)
            {
                maxi = cur;
                ans = h;
            }
            if(Q.empty())
            {
                cout << ans;
                return 0;
            }
            h++;
            cur = 0;
            Q.push(NULL);
            continue;
        }
        cur += temp->val;
        if(temp->right)
        {
            Q.push(temp->right);
        }
        if(temp->left)
        {
            Q.push(temp->left);
        }
    }
    cout << ans;
    return 0;
}