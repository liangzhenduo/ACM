// http://community.topcoder.com/longcontest/?module=ViewProblemStatement&compid=64279&rd=17179
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

class CrystalLighting {
public:
    int width, height;
    char board[100][100];
    char origin[100][100];
    vector<string> placeItems(vector<string> targetBoard, int costLantern, int costMirror, int costObstacle, int maxMirrors, int maxObstacles) {
        height = targetBoard.size();
        width = targetBoard[0].length();
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < width; j ++) {
                board[i][j] = targetBoard[i][j];
                origin[i][j] = targetBoard[i][j];
            }
        }
        vector <string> rst;
        
        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < width; j ++) {
                if (board[i][j] != '.') {
                    continue;
                }
                int color = lightPri(i, j, costLantern);
                if (color > 0) {
                    rst.push_back(makeString(i, j, color));
                    board[i][j] = '*';
                }
            }
        }

        for (int i = 0; i < height; i ++) {
            for (int j = 0; j < width; j ++) {
                if (board[i][j] != '.') {
                    continue;
                }
                int color = lightSec(i, j, costLantern);
                if (color > 0) {
                    rst.push_back(makeString(i, j, color));
                    board[i][j] = '*';
                }
            }
        }

        return rst;
    }

private:
    int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int lightPri(int hh, int ww, int cost) {
        vector <pair <int, int> > crystal;  //crystal in the same line
        for (int i = 0; i < 4; i ++) {
            for (int w = ww + offset[i][0], h = hh + offset[i][1]; 
                w >= 0 && h >= 0 && w < width && h < height; 
                w += offset[i][0], h += offset[i][1]) {
                if (board[h][w] == '*') {
                    return 0;
                }
                if (board[h][w] == 'X') {
                    break;
                }
                if (isNum(board[h][w])) {
                    crystal.push_back(make_pair(h, w));
                    break;
                }
            }
        }
        
        int ret = 0, score = 0;
        for (int c = 1; c <= 4; c *= 2) {   //3 colors
            int point = 0;
            for (int i = 0; i < crystal.size(); i ++) {
                int nu = origin[crystal[i].first][crystal[i].second] - '0';
                int num = board[crystal[i].first][crystal[i].second] - '0';
                if (c == nu) {
                    point += 20;  //20 points for primary color
                }
                else if ((c | num) == num) {    //a part of sencondary
                    
                }
                else {
                    point = 0;
                    break;
                }
            }
            if (point > score && point > cost) {
                score = point;
                ret = c;
            }
        }

        if (ret > 0) {
            for (int i = 0; i < crystal.size(); i ++) {
                int num = board[crystal[i].first][crystal[i].second] - '0';
                board[crystal[i].first][crystal[i].second] = num - ret + '0';
            }
        }
        return ret;
    }

    int lightSec(int hh, int ww, int cost) {
        vector <pair <int, int> > crystal;  //crystal in the same line
        for (int i = 0; i < 4; i ++) {
            for (int w = ww + offset[i][0], h = hh + offset[i][1]; 
                w >= 0 && h >= 0 && w < width && h < height; 
                w += offset[i][0], h += offset[i][1]) {
                if (board[h][w] == '*') {
                    return 0;
                }
                if (board[h][w] == 'X') {
                    break;
                }
                if (isNum(board[h][w])) {
                    crystal.push_back(make_pair(h, w));
                    break;
                }
            }
        }
        
        int ret = 0, score = 0;
        for (int c = 1; c <= 4; c *= 2) {   //3 colors
            int point = 0;
            for (int i = 0; i < crystal.size(); i ++) {
                int nu = origin[crystal[i].first][crystal[i].second] - '0';
                int num = board[crystal[i].first][crystal[i].second] - '0';
                if (c == num && c < nu) {
                    point += 30;  //30 points for secondary color
                }
                else if (num == 0) {
                    point -= 10;
                    if ((c | nu) == nu) {   //keep ordinary
                        point += 10;
                    }
                    else if (nu == 1 || nu == 2 || nu == 4) {   //damage primary
                        point -= 20;
                    }
                    else {  //damage secondary
                        point -= 30;
                    }
                }
            }
            if (point > score && point > cost) {
                score = point;
                ret = c;
            }
        }

        if (ret > 0) {
            for (int i = 0; i < crystal.size(); i ++) {
                int num = board[crystal[i].first][crystal[i].second] - '0';
                board[crystal[i].first][crystal[i].second] = (num & (~ ret)) + '0';
            }
        }
        return ret;
    }

    bool isNum(char c) {
        return (c >= '0' && c <= '9');
    }

    string makeString(int a, int b, int c) {
        stringstream ss;
        ss << a << " " << b << " " << c;
        return ss.str();
    }
};

// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    CrystalLighting cl;
    int H;
    cin >> H;
    vector<string> targetBoard(H);
    getVector(targetBoard);
    int costLantern, costMirror, costObstacle, maxMirrors, maxObstacles;
    cin >> costLantern >> costMirror >> costObstacle >> maxMirrors >> maxObstacles;

    vector<string> ret = cl.placeItems(targetBoard, costLantern, costMirror, costObstacle, maxMirrors, maxObstacles);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
