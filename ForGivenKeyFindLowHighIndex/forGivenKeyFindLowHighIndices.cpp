#include <iostream>
#include <vector>

using namespace std;

int findLowForGivenKey(vector<int> & vect, int key)
{
    int low = 0;
    int high = vect.size() - 1;
    int mid = high / 2;

    while(low <= high)
    {
        if(vect.at(mid) < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
        mid = low + (high - low) / 2;
    }

    if(low < vect.size() && vect.at(low) == key)
    {
        return low;
    }

    return -1;
}

int findHighForGivenKey(vector<int> & vect, int key)
{
    int low = 0;
    int high = vect.size() - 1;
    int mid = high / 2;

    while(low <= high)
    {
        if(vect.at(mid) <= key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }

        mid = low + (high - low) / 2;
    }

    if(high == -1)
    {
        return high;
    }

    if(high < vect.size() && vect.at(high) == key)
    {
        return high;
    }

    return -1;
}

int main()
{
    int value, key, low=-1, high=-1;
    vector<int> vect;

    cout << "Enter 10 elements of a vector in sorted manner : " << endl;
    for(int i=0; i<10; ++i)
    {
        cin >> value;
        vect.push_back(value);
    }

    cout << "Enter key to find Low and High values : ";
    cin >> key;

    low = findLowForGivenKey(vect, key);
    high = findHighForGivenKey(vect, key);

    cout << "Given vector :" << endl;
    for(int i=0; i<10; ++i)
    {
        cout << vect.at(i) << "  ";
    }

    cout << "\nLow for the key is : " << low << endl;
    cout << "High for the key is : " << high << endl;
}