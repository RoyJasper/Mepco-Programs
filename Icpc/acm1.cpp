#include<iostream>
using namespace std;
main()
{
    int n,m;
    cin>>n>>m;
    int i,j,k=0,a[n][m],b[m],c=0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>a[i][j];
    for(i=0; i<m; i++)
        cin>>b[i];
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            a[i][j]=(a[i][j]+i)%m;
            if((a[i][j]==0||a[i][j]==2)&&c==0)
            {
                k++;
                c=1;
            }
        }
        c=0;
    }
    cout<<k;
}
