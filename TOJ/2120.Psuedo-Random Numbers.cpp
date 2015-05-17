#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int z,i,m,l,t=0;
    while(cin >>z>>i>>m>>l&&z)
    {
        cout <<"Case "<<++t<<": ";
        int a[10001]={0},b[10001]={0},k=1;
        a[l]=1;
        b[k++]=l;
		l=(z*l+i)%m;
        while(!a[l])
        {
           	a[l]=1;
            b[k++]=l;
			l=(z*l+i)%m;
        }
        for(int j=0;j<k;j++)
           	if(b[j]==l)
        	{
				cout <<k-j<<endl;
				break;
			}
    }
    return 0;
}
