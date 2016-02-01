#include <bits/stdc++.h>
class Solution {
public:
    int addDigits(int num) {
        if(num>9){
            int ans=0;
            while(num){
                ans+=(num%10);
                num/=10;
            }
            return addDigits(ans);
        }
        else return num;
    }
};