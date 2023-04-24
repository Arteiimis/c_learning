#include "date.h"
#include "user_date.h"
using namespace std;

int main()
{
    user_date u0(2020, 4, 1);
    user_date u1(2021, 3, 1);
    user_date u2(2021, 3, 1);
    user_date u3(2022, 3, 1);
    user_date u4(2022, 3, 6);

    cout << "u0 == u1: " << ((u0 == u1) ? "true" : "false") << endl;
    cout << "u1 == u2: " << ((u1 == u2) ? "true" : "false") << endl;
    cout << "u1 != u2: " << ((u1 != u2) ? "true" : "false")<< endl;
    cout << "u2 < u3:  " << ((u2 < u3) ? "true" : "false") << endl;
    cout << "u3 < u4:  " << ((u3 < u4) ? "true" : "false") << endl;
}