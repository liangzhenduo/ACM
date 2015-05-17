#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n&&n)
    {
        const int m=n;
        int permutation[m],inverse[m];
        for(int i=0;i<n;i++)
        {
            cin >>permutation[i];
            inverse[permutation[i]-1]=i+1;
        }
        int k=1;
        for(int i=0;i<n;i++)
            if(permutation[i]!=inverse[i])
            {
                k--;
                break;
            }
        if(k)
            cout <<"ambiguous"<<endl;
        else
            cout <<"not ambiguous"<<endl;
    }
    return 0;
}
