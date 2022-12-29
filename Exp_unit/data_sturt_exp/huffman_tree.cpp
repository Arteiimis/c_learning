#include <bits/stdc++.h>
using namespace std;

template <typename eletype>
struct HuffNode
{
    eletype weight; //权值域
    HuffNode<eletype> *left, *right;

    HuffNode(eletype w, HuffNode<eletype> *l = NULL, HuffNode<eletype> *r = NULL)
        : weight(w), left(l), right(r) {}
    ~HuffNode() {}
};

template <typename eletype>
class HuffmanTree
{
private:
    HuffNode<eletype> *root;
    deque<HuffNode<eletype> *> forest;

private:
    void preOrder(HuffNode<eletype> *t);
    void inOrder(HuffNode<eletype> *t);
    void postOrder(HuffNode<eletype> *t);
    void printer(HuffNode<eletype> *t);

public:
    void creat(eletype w[], int size);
    void printer()
    {
        printer(root);
    }
    void destroy()
    {
        destory(root);
    }
    void preOrder()
    {
        preOrder(root);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void postOrder()
    {
        postOrder(root);
    }

    void preOrder();
    void inOrder();
    void postOrder();

    HuffmanTree();
    ~HuffmanTree();
};

template <typename eletype>
void HuffmanTree<eletype>::creat(eletype a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        forest.push_back(new HuffNode<eletype>(a[i]));
    }
    for (int i = 0; i < size - 1; i++)
    {
        sort(forest.begin(), forest.end(), [](HuffNode<eletype> *a, HuffNode<eletype> *b)
             { return a->weight < b->weight; });
        // HuffNode<eletype> *node = new HuffNode<eletype>(forest[0]->weight + forest[1]->weight, forest[0], forest[1]);
        forest.push_back(new HuffNode<eletype>(forest[0]->weight + forest[1]->weight, forest[0], forest[1]));
        forest.pop_front();
        forest.pop_front();
    }
    root = forest.front();
    forest.clear();
}

template <typename eletype>
void HuffmanTree<eletype>::printer(HuffNode<eletype> *node)
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
        printer(node->left);
        printer(node->right);
    }
}

int main()
{
    HuffmanTree<int> huff;
    int a[] = {10, 20, 30, 40};
    huff.creat(a, 4);
    huff.printer();

    return 0;
}