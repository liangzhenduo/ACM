#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m,n,i,j,k=0;
    cin >>m>>n;
    int a[4001],b[160001];
    for(int i=0;i<m;i++)
        cin >>a[i];
    sort(a,a+m-1);
    for(int j=0;j<n;j++)
        cin >>b[j];
    sort(b,b+n-1);
    i=0,j=0;
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
            i++;
        else if(a[i]>b[j])
            j++;
        else
        {
            k++;
            i++;
            j++;
        }
    }
    cout <<k<<endl;
    return 0;
}
