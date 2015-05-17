#include <stdio.h>
#include <set>
int main()
{
    int n,t;
    char d;
    while(scanf("%d",&n)&&n)
    {
        std::multiset<int>score;
        while(n--)
        {
            getchar();
            scanf("%c",&d);
            if(d=='B')
            {
                scanf("%d",&t);
                score.insert(t);
            }
            else
            {
                printf("%d\n",*score.begin());
                score.erase(score.begin());
            }
        }
    }
}
