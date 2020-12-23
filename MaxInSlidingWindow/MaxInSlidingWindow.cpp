#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <time.h>

using namespace std;

void printMaxInSlidingWindow(vector<int> &vect, int windowSize)
{
    int max=vect.at(0);
    deque<int> window;

    cout << "Max in sliding window is:" << endl;
    for(auto i=0; i<vect.size(); ++i)
    {
        while(!window.empty() && vect.at(i)>=vect.at(window.back()))
        {
            window.pop_back();
        }

        if(!window.empty() && window.front()<=i-windowSize)
        {
            window.pop_front();
        }

        window.push_back(i);
        cout << vect.at(window.front()) << "  ";
    }
}

int main()
{
    const auto low = -100;
    const auto high = 100;
    vector<int> vect;

    // seeding for random
    srand(time(0));
    const auto range = (high - low);

    // populate vector with random numbers within range
    for(auto i=0; i<20; ++i)
    {
        vect.push_back((rand() % (range + 1)) + low);
    }

    // print initial vector
    cout << "Initial vector:" << endl;
    for(auto i : vect)
    {
        cout << i << "  ";
    }
    cout << endl;

    int windowSize = 0;
    cout << "Please enter sliding window size (less than 10): ";
    cin >> windowSize;
    cout << endl;

    printMaxInSlidingWindow(vect, windowSize);

    return 0;
}