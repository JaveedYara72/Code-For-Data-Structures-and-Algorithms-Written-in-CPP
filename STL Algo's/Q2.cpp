#include<bits/stdc++.h>
using namespace std;

int maxsumbetween(int a[],int l,int m,int h)
{
    int lsum=INT_MIN,sum=0;
    for(int i=l;i<=m;i++)
    {
        sum=sum+a[i];
        lsum=max(lsum,sum);
    }
    int rsum=INT_MIN;
    sum=0;
    for(int i=m+1;i<=h;i++)
    {
        sum=sum+a[i];
        rsum=max(rsum,sum);
    }
    return max(lsum,max(rsum,lsum+rsum));

}
int maxsum(int a[],int l,int h)
{
    if(l==h)return a[l];
    int m=(l+h)/2;
    return (max(maxsum(a,l,m),max(maxsum(a,m+1,h),maxsumbetween(a,l,m,h))));
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<maxsum(a,0,n-1);
}
