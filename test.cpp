#include <bits/stdc++.h>
#include "program_tester/tester.h"
using namespace std;

void mergeSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;                   // 如果左右指针相遇，返回
    int mid = (left + right) / 2; // 计算中间位置

    // ↓递归调用 mergeSort 对左右子数组"排序"↓
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    // ↓合并左右子数组部分↓
    vector<int> temp(right - left + 1); // 临时数组
    int i = left, j = mid + 1, k = 0;   // i、j、k 分别指向左、右、临时数组的下标
    while (i <= mid && j <= right)
    { // 左右子数组都有元素
        if (nums[i] <= nums[j])
        {                          // 如果左子数组的元素小于等于右子数组的元素
            temp[k++] = nums[i++]; // 将左子数组的元素放入临时数组中
        }
        else
        {                          // 如果左子数组的元素大于右子数组的元素
            temp[k++] = nums[j++]; // 将右子数组的元素放入临时数组中
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
    MONITOR_FUNCTION_BEGIN();

    mergeSort(nums, 0, nums.size() - 1);

    MONITOR_FUNCTION_END();
}

// 归并排序迭代实现
void mergeSort_ite(vector<int> &nums)
{
    int n = nums.size();
    // 子数组的大小从 1 开始，每次翻倍, 作为外层最大循环, 在这个大循环结束之后, 数组容量才会翻倍.
    for (int size = 1; size < n; size *= 2)
    {
        // left 表示左子数组的起始位置
        for (int left = 0; left < n - size; left += 2 * size)
        {
            int mid = left + size - 1;                   // 计算中间位置
            int right = min(left + 2 * size - 1, n - 1); // 计算右子数组的结束位置
            vector<int> temp(right - left + 1);          // 临时数组
            int i = left, j = mid + 1, k = 0;            // i、j、k 分别指向左、右、临时数组的下标
            while (i <= mid && j <= right)               // 左右子数组都有元素
            {
                if (nums[i] <= nums[j]) // 如果左子数组的元素小于等于右子数组的元素
                {
                    temp[k++] = nums[i++]; // 将左子数组的元素放入临时数组中
                }
                else // 如果左子数组的元素大于右子数组的元素
                {
                    temp[k++] = nums[j++]; // 将右子数组的元素放入临时数组中
                }
            }
            // 将左子数组中剩余的元素放入临时数组中
            while (i <= mid)
            {
                temp[k++] = nums[i++];
            }
            // 将右子数组中剩余的元素放入临时数组中
            while (j <= right)
            {
                temp[k++] = nums[j++];
            }
            // 将临时数组中的元素复制回原数组
            for (int p = 0; p < k; p++)
            {
                nums[left + p] = temp[p];
            }
        }
    }
}

void quickSort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;              // 如果左右指针相遇，返回
    int i = left, j = right; // i、j 分别指向左、右
    int pivot = nums[left];  // 基准值区序列左端函数

    while (i < j)
    {
        while (i < j && nums[j] >= pivot)
            j--;
        while (i < j && nums[i] <= pivot)
            i++;
        if (i < j)
            swap(nums[i], nums[j]);
    }

    nums[left] = nums[i];
    nums[i] = pivot;

    quickSort(nums, left, i - 1);
    quickSort(nums, i + 1, right);
}

int randomPartition(vector<int> &nums, int left, int right)
{
    srand(time(nullptr));
    int i = rand() % (right - left + 1) + left;
    swap(nums[i], nums[left]); // 将随机选取的元素交换到序列左端

    int pivot = nums[left]; // 基准值
    int j = left;           // j 指向小于基准值的子序列的最后一个元素

    // 将小于基准值的元素放到基准值的左边
    for (int k = left + 1; k <= right; k++) // 从基准值的下一个元素开始遍历
    {
        // 如果当前元素小于基准值
        if (nums[k] < pivot)
            swap(nums[++j], nums[k]); // 将当前元素交换到小于基准值的子序列的最后一个元素的后面
    }

    swap(nums[left], nums[j]); // 将基准值交换到小于基准值的子序列的最后一个元素的后面
    return j;                  // 返回基准值的位置
}

int midPartition(vector<int> &nums, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (nums[left] > nums[mid])
        swap(nums[left], nums[mid]);
    if (nums[left] > nums[right])
        swap(nums[left], nums[right]);
    if (nums[mid] > nums[right])
        swap(nums[mid], nums[right]);

    swap(nums[mid], nums[left]); // 将中间值交换到序列左端

    int pivot = nums[left]; // 基准值
    int j = left;           // j 指向小于基准值的子序列的最后一个元素

    // 将小于基准值的元素放到基准值的左边
    for (int k = left + 1; k <= right; k++) // 从基准值的下一个元素开始遍历
    {
        // 如果当前元素小于基准值
        if (nums[k] < pivot)
            swap(nums[++j], nums[k]); // 将当前元素交换到小于基准值的子序列的最后一个元素的后面
    }

    swap(nums[left], nums[j]); // 将基准值交换到小于基准值的子序列的最后一个元素的后面
    return j;                  // 返回基准值的位置
}

void quickSort_rand(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return; // 如果左右指针相遇，返回
    int pivot = randomPartition(nums, left, right);
    quickSort_rand(nums, left, pivot - 1);
    quickSort_rand(nums, pivot + 1, right);
}

void quickSort_mid(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return; // 如果左右指针相遇，返回
    int pivot = midPartition(nums, left, right);
    quickSort_mid(nums, left, pivot - 1);
    quickSort_mid(nums, pivot + 1, right);
}

void quickSort(vector<int> &nums)
{
    MONITOR_FUNCTION_BEGIN();

    quickSort_rand(nums, 0, nums.size() - 1);

    MONITOR_FUNCTION_END();
}

int main()
{
    vector<int> nums;
    Fill(nums, 10000, make_pair(0, 10000), "normal");

    quickSort(nums);

    if (isSorted(nums))
        cout << "Sorted!" << endl;
    else
        cout << "Not sorted!" << endl;

    return 0;
}