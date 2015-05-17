#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char num[101][101]={"0"},result[103]={"0"};
    int l,k=0,length=0,i,j,o=0;
    for(i=0;i<101;i++)
    {
        cin >>num[i];
        if(strlen(num[i])>length)
            length=strlen(num[i]);
        if(num[i][0]==48&&strlen(num[i])==1)
        {
            l=i;
            break;
        }
    }
    for(i=0;i<length;i++)
    {
        for(j=0;j<l;j++)
            if(strlen(num[j])>i)
                k+=num[j][strlen(num[j])-i-1]-48;
        result[i]=k%10+48;
        if(i==length-1)
        {
            result[i+1]=(k/10)%10+48;
            result[i+2]=k/100+48;
        }
        k/=10;
    }
    for(i=strlen(result)-1;i>=0;i--)
    {
        if(result[i]!=48)
            o=1;
        if(o==1)
            cout <<result[i];
    }
    if(!(num[0][0]==48&&strlen(num[0])==1))
        cout <<endl;
    return 0;
}

