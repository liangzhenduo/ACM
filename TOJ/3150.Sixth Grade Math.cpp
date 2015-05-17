#include <iostream>
using namespace std;
int main()
{
    int n,a,b;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >>a>>b;
        if(a>b)
        {
            int c=a;
            a=b;
            b=c;
        }
        int lcm,gcf;
        for(int j=b;;j++)
            if(j%a==0&&j%b==0)
            {
                lcm=j;
                break;
            }
        for(int j=a;;j--)
            if(a%j==0&&b%j==0)
            {
                gcf=j;
                break;
            }
        cout <<i+1<<" "<<lcm<<" "<<gcf<<endl;
    }
    return 0;
}

