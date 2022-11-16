#include <bits/stdc++.h>
using namespace std;

struct HuffNode
{
    int weight;
    HuffNode *left, *right;

    HuffNode(int w, HuffNode *l = NULL, HuffNode *r = NULL)
        : weight(w), left(l), right(r) {}
    ~HuffNode(){};
};

HuffNode *creat_HuffTree(int a[], int size)
{
    HuffNode *root;
    deque<HuffNode *> forest;
    for (int i = 0; i < size; i++)
    {
        forest.push_back(new HuffNode(a[i]));
    }
    for (int i = 0; i < size - 1; i--)
    {
        sort(forest.begin(), forest.end(), [](HuffNode *a, HuffNode *b)
             { return a->weight < b->weight; });
        HuffNode *node = new HuffNode(forest[0]->weight + forest[1]->weight, forest[0], forest[1]);
        forest.push_back(node);
        forest.pop_front();
        forest.pop_front();
    }
    root = forest.front();
    forest.clear();

    return root;
}

void print(HuffNode *node)
{
    if (node != NULL)
    {
        cout << "当前节点：" << node->weight << ".";
        if (node->left != NULL)
            cout << "其左孩子节点为：" << node->left->weight << ".";
        else
            cout << "该节点无左孩子";
        if (node->right != NULL)
            cout << "其右孩子节点为：" << node->right->weight << ".";
        else
            cout << "该节点无右孩子";
        cout << endl;
        print(node->left);
        print(node->right);
    }
}

int main()
{
    int a[] = {10, 20, 30, 40};
    HuffNode *huff = creat_HuffTree(a, 4);
    print(huff);

    return 0;
}