#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
using namespace std;
struct Drop{
    int x,y,sz,ct;
}drop[101];
struct SmallDrop{
    int x,y,dir,dis;
}tmp;
int grid[101][101],gridw[101][101];
list<SmallDrop> sd;
int main(){
    int r,c,n,t,i,j,k,x,y;
    list<SmallDrop>::iterator it;
    while(scanf("%d%d%d%d",&r,&c,&n,&t)!=EOF){
        memset(grid,0,sizeof(grid));
        memset(gridw,0,sizeof(gridw));
        memset(drop,0,sizeof(drop));
        sd.clear();
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&drop[i].x,&drop[i].y,&drop[i].sz);
            drop[i].ct=-1;
            gridw[drop[i].x][drop[i].y]=drop[i].sz;
        }
        scanf("%d%d",&x,&y);
        drop[0].x=x,drop[0].y=y;
        drop[0].sz=5,drop[0].ct=-1;
        for(j=0;j<=t;j++){
            for(it=sd.begin();it!=sd.end();it++){
                if((*it).dis==1) continue;
                if((*it).dir==0){//up
                    grid[(*it).x][(*it).y]--;
                    if((*it).x-1<1)
                        (*it).dis=1;
                    else{
                        grid[--(*it).x][(*it).y]++;
                        if(gridw[(*it).x][(*it).y]>0)
                            gridw[(*it).x][(*it).y]++,(*it).dis=1;
                    }
                }
                else if((*it).dir==1){//right
                    grid[(*it).x][(*it).y]--;
                    if((*it).y+1>c)
                        (*it).dis=1;
                    else{
                        grid[(*it).x][++(*it).y]++;
                        if(gridw[(*it).x][(*it).y]>0)
                            gridw[(*it).x][(*it).y]++,(*it).dis=1;
                    }
                }
                else if((*it).dir==2){//down
                    grid[(*it).x][(*it).y]--;
                    if((*it).x+1>r)
                        (*it).dis=1;
                    else{
                        grid[++(*it).x][(*it).y]++;
                        if(gridw[(*it).x][(*it).y]>0)
                            gridw[(*it).x][(*it).y]++,(*it).dis=1;
                    }
                }
                else if((*it).dir==3){//left
                    grid[(*it).x][(*it).y]--;
                    if((*it).y-1<1)
                        (*it).dis=1;
                    else{
                        grid[(*it).x][--(*it).y]++;
                        if(gridw[(*it).x][(*it).y]>0)
                            gridw[(*it).x][(*it).y]++,(*it).dis=1;
                    }
                }
            }
            for(i=0;i<=n;i++)
                if(drop[i].ct==-1){//occupy
                    if(grid[drop[i].x][drop[i].y]>0){
                        drop[i].sz+=grid[drop[i].x][drop[i].y];
                        grid[drop[i].x][drop[i].y]=0;
                    }
                    if(drop[i].sz>4){//crack
                        drop[i].ct=j;
                        gridw[drop[i].x][drop[i].y]=0;
                        for(k=0;k<4;k++){//produce small drops
                            tmp.x=drop[i].x;
                            tmp.y=drop[i].y;
                            tmp.dir=k;
                            tmp.dis=0;
                            sd.push_back(tmp);
                            grid[tmp.x][tmp.y]++;
                        }
                    }
                }
        }
        for(i=1;i<=n;i++){
            if(drop[i].ct>0)
                printf("0 %d\n",drop[i].ct);
            else
                printf("1 %d\n",drop[i].sz);
        }
    }
}
