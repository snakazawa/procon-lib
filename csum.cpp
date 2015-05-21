/***** �ݐϘa *****/

// �ꎟ���ݐϘa
template<typename T>
vector<T> calc_csum(vector<T> &val) {
	vector<T> sum(val.size() + 1);
	partial_sum(val.begin(), val.end(), sum.begin() + 1);
	return sum;
}

template<typename T>
T sum_csum(vector<T> &sum, int begin, int end) {
	return sum[end] - sum[begin];
}

// �񎟌��ݐϘa
template<typename T>
vector< vector<T> > calc_csum2(vector< vector<T> > &val) {
	int H = val.size();
	int W = val[0].size();
	vector< vector<T> > sum(H + 1, vector<T>(W + 1));

	for (int y = 0; y < H; y++) {
		partial_sum(val[y].begin(), val[y].end(), sum[y + 1].begin() + 1);
	}

	for (int y = 0; y < H; y++) {
		for (int x = 0; x <= W; x++) {
			sum[y + 1][x] += sum[y][x];
		}
	}

	return sum;
}

template<typename T>
T sum_csum2(vector< vector<T> > &sum, int y1, int y2, int x1, int x2) {
	return sum[y2][x2] - sum[y2][x1] - sum[y1][x2] + sum[y1][x1];
}

/***** /�ݐϘa *****/
