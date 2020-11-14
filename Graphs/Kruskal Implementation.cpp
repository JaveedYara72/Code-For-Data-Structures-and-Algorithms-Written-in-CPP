//Kruskal's Algorithm
// Implament DSU Data Structure
// Do it By Path Comprerssion + Union By Rank
class DSU {

	int* parent;
	int* rank;

public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];

		//parent = -1 and rank  = 1. Intiially, Rank is esentially the size of each set
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find Function
	int find(int i) {
		//base case
		if (parent[i] == -1) {
			return i; // THis is the parent, Other wise
		}
		return parent[i] = find(parent[i]);
	}


	//Unite (union) Function
	// THis is the code for Union function Using DSU Data Structure
	void Unite(int x, int y) {
		int s1 = find(x); // Find the set to which x belongs
		int s2 = find(y); // Find the set to which x belongs

		if (s1 != s2) {
			//union by rank
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}

		}

	}

};


class GraphKruskal {
	vector<vector<int>> edgeList;
	int V;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x, int y, int w) {
		edgeList.push_back(w, x, y);
		// Why is weight here first?
		// Because when we call the sort Function, it is gonna sort it on the basis of Weight
		// So it is gonna make our Job Easy While selecting the Edges.
	}

	int kruskal_mst() {
		//Main Logic
		//First step is to sort all the edges based on weight

		sort(edgeList.begin(), edgeList.end());

		//Initialise a DSU
		DSU s(V);

		int ans = 0;
		for (auto edge : edgeList) { // We are Gonna Iterate Over X and Y. So For Every Vector, there is a vector inside which holds all three information of w,x,y.
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			// edge is just an iterator over the vector that we have created.

			//Take that edge in MST, if it does not form a Cycle.
			if (s.find(x) != s.find(y)) { // Check if Both of these are connected earlier, if not then connect them and add their weight to the answer.
				s.Unite(x, y);
				ans += w;
			}
		}
		return ans;
	}

};

int main() {


	int n, m;
	cin >> n >> m;

	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w); //Zero Based Implementation, that means we are gonna have our operations doing satrting from the 0th Index.
	}

	cout << g.kruskal_mst() << endl;




}