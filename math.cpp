LL power_mod(LL n, LL p) { // n^p
//	static const LL MOD = 1000000007;
	static map<pair<LL, LL>, LL> power_mod_memo;
	
	if (p == 0) return 1;
	if (p == 1) return n;
	
	pair<LL, LL> temp_pair(n, p);
	if (power_mod_memo.count(temp_pair)) return power_mod_memo[temp_pair];

	LL t = power_mod(n, p / 2) % MOD;
	return power_mod_memo[temp_pair] = t * t % MOD * power_mod(n, p % 2) % MOD;
}

LL comb_mod(LL n, LL r) { // nCr
//	static const LL MOD = 1000000007;
	static map<pair<LL, LL>, LL> comb_mod_memo;

	if (n - r < r) {
		return comb_mod(n, n - r);
	}

	pair<LL, LL> current_pair(n, r);

	if (comb_mod_memo.count(current_pair)) {
		return comb_mod_memo[current_pair];
	}

	LL pn = 1;
	for (LL i = n - r + 1; i <= n; i++) {
		(pn *= i) %= MOD;
	}

	LL pr = 1;
	for (LL i = 1; i <= r; i++) {
		(pr *= i) %= MOD;
	}

	return comb_mod_memo[current_pair] = pn * power_mod(pr, MOD - 2) % MOD;
}
