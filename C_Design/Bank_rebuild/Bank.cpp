#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class node
{
public:
    node();
    node *next;
    node *prev;
};

class Account: public node
{
public:
    Account();
    string cardname[20];
    string cardnumber[20];
    string name[20];
    string password[20];
    double balance;
    int state;
};

class Bank
{
public:
    Bank();

}

void Accoun