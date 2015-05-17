#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin >>n)
    {
        const int m=n;
        int xmin[m],xmax[m],ymin[m],ymax[m],k=0;
        for(int i=0;i<n;i++)
            cin>>xmin[i]>>xmax[i]>>ymin[i]>>ymax[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(j!=i&&xmax[j]>=xmax[i]&&xmin[j]<=xmin[i]&&ymax[j]>=ymax[i]&&ymin[j]<=ymin[i])
                {
                    k++;
                    break;
                }
        cout <<k<<endl;
    }
    return 0;
}
