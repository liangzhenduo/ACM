// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class InvestmentAdvice {
public:
    vector<vector<int> > rec;
    vector<int> mon;
    vector<int> getInvestments(vector<int> advice, vector<int> recent, int money, int timeLeft, int roundsLeft) {
        rec.push_back(recent);
        mon.push_back(money);
        vector<int> ret(advice.size());
        vector<int> gain(advice.size());
        int loop = int(timeLeft * 3000 / (roundsLeft + 1));
        double sum1 = 0, sum2 = 0;
        for (int i = 0; i < advice.size(); i++) {
            if (advice[i] > 0) {
                sum1 += advice[i];
                for (int j = 0; j < rec.size(); j++) {
                    gain[i] += rec[j][i];
                }
                sum2 += gain[i];
            }
        }
        for (int j = 0; j < loop && money > 0; j++) {
            double tot1 = 0, tot2 = 0;
            for (int i = 0; i < advice.size(); i++) {
                if (advice[i] > 0 && gain[i] > 0 && ret[i] < 400000) {
                    int tmp = int (money * (advice[i] / sum1 + gain[i] / sum2) / 2 );
                    money += ret[i];
                    if (ret[i] + tmp < 400000) {
                        ret[i] += tmp;
                        tot1 += advice[i];
                        tot2 += gain[i];
                    }
                    else {
                        ret[i] = 400000;
                    }
                    money -= ret[i];
                }
            }
            sum1 = tot1;
            sum2 = tot2;
        }
        return ret;
    }
};

// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    InvestmentAdvice sol;
	int roundsLeft = 99;
	while (roundsLeft > 1) {
      int A;
      cin >> A;
      vector<int> advice(A);
      getVector(advice);
      int R;
      cin >> R;
      vector<int> recent(R);
      getVector(recent);
      int money;
	  int timeLeft;
	  cin >> money;
	  cin >> timeLeft;
	  cin >> roundsLeft;
      vector<int> ret = sol.getInvestments(advice, recent, money, timeLeft, roundsLeft);
      cout << ret.size() << endl;
      for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
      cout.flush();
	}
}
