// using namespace std;
// typedef pair<int, int> PII;
// typedef vector<VB> VVB;
// typedef vector<PII> VPII;
// #define Y first
// #define X second
// #define MP make_pair
// #define EB emplace_back 
// const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};

/*** DancingLinks ***/
// ある格子点から未到達の四近傍の位置がO(1)で求められるデータ構造

struct Tile {
    Tile () {}
    Tile(int y, int x) : p(y, x) {
        for (int i = 0; i < 4; i++) {
            ps.EB(y + DY[i], x + DX[i]);
        }
    }
    PII p; // 現在の位置
    VPII ps;　// 未到達の四近傍の位置
};

map<PII, Tile> ms;

Tile& get_tile(PII p) {
    if (ms.count(p)) {
        return ms[p];
    } else {
        return ms[p] = Tile(p.Y, p.X);
    }
}

void visit(Tile &t) {
    for (int i = 0; i < 4; i++) {
        int j = (i + 2) % 4;
        
        Tile &a = get_tile(t.ps[i]);
        a.ps[j] = t.ps[j];
    }
}

/*** /DancingLinks ***/
