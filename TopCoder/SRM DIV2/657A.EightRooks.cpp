#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"R.......",
 ".R......",
 "..R.....",
 "...R....",
 "....R...",
 ".....R..",
 "......R.",
 ".......R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Correct"; verify_case(0, Arg1, isCorrect(Arg0)); }
	void test_case_1() { string Arr0[] = {"........",
 "....R...",
 "........",
 ".R......",
 "........",
 "........",
 "..R.....",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Incorrect"; verify_case(1, Arg1, isCorrect(Arg0)); }
	void test_case_2() { string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".....R..",
 "..R.....",
 ".......R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Correct"; verify_case(2, Arg1, isCorrect(Arg0)); }
	void test_case_3() { string Arr0[] = {"......R.",
 "....R...",
 "...R....",
 ".R......",
 "R.......",
 ".......R",
 "..R.....",
 ".......R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Incorrect"; verify_case(3, Arg1, isCorrect(Arg0)); }
	void test_case_4() { string Arr0[] = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Incorrect"; verify_case(4, Arg1, isCorrect(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main(){
	EightRooks test;
	test.run_test(-1);
	return 0;
}
// END CUT HERE
