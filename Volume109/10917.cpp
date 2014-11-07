#include <bits/stdc++.h>
using namespace std ;
#define gc getchar_unlocked
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
// double st = clock() ;
//cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;
#define P first
#define Q second
typedef pair < int , int > ii ;
vector < ii > adj [1111] ;
int dist [1111] ;
int dp [1111] ;
int n , m ;
void dij(){
  priority_queue < ii , vector  < ii  > , greater <ii> > pq ;
  dist[2] = 0 ;
  pq.push(ii(dist[2],2));
  while( !pq.empty() ){
  	  ii t = pq.top() ; pq.pop();
  	  if( dist[t.Q] == t.P){
          for ( int i = 0 ; i < adj[t.Q].size() ; i++)
          {
          	 ii v = adj[t.Q][i];
          	 if( dist[v.P] > dist[t.Q] + v.Q ){
          	 	 dist[v.P] = dist[t.Q] + v.Q ;
          	 	 pq.push(ii(dist[v.P],v.P)) ;
          	 }
          }
  	  }
  } 
}

int topdown( int node ){
  if( dp[node] != -1)
  return dp[node];
  if( node == 2)
  return 1 ;
  int ans = 0 ;
  for(int i = 0 ; i < adj[node].size() ; i++){
      ii v = adj[node][i];
      if( dist[v.P]  < dist[node]  )
      ans += topdown(v.P) ;
  }
  return dp[node] = ans ;
}

int main(){
	int i , j, k , u , v , w ;
    while(1){
    	 scanint(n); if( n == 0) break ;
    	 scanint(m);
    	 for( i = 0 ; i <= n ; i++)
    	 adj[i].clear() , dist[i] = 1e9 , dp[i] = -1;
         for ( i = 0 ; i < m ; i++){
         	 scanint(u) ; scanint(v)  ; scanint(w);
         	 adj[u].push_back(ii(v,w));
         	 adj[v].push_back(ii(u,w));
         }
    	 dij();
    	 int ans = topdown(1);
    	 printf("%d\n",ans);
    }
    
	return  0;
}
