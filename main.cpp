#include<iostream>
using namespace std;

class graph{
	public:
	int cities,flights;
	int start,end,cost;
	graph(){
		cout<<"enter the no of cities: ";
		cin>>cities;
		cout<<"enter the no of flights:  ";
		cin>>flights;
	}
	int adj[5][5];
	int visited[10];
	
	void read();
	void connected_graph();
	void display();
	

	
};

void graph::read(){
	for(int i=0;i<cities;i++){
		for(int j=0;j<cities;j++){
			adj[i][j]=0;
		}
	}
	for(int i=0;i<cities;i++){
		visited[i]=0;
	}
	cout<<"enter start end cost\n";
	for(int i=0;i<flights;i++){
		cin>>start>>end>>cost;
		adj[start][end]=cost;
		adj[end][start]=cost;

	}
}
void graph::display(){
	cout<<"Adjancency Matrix\n";
	for(int i=0;i<cities;i++){
		for(int j=0;j<cities;j++){
			cout<<adj[i][j]<<"  ";
		}
		cout<<endl;
	}cout<<endl;
}

void graph::connected_graph(){
	cout<<"Path \n";
	for(int i=0;i<cities;i++){
		for(int j=0;j<cities;j++){
			if(adj[i][j]!=0 && visited[i]==0){
				cout<<i<<" to "<<j<<":"<<adj[i][j]<<"\n";
				visited[i]=1;
			}
		}
	}
	cout<<"\n";
	bool flag=false;
	
	for(int i=0;i<cities;i++){
		if(visited[i]!=1){
			cout<<"Not connected";
			flag=true;
			break;
		}
	}
	if(!flag){
		cout<<"Connected";
	}
	
}

int main(){
	graph b;
	b.read();
	b.display();
	b.connected_graph();
	
	return 0;
}



