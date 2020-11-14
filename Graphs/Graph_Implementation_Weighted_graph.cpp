//For a Weighted Graph
class Graph1 {

	// Adj List.
	unordered_map<string, list<pair<string, int>>> l;
public:

	void addEdge1(string x, string y, bool bidir, int wt) {

		l[x].push_back(make_pair(y, wt));
		if (bidir) {
			l[y].push_back(make_pair(x, wt));
		}

	}

	void printAdjList1() {
		//iterate over all the keys in map.
		for (auto p : l) {
			// I Will get the key,value pair for every key that is being iterated.

			string city = p.first;
			list<pair<string, int>> nbrs = p.second;


			cout << city << "->";
			for (auto nbr : nbrs) {
				string dest = nbr.first;
				int dist = nbr.second;

				cout << dest << " " << dist << ",";
			}
			cout << endl;
		}
	}

};


int main() {

	Graph1 b;
	b.addEdge1("A", "B", true, 20);
	b.addEdge1("B", "D", true, 40);
	b.addEdge1("A", "D", false, 50);
	b.addEdge1("C", "D", true, 40);
	b.addEdge1("A", "C", true, 10);
	b.printAdjList1();

	return 0;
}