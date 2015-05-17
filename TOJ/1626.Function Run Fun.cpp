#include <iostream>
using namespace std;
int r[100][100][100];

    int w(int a,int b,int c)
    {
        if(a<=0||b<=0||c<=0)
            return 1;
        if(r[a][b][c])
            return r[a][b][c];
        else if(a>20||b>20||c>20)
            return r[a][b][c]=w(20,20,20);
        else if(a<b&&b<c)
            return r[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        else
            return r[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        return r[a][b][c];
    }

int main()
{
    int a,b,c;
    while(cin >>a>>b>>c&&a*b*c!=-1)
        cout <<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
    return 0;
}
