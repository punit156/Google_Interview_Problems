/* 
Problem Statement :-

Given a hotel which has 10 floors [0-9], and each floor has 26 rooms
[A-Z]. '+' sign means room is booked and '-' sign means room is freed.
Find out which room is booked maximum number of times. If multiple
rooms are booked same number of times, return the lexicographically
smaller room number.

Given sequence will be valid. A room can only be freed after it has
been booked and initially all rooms are free.

Ex :- ["+1A", "+3E", "-1A", "+4F", "+1A", "-3E", "+3E"]

Here both 1A and 3E are booked same number of times (2), return 1A.

*/

/*
Tip :- We can ignore the freed rooms, i.e the elements starting with '-'
because ultimately we are counting the maximum room bookings, so only
'+' matters. 
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    vector<string> bookings = {"+1A", "-1A", "+4F", "+3E"};
    int n = bookings.size();
    unordered_map <string, int> hash;
    
    /* Calculate the frequency of all bookings first */

    for(auto book : bookings)
    {
        if(book[0] == '+')
        {
            string room = book.substr(1);  //We don't need the + sign.
            hash[room]++;
        }
    }

    string most_booked = "";
    int max_freq = 0;

    //Iterate over our hashmap to find out the most frequency room.

    for(auto it = hash.begin(); it != hash.end(); it++)
    {
        if(it->second > max_freq)
        {
            /* If current freq is greater than max_freq, update the
            most booked room and the max_freq*/
            
            most_booked = it->first;
            max_freq = it->second;
        }
        else if(it->second == max_freq)
        {
            /* If current freq is equal to max_freq, update most_booked
            only if it is lexicographically greater than current one. */
            
            if(it->first < most_booked)
            {
                most_booked = it->first;
            }

            /* No need to update the max_freq, as it is the same */

        }
    }
    cout << most_booked;
    return 0;
}