#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool non_degenerate_triangle(vector<int> v)
{
    int SIZE = v.size();

    if (SIZE < 3)
        return false;

    sort(v.begin(),v.end());

    for(int i = 0; i < SIZE - 2; i++)
    {

        if (v[i] + v[i+1] > v[i+2])
        {
            cout << "YES" << endl;
            cout << "Sides of possible non degenerate triangle are: ";
            cout << v[i] << " " << v[i+1] <<" "<< v[i+2] << endl;
            return true;
        }

    }
    cout << "NO possible sides!" <<endl;
    return false;
}

int main()
{
    vector <int> v1 = {5, 4, 3, 1, 2};
    non_degenerate_triangle(v1);
    cout << endl;
    vector <int> v2 = {4,1,2};
    non_degenerate_triangle(v2);
    cout << endl;
    vector <int> v3 = {5, 4, 9, 3, 1};
    non_degenerate_triangle(v3);
    return 0;
}
