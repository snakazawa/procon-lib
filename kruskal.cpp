/***** Kruskal *****/

struct edge {
	int from,
		to,
		cost;
};

bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

const int MAX_E = 10000;
edge es[MAX_E];
int V, E;

int kruskal(void){
	sort(es, es + E, comp);
	union_find_init(V);

	int res = 0;
	for(int i=0; i<E; ++i){
		edge e = es[i];
		if(!same(e.from, e.to)){
			unite(e.from, e.to);
			res += e.cost;
		}
	}

	return res;
}

/***** /Kruskal *****/
