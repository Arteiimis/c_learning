#include <bits/stdc++.h>
using namespace std;

void insertSort(int *arr, int len)
{
    assert(arr != nullptr);
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int findval(int *arr, int left, int right, int val)
{
    assert(arr != nullptr);
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == val)
        {
            while (mid > 0 && arr[mid - 1] == val)
                mid--;
            return mid;
        }
        else if (arr[mid] > val)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

void binInsertSort(int *arr, int len)
{
    assert(arr != nullptr);
    bool allsame = true;
    for (int i = 1; i < len; i++)
        if (arr[i] != arr[i - 1])
        {
            allsame = false;
            break;
        }
    if (allsame)
        return;
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int pos = findval(arr, 0, i - 1, temp);
        for (int j = i; j > pos; j--)
            arr[j] = arr[j - 1];
        arr[pos] = temp;
    }
}


void quickRecursion(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;

    while (lef)
}

void quickSort(int *arr, int len)
{
    assert(arr != nullptr);
    quickRecursion(arr, 0, len - 1);
}

void printArr(int *arr, int len)
{
    assert(arr != nullptr);
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10];
    srand(time(nullptr));
    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 100;
    printArr(arr, 10);
    binInsertSort(arr, 10);
    printArr(arr, 10);
}