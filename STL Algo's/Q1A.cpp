#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][n],b[n][n];
    cout<<"Enter elements of first matrix"<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    cout<<"Enter elements of second matrix"<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    }
    int res[n][n]={{0}};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                res[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
    }
    cout<<"\n";

}
