// ���A���������� scc
class Scc {
public:
	int V;
	int K;
	vector< vector<int> > G; // �O���t�̗אڃ��X�g
	vector< vector<int> > rG; // �ӂ̌������t�ɂ����O���t
	vector<int> vs;		// �A�肪���̏��̕���
	vector<bool> used;	// ���łɒ��ׂ���
	vector<int> cmp;	// �����鋭�A�������̃g�|���W�J������
	vector< vector<int> > cG; // �g�|���W�J�������ɂ�����O���t (cG[�g�|���W�J������i] = [������m�[�hj])

	Scc(int v) {
		V = v;
		G = vector< vector<int> >(V);
		rG = vector< vector<int> >(V);
		cmp = vector<int>(V);
		cG = vector< vector<int> >();
	}

	void addEdge(int from, int to) {
		G[from].push_back(to);
		rG[to].push_back(from);
	}

	void dfs(int v) {
		used[v] = true;
		for (int i = 0; i < (int)G[v].size(); i++) {
			if (!used[G[v][i]]) {
				dfs(G[v][i]);
			}
		}
		vs.push_back(v);
	}

	void rdfs(int v, int k) {
		used[v] = true;
		cmp[v] = k;
		cG[k].push_back(v);
		for (int i = 0; i < (int)rG[v].size(); i++) {
			if (!used[rG[v][i]]) {
				rdfs(rG[v][i], k);
			}
		}
	}

	int solve() {
		used.clear();
		used.resize(V, false);
		vs.clear();
		vs.resize(V);
		for (int v = 0; v < V; v++) {
			if (!used[v]) {
				dfs(v);
			}
		}

		used.clear();
		used.resize(V, false);
		int k = 0;
		for (int i = vs.size() - 1; i >= 0; i--) {
			if (!used[vs[i]]) {
				cG.push_back(vector<int>());
				rdfs(vs[i], k++);
			}
		}

		return K = k;
	}
};
// /scc
