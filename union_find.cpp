/***** Union-Find *****/

const int MAX_N = 10000;
int Par[MAX_N];
int Rank[MAX_N];

void union_find_init(int n){
	for(int i=0; i<n; ++i){
		Par[i] = i;
		Rank[i] = 0;
	}
}

int find(int x){
	if(Par[x] == x){
		return x;
	}else {
		return Par[x] = find(Par[x]);
	}
}

void unite(int x, int y){
	x = find(x);
	y = find(y);

	if(x == y)
		return ;

	if(Rank[x] < Rank[y]){
		Par[x] = y;
	} else{
		Par[y] = x;
		if(Rank[x] == Rank[y]){
			++Rank[x];
		}
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

/***** /Union-Find *****/
