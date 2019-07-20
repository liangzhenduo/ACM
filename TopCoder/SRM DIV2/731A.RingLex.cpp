// BEGIN CUT HERE
/*
PROBLEM STATEMENT
Hero has an infinite periodic string t.
You are given the string s that is the period of Hero's string.
For example, if s = "abc", Hero's actual string is t = "abcabcabcabc..."

Let n be the length of string s.
Hero is now going to use the infinite string t to generate a new n-character string by doing the 
following steps:

He will choose an offset: a non-negative integer x.
He will choose the length of a step: a prime number p that is less than n.
The new string will consists of the first n characters we can read in the string t if we start at 
the index x and after each character we move p positions to the right.


Formally, Hero's new string will consist of the following characters, in order:
t[x], t[x + p], t[x + 2*p], ..., t[x + (n-1)*p].

Find and return the lexicographically smallest string Hero can produce.

DEFINITION
Class:RingLex
Method:getmin
Parameters:string
Returns:string
Method signature:string getmin(string s)


NOTES
-Given two distinct strings of the same length, the lexicographically smaller one is the one that 
has a smaller character at the first position where they differ.
-A positive integer p is a prime if it has exactly two distinct divisors: 1 and p. Note that the 
number 1 is not a prime.


CONSTRAINTS
-s will contain between 3 and 50 characters, inclusive.
-Each character in s will be between 'a' and 'z', inclusive.


EXAMPLES

0)
"cba"

Returns: "abc"

Hero should choose the offset x=2 and the step p=2. The resulting string is t[2]+t[4]+t[6] = 
'a'+'b'+'c' = "abc".

1)
"acb"

Returns: "abc"

Here, Hero should choose x=0 and p=2.


2)
"abacaba"

Returns: "aaaabcb"



3)
"aaabb"

Returns: "aabab"



4)
"azzzabbb"

Returns: "abazabaz"

Note that Hero cannot choose x=0 and p=4, because 4 is not a prime number.

5)
"abbaac"

Returns: "aaaaaa"



6)
"fsdifyhsoe"

Returns: "dehifsfsoy"



*/

#include <iostream>
#include <sstream>
// END CUT HERE
#include <string>
using namespace std;

class RingLex {
public:
    string getmin(string s) {
    	int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    	int n = s.length();
    	string res = "";
    	for (int i = 0; p[i] < n; i ++) {	//遍历质数
    		for (int j = 0; j < n; j ++) {	//遍历偏移
    			string tmp = "";
    			for (int k = j; tmp.length() < n; k += p[i]) {
    				tmp.append(s, k%n, 1);
    			}
    			if (res == "" || res > tmp) {
    				res = tmp;
    			}
    		}
    	}
    	return res;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cba"; string Arg1 = "abc"; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "acb"; string Arg1 = "abc"; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "abacaba"; string Arg1 = "aaaabcb"; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "aaabb"; string Arg1 = "aabab"; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "azzzabbb"; string Arg1 = "abazabaz"; verify_case(4, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arg0 = "abbaac"; string Arg1 = "aaaaaa"; verify_case(5, Arg1, getmin(Arg0)); }
	void test_case_6() { string Arg0 = "fsdifyhsoe"; string Arg1 = "dehifsfsoy"; verify_case(6, Arg1, getmin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    RingLex ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
