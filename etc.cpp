// vectorを非負整数列maxNum進とみなしてデクリメント
bool vectorDec(vector<int>& val, int decimal) {
	unsigned int i;
	for (i = 0;  i < val.size() && val[i] == 0; i++) {
		val[i] = decimal - 1;
	}
	
	if (i < val.size()) {
		val[i]--;
		return true;
	}else {
		fill(val.begin(), val.end(), decimal - 1);
		return false;
	}
}

// 累積和チェック
// TODO: template追加
bool pertialSumCheck(vector<int>& val, vector<Count>& que, vector<int>& sum) {
	sum.resize(1, 0);
	partial_sum(val.begin(), val.end(), back_inserter(sum));

	for (unsigned int i = 0; i < que.size(); i++) {
		if (sum[que[i].end] - sum[que[i].begin] != que[i].num) {
			return false;
		}
	}
	
	return true;
}

bool pertialSumCheck(vector<int>& val, vector<Count>& que) {
	vector<int> sum;
	return pertialSumCheck(val, que, sum);
}

// 最小公倍数
int lcm(int n, int m) {
	return n * m / __gcd(n, m);
}

// ユニーク処理
template<typename T>
void myuniq(T &vec) {
    sort(vec.begin(), vec.end());
    auto it = unique(vec.begin(), vec.end());
    vec.resize(vec.begin(), it);
}
