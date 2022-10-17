#include <vector>
#include <iostream>
using namespace std;

void traversNode(
    int i, int j, 
    vector<vector<int>>& matrix,
    vector<vector<bool>>& visited,
    vector<int>& sizes
);

vector<vector<int>> getNeighborNodes(
    int i, int j,
    vector<vector<int>>& matrix,
    vector<vector<bool>>& visited
);

vector<int> riverSizes(vector<vector<int>> matrix) {
  vector<int> sizes {};
  vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
  for (int i = 0; i < matrix.size();i++){
    for (int j = 0; j < matrix[i].size();j++){
        if (visited[i][j]) continue;

        traversNode(
            i,j,matrix,visited,sizes
        );
    }
  }

  return sizes;
}


void traversNode(
    int i, int j, 
    vector<vector<int>>& matrix,
    vector<vector<bool>>& visited,
    vector<int>& sizes
){
    vector<vector<int>> nodesToVisit {{i,j}};
    int riverSize = 0;

    while (nodesToVisit.size() != 0){
        vector<int> currNode = nodesToVisit.back();
        nodesToVisit.pop_back();

        int i = currNode[0];
        int j = currNode[1];

        if (visited[i][j]) continue;

        visited[i][j] = true;

        if (matrix[i][j] == 0) continue;

        riverSize++;

        vector<vector<int>> unvisitedNodes = getNeighborNodes(i,j,matrix,visited);

        for (vector<int> node : unvisitedNodes){
            nodesToVisit.push_back(node);
        }       
    }

    if (riverSize > 0) sizes.push_back(riverSize);
}


vector<vector<int>> getNeighborNodes(
    int i, int j,
    vector<vector<int>>& matrix,
    vector<vector<bool>>& visited
){
    vector<vector<int>> unvisitedNeighbors{};
    
    if (i > 0 && !visited[i-1][j] ) unvisitedNeighbors.push_back({i-1,j});
    if (i < matrix.size()-1 && !visited[i+1][j]) unvisitedNeighbors.push_back({i+1,j});

    if (j > 0 && !visited[i][j-1]) unvisitedNeighbors.push_back({i,j-1});

    if (j<matrix[0].size()-1 && !visited[i][j+1]) unvisitedNeighbors.push_back({i,j+1});

    return unvisitedNeighbors;
}