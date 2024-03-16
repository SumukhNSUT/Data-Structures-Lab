#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements:\n";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Original array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Enter element to be deleted: ";
    int x;
    cin >> x;

    int temp = 0; // Variable to store the index of the element to be deleted

    for (int i = 0; i < size; i++)
    {
        if (x == arr[i])
        {
            temp = i;
            break;
        }
    }

    if (temp != 0)
    {
        // Shift the elements to remove the specified element
        for (int i = temp; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        // Decrease the size of the array as element is removed
        size--;

        cout << "Array after deletion: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Element not present in the original array\n";
    }

    return 0;
}
