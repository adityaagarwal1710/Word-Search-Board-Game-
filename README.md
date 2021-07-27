# Word-Search-Board-Game-
This Board word search game uses Tries+DFS Algorithm+Backtracking+Graph to search given wods from a M*N matrix fill of jumbeled alphabets. Tries are used to control the search direction and limit it. 

Trie are used to store all the words that have to be found out in the board matrix of size(MxN).
Trie is also used to control the search parameter while using 8 way DFS.
We are also maintaining a boolean matrix to store which elements or word are visited that will help in DFS search algorithm.
Output array is used to store the words that have been found out from the board matrix.
