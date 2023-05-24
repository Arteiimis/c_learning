#include <bits/stdc++.h>
using namespace std;

class myString
{
private:
    struct strNode          // 字符串节点
    {
        int ref;            // 引用计数, 4 bytes
        int capacity;       // 容量, 4 bytes
        int len;            // 长度, 4 bytes
        char data[0];       // 数据, 0 bytes
    };

    strNode* pstr;          // 指向字符串节点的指针
    strNode* getNode(int total) const  // 申请节点
    {
        strNode* s = (strNode*) malloc(sizeof(strNode) + sizeof(char) * total); // 申请节点
        if (s == nullptr) { throw bad_alloc(); }                                // 申请失败
        return s;
    }

public:
    myString(const char* p = nullptr) : pstr(nullptr)
    {
        if (p != nullptr)
        {
            int len = strlen(p);
            int total = len * 2;
            pstr = getNode(total);
            pstr->ref = 1;
            pstr->len = len;
            pstr->capacity = total - 1;
            strcpy(pstr->data, p);
        }
    }

    myString(const myString& s) : pstr(s.pstr)
    {
        if (pstr != nullptr) { ++pstr->ref; }
    }

    myString operator=(const myString& s)
    {
        if (pstr == s.pstr) { return *this; }
        if (pstr != nullptr && --pstr->ref == 0) { free(pstr); }
        pstr = s.pstr;
        if (pstr != nullptr) { ++pstr->ref; }
        return *this;
    }

    myString operator+(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return myString(); }
        int total = pstr->len + s.pstr->len;
        strNode* s1 = getNode(total);
        s1->ref = 1;
        s1->len = total;
        s1->capacity = total - 1;
        strcpy(s1->data, pstr->data);
        strcat(s1->data, s.pstr->data);

        return myString((const myString&) s1);
    }

    myString operator+=(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return *this; }
        int total = pstr->len + s.pstr->len;
        strNode* s1 = getNode(total);
        s1->ref = 1;
        s1->len = total;
        s1->capacity = total - 1;
        strcpy(s1->data, pstr->data);
        strcat(s1->data, s.pstr->data);

        if (pstr != nullptr && --pstr->ref == 0) { free(pstr); }
        pstr = s1;
        return *this;
    }

    constexpr bool operator==(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return false; }
        return strcmp(pstr->data, s.pstr->data) == 0;
    }

    constexpr bool operator!=(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return true; }
        return strcmp(pstr->data, s.pstr->data) != 0;
    }

    constexpr bool operator<(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return false; }
        return strcmp(pstr->data, s.pstr->data) < 0;
    }

    constexpr bool operator>(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return false; }
        return strcmp(pstr->data, s.pstr->data) > 0;
    }

    constexpr bool operator<=(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return false; }
        return strcmp(pstr->data, s.pstr->data) <= 0;
    }

    constexpr bool operator>=(const myString& s)
    {
        if (pstr == nullptr || s.pstr == nullptr) { return false; }
        return strcmp(pstr->data, s.pstr->data) >= 0;
    }

    friend ostream& operator<<(ostream& os, const myString& s)
    {
        if (s.pstr != nullptr) { os << s.pstr->data; }
        return os;
    }

    ~myString()
    {
        if (pstr != nullptr && --pstr->ref == 0) { free(pstr); }
        pstr = nullptr;
    }
};

int main()
{
    myString s1("hello");
    myString s2("world");
    myString s3 = s1 + " " + s2;
    cout << s3 << endl;
    bool sign = s1 < s2;
    cout << sign << endl;

    return 0;
}