#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void display(string arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nextPermutation(string arr[], int n)
{
    sort(arr, arr + n);
    do
    {
        display(arr, n);
    } while (next_permutation(arr, arr + n));
}

int main()
{
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    nextPermutation(arr, n);
    return 0;
}