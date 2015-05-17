#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >>n;
    const int m=n;
    int score[m];
    int k=1;
    for(int j=0;j<m;j++)
    {
        cin >>score[j];
        if(score[j]>score[0])
            k++;
    }
    cout <<k<<endl;
    return 0;
}

