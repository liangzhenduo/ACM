//https://community.topcoder.com/longcontest/?module=ViewProblemStatement&rd=17153&pm=14907
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class RoadsAndJunctions {
private:
    struct Vertex {
        int x;
        int y;
    };

    struct Edge {
        int p;
        int q;
        double w;
    };

protected:
    int NC;
    int NJ;
    vector <Vertex> VC;
    vector <Vertex> VJ;
    vector <Edge> E;    //城市直接连接
    vector <Edge> F;
    vector <Edge> G;

public:
    vector <int> buildJunctions(int S, vector <int> cities, double junctionCost, double failureProbability) {
        NC = cities.size() / 2;
        for (int i = 0; i < NC; i ++) {
            //构造点集
            Vertex city = {cities[2 * i], cities[2 * i + 1]};
            VC.push_back(city);
            //构造边集
            for (int j = 0; j < i; j ++) {
                Edge road = {j, i, Distance(VC[j], VC[i])};
                E.push_back(road);
            }
        }

        vector <int> junctions;
        Kruskal(F, NC);
        sort(F.begin(), F.end(), Compare);
        for (int i = 0; i < F.size(); i ++) {
            for (int j = i + 1; j < F.size(); j ++) {
                if (F[j].p == F[i].p || F[j].p == F[i].q) { //相交
                    double sum = F[i].w + F[j].w;
                    Vertex fermat = Fermat(VC[F[i].p], VC[F[i].q], VC[F[j].q]);
                    if (Distance(fermat, VC[F[i].p]) + Distance(fermat, VC[F[i].q]) + Distance(fermat, VC[F[j].q]) + junctionCost < sum) {
                        bool exist = false;
                        for (int k = 0; k < VC.size(); k ++) {
                            if (VC[k].x == fermat.x && VC[k].y == fermat.y) {
                                exist = true;
                            }
                        }
                        for (int k = 0; k < VJ.size(); k ++) {
                            if (VJ[k].x == fermat.x && VJ[k].y == fermat.y) {
                                exist = true;
                            }
                        }
                        if (!exist) {
                            VJ.push_back(fermat);
                            junctions.push_back(fermat.x);
                            junctions.push_back(fermat.y);
                        }
                    }
                }
            }
        }
        NJ = VJ.size();
        return junctions;
    }

    vector <int> buildRoads(vector <int> junctionStatus) {
        for (int i = 0; i < junctionStatus.size(); i ++) {
            if (junctionStatus[i] == 1) {
                for (int j = 0; j < NC; j ++) {
                    Edge road = {j, NC + i, Distance(VC[j], VJ[i])};
                    E.push_back(road);
                }
            }
        }

        Kruskal(G, NC + NJ);

        vector<int> roads;
        for (int i = 0; i < G.size(); i ++) {
            roads.push_back(G[i].p);
            roads.push_back(G[i].q);
        }
        return roads;
    }
    
private:
    static bool CompareW(Edge p, Edge q){
        return p.w < q.w;
    }

    static bool Compare(Edge p, Edge q){
        if (p.p == q.p) {
            return p.q < q.q;
        }
        return p.p < q.p;
    }

    double Distance(Vertex p, Vertex q) {
        double dx = p.x - q.x;
        double dy = p.y - q.y;
        return sqrt(dx * dx + dy * dy);
    }

    void Kruskal(vector <Edge> &mst, int n) {
        vector <int> parent;
        for (int i = 0; i < n; i ++) {
            parent.push_back(i);
        }
        sort(E.begin(), E.end(), CompareW);
        for (int i = 0; i < E.size(); i ++) {
            Union(E[i], mst, parent);
        }
    }

    int Find(int p, vector <int> &parent) {
        return parent[p] - p ? parent[p] = Find(parent[p], parent) : p;
    }

    void Union(Edge e, vector <Edge> &mst, vector <int> &parent){
        int p = Find(e.p, parent);
        int q = Find(e.q, parent);
        if (p != q) {
            parent[p] = q;
            mst.push_back(e);
        }
    }

    Vertex Fermat(Vertex a, Vertex b, Vertex c) {
        int minX = min(min(a.x, b.x), c.x);
        int minY = min(min(a.y, b.y), c.y);
        int maxX = max(max(a.x, b.x), c.x);
        int maxY = max(max(a.y, b.y), c.y);

        Vertex u = b;
        for (int i = minX; i <= maxX; i ++) {
            for (int j = minY; j <= maxY; j ++) {
                Vertex v = {i, j};
                if (Distance(u, a) + Distance(u, b) + Distance(u, c) > Distance(v, a) + Distance(v, b) + Distance(v, c)) {
                    u = v;
                }
            }
        }
        return u;
    }
};

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    RoadsAndJunctions rj;
    int S, C;
    cin >> S >> C;
    vector<int> cities(C);
    getVector(cities);
    double junctionCost, failureProbability;
    cin >> junctionCost >> failureProbability;

    vector<int> ret = rj.buildJunctions(S, cities, junctionCost, failureProbability);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
    
    int J;
    cin >> J;
    vector<int> junctionStatus(J);
    getVector(junctionStatus);

    ret = rj.buildRoads(junctionStatus);
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
/*
int main() {
    RoadsAndJunctions rj;
    int S = 1000, C = 100;
    //cin >> S >> C;

    vector<int> cities;
    int city[] = {233,501,760,7,318,611,616,20,854,581,120,245,109,30,184,576,349,977,147,649,299,943,797,919,203,771,407,709,5,995,166,55,907,297,6,868,74,832,590,318,177,711,761,720,119,146,139,767,937,220,383,310,969,556,69,143,397,711,103,207,244,226,41,383,767,314,765,517,259,650,166,630,617,890,371,874,846,559,590,559,822,462,816,31,796,317,183,403,472,124,56,391,264,179,990,851,383,540,979,835,447,750,436,871,18,455,363,288,58,679,691,984,25,80,249,754,737,677,506,377,23,565,449,48,244,558,844,768,671,646,431,81,382,950,541,395,351,100,630,855,572,163,904,825,678,767,518,996,831,519,226,407,165,663,15,804,307,839,69,366,519,588,521,240,648,849,918,361,203,233,945,605,443,725,188,304,767,628,21,651,278,65,306,381,366,8,83,437,317,198,343,426,686,647,841,185,110,763,376,782};
    for (int i = 0; i < C; i ++) {
        cities.push_back(city[i]);
    }
    //getVector(cities);
    double junctionCost = 10.0, failureProbability = 0.4;
    //cin >> junctionCost >> failureProbability;

    vector<int> ret = rj.buildJunctions(S, cities, junctionCost, failureProbability);
    cout << ret.size() << endl;
}
*/