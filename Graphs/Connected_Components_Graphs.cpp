// Graph Class for finding Connected Graphs
template<typename T>
class GraphDFSCompo {
	map<T, list<T>> l;
public:

	void addEdgeCompo(int x, int y) {
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
	void dfs() {
		map<T, bool>visited;
		//Mark all the nodes as not visited in the Beginning
		for (auto p : l) {
			T node = p.first;
			visited[node] = false;
		}

		//Call the helper function
		int cnt = 0;
		///iterate over all the vertices and initiate a dfs call if not visited the particular node
		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				cout << endl << "Component " << cnt << "-->" << endl;
				dfs_helper(node, visited);
				cnt++;
			}
		}
	}
};



int main() {


	GraphDFSCompo<int>z;
	z.addEdgeCompo(0, 1);
	z.addEdgeCompo(1, 2);
	z.addEdgeCompo(2, 3);
	z.addEdgeCompo(0, 3);
	z.addEdgeCompo(0, 4);
	z.addEdgeCompo(5, 6);
	z.addEdgeCompo(6, 7);
	z.addEdgeCompo(8, 8);
	z.dfs(); // Not Giving a starting point because it has to find component from any given node.




	return 0;
}