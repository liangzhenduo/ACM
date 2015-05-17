#include <iostream>
using namespace std;
int main()
{
    int k,lotto[13];
    cin >>k;
    while(k)
    {
        for(int h=0;h<k;h++)
            cin >>lotto[h];
        for(int i=0;i<k-5;i++)
            for(int j=i+1;j<k-4;j++)
                for(int l=j+1;l<k-3;l++)
                    for(int m=l+1;m<k-2;m++)
                        for(int n=m+1;n<k-1;n++)
                            for(int o=n+1;o<k;o++)
                                cout <<lotto[i]<<" "<<lotto[j]<<" "<<lotto[l]<<" "<<lotto[m]<<" "<<lotto[n]<<" "<<lotto[o]<<endl;
        cin >>k;
        if(k)
            cout <<endl;
    }
    return 0;
}
