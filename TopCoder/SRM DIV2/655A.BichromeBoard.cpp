#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class BichromeBoard{
	public:
	string ableToDraw(vector <string> board){
		int m=board[0].size();
		int n=board.size();
		int i,j,b,w;
		bool flag=1;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(board[i][j]!='?'){
					if(board[i][j]=='B')b=(i+j)%2,w=(i+j+1)%2;
					else if(board[i][j]=='W')w=(i+j)%2,b=(i+j+1)%2;
					break;
				}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if((board[i][j]=='B'&&(i+j)%2!=b)||(board[i][j]=='W'&&(i+j)%2!=w)){
					flag=0;
					break;
				}
		if(flag) return "Possible";
		else return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W?W",
 "??B",
 "???"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(0, Arg1, ableToDraw(Arg0)); }
	void test_case_1() { string Arr0[] = {"W??W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(1, Arg1, ableToDraw(Arg0)); }
	void test_case_2() { string Arr0[] = {"??"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(2, Arg1, ableToDraw(Arg0)); }
	void test_case_3() { string Arr0[] = {"W???",
 "??B?",
 "W???",
 "???W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(3, Arg1, ableToDraw(Arg0)); }
	void test_case_4() { string Arr0[] = {"W???",
 "??B?",
 "W???",
 "?B?W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Impossible"; verify_case(4, Arg1, ableToDraw(Arg0)); }
	void test_case_5() { string Arr0[] = {"B"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Possible"; verify_case(5, Arg1, ableToDraw(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main(){
	BichromeBoard test;
	test.run_test(-1);
	return 0;
}
// END CUT HERE
