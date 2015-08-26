#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class LuckyXor{
	public:
	int construct(int a){
		int ans=-1;
		for(int i=a+1;i<101;i++){
			int b=a^i;
			while(b){
				if(b%10!=4&&b%10!=7) break;
				b/=10;
			}
			if(!b){
				ans=i;
				break;
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 40; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 20; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 88; int Arg1 = 92; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 36; int Arg1 = -1; verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE
};

// BEGIN CUT HERE
int main(){
	LuckyXor test;
	test.run_test(-1);
	return 0;
}
// END CUT HERE
