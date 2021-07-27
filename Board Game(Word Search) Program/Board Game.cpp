#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define M 3
#define N 4


class Node {		//Trie node
public:
	char s;
	unordered_map<char, Node*>children;	//key=char, node*=value
	string word;
	bool isTerminal;

	Node(char s) {
		this->s = s;
		isTerminal = false;
		word = "";	//word will be uploaded only at the leaf node(used to store the word formed at the termial node)
	}

};

class Trie {
public:
	Node*root;
	Trie() {
		root = new Node('\0');

	}

	void AddWord(string word) {
		Node *temp = root;
		for (auto ch : word) {
			if (temp->children.count(ch) == 0) {	//if that charcater node does not exisits in the trie
				temp->children[ch] = new Node(ch);	//add a new node of that character
			}
			temp = temp->children[ch];	//if that character alreday exists move on to that charcater node
		}
		//now we are out of the loop that means it is the terminal node
		temp->isTerminal = true;
		temp->word = word;
	}





};
void dfs(char board[M][N], Node *node, int i, int j, bool visited[][N], unordered_set<string>&output) {
	//base case
	char ch = board[i][j];
	if (node->children.count(ch) == 0)	//if thetrie does not contain this particular trie return
		return;

	//otherwise if trie contains the node
	visited[i][j] = true;
	node = node->children[ch];

	//if the node is terminal node then
	if (node->isTerminal)
		output.insert(node->word);

	//exploring all the neighbours in the 8 directions
	int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

	int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1};

	for (int k = 0; k < 8; k++) {
		int new_i = i + dx[k];
		int new_j = j + dy[k];

		//if it is in boundary and not visited earlier
		if (new_i >= 0 and new_j >= 0 and new_i < M and new_j < N and !visited[new_i][new_j]) {
			dfs(board, node, new_i, new_j, visited, output);
		}
	}

	//backtraacking time
	visited[i][j] = false;
	return;

}

int main(void) {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string words[] = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};

	char board[M][N] = {{'S', 'E', 'R', 'T'},
		{'U', 'N', 'K', 'S'},
		{'T', 'C', 'A', 'T'}
	};

	//creating a trie
	Trie t;
	for (auto w : words) {
		t.AddWord(w);
	}

	// a container to insert the words that are present in the dfs search
	unordered_set<string>output;	//unordered_set data structure is used to avoid the duplicacy if sam word can be found out multiple times
	bool visited[M][N] = {0};
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			dfs(board, t.root, i, j, visited, output);

		}
	cout << "Words Found are=\n";
	for (auto word : output) {
		cout << word << "\n";
	}

}
