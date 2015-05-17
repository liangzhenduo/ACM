#include <iostream>
using namespace std;

    void triangle()
    {
        int h;
        cin >>h;
        int n=h;
        for(int i=0;i<h;i++)
        {
            for(int j=0;j<n-1;j++)
                cout <<" ";
            for(int k=0;k<2*i+1;k++)
                cout <<"*";
            cout <<'\n';
            n--;
        }
        cout <<endl;
    }

    void parallelogram()
    {
         int w,h;
         cin >>w>>h;
         int n=h;
         for(int i=0;i<h;i++)
         {
            for(int j=0;j<n-1;j++)
                cout <<" ";
            for(int i=0;i<w;i++)
                cout <<"*";
            cout <<'\n';
            n--;
         }
         cout <<endl;
    }

    void rectangle()
    {
         int w,h;
         cin >>w>>h;
         for(int i=0;i<h;i++)
         {
            for(int i=0;i<w;i++)
                    cout <<"*";
            cout <<'\n';
         }
         cout <<endl;
    }

int main()
{
    int c;
    while(cin >>c)
    {
        if(c==1)
            triangle();
        else if(c==2)
            parallelogram();
        else if(c==3)
            rectangle();
        else if(c==-1)break;
    }
    return 0;
}
