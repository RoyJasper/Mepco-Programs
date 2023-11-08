#include<iostream>
using namespace std;
main()
{
    int n,m;
    cin>>n>>m;
    int i,j,k=0,a[n][m],b[m],c[n];
    for(i=0; i<n; i++)
        c[i]=-1;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];
    for(i=0; i<m; i++)
        cin>>b[i];
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        {
            a[i][j]=(a[i][j]+i)%m;
            if(a[i][j]==0||a[i][j]==2)
            {
                c[k]=i;
                k++;
            }
        }
    //for(i=0; i<k; i++)
        cout<<k-1;
}
