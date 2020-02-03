#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string,int>m;
    int num=0;
    string word="";
    for(int i=0; true; i++)
    {
        cout<<"Enter word and number: ";
        cin>>word;
        if(word=="done")break;
        cin>>num;
        m.insert(pair<string,int>(word,num));
    }
    cout<<endl;
    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<"         ";
        cout<<it->second<<endl;
    }


    cout<<"*****************************************************\nAfter deletion\n\n";


    map<string,int>::iterator it2=m.begin();
    while (it2!=m.end())
    {
        if(it2->first[0]=='a')
        {
            m.erase(it2);
            it2=m.begin();
        }

        else it2++;
    }



    for(map<string,int>::iterator it=m.begin(); it!=m.end(); it++)
    {
        cout<<it->first<<"         ";
        cout<<it->second<<endl;
    }

    return 0;
}
