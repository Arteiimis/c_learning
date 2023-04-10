#include <bits/stdc++.h>
#include <chrono>
using namespace std;

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;                         // 如果左右指针相遇，返回
    int mid = (left + right) / 2;       // 计算中间位置

    // ↓递归调用 mergeSort 对左右子数组"排序"↓
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    // ↓合并左右子数组部分↓
    vector<int> temp(right - left + 1); // 临时数组
    int i = left, j = mid + 1, k = 0;   // i、j、k 分别指向左、右、临时数组的下标
    while (i <= mid && j <= right)
    { // 左右子数组都有元素
        if (nums[i] <= nums[j])
        {                               // 如果左子数组的元素小于等于右子数组的元素
            temp[k++] = nums[i++];      // 将左子数组的元素放入临时数组中
        }
        else
        {                               // 如果左子数组的元素大于右子数组的元素
            temp[k++] = nums[j++];      // 将右子数组的元素放入临时数组中
        }
    }
    // ↓如果左子树有剩余元素, 则将左子数组中剩余的元素放入临时数组中↓
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    // ↓如果右子树有剩余元素, 则将右子数组中剩余的元素放入临时数组中↓
    while (j <= right)
    {
        temp[k++] = nums[j++];
    }
    // ↓将临时数组中的元素复制回原数组↓
    for (int p = 0; p < k; p++)
    {
        nums[left + p] = temp[p];
    }
}

void mergeSort(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    vector<int> nums(10000);
    for (unsigned long long i = 0; i < nums.size(); i++)
    {
        nums[i] = rng() % 10000;
    }

    auto start = chrono::steady_clock::now();
    mergeSort(nums);
    auto end = chrono::steady_clock::now();
    
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}