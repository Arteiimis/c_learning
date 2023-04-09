#include <bits/stdc++.h>
using namespace std;

struct priorityQueue
{
    int *base;
    int curSize;
    int maxSize;
};

priorityQueue *init(int size)
{
    assert(size > 0);
    priorityQueue *pq = (priorityQueue *)malloc(sizeof(priorityQueue));
    pq->base = (int *)malloc(size * sizeof(int));
    pq->curSize = 0;
    pq->maxSize = size;
    return pq;
}

void filterDown(int *heap, const int start, const int end)
{
    assert(heap != nullptr);
    int i = start, j = 2 * i + 1;
    int temp = heap[i];
    while (j < end)
    {
        if (j + 1 < end && heap[j] < heap[j + 1])
            j++;
        if (temp >= heap[j])
            break;
        heap[i] = heap[j];
        i = j;
        j = 2 * i + 1;
    }
    heap[i] = temp;
}

void filterUp(int *head, const int start)
{
    assert(head != nullptr);
    int i = start, j = (i - 1) / 2;
    int temp = head[i];
    while (j >= 0)
    {
        if (temp <= head[j])
            break;
        head[i] = head[j];
        i = j;
        j = (i - 1) / 2;
    }
}

void heapSort(int *a, const int n)
{
    assert(a != nullptr);
    for (int i = n / 2 - 1; i >= 0; i--)
        filterDown(a, i, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        filterDown(a, 0, i);
    }
}

void push(priorityQueue *pq, int val)
{
    assert(pq != nullptr);
    if (pq->curSize == pq->maxSize)
    {
        pq->base = (int *)realloc(pq->base, (pq->maxSize + 1) * sizeof(int));
        pq->maxSize++;
    }
    pq->base[pq->curSize] = val;
    pq->curSize++;
    filterUp(pq->base, pq->curSize - 1);
}

int pop(priorityQueue *pq)
{
    assert(pq != nullptr);

    int temp = pq->base[0];
    pq->base[0] = pq->base[pq->curSize - 1];
    pq->curSize--;
    filterDown(pq->base, 0, pq->curSize);

    return temp;
}

void printArr(int *a, const int n)
{
    assert(a != nullptr);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    priorityQueue *pq = init(10);
    //随即插入十个数据
    srand(time(0));
    for (int i = 0; i < 10; i++)
        push(pq, rand() % 100);
    printArr(pq->base, pq->curSize);
    int temp = pop(pq);
    cout << temp << endl;
    printArr(pq->base, pq->curSize);
}