#include "books.h"
#include<bits/stdc++.h>
using namespace std;
books::books(){}
books::books(string x,string y ,int a,int b)
{
    Bookn=x;
    Author=y;
    year=a;
    nVersions=b;
}
istream& operator >> (istream& in, books & b)//operator cin the number
{
    cout<<"Enter book name: ";
    in>>b.Bookn;
    cout<<"Enter Author name: ";
    in>>b.Author;
    cout<<"Enter Year: ";
    in>>b.year;
    cout<<"Enter number of versions: ";
    cin>>b.nVersions;
    return in;
}
ostream& operator << (ostream& out, books & b)//operator cin the number
{
    out<<"book name: "<<b.Bookn<<endl;
    out<<"Author name: "<<b.Author<<endl;
    out<<"Year: "<<b.year<<endl;
    out<<"number of versions: "<<b.nVersions<<endl;
    return out;
}
books books:: addbook()
{
    books b;
    cin>>b;
    return b;
}
void books:: searchByname(vector <books>b)
{
    cout<<"Enter book name: ";
    string n;
    cin>>n;
    for(unsigned int i=0; i<b.size(); i++)
    {
        if(n==b[i].Bookn)
        {
            cout<<"ur book is"<<endl;
            cout<<b[i];
            break;
        }
    }

}
void books:: searchByAuthor(vector <books>b)
{
    cout<<"Enter Author name: ";
    string n;
    cin>>n;
    for(unsigned int i=0; i<b.size(); i++)
    {
        if(n==b[i].Author)
        {
            cout<<"ur book is"<<endl;
            cout<<b[i];
            break;
        }
    }

}
void books:: list_(vector <books>b){
    vector<string>v;
    for(unsigned int i=0;i<b.size();i++){
        v.push_back(b[i].Bookn);
    }
    sort(v.begin(),v.end());
    cout<<"after sorting: "<<endl;
    for(unsigned int i=0;i<v.size();i++){
        for(unsigned int j=0;j<b.size();j++){
            if(v[i]==b[j].Bookn)
                cout<<b[j];
        }
    }



}

void books:: update_vesion(vector <books>b)
{
    cout<<"Enter Book name: ";
    string n;
    cin>>n;
    for(unsigned int i=0; i<b.size(); i++)
    {
        if(n==b[i].Bookn)
        {
            cout<<"enter the new number: ";
            cin>>b[i].nVersions;
            cout<<b[i];
            break;
        }
    }

}
void books:: find_(vector <books>b)
{
    vector <int>x;
    for (unsigned int i=0; i<b.size(); i++)
        x.push_back(b[i].nVersions);
    int maxx= *max_element(x.begin(), x.end());
    for (unsigned int i=0; i<b.size(); i++)
    {
        if(maxx==b[i].nVersions)
        {
            cout<<"ur book is"<<endl;
            cout<<b[i];
            break;
        }
    }

}

