#include <mutex>
#include <iostream>
#include <thread>
#include <condition_variable>
#include <set>
#include <unordered_set>
using namespace std;

std::mutex mx;
std::condition_variable cv;

class Count
{
public:
    Count(int m) : money(m) { }
    ~Count() = default;
    bool operator<(const Count& src)const { return money < src.money; }
    int getMoney() { return money; }
    void setMoney(int m) { money = m; }
private:
    int money;
};

class Account
{
private:
    Account() = default;
    Account(const Account& src) = delete;
    Account& operator=(const Account& src) = delete;
    set<Count> s;

public:
    ~Account() = default;
    static Account* getInstance()
    {
        static Account a;
        return &a;
    }

    void apply(Count& A, Count& B)
    {
        unique_lock<mutex> lc(mx); //申请账户 先上锁
        while (s.count(A) > 0 || s.count(B) > 0)
        { cv.wait(lc); }//阻塞等待 

        s.insert(A);
        s.insert(B);
    }

    void free(Count& A, Count& B)
    {
        unique_lock<mutex> lc(mx);
        s.erase(A);
        s.erase(B);
        cv.notify_all();
    }


};

void thread_func1(Count& A, Count& B, int money) //A---> B转账money元
{
    Account* acc = Account::getInstance();
    acc->apply(A, B);

    if (A.getMoney() >= money)
    {
        A.setMoney(A.getMoney() - money);
        B.setMoney(B.getMoney() + money);
        cout << "successful:" << endl;
        cout << money << endl;
    }
    else
    { cout << "余额不足" << endl; }
    acc->free(A, B);
}

int main()
{
    Count A(1000);
    Count B(1000);
    thread s1(thread_func1, ref(A), ref(B), 300); //A----->B 300   // 700   1300
    thread s2(thread_func1, ref(B), ref(A), 100); //B----->A 100   // 800 	1200
    s1.join();
    s2.join();
    cout << A.getMoney() << endl;
    cout << B.getMoney() << endl;
    system("pause");
    return 0;
}