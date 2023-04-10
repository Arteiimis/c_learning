#include <bits/stdc++.h>
using namespace std;

void find2min(int *arr,int len, int *n, int *m)
{
    int i;
    *n = *m = INT_MAX;
    for (i = 0; i < len; i++)
    {
        if (arr[i] < *n)
        {
            *m = *n;
            *n = arr[i];
        }
        else if (arr[i] < *m)
            *m = arr[i];
    }
}

vector<int> _find2min(int *arr, int len)
{
    int i;
    int n = INT_MAX, m = INT_MAX;
    for (i = 0; i < len; i++)
    {
        if (arr[i] < n)
        {
            m = n;
            n = arr[i];
        }
        else if (arr[i] < m)
            m = arr[i];
    }
    return {n, m};
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selecSort(int *arr, int len)
{
    int i, j, min;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
            swap(arr[i], arr[min]);
    }
}

int main()
{
    int arr[] = {10, 5, 2, 3, 4, 6, 7, 8, 9, 1};
    int n, m;
    n = _find2min(arr, 10)[0];
    m = _find2min(arr, 10)[1];
    cout << n << " " << m << endl;
    selecSort(arr, 10);
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
}