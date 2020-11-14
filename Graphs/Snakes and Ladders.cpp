//Snakes and Ladders Problem.
// Starting From Source -> 0. Minimum Number of Dice Throws such that you could reach 36 and win the game.
// Also find the Shortest Distance.
template<typename T>
class GraphSnakesandLadders {

	map<T, list<T>> l; // if T is an Integer and a key, then it would become map<int,list<int>> l.
public:
	void addEdgeBfs(int x, int y) {
		l[x].push_back(y); //UniDirectional Edges
	}

	int bfs(T src, T dest) { // int src.
		// This code is for finding thr source node.
		// we need a queue and an array. One to store the output and the other to mark the array marked values.
		map<T, int> dist;
		map<T, T> parent;
		queue<T>q;

		for (auto node_pair : l) {
			T node = node_pair.first;
			dist[node] = INT_MAX;
		}

		parent[src] = src;
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
					parent[nbr] = node;
				}
			}
		}
		//print the dest to dest node
		T temp = dest;
		while (temp != src) {
			cout << temp << "<--";
			temp = parent[temp];
		}

		// print the distance to destinatio node
		for (auto node_pair : l) {
			cout << node_pair.first << " and dist " << dist[node_pair.first] << endl;
		}

		cout << src << " ";
		return dist[dest];
	}


};

int main() {


	//Input for Snake and Ladder Game
	int board[50] = {0};

	//Snakes and Ladders Respectively.
	board[2] = 13; // For this, it has a ladder which will take us to 13, which means there is and edge from 2-15. because 15-2 = 13. This is one of the main reasons. so there is and edge between 1-15 now
	// 1 = 1(Default) + 1(Dice)+ 13 (jump by the ladder). so 1-15 is an edge.
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -2;
	board[34] = -22; // All the Minuses are with Snakes rest all have ladders.

	//Add all edges to the graph
	GraphSnakesandLadders<int> a;
	for (int i = 0; i <= 36 ; i++) {
		for (int dice = 1; dice <= 6; dice++) {
			int j = i + dice;
			j += board[j];

			if (j <= 36) {
				a.addEdgeBfs(i, j);
			}
		}
	}
	a.addEdgeBfs(36, 36);

	cout << a.bfs(0, 36) << endl;


	int gcd1 = 5, lcm1 = 10;

	int product = gcd1 * lcm1;








	return 0;
}