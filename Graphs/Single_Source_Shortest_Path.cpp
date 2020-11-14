template<typename T>
class GraphSSSP {

	map<T, list<T>> l; // if T is an Integer and a key, then it would become map<int,list<int>> l.
public:
	void addEdgeBfs(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x); // Assuming all edges are bi directional.
	}

	void bfs(T src) { // int src.
		// This code is for finding thr source node.
		// we need a queue and an array. One to store the output and the other to mark the array marked values.
		map<T, int> dist;
		queue<T>q;

		for (auto node_pair : l) {
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		q.push(src);
		dist[src] = 0; // 0 Because of Initially there is no distance.

		while (!q.empty()) { // Remove one from the queue.
			T node = q.front();
			q.pop();

			cout << node << " ";
			for (int nbr : l[node]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					//mark that Distance
					dist[nbr] = dist[node] + 1;
				}
			}
		}

		// print the distance to every node
		for (auto node_pair : l) {
			T node = node_pair.first;
			int d = dist[node];
			cout << "Node " << node << "D from Src" << d << endl;
		}
	}

};
