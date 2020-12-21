#include <iostream>
#include <vector>

using namespace std;

void rotateArray(vector<int> *vect, int li, int ri)
{
    int temp = 0;

    while(li < ri)
    {
        temp = vect->at(li);
        vect->at(li) = vect->at(ri);
        vect->at(ri) = temp;
        ++li;
        --ri;
    }
}

int main()
{
    int rotationIndex = 0;
    int input = 0;
    vector<int> *arr = new vector<int>(10);

    cout << "Insert 10 integers to the vector :" << endl;
    for(int i=0; i<10; ++i)
    {
        cin >> input;
        arr->at(i) = input;
    }

    cout << "Vector before rotation:" << endl;
    for(int i=0; i<10; ++i)
    {
        cout << arr->at(i) << "  ";
    }

    cout << "\nEnter the rotation index: " << endl;
    cin >> rotationIndex;
    
    // initial entire array rotation
    rotateArray(arr, 0, 9);
    cout << "Array after initial rotation:" << endl;
    for(int i=0; i<10; ++i)
    {
        cout << arr->at(i) << "  ";
    }

    // rotate array upto rotation index
    rotateArray(arr, 0, rotationIndex-1);
    cout << "\nArray after first limited rotation:" << endl;
    for(int i=0; i<10; ++i)
    {
        cout << arr->at(i) << "  ";
    }

    // rotate array from rotation index to end
    rotateArray(arr, rotationIndex, 9);
    cout << "\nArray after second limited rotation that is final output:" << endl;
    for(int i=0; i<10; ++i)
    {
        cout << arr->at(i) << "  ";
    }

    cout << "\n\n";

    return 0;
}