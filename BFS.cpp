 #include <iostream>
#include <list>

using namespace std;

class Graph
 {
  int numV;
  list<int>* adjL;
  bool* number;

   public:
  Graph(int vertices);
  void addEdge(int u, int v);
  void BFS(int a);
};


Graph::Graph(int vertices) 
{
  numV = vertices;
  adjL = new list<int>[vertices];
}


void Graph::addEdge(int u, int v)
{
  adjL[u].push_back(v);
  adjL[v].push_back(u);
}


void Graph::BFS(int a)
{
  number = new bool[numV];
  for (int i = 0; i < numV; i++)
    number[i] = false;

  list<int> queue;

  number[a] = true;
  queue.push_back(a);

  list<int>::iterator i;

  while (!queue.empty()) 
  {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjL[currVertex].begin(); i != adjL[currVertex].end(); ++i)
     {
      int adjVertex = *i;
      if (!number[adjVertex])
       {
        number[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() 
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}