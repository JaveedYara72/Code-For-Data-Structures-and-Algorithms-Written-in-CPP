#include<bits/stdc++.h>
using namespace std;

int karatsuba(int x,int y)
{
    if(x <10 && y<10)
        return x*y;
    float n=max(to_string(x).length(),to_string(y).length());
    int m = ceil(n/2);
    int z=pow(10,m);
    int xh= floor(x/z);
    int xl= x%z;
    int yh= floor(y/z);
    int yl=y%z;
    int S1= karatsuba(xh,yh);
    int S2= karatsuba(xl ,yl);
    int S3= karatsuba(xh+xl,yh+yl);
    int S4= S3-S2-S1;
    return (S1*pow(10,2*m))+(S4*pow(10,m))+S2;
}

int main()
{
    int n,m;
    cout<<"Enter two numbers";
    cin>>n>>m;
    cout<<karatsuba(n,m);
}
