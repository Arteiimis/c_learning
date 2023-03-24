#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int *data;
    int capacity;
    int cursize;
} seqlist;

void init_seqlist(seqlist *L, int capacity)
{
    L->data = (int *)malloc(sizeof(int) * capacity);
    L->capacity = capacity;
    L->cursize = 0;
}

void destory_seq_list(seqlist *L)
{
    free(L->data);
    L->capacity = 0;
    L->cursize = 0;
}

void clear_list(seqlist *L)
{
    L->cursize = 0;
}

int list_empty(seqlist *L)
{
    return L->cursize == 0;
}

int get_size(seqlist *L)
{
    return L->cursize;
}

int get_capacity(seqlist *L)
{
    return L->capacity;
}

bool is_empty(seqlist *L)
{
    return L->cursize == 0;
}

bool is_full(seqlist *L)
{
    return L->cursize == L->capacity;
}

void push_frount(seqlist *L, int value)
{
    if (is_full(L))
    {
        L->data = (int *)realloc(L->data, sizeof(int) * L->capacity * 2);
        L->capacity *= 2;
    }
    for (int i = L->cursize; i > 0; i--)
        L->data[i] = L->data[i - 1];
    L->data[0] = value;
    L->cursize++;
}

void print_list(seqlist *L)
{
    for (int i = 0; i < L->cursize; i++)
        printf("%d ", L->data[i]);
    printf("size = %d, capacity = %d", L->cursize, L->capacity);
}

void BubbleSort(seqlist *plist)
{
    int i, j;
    for (i = 0; i < plist->cursize - 1; i++)
    {
        for (j = 0; j < plist->cursize - 1 - i; j++)
        {
            if (plist->data[j] > plist->data[j + 1])
            {
                int temp = plist->data[j];
                plist->data[j] = plist->data[j + 1];
                plist->data[j + 1] = temp;
            }
        }
    }
}

int binsearch(seqlist *plist, int key)
{
    int low = 0;
    int high = plist->cursize - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (key < plist->data[mid])
            high = mid - 1;
        else if (key > plist->data[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

//递归实现二分查找
int binsearch2(seqlist *plist, int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (key < plist->data[mid])
        return binsearch2(plist, key, low, mid - 1);
    else if (key > plist->data[mid])
        return binsearch2(plist, key, mid + 1, high);
    else
        return mid;
}

void mergelist(const seqlist *plist1, const seqlist *plist2, seqlist *plist3)
{
    int i = 0, j = 0, k = 0;
    while (i < plist1->cursize && j < plist2->cursize)
    {
        if (plist1->data[i] < plist2->data[j])
            plist3->data[k++] = plist1->data[i++];
        else
            plist3->data[k++] = plist2->data[j++];
    }
    while (i < plist1->cursize)
        plist3->data[k++] = plist1->data[i++];
    while (j < plist2->cursize)
        plist3->data[k++] = plist2->data[j++];
    plist3->cursize = plist1->cursize + plist2->cursize;
}