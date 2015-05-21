class Pascal{
private:
	const LL MOD = 1000000007;
	vector< vector<LL> > triangle;
	void build(int n) {
		triangle = vector< vector<LL> >(n + 1, vector<LL>(n + 1));
		for (int i = 0; i <= n; i++) {
			triangle[i][0] = 1;
			triangle[i][i] = 1;
			for (int j = 1; j < i; j++) {
				triangle[i][j] = (triangle[i - 1][j] + triangle[i - 1][j - 1]) % MOD;
			}
		}
	}
public:
	Pascal(int n) {
		build(n);
	}

	LL comb(int m, int n) {	// mCn
		return triangle[m][n];
	}

	void dump() {
		for (auto r : triangle) {
			for (auto c : r) cout << c << " ";
			cout << endl;
		}
		cout << endl;
	}
};
