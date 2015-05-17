#include <iostream>
using namespace std;
int main()
{
    int m,element;
    while(cin >>m>>element)
    {
        int x=1+(element-1)/m,y=element%m;
        for(int i=0;;i++)
        {
            if(x+i==m||y+i==m)
            {
                cout <<element+i*(m+1)<<endl;
                break;
            }
            else
                cout <<element+i*(m+1)<<" ";
        }
    }
    return 0;
}

