vector<bool> Prime;
vector<int> PrimeStk;
void initPrime(long num) {
	Prime = vector<bool>(num + 1, true);
	Prime[1] = Prime[0] = false;
	long sq_num = sqrt((double)num);
	for (long i = 2; i <= sq_num; i++) {
		if (Prime[i]) {
			for (long j = i + i; j <= num; j += i) {
				Prime[j] = false;
			}
		}
	}
}
void initPrimeStk(long begin) {
	PrimeStk.clear();
	for (long i = begin; i < Prime.size(); i++) {
		if (Prime[i]) {
			PrimeStk.push_back(i);
		}
	}
}
