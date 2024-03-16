#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter elements:";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Entered elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // mean
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    cout << "Mean of all elements of array is: " << sum / size << endl;
    // median
    int start = 1;
    int end = size;
    int median1, median2;
    if (size % 2 == 0)
    {
        median1 = ((start + end) + 1) / 2;
        median2 = ((start + end) - 1) / 2;
        cout << "Medians are: " << median2 << " and " << median1;
    }
    else
    {
        median1 = (start + end) / 2;
        cout << "Median is: " << median1;
    }
    return 0;
}