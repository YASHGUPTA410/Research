#include<bits/stdc++.h>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;   // Pointer to an array containing adjacency lists
      
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);    // function to add an edge to graph
    void BFS(int s);    // prints BFS traversal from a given source s
};
 
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::BFS(int s){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
    vector<int>sizes;
    vector<int>bfs;
    int level=0;
    while(!queue.empty())
    {
        level++;
        int size=queue.size();
        sizes.push_back(size);
        while(size--)
        {
            // Dequeue a vertex from queue and print it
            s = queue.front();
            cout << s << " ";
            bfs.push_back(s);
            queue.pop_front();
     
            // Get all adjacent vertices of the dequeued vertex s. 
            // If a adjacent has not been visited, then mark it visited and enqueue it
            for (i = adj[s].begin(); i != adj[s].end(); ++i){
                if (!visited[*i]){
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
    cout<<"\n";
    cout<<"Number of nodes at each level : ";
    for(int i=0;i<sizes.size();i++){
        cout<<sizes[i]<<" ";
    }
    cout<<"\n";
    
    int sum=0;
    for(int i=0;i<sizes.size();i++){
        sum+=sizes[i];
        if(sizes[i]>=bfs.size()/2){
            int k=sum-sizes[i];
            cout<<"Median Center : "<<bfs[k-1]<<"\n";
            break;
        }
    }
    /*
    int d=0;
    int v=4;
    while(d<v){
        int count=size[d];
        if(count>=(v/2){
            return 
        }
    }
    */
}
 

int main()
{
    int v=4; // Number of vertices
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
 
    for(int i=0;i<v;i++){
        cout<<"BFS Traversal from vertex "<<i<<" : ";
        g.BFS(i);
        cout<<"\n";
        cout<<"\n";
    }
    return 0;
}