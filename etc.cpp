// vector��񕉐�����maxNum�i�Ƃ݂Ȃ��ăf�N�������g
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

// �ݐϘa�`�F�b�N
// TODO: template�ǉ�
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

// �ŏ����{��
int lcm(int n, int m) {
	return n * m / __gcd(n, m);
}

// ���j�[�N����
template<typename T>
void myuniq(T &vec) {
    sort(vec.begin(), vec.end());
    auto it = unique(vec.begin(), vec.end());
    vec.resize(vec.begin(), it);
}
