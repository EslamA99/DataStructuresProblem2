#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class books
{
    public:
        books();

        books(string ,string ,int,int);
        books addbook();
        void searchByname(vector <books>b);
        void searchByAuthor(vector <books>b);
        void list_(vector <books>b);
        void update_vesion(vector <books>b);
        void find_(vector <books>b);
        friend istream &operator>>(istream &in,books &b);
        friend ostream &operator<<(ostream &in,books &b);
    protected:
    private:
        string Bookn;
        string Author;
        int year;
        int nVersions;
};

#endif // BOOKS_H
