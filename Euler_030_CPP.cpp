// Euler_030_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 5 * pow(9, 5); //5 digit number limit max 9^5 each
    int grandTotal = 0; //total of all valid numbers (final answer)
    //cout << n;
    for (int i = 2; i < n; i++) //checks all numbers after 1, before limit
    {
        int temp = i;
        vector<int> vect;
        while (temp != 0) //separates ints into digits
        {
            vect.push_back(temp % 10); 
            temp /= 10;
        }
        //reverse(vect.begin(),vect.end()); //puts digits in right order, but unncessary here
        int total = 0; //total of powers of digits of singular number
        for (int j = 0; j < vect.size(); j++) //add each digit^5
        {
            total = total + pow(vect[j], 5); 
        }
        if (total == i) //for adding all viable numbers
        {
            cout << i << endl;
            grandTotal += i;
        }
    }
    cout << "The sum of all viable numbers is: " << grandTotal << endl;
}
