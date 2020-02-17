

int dijkstra(int src, int dest) {

	vector<int> dist(N+1, INF);
	dist[src] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0, src});

	while(!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		
		pq.pop();

		if(dist[here] < cost) continue;

		for(int i = 0 ; i < adj[here].size(); i++) {
			int there = adj[here][i].second;
			int nextDist = cost + adj[here][i].first;

			if(nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push({-nextDist, there});
			}
		}
	}
	return dist[dest];
}
