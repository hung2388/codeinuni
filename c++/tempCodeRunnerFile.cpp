#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> A;
    for(int i=0;i<10;i++)
    {
        int c;
        cin>>c;
        A.push_back(c);
    }
    sort(A.begin(),A.end());
    for(int i:A)
    {
        cout<<i<<" ";
    }
}