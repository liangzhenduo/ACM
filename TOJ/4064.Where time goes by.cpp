#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int T,n,s,t;
    cin >>T;
    while(T--)
    {
        cin >>n>>s>>t;
        cin.get();
        int i,j,l,w[1001]={0},v[1001]={0},f[100001]={0};
        for(i=0;i<n;i++)
        {
            char algorithm[256];
            cin.getline(algorithm,256);
            for(j=strlen(algorithm)-1,l=0;algorithm[j]-32;j--,l++)
                w[i]+=(algorithm[j]-48)*pow(10,l);
            for(j--,l=0;algorithm[j]-32;j--,l++)
                v[i]+=(algorithm[j]-48)*pow(10,l);
        }
        for(i=0;i<n;i++)
            for(j=t;j>=w[i];j--)
                if(f[j]<f[j-w[i]]+v[i])
                    f[j]=f[j-w[i]]+v[i];
        cout <<(f[t]<s?"Where time goes by! ":"Final, I'm coming! ")<<f[t]<<endl;
    }
    return 0;
}
