class GraphPrim {
	//adjacency List
	// Why Adjacency List? While traversing, let's say from X to Y. Y has to store all the vertices a,b,c.
	// So Adjacency List can Store all of them
	// Here it is Gonna Store like 1 -> (a,weight1),(b,weight2),(c,weight3)
	// So We Storing the edges of  in one vector.
	// And we are gonna have an array of vectors.


	vector<pair<int, int>> *l;
	int V;

public:

	Graph(int n) {
		V = n;
		l = new vector<pair<int, int>> [n];
	}

	void addEdgePrim(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}

	int prim_mst() {
		// Most Important Stuff
		//Use a Min Heap or a Priority Queue.
		// Inititalised a Min heap. Greater keyword here will reverse it out. Making it a Min Heap, Rather than a Max Heap.
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
		// Why are we doing this sort of thing?
		// suppose x is connected to Y Which has a weight of w.
		// So We are Storing the Values of W and Y Together Like a Pair.

		//Another Array
		// Visited Array that denotes whether a node has been visited or not in the MST.
		bool* visited = new bool[V] {0};

		int ans = 0;
		//Beginning start from the Source Node.
		Q.push({0, 0}); // First Value Says About Weight and the other about node, Second One is Just like the Name.

		while (!Q.empty()) {
			//pick out the edge with min weight.
			auto best = Q.top(); // Best Edge is the one with the less(min) Weight.
			Q.pop();

			// This is the Part Where i am looking at the other Nodes which have Values and the name of their Nodes. THe Pair has The first one as weight and the second one as Name of Node.
			int to = best.second; // Second is generally the name of the Node
			int weight = best.first; // First is generally the nvalue of the Weight.

			if (visited[to]) {
				// If the Node has already been visited, then just discard it and continue
				continue;
			}

			// Otherwise take the current edge
			ans += weight;
			visited[to] = 1; //We mark the current vertice of the edge as visited.

			//Add new edges in the queue.
			for (auto x : l[to]) {
				if (visited[x.first] == 0) {
					Q.push({x.second, x.first});
				}
			}
		}
		return ans;
	}
};


int main() {


	int n, m;
	cin >> n >> m;

	GraphPrim g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdgePrim(x - 1, y - 1, w);
	}

	cout << g.prim_mst() << endl;
}