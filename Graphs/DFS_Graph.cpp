template<typename T>
class GraphDFS {
	map<T, list<T>> l;
public:

	void addEdge2(int x, int y) {
		l[x].push_back(y); // Assuming it is Bidirectional
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited) { // This will help us to tell where it started from
		//Recursive Function that will traverse the graph
		cout << src << " ";
		visited[src] = true;
		// go to any neighbour of that node, that is not visited.
		for (T nbr : l[src]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited);
			}
		}
	}

	//Maintain a Visited array
	void dfs(T src) {
		map<T, bool>visited;
		// Goal of the Visited map is to just find and mark all the visited nodes of the graph
		// Mark all the Nodes as not visited in the Beginning.
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		// Call the Helper Function
		dfs_helper(src, visited);
		// THe dfs gets activated first, but then it calls the recursive function again
	}
};