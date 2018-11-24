// C++ program to print all elements that
// appear more than once.
#include <iostream>
using namespace std;

// function to find repeating elements
void printRepeating( int arr[], int n)
{
    // First check all the values that are
    // present in an array then go to that
    // values as indexes and increment by
    // the size of array
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n; // because arra[i] added multiple of n, so the reminder will be its' original value
        cout << "old arr["<<index<<"]-->"<<arr[index]<<endl;
        arr[index] += n; //the time it repeats, n will be added these times
        cout << "new arr["<<index<<"]-->"<<arr[index]<<endl;
    }
    //print out array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    // Now check which value exists more
    // than once by dividing with the size
    // of array
    for (int i = 0; i < n; i++)
    {
        if ((arr[i]/n) > 1) //because this index i was access twice, so we return i to say this value has repeated
            cout << i << " ";
    }
}

// Driver's code
int main()
{
    int arr[] = {1, 6, 3, 1, 3, 6, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    cout << "The repeating elements are: \n";
    printRepeating( arr, arr_size);
    return 0;
}
