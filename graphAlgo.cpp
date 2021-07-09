

.........................
	  DFS
.........................

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
	2D  DFS
.........................
int vis[1001][1001];
int ara[1001][1001];
int n,m;

bool isValid (int x, int y){
    if(x < 1 || x>n || y<1 || y>m)return false;

    if(vis[x][y]== true || ara[x][y]==false)return false;

    return true;
}

int dx[ ] ={-1,0,1,0};
int dy[ ] ={0,1,0,-1};
void dfs( int x , int y){


 vis[x][y] = 1;

 cout<<x<<" "<<y<<endl;

   for(int i=0;i<4;i++){
     if(isValid(x+dx[i], y+dy[i]))
     dfs( x+dx[i], y+dy[i] );
    }
   
}

int main( ){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ara[i][j];
        }
    }
    int cc = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]==false&&ara[i][j]==true){
                dfs(i,j),cc++;
            }
        }
    }
    cout<<"CC "<<cc<<endl;
   
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
https://cp-algorithms.com/graph/finding-cycle.html
	
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
	for find the sub tree
	
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

     
 .........................
	  BFS
..........................
vector<int> ar[10001];
int vis[10001],dist[10001];

void BFS(int src){
    queue<int> q;
    q.push(src);
    dist[src] =0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto neighbour : ar[cur]){
            if(!vis[neighbour]){
                q.push(neighbour);
                dist[neighbour]=dist[cur]+1;
                vis[neighbour] = 1;
            }
        }
    }
}
     
.........................
	  2D BFS
..........................
     
int dist[1001][1001];
int n,m;
int vis[1001][1001];

bool isValid(int x, int y){
    if(x<1 || x > n || y < 1 || y>m)return false;
    if(vis[x][y]==1)return false;

    return true;
}
int dx[ ] = {-1, 0, 1, 0};
int dy[ ] = {0, 1, 0, -1};

void bfs(int srcX, int srcY){

    queue< pair<int,int> > q;

    q.push({srcX, srcY});
    vis[srcX][srcY] =1;
    dist[srcX][srcY] =0;

   while(!q.empty()){
       int currX = q.front().first;
       int currY = q.front().second;
       q.pop();
    
       for(int i=0;i<4;i++){   
            if(isValid(currX+dx[i],currY+dy[i])){
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                
                q.push({newX,newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1;
             }
        }

    }

      cout<<"distance array\n";
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++)
              cout<<dist[i][j]<<" ";

              cout<<endl;

      }

}

int main(){
    int x,y;
    cin>>n>>m;
    cin>>x>>y;
    bfs(x,y);
}
     
 .........................
	 Dijkstra
..........................
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<pii>vii;
typedef vector<pll>vll;
const int mx = 1e5+123;
vii adj[mx];
ll dist[mx];

void dijkstra (int src, int n){
    for(int i = 0; i <= n; i++ )dist[i]=9e6;
    dist[src] = 0;
   cout<<"i am call"<<endl;
    priority_queue < pii, vii, greater<pii> >pq;
    pq.push({src,0});

    while(!pq.empty()){
        int u = pq.top().first;
        int curD = pq.top().second;
        pq.pop();

        if( dist[u]< curD ) continue;

        for(auto child : adj[u]){
            int v = child.first;
            int w = child.second;

            if(curD + w < dist[v]){
                dist[v] = curD+w;
                pq.push({v,dist[v]});


            }

        }
    }

}

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    dijkstra(1,n);
    for(int i=0; i<=n; i++)cout<<dist[i]<<" ";
    cout<<endl;

}

