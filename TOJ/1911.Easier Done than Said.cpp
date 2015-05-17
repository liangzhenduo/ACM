#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int asc[26]={0};
    asc[0]=1,asc[4]=1,asc[8]=1,asc[14]=1,asc[20]=1;
    char password[21];
    while(cin >>password&&!(password[0]=='e'&&password[1]=='n'&&password[2]=='d'&&strlen(password)==3))
    {
        int k=1,vowel=0;
        for(int i=0;i<strlen(password);i++)
        {
            if(asc[password[i]-97]==1)
                vowel++;
            if((password[i]==password[i+1]&&password[i]!='e'&&password[i]!='o')||(asc[password[i]-97]==0&&asc[password[i+1]-97]==0&&asc[password[i+2]-97]==0||asc[password[i]-97]==1&&asc[password[i+1]-97]==1&&asc[password[i+2]-97]==1))
            {
                k--;
                break;
            }
        }
        if(k&&vowel)
            cout <<"<"<<password<<"> is acceptable."<<endl;
        else
            cout <<"<"<<password<<"> is not acceptable."<<endl;
    }
    return 0;
}

