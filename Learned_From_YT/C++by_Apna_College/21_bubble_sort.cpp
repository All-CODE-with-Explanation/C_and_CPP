// Bubble Sorting Array - the greatest element is shifted to the extreme  right side.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the size of Array : ";
    int size;
    cin >> size;

    int arr[size];
    cout << "Enter the Elements of Array : ";

    // Taking Array as Input
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Bubble Sorting
    int counter = 1;
    while (counter < size)
    {
        for (int i = 0; i < size-counter; i++)
        {
            if (arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }

    // Print the Array 
    for (int i=0; i<size; i++)
    {
        cout<< arr[i] << " ";
    }
}