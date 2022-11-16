#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    char data;
    int weight;
    int parent, lchild, rchild;
}HuffmanNode, *HuffmanTree;

typedef struct
{
    char code[100];
    int start;
}HuffCode;

typedef char **HuffmanCode;