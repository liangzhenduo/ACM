#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
class EightRooks{
public:
	string isCorrect(vector <string> board){
		int c[8]={0},r[8]={0},i,j,k;
		for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='R'){
                    c[i]++;
                    r[j]++;
                }
            }
		}
		for(j=k=i=0;i<8;i++){
            if(c[i]==1) j++;
            if(r[i]==1) k++;
		}
		if(j==8&&k==8) return "Correct";
		else return "Incorrect";
	}
};
