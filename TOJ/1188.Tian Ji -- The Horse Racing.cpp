#include <stdio.h>
#include <algorithm>
#include <vector>
int main()
{
    int n,spe[1000],i,j,m;
    while(scanf("%d",&n)&&n)
    {
        for(i=m=0;i<n;i++)
            scanf("%d",&spe[i]);
        std::sort(spe,spe+n);
        std::vector<int> tia(spe,spe+n);
        for(i=0;i<n;i++)
            scanf("%d",&spe[i]);
        std::sort(spe,spe+n);
        std::vector<int> kin(spe,spe+n);
        while(kin.size())
        {
            if(tia.back()>kin.back())
                m+=200,tia.pop_back(),kin.pop_back();
            else if(tia.back()<kin.back())
                m-=200,tia.erase(tia.begin(),tia.begin()+1),kin.pop_back();
            else
            {
                if(tia.front()>kin.front())
                    m+=200,tia.erase(tia.begin(),tia.begin()+1),kin.erase(kin.begin(),kin.begin()+1);
                else if(tia.front()<kin.front())
                    m-=200,tia.erase(tia.begin(),tia.begin()+1),kin.pop_back();
                else if(tia.front()<kin.back())
                    m-=200,tia.erase(tia.begin(),tia.begin()+1),kin.pop_back();
                else
                    kin.clear();
            }
        }
        printf("%d\n",m);
    }
}
