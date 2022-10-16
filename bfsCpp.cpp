#include <vector>
#include <string>
#include <queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    // Write your code here.
    
    queue<Node*> queueNodes;
    queueNodes.push(this);

    while (!queueNodes.empty()){
        Node* currNode = queueNodes.front();
        queueNodes.pop();

        array->push_back(currNode->name);
        
        for (Node* child : currNode->children){
            queueNodes.push(child);
        };
    }

    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
