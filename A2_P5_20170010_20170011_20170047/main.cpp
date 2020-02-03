#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1] ;
    int R[n2] ;
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void quickSort(vector<int> &arr, int left, int right)
{
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
// for(int i=0;i<5000;i++){cout<<vec[i]<<endl;}

string num_to_string(double x)
{
    stringstream y;
    y<<x;
    return y.str();
}
int main()
{
    cout<<"Array      Quick       Merge"<<endl;
    vector<int>vec;
    string in="";
    ofstream file;
        file.open("ty.csv");
    for(int n=5000; n<=100000; n+=5000)
    {
        in+=num_to_string(n);
        in+=",";


        for(int i=0; i<n; i++)
        {
            vec.push_back(rand()%10000+1);
        }

        double t1 = clock();
        quickSort(vec,0,n-1);
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
        mergeSort(vec,0,n-1);
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
