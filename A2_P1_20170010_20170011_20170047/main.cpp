#include <iostream>
#include "books.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    books bb;
    vector <books>b;
    int choice =0;
    b.push_back(bb.addbook());
    while(true)
    {
        cout<<"1-Add book\n2-Search book by name\n3-Search book by author\n4-List books in alphabetical order\n5-update available number of versions of a book\n6-Find the books which have the highest number of versions\n7-Exit\nEnter ur Choice: ";
        cin>> choice;
        switch (choice)
        {
        case 1:
            b.push_back(bb.addbook());
            break;

            case 2:
                bb.searchByname(b);
                break;
            case 3:
                bb.searchByAuthor(b);
                break;
            case 4:
                bb.list_(b);
                break;
            case 5:
                bb.update_vesion(b);
                break;
            case 6:

                bb.find_(b);
                break;
            case 7:
                exit(0);
            default :
                cout<<"Error!"<<endl;
                break;
        }
    }
    return 0;
}
