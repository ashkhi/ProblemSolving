#include <iostream>
#include <vector>

#include <bits/stdc++.h> 

#include <stdlib.h>
#include <time.h>

using namespace std;

void sortGivenVector(vector<int>& vect)
{
    sort(vect.begin(), vect.end());
}

void findSmallestCommonFromGivenVectors(vector<int>& vect1, vector<int>& vect2, vector<int>& vect3)
{
    int smallest = -111;
    vector<int>::iterator itr1 = vect1.begin();
    vector<int>::iterator itr2 = vect2.begin();
    vector<int>::iterator itr3 = vect3.begin();

    while(itr1 != vect1.end() && itr2 != vect2.end() && itr3 != vect3.end())
    {
        if (*itr1 == *itr2 && *itr2 == *itr3)
        {
            smallest = *itr1;
            break;
        }

        if(*itr1 <= *itr2 && *itr1 <= *itr3)
        {
            ++itr1;
        }
        else if(*itr2 <= *itr3 && *itr2 <= *itr1)
        {
            ++itr2;
        }
        else if(*itr3 <= *itr1 && *itr3 <= *itr2)
        {
            ++itr3;
        }
    }

    if(smallest == -111)
    {
        cout << "there is no common element in given vectors" << endl;
    }
    else
    {
        cout << "The smallest common element of given vectors is : " << smallest << endl;
    }    
}

int main()
{
    const auto low=0;
    const auto high=10;
    // set the seed for random
    srand(time(0));

    const auto range = high - low;

    int lengthFirstVect=0;
    cout << "Enter length of first vector: ";
    cin >> lengthFirstVect;
    vector<int> vect1;

    // populate first vector with random numbers in range
    for (auto i=0; i<lengthFirstVect; ++i)
    {
        vect1.push_back((rand() % (range + 1)) + low);
    }

    cout << "Original first Vector:" << endl;
    for (auto x:vect1)
    {
        cout << x << "  ";
    }
    cout << endl;

    int lengthSecondVect=0;
    cout << "Enter length of second vector: ";
    cin >> lengthSecondVect;
    vector<int> vect2;

    // populate first vector with random numbers in range
    for (auto i=0; i<lengthSecondVect; ++i)
    {
        vect2.push_back((rand() % (range + 1)) + low);
    }

    cout << "Original second Vector:" << endl;
    for (auto x:vect2)
    {
        cout << x << "  ";
    }
    cout << endl;

    int lengthThirdVect=0;
    cout << "Enter length of third vector: ";
    cin >> lengthThirdVect;
    vector<int> vect3;

    // populate first vector with random numbers in range
    for (auto i=0; i<lengthThirdVect; ++i)
    {
        vect3.push_back((rand() % (range + 1)) + low);
    }

    cout << "Original third Vector:" << endl;
    for (auto x:vect3)
    {
        cout << x << "  ";
    }
    cout << endl;

    sortGivenVector(vect1);
    sortGivenVector(vect2);
    sortGivenVector(vect3);

    findSmallestCommonFromGivenVectors(vect1, vect2, vect3);

    return 0;
}