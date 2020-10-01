#include<iostream>
using namespace std;
int** submatri(int** A,int** B,int n)
{
    int** C= new int*[n];
    for(int i=0 ; i<n ; i++)
      C[i]=new int[n];
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
    return C;
}
int** addmatri(int** A,int** B,int n)
{
    int** C= new int*[n];
    for(int i=0 ; i<n ; i++)
      C[i]=new int[n];
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
    return C;
}
 void splitmatri(int** x, int** y, int iB, int jB,int clen)
    {
        for(int i1 = 0, i2 = iB; i1 < clen; i1++, i2++)
            for(int j1 = 0, j2 = jB; j1 < clen; j1++, j2++)
                y[i1][j1] = x[i2][j2];
    }
 void join(int** y, int** x, int iB, int jB,int clen)
    {
        for(int i1 = 0, i2 = iB; i1 < clen; i1++, i2++)
            for(int j1 = 0, j2 = jB; j1 < clen; j1++, j2++)
                x[i2][j2] = y[i1][j1];
    }
int** multiply(int** A,int** B,int n)
{
    int** R= new int*[n];
    for(int i=0 ; i<n ; i++)
      R[i]=new int[n];
    if(n==1)
     R[0][0]=A[0][0]*B[0][0];
    else
    {
    int** A11= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      A11[i]=new int[n/2];
    int** A12= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      A12[i]=new int[n/2];
    int** A21= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      A21[i]=new int[n/2];
    int** A22= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      A22[i]=new int[n/2];
    int** B11= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      B11[i]=new int[n/2];
    int** B12= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      B12[i]=new int[n/2];
    int** B21= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      B21[i]=new int[n/2];
    int** B22= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      B22[i]=new int[n/2];
    splitmatri(A,A11,0,0,n/2);
    splitmatri(A,A12,0,n/2,n/2);
    splitmatri(A,A21,n/2,0,n/2);
    splitmatri(A,A22,n/2,n/2,n/2);
    splitmatri(B,B11,0,0,n/2);
    splitmatri(B,B12,0,n/2,n/2);
    splitmatri(B,B21,n/2,0,n/2);
    splitmatri(B,B22,n/2,n/2,n/2);
    int** M1= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M1[i]=new int[n/2];
    int** M2= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M2[i]=new int[n/2];
    int** M3= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M3[i]=new int[n/2];
    int** M4= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M4[i]=new int[n/2];
    int** M5= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M5[i]=new int[n/2];
    int** M6= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M6[i]=new int[n/2];
    int** M7= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      M7[i]=new int[n/2];

     M1= multiply(addmatri(A11, A22,n/2), addmatri(B11, B22,n/2),n/2);
     M2= multiply(addmatri(A21, A22,n/2), B11,n/2);
     M3= multiply(A11, submatri(B12, B22,n/2),n/2);
     M4= multiply(A22, submatri(B21, B11,n/2),n/2);
     M5= multiply(addmatri(A11, A12,n/2), B22,n/2);
     M6= multiply(submatri(A21, A11,n/2), addmatri(B11, B12,n/2),n/2);
     M7= multiply(submatri(A12, A22,n/2), addmatri(B21, B22,n/2),n/2);

     int** C11= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      C11[i]=new int[n/2];
    int** C12= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      C12[i]=new int[n/2];
    int** C21= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      C21[i]=new int[n/2];
    int** C22= new int*[n/2];
    for(int i=0 ; i<n/2 ; i++)
      C22[i]=new int[n/2];

    C11 = addmatri(submatri(addmatri(M1, M4,n/2), M5,n/2), M7,n/2);
    C12 = addmatri(M3, M5,n/2);
    C21 = addmatri(M2, M4,n/2);
    C22 = addmatri(submatri(addmatri(M1, M3,n/2), M2,n/2), M6,n/2);

    join(C11, R, 0 , 0,n/2);
    join(C12, R, 0 , n/2,n/2);
    join(C21, R, n/2, 0,n/2);
    join(C22, R, n/2, n/2,n/2);

    }
    return R;



}
int main()
{
    cout<<"Enter order of matrix: (2^n type)\n";
    int n; cin>>n;
    int** A= new int*[n];
    for(int i=0 ; i<n ; i++)
      A[i]=new int[n];
    int** B= new int*[n];
    for(int i=0 ; i<n ; i++)
      B[i]=new int[n];
    cout<<"Enter  elements of matrix A: \n";
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin>>A[i][j];
    cout<<"Enter  elements of  matrix B: \n";
    for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin>>B[i][j];
     int** C= new int*[n];
    for(int i=0 ; i<n ; i++)
      C[i]=new int[n];
     C= multiply(A,B,n);
    cout<<"Product of matrices:\n";
     for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout<<C[i][j]<<" ";
            cout<<"\n";
        }

}
