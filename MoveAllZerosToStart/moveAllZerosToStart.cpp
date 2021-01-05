#include <iostream>
#include <vector>

using namespace std;

void moveAllZerosToStart(vector<int> & vect)
{
    int read = vect.size() - 1;
    int write = vect.size() - 1;

    while(read >= 0)
    {
        if(vect.at(read) == 0)
        {
            --read;
        }
        else
        {
            vect.at(write) = vect.at(read);
            --read;
            --write;
        }
    }

    while(write >=0)
    {
        vect.at(write) = 0;
        --write;
    }
}

int main()
{
    int value;
    vector<int> vect;

    cout << "Enter 10 values for input vector :";
    for(int i=0; i<10; ++i)
    {
        cin >> value;
        vect.push_back(value);
    }

    cout << "Initial vector :" << endl;
    for(int i=0; i<vect.size(); ++i)
    {
        cout << vect.at(i) << "  ";
    }

    cout << "\nVector after moving all zeros to start :" << endl;
    moveAllZerosToStart(vect);
    for(int i=0; i<vect.size(); ++i)
    {
        cout << vect.at(i) << "  ";
    }
    cout << endl;
}