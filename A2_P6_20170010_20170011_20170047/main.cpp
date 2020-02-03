#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string num_to_string(double x)
{
    stringstream y;
    y<<x;
    return y.str();
}
int binarySearch(vector<int>&arr, int left, int right, int value)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            binarySearch(arr, left, mid - 1, value);
        else
            binarySearch(arr, mid + 1, right, value);
    }
    else
    {
        if(arr[left]>value)
            return left;
        else
            return left+1;
    }
}

void insertionSortWithBinary(vector <int>&arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int pos=binarySearch(arr,0,i,arr[i]);
        int tmp=arr[i];
        int cont=i;
        while(cont>pos)
        {
            swap(arr[cont],arr[cont-1]);
            cont--;
        }
    }

}
void insertionSort(vector <int>&arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int tmp=arr[i];
        int cont=i;
        while(cont>0&&arr[cont-1]>tmp)
        {
            swap(arr[cont],arr[cont-1]);
            cont--;
        }
    }
}

int main()
{
    vector <int>arr;
    arr= {64,34,25,11,22,11,90};
    insertionSort(arr,7);
    for(int i=0; i<7; i++)
        cout<<arr[i]<<" ";
    cout<<endl<<endl;
    cout<<"Array      Binary      Normal"<<endl;
    vector<int>vec;
    string in="";
    ofstream file;
    file.open("ty.csv");

    for(int n=1000; n<=10000; n+=1000)
    {
        in+=num_to_string(n);
        in+=",";


        for(int i=0; i<n; i++)
        {
            vec.push_back(rand()%10000+1);
        }

        double t1 = clock();
        insertionSortWithBinary(vec,n);
        double t2 = clock();

        cout<<n<<"       "<<((double)(t2-t1))/CLOCKS_PER_SEC;
        in+=num_to_string(((double)(t2-t1))/CLOCKS_PER_SEC);
        in+=",";
        vec.resize(0);
        for(int i=0; i<n; i++)
        {
            vec.push_back(rand()%10000+1);
        }

        t1 = clock();
        insertionSort(vec,n);
        t2 = clock();

        cout<<"       "<<((double)(t2-t1))/CLOCKS_PER_SEC<<endl;
        in+=num_to_string(((double)(t2-t1))/CLOCKS_PER_SEC);
        in+=",";
        in+="\n";
        vec.resize(0);
    }


    file<<in;
    return 0;
}
