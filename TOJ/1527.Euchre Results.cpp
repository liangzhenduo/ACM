#include <iostream>
using namespace std;
int main()
{
    int w1,w2,w3,w4,l1,l2,l3,l4;
    while(cin >>w1>>l1>>w2>>l2>>w3>>l3&&w1+w2+w3+l1+l2+l3!=0)
    {
        w4=(2*l1+l2+l3-w2-w3)/2;
        l4=(2*w1+w2+w3-l2-l3)/2;
        cout <<"Anna's won-loss record is "<<w4<<"-"<<l4<<"."<<endl;
    }
    return 0;
}

