#include <iostream>
using namespace std;
int main()
{
    int t,n,num;
    cin >>t;
    while(t--)
    {
        cin >>n>>num;
        int k=0;
        for(int i=2;(i+1)*i/2<=num;i++)
            if((num-(i+1)*i/2)%i==0)
                k++;
        cout <<n<<" "<<k<<endl;
    }
    return 0;
}
