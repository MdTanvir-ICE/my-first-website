

.........................
	  DFS
........................

const int mx = 1e5+123;
bool vis[mx];
vector<int> adj[mx];
//dfs function
void dfs ( int node )
{
    vis[node] =  true;
    for ( auto neighbour : adj[node] ) {
           // cout<<v<<" "<<adj[node].size()<<endl;
        if ( !vis[neighbour] ) {
            dfs ( neighbour );
        }
    }
 
}

.........................
	  DISTANCE
........................
const int mx = 1e5+123;
bool vis[mx];
int dis[mx];
vector<int> adj[mx];

void dfs ( int node,int dist )
{
    vis[node] =  true;
    dis[node]=dist;
    for ( auto neighbour : adj[node] ) {
        if ( !vis[neighbour] ) {
          //  cout<<"First"<<" "<<neighbour<<endl;
            dfs ( neighbour, dis[node]+1 );
           // cout<<"Second"<<" "<<neighbour<<endl;
        }
    }

}


.........................
	  BIPARTITE
........................
const int mx = 1e5+123;
bool vis[mx];
int col[mx];
vector<int> adj[mx];

bool dfs ( int node,int c )
{
    vis[node] =  true;
    col[node]=c;
    for ( auto neighbour : adj[node] ) {
        if ( !vis[neighbour] ) {

          bool res =  dfs ( neighbour, c ^ 1);
           if(res == false) return false;
        }
        else {
            if(col[node]==col[neighbour])return false;
        }
    }
    return true;

}
