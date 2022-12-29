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
    void creat(eletype w[]);
    void printer();
    void destroy();

    void preOrder();
    void inOrder();
    void postOrder();

    HuffmanTree();
    ~HuffmanTree();
};

template<typename eletype>
void HuffmanTree<eletype>::creat(eletype a[])
{
    int size = sizeof(*a) / sizeof(a[0]);
    for (int i = 0; i < size; i++)
    {
        forest.push_back(new HuffNode<eletype>(a[i]));
    }
    for (int i = 0; i < size - 1;i++)
    {
        sott(forest.begin(), forest.end(), [](HuffNode<eletype> *a, HuffNode<eletype> *b) { return a->weight < b->weight; });
        HuffNode<eletype> *node = new HuffNode<eletype>(forest[0]->weight + forest[1]->weight, forest[0], forest[1]);
        forest.push_back(node);
        forest.pop_front();
        forest.pop_front();
    }
    root = forest.front();
    forest.clear();
}

int main()
{
}