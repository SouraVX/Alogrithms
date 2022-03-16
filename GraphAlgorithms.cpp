#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void dfsRecursive(T Node, unordered_map<T, vector<T>> &Graph,
                  unordered_set<T> &VisitedSet, stack<T> &Stack) {
  if (VisitedSet.find(Node) != VisitedSet.end())
    return;
  VisitedSet.insert(Node);
  auto Neighbours = Graph.find(Node)->second;
  for (auto Neighbour : Neighbours)
    if (VisitedSet.find(Neighbour) != VisitedSet.end())
      dfsRecursive(Neighbour, Graph, VisitedSet, Stack);
  Stack.push(Node);
}

template <typename T> void topologicalSort(unordered_map<T, vector<T>> &Graph) {

  unordered_set<T> VisitedSet;
  stack<T> Stack;
  for (auto Node : Graph)
    dfsRecursive(Node.first, Graph, VisitedSet, Stack);
  vector<T> topologicalOrder;
  while (!Stack.empty()) {
    topologicalOrder.push_back(Stack.top());
    Stack.pop();
  }
  cout << "Topological Sort: ";
  for (auto &x : topologicalOrder)
    cout << x << "\t";
  cout << "\n";
}

template <typename T>
bool isConnenctedComponentIterative(T Node, unordered_map<T, vector<T>> &Graph,
                                    unordered_set<T> &VisitedSet) {

  if (VisitedSet.find(Node) != VisitedSet.end())
    return false;
  VisitedSet.insert(Node);
  stack<T> Stack;
  Stack.push(Node);
  T Key;
  while (!Stack.empty()) {
    Key = Stack.top();
    Stack.pop();
    for (auto x : Graph.find(Key)->second) {
      if (VisitedSet.find(x) != VisitedSet.end())
        continue;
      VisitedSet.insert(x);
      Stack.push(x);
    }
  }
  return true;
}

template <typename T>
bool isConnenctedComponentRecursive(T Node, unordered_map<T, vector<T>> &Graph,
                                    unordered_set<T> &VisitedSet) {

  if (VisitedSet.find(Node) != VisitedSet.end())
    return false;
  VisitedSet.insert(Node);
  for (auto x : Graph.find(Node)->second)
    isConnenctedComponentRecursive(x, Graph, VisitedSet);
  return true;
}

template <typename T>
int connectedComponentsCount(unordered_map<T, vector<T>> &Graph) {
  int Count = 0;
  unordered_set<T> VisitedSet{};
  for (auto Node : Graph)
    if (isConnenctedComponentRecursive(Node.first, Graph, VisitedSet))
      Count++;
  return Count;
}

template <typename T> void printGraph(unordered_map<T, vector<T>> &Graph) {
  cout << "Input Graph:\n";
  for (auto x : Graph) {
    cout << x.first << ": [";
    for (auto y : x.second)
      cout << y << ", ";
    cout << " ]\n";
  }
}
