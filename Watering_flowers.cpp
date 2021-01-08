/*
Problem Statement :-
Given an array of integers describing the water requirements of a single
plant, you and your friend start watering from either ends. Water each
plant in one go, i.e. without taking a break to refill the watering 
can in the middle of watering a single plant. This means you may have 
to refill your can before or after watering a plant.
If you and your friend meet in the middle, and collectively you have
enough water that meets the plant's requirement, you can water it. If 
not, one of you needs to refill.

At the beginning you both start with empty watering cans. How many
times will you and your friend need to refill your watering cans in 
order to water all plants in the row.

Both of the cans are large enough to fully water any single plant.

Ex :-
Input 
flowers = [2,4,5,1,2], capacity1 = 5, capacity2 = 7
Output = 3

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> flowers = {2,4,5,1,2};
    int cap1 = 5;
    int cap2 = 7;
    int i = 0;
    int j = flowers.size() - 1;
    int your_can = 0;
    int friends_can = 0;
    int refills = 0;
    while(i < j)
    {
        if(your_can < flowers[i])
        {
            your_can = cap1;
            refills++;
        }
        if(friends_can < flowers[j])
        {
            friends_can = cap2;
            refills++;
        }
        your_can -= flowers[i];
        friends_can -= flowers[j];
        i++;
        j--;
    }
    if(i == j && flowers[i] > your_can + friends_can)
    {
        cout << ++refills;
    }
    else
    {
        cout << refills;
    }
    return 0;
}