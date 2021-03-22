

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


.........................
	CYCLE DETECTION
........................
	
void dfs ( int node,int parent )
{
    vis[node] =  true;
 
    for ( auto neighbour : adj[node] ) {
	    
        if ( !vis[neighbour] ) {
           if( dfs ( neighbour, node ) = true )
		   return true;
        }
      else {
	      if(child != parent ) return true;
        }

    }
    
	return false;
}



.........................
	IN/OUT TIME
........................
	
int timer = 1;	
void dfs ( int node )
{
    vis[node] =  true;
    in[node]	= timer++;
    for ( auto neighbour : adj[node] ) {
           // cout<<v<<" "<<adj[node].size()<<endl;
        if ( !vis[neighbour] ) {
            dfs ( neighbour );
        }
    }
 out[[node]=timer++;
}
  
     
     
.........................
 LONGEST PATH IN A TREE
........................
     
 vi v[10001];
int vis[10001];
int maxD,maxNode;
void dfs (int node, int d){
    vis[node]=1;
    if(d > maxD)maxD = d, maxNode = node;

    for(int neighbor : v[node])
    if(!vis[neighbor])
        dfs(neighbor, d+1);
}
 
int main(){
	//here the function is called 2 time
	//first time search the desire node
	//second time search the distance
	maxD=-1;
	dfs(1,0);
	for(int i=0;i<n;i++)vis[i]=0;
	maxD=-1;
	dfs(maxNode,0);
	
}
