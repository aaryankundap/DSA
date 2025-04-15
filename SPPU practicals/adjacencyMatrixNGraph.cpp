#include<iostream>
using namespace std;

class graph
{
    public:
    int flights, cities, cost, i, j;
    int start, end;
    string city[10];
    graph()
    {
        cout << "Enter number of cities: ";
        cin >> cities;
        cout << "Enter number of flights: ";
        cin >> flights;
        
        for(int i = 0; i < cities; i++)
        {
            cout << "Enter name of city " << i + 1 << ": ";
            cin >> city[i];
        }
    }

    int adj_mat[10][10], visited[10];
    void read();
    void display();
    void connected_graph();
    void dfs(int node);
};

void graph::read()
{
    for(int i = 0; i < cities; i++)
    {
        for(int j = 0; j < cities; j++)
        {
            adj_mat[i][j] = 0;
        }
    }

    for(int i = 0; i < flights; i++)
    {
        visited[i] = 0;
        cout << "Enter Starting Point (city number starting from 0): ";
        cin >> start;
        cout << "Enter End Point (city number starting from 0): ";
        cin >> end;
        cout << "Enter Cost of Flight: ";
        cin >> cost;
        
        adj_mat[start][end] = cost;
        adj_mat[end][start] = cost;
    }
}

void graph::display()
{
    cout << "Adjacency Matrix:\n";
    cout << "\t";
    for(int i = 0; i < cities; i++)
    {
        cout << city[i] << "\t";
    }
    cout << "\n";
    for(int i = 0; i < cities; i++)
    {
        cout << city[i] << "\t";
        for(int j = 0; j < cities; j++)
        {
            cout << adj_mat[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void graph::dfs(int node)
{
    visited[node] = 1;
    for(int i = 0; i < cities; i++)
    {
        if(adj_mat[node][i] != 0 && !visited[i])
        {
            dfs(i);
        }
    }
}

void graph::connected_graph()
{
    for(int i = 0; i < cities; i++)
    {
        visited[i] = 0;
    }

    dfs(0);

    for(int i = 0; i < cities; i++)
    {
        if(visited[i] == 0)
        {
            cout << "Graph is not connected.\n";
            return;
        }
    }
    cout << "Graph is connected.\n";
}

int main()
{
    graph g;
    g.read();
    g.display();
    g.connected_graph();
    return 0;
}























