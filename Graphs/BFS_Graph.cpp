template<typename T>
class GraphBfs {

	map<T, list<T>> l; // if T is an Integer and a key, then it would become map<int,list<int>> l.
public:
	void addEdgeBfs(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x); // Assuming all edges are bi directional.
	}

	void bfs(T src) { // int src.
		// This code is for finding thr source node.
		// we need a queue and an array. One to store the output and the other to mark the array marked values.
		map<T, int> visited;
		queue<T>q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) { // Remove one from the queue.
			T node = q.front();
			q.pop();

			cout << node << " ";
			for (int nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					//mark that neighbour as visited.
					visited[nbr] = true;
				}
			}
		}
	}


};

int main() {



	GraphBfs<int> f;
	f.addEdgeBfs(0, 1);
	f.addEdgeBfs(1, 2);
	f.addEdgeBfs(2, 3);
	f.addEdgeBfs(3, 4);
	f.addEdgeBfs(4, 5);
	f.bfs(0);


	return 0;
}