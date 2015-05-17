#include <iostream>
using namespace std;
int main()
{
    int d;
    cin >>d;
    for (int i=0;i<d;i++)
    {
        int x,y;
        int n=0;
        cin >>x;
        while(x>0)
        {
            y=x%2;
            if (y==1&&x!=1)
                cout <<n<<" ";
            else if (y==1&&x==1)
                cout <<n<<endl;
            n++;
            x=x/2;
        }
    }
    return 0;
}
