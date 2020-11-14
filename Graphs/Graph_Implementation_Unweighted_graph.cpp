// Graphs
// Find Number of Vertices
//and then build on the adjacency List.

class Graph {
	int V;

	//Array of List.
	list<int> *l; // We Would know about the l Only in the Run Time.
	//
public:
	Graph(int V) {
		this->V = V; //  These are the Number of Vertices that are set.
		l = new list<int>[V]; // l is a pointer to an array of lists. l[0] points out to the first linked list
	}

	void addEdge(int x, int y) {
		//Assume that it is a bi directional Edge
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void printAdjList() {
		//Iterate over the Vertices.
		for (int i = 0; i < V; i++) {
			cout << "Vertex " << i << "->";
			for (int x : l[i]) {
				cout << x << " ";
			}
			cout << endl;
		}
	}


};


int main() {

	Graph g(4); //Calling Constructor, with 4 Vertices.
	g.addEdge(0, 1); //Assuming all the Edges are bi Directional
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3); // Connecting as the One Drawn in Notebook.
	g.printAdjList();
}