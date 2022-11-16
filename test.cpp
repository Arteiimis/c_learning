#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
/*���������Ľڵ㶨��*/
template <typename T>
struct HuffmanNode
{
    HuffmanNode(T k, HuffmanNode<T> *l = nullptr, HuffmanNode<T> *r = nullptr)
        : key(k), lchild(l), rchild(r) {}
    ~HuffmanNode();

    T key;                  //�ڵ��ֵ
    HuffmanNode<T> *lchild; //�ڵ���
    HuffmanNode<T> *rchild; //�ڵ��Һ�
};
template <typename T>
class Huffman
{
public:
    Huffman();
    ~Huffman();

    void preOrder();  //ǰ�������������
    void inOrder();   //���������������
    void postOrder(); //���������������

    void creat(T a[], int size); //������������
    void destory();              //���ٹ�������
    void print();                //��ӡ��������

private:
    void preOrder(HuffmanNode<T> *pnode);
    void inOrder(HuffmanNode<T> *pnode);
    void postOrder(HuffmanNode<T> *pnode);
    void print(HuffmanNode<T> *pnode);
    void destroy(HuffmanNode<T> *pnode);

private:
    HuffmanNode<T> *root;
    deque<HuffmanNode<T> *> forest; //ɭ��
};

/*Ĭ�Ϲ��캯��*/
template <typename T>
Huffman<T>::Huffman() : root(nullptr){};

/*��������*/
template <typename T>
Huffman<T>::~Huffman()
{
    destroy(root);
};

/*������������*/
template <typename T>
void Huffman<T>::creat(T a[], int size)
{
    for (int i = 0; i < size; i++) //ÿ���ڵ㶼��Ϊһ��ɭ��
    {
        HuffmanNode<T> *ptr = new HuffmanNode<T>(a[i], nullptr, nullptr);
        forest.push_back(ptr);
    }
    for (int i = 0; i < size - 1; i++)
    {
        sort(forest.begin(), forest.end(), [](HuffmanNode<T> *a, HuffmanNode<T> *b)
             { return a->key < b->key; });
        HuffmanNode<T> *node = new HuffmanNode<T>(forest[0]->key + forest[1]->key, forest[0], forest[1]);
        forest.push_back(node);
        forest.pop_front();
        forest.pop_front();
    }
    root = forest.front();
    forest.clear();
};

/*ǰ�������������*/
template <typename T>
void Huffman<T>::preOrder(HuffmanNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        cout << pnode->key;
        preOrder(pnode->lchild);
        preOrder(pnode->rchild);
    }
};
template <typename T>
void Huffman<T>::preOrder()
{
    preOrder(root);
};
/*���������������*/
template <typename T>
void Huffman<T>::inOrder(HuffmanNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        inOrder(pnode->lchild);
        cout << pnode->key;
        inOrder(pnode->rchild);
    }
};
template <typename T>
void Huffman<T>::inOrder()
{
    inOrder(root);
};
/*���������������*/
template <typename T>
void Huffman<T>::postOrder(HuffmanNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        postOrder(pnode->lchild);
        postOrder(pnode->rchild);
        cout << pnode->key;
    }
};
template <typename T>
void Huffman<T>::postOrder()
{
    postOrder(root);
};
/*��ӡ��������*/
template <typename T>
void Huffman<T>::print(HuffmanNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        cout << "��ǰ��㣺" << pnode->key << ".";
        if (pnode->lchild != nullptr)
            cout << "�������ӽڵ�Ϊ��" << pnode->lchild->key << ".";
        else
            cout << "��û������.";
        if (pnode->rchild != nullptr)
            cout << "�����Һ��ӽڵ�Ϊ��" << pnode->rchild->key << ".";
        else
            cout << "��û���Һ���.";
        cout << endl;
        print(pnode->lchild);
        print(pnode->rchild);
    }
};
template <typename T>
void Huffman<T>::print()
{
    print(root);
};
/*���ٹ�������*/
template <typename T>
void Huffman<T>::destory()
{
    destroy(root);
};
template <typename T>
void Huffman<T>::destroy(HuffmanNode<T> *pnode)
{
    if (pnode != nullptr)
    {
        destroy(pnode->lchild);
        destroy(pnode->rchild);
        delete pnode;
        pnode = nullptr;
    }
};

int main()
{
    Huffman<int> huff;
    int a[] = {10, 20, 30, 40};
    huff.creat(a, 4); //构建一棵哈夫曼树
    huff.print();     //打印节点间关系
    getchar();
    return 0;
}
