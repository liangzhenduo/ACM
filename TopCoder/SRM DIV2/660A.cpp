#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
class Cyclemin{
public:
	string bestmod(string s,int k){
		int i,j,l;
		string ans=s;
		char tmp[51];
		for(i=0;i<s.length();i++){
			for(j=i,l=0;l<s.length();l++){
				tmp[l]=s[j];
				if(++j==s.length()) j=0;
			}
			tmp[l]='\0';
			for(j=l=0;l<k;j++){
				if(tmp[j]>'a') tmp[j]='a',l++;
			}
			if(tmp<ans)	ans.assign(tmp);
		}
		return ans;
	}
};
