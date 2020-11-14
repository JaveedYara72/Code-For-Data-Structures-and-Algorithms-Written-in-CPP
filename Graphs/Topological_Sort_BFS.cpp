class GraphTopoBFS {
	list<int> *l; // Array of lists.
	int V; //Number of Vertices
public:

	Graph(int V) {
		this->V = V;
		l = new list<int>[V]; //There are V Nummber of Linked Lists. Each Node Pointing to its own set of Conncections
	}

	void addEdge(int x, int y) {
		//since it is a directed graph
		l[x].push_back(y);
	}

	void topologicalsort() {
		//Create an Array of indegree
		int* indegree = new int[V];
		for (int i = 0; i < V; i++) {
			indegree[i] = 0;
		}
		//update indegree by traversing the edges
		//indegree[y] ++;

		for (int i = 0; i < V; i++) {
			for (auto y : l[i]) {
				indegree[y]++;
			}
		}

		//bfs
		queue<int>q;
		// find nodes with 0 indegree
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		//start removing elmenents from the queue
		while (!q.empty()) {
			int node = q.front();
			cout << node << " " << endl;
			q.pop();

			//iterate over nbrs of that node, then reduce their indegreee
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

};