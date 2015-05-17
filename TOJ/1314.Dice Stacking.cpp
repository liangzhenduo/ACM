#include <iostream>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin >>n;
        int die[10001][6],top,bottom,index,sum,maximum=0;
        for(int i=0;i<n;i++)
            cin>>die[i][0]>>die[i][1]>>die[i][2]>>die[i][4]>>die[i][3]>>die[i][5];
        for(int i=0;i<6;i++){
            bottom=die[0][i],index=i,sum=0;
            for(int j=0;j<n;j++){
                top=die[j][5-index];
                if(bottom!=6&&top!=6)
                    sum+=6;
                else if(bottom+top==11)
                    sum+=4;
                else
                    sum+=5;
                for(int k=0;k<6;k++)
                    if(die[j+1][k]==top){
                        bottom=die[j+1][k];
                        index=k;
                        break;
                    }
            }
            if(sum>maximum)
                maximum=sum;
        }
        cout<<maximum<<endl;
    }
}
