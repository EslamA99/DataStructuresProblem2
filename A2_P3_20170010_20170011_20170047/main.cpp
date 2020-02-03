#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class searcher
{
public:
    int numofcom = 0;

    searcher() {};

    void Load_data(vector<string>& v1,string filename)
    {
        fstream myfile(filename,ios::in|ios::out);
        string str;
        while(myfile >> str)
        {
            if(str.length() > 0)
            {
                v1.push_back(str);
            }
        }
        myfile.close();

    }

    int binarySearch(vector<string>& v, string x,int&n)
    {
        sort(v.begin(),v.end());
        int first = 0;
        int last  = v.size()-1;

        while (first <= last)
        {
            int mid = first + (last - first) / 2;

            if (x == (v[mid]))
            {
                numofcom++;
                n = numofcom;

                return mid;
            }

            if (x > v[mid])
            {
                numofcom++;
                n = numofcom;
                first = mid + 1;
            }

            else
            {
                numofcom++;
                n = numofcom;
                last = mid - 1;
            }
        }
        return -1;
    }

    double testPerformance_time(vector<string>& v, string x,int c)
    {
        int y =0;
        double t1 = clock();
        if(c==1)
            cout <<"index: "<<binarySearch(v,x,y) << endl;
        else
            binarySearch(v,x,y);
        double t2 = clock();
        double time = ((double)(t2-t1))/CLOCKS_PER_SEC;
        return time;
    }

    int testPerformance_numofcom(vector<string>& v, string x)
    {
        int c = 0;
        numofcom = 0;
         binarySearch(v,x,c);
        return c;

    }

};
string num_to_string(double x)
{
    stringstream y;
    y<<x;
    return y.str();
}
int main()
{
    srand(time(0));
    searcher o;
    double time=0,num=0;

    vector <string> v;
    vector <string> v2 = {"aaaaaAA","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    string filename;
    string x = "c";
    cout << "Enter file name: ";

    cin  >> filename;

    o.Load_data(v,filename);

    int s = rand() % v.size();
    int choice =0;



    ofstream file;
    file.open("ty.csv");
    string in[99999];
    while(true)
    {
    cout << "1- first case word is found (random word).\n";
    cout << "2- Do this 100 times and calculate the average time and average number of comparison.\n";
    cout << "3- second case word is not found (random word).\n";
    cout << "4- Do this 100 times and calculate the average time and average number of comparison.\n";
    cout << "5- Exit.\n";
        cout << "Enter your choice: ";

        cin  >> choice;
        if (choice == 1)
        {
            cout<<"the word is: "<<v[s]<<endl;
            cout << "Time: "<< o.testPerformance_time(v, v[s],1) << endl;
            cout << "Number of comparisons: "<<o.testPerformance_numofcom(v,v[s]) << endl;
        }

        if (choice == 2)
        {
            int cont =0;

            for (int i =0; i <100; i++)
            {
                int s = rand() % v.size();
                in[cont]=num_to_string(o.testPerformance_time(v,v[s],0));
                in[cont]+=",";
                in[cont+2]=",\n";
                cont+=3;
                cout<<"the word is: "<<v[s]<<"   ";
                time += o.testPerformance_time(v,v[s],1);
                num  += o.testPerformance_numofcom(v,v[s]);

            }

            cout << "Average number of time: " << (time/100) << endl;
            cout << "Average number of comparison: " << (num/100) << endl;

        }

        if (choice == 3)
        {
            int s = rand() % v2.size();
            cout<<"the word is: "<<v2[s]<<endl;
            cout << "Time: "<< o.testPerformance_time(v, v2[s],1) << endl;
            cout << "Number of comparisons: "<<o.testPerformance_numofcom(v,v2[s]) << endl;
        }

        if (choice == 4)
        {
            int cont=1;
            for (int i =0; i <100; i++)
            {
                int s = rand() % v2.size();
                in[cont]=num_to_string(o.testPerformance_time(v,v2[s],0));
                cont+=3;
                cout<<"the word is: "<<v2[s]<<"    ";
                time += o.testPerformance_time(v,v2[s],1);
                num  += o.testPerformance_numofcom(v,v2[s]);

            }
            string comp="";
            for(int i=0; i<(sizeof in/sizeof in[0]); i++)
                comp+=in[i];

            file<<comp;

            cout << "Average number of time: " << (time/100) << endl;
            cout << "Average number of comparison: " << (num/100) << endl;
        }
        if(choice==5){
                file.close();
            exit(0);}

    }
}
