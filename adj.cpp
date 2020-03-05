#include<iostream>
#include<queue>
#include<stack>
// Name : Vivek S. Sharma
using namespace std;
class Graph{
	int g[10][10];
	int v[10];
	int n,e;
public:
	void create(){
		int v1,v2;
		cout<<"\nEnter no. of vertices : ";
		cin>>n;
		cout<<"\nEnter no. of edges : ";
		cin>>e;
		for(int i=1; i<=n ; i++){
			for(int j=1; j<=n ; j++){
				g[i][j]=0;
				v[i]=0;
			}
		}
		for(int i=1; i<=e ;i++ ){
			cout<<"\nEnter the edge : ";
			cin>>v1>>v2;
			g[v1][v2]=g[v2][v1]=1;
		}
	}
	void bfs(){
		int v1,v2;
		cout<<"\nEnter the starting vertex : ";
		cin>>v1;
		queue<int> q;
		q.push(v1);
		v[v1]=1;
		while(!q.empty()){
			v1=q.front();
			q.pop();
			cout<<v1;
			for( v2=1; v2<=n ; v2++){
				if(g[v1][v2]==1 && v[v2]==0){
					q.push(v2);
				v[v2]=1;}
			}

		}
	}

	void dfs(){
		int v1,v2;
		cout<<"\nEnter starting vertex : ";
		cin>>v1;
		stack <int> s;
		s.push(v1);
		while(!s.empty()){
			v1=s.top();
			s.pop();
			if(v[v1]==0){
				cout<<v1;
				v[v1]=1;
			}
			for(v2=1; v2<=n ; v2++){
				if(g[v1][v2]==1 && v[v2]==0)
					s.push(v2);
			}
		}
	}
	void dfs_recurssion(int v1){

		int v2;
		cout<<v1;
		v[v1]=1;
		for( v2=1; v2<=n ; v2++){
			if(g[v1][v2]==1 && v[v2]==0)
				dfs_recurssion(v2);
		}
	}
};

int main(){
Graph g;
int v;
g.create();
/*cout<<"\nEnter the starting vertex : ";
cin>>v;
g.dfs_recurssion(v);
//g.dfs();*/
g.bfs();
return 0;
}

