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
// ����i�q�_���疢���B�̎l�ߖT�̈ʒu��O(1)�ŋ��߂���f�[�^�\��

struct Tile {
    Tile () {}
    Tile(int y, int x) : p(y, x) {
        for (int i = 0; i < 4; i++) {
            ps.EB(y + DY[i], x + DX[i]);
        }
    }
    PII p; // ���݂̈ʒu
    VPII ps;�@// �����B�̎l�ߖT�̈ʒu
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
