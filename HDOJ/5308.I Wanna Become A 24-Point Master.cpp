#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if (n < 4){
            puts("-1");
            continue;
        }
        if (n == 4){
            printf("1 * 2\n5 + 3\n6 + 4\n");
        }
        else if (n == 5){
            puts("1 / 2");
            puts("6 / 3");
            puts("4 - 7");
            puts("8 * 5");
        }
        else if (n == 6){
            puts("1 + 2");
            puts("3 + 7");
            puts("8 + 4");
            puts("5 - 6");
            puts("9 + 10");
        }
        else if (n == 7){
            puts("1 / 2");
            puts("3 + 8");
            puts("4 + 5");
            puts("6 + 10");
            puts("11 / 7");
            puts("9 * 12");
        }
        else if (n == 8){
            puts("1 / 2");
            puts("3 - 9");
            puts("4 * 10");
            puts("11 - 5");
            puts("12 - 6");
            puts("13 - 7");
            puts("14 - 8");
        }
        else if (n == 9){
            puts("1 / 2");
            puts("3 / 4");
            puts("5 / 6");
            puts("7 - 10");
            puts("8 - 11");
            puts("9 - 12");
            puts("13 + 14");
            puts("15 + 16");
        }
        else if (n == 10){
            puts("1 + 2");
            puts("11 / 3");
            puts("4 - 12");
            puts("5 + 6");
            puts("7 + 14");
            puts("15 / 8");
            puts("9 - 10");
            puts("13 * 16");
            puts("17 + 18");
        }
        else if (n == 11){
            puts("1 / 2");
            puts("3 + 12");
            puts("4 / 5");
            puts("6 / 7");
            puts("14 + 15");
            puts("13 * 16");
            puts("8 - 9");
            puts("10 - 11");
            puts("18 - 19");
            puts("17 + 20");
        }
        else if (n == 12){
            puts("1 + 2");
            puts("3 - 4");
            puts("5 - 6");
            puts("7 - 8");
            puts("9 - 10");
            puts("11 - 12");
            puts("14 + 15");
            puts("16 + 17");
            puts("18 + 19");
            puts("20 + 21");
            puts("22 + 13");
        }
        else{
            if (n % 2 == 1){
                puts("1 + 2");
                printf("%d / 3\n", n + 1);//n+2=>2
                puts("4 + 5");
                printf("%d / 6\n", n + 3);//n+4=>2
                puts("7 + 8");
                printf("%d / 9\n", n + 5);//n+6=>2
                puts("10 + 11");
                printf("12 + %d\n", n + 7);//n+8=>3n
                printf("%d / 13\n", n + 8);//n+9=>3
                printf("%d * %d\n", n + 2, n + 4);//n+10=>4
                printf("%d * %d\n", n + 10, n + 6);//n+11=>8
                printf("%d * %d\n", n + 11, n + 9);//n+12=>24
                for (int i = 12; i < n - 1; ++i)
                    printf("%d %c %d\n", n + i, (i & 1 ? '-' : '+'), i + 2);
            }
            else{
                puts("1 + 2");
                printf("%d / 3\n", n + 1);
                puts("4 + 5");
                printf("%d / 6\n", n + 3);
                puts("7 / 8");
                puts("9 / 10");
                printf("%d + %d\n", n + 5, n + 6);
                puts("11 + 12");
                printf("%d + 13\n", n + 8);
                printf("%d / 14\n", n + 9);
                printf("%d * %d\n", n + 10, n + 2);
                printf("%d * %d\n", n + 11, n + 4);
                printf("%d * %d\n", n + 12, n + 7);
                for (int i = 15; i <= n; ++i)
                    printf("%d %c %d\n", n + i -2, (i & 1 ? '+' : '-'), i);
            }
        }
    }
    return 0;
}
