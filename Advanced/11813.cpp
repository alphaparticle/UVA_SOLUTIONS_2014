#include <bits/stdc++.h>
using namespace std ;
#define gc getchar
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
#define pb push_back
typedef long long LL ;
typedef pair < LL , int > li ;
typedef pair < int , LL > il ;
int test , n , m , s;
map < int , int > id ;
vector < il > adj [100010] ;
vector < int > store ;
LL dist [12][100010] ;
LL dp   [1<<12][12];

void dij( int s ){
  priority_queue < li , vector < li > , greater < li > > pq; 
  dist[ id[s] ][s] = 0;
  pq.push(li(0,s));
  while( !pq.empty() ){
      li u = pq.top() ; pq.pop() ;
      if( dist[id[s]][u.Q] == u.P )
      for( int i = 0 ; i  < adj[u.Q].size() ; i++){
      	 il v = adj[u.Q][i] ;
      	 if( dist[ id[s] ][v.P] > u.P + v.Q ){
      	 	dist[ id[s] ][v.P] = u.P + v.Q ;
      	 	pq.push( li(dist[ id[s] ][v.P] ,v.P ));
      	 }
      } 
  }

}

LL tsp ( int mask , int last){
	if( mask == (1<<s)-1 )
	return dist[id[store[last]]] [0];
    
    if( last == -1){
    	LL ans= 1e18 ;
    	for ( int i = 0 ; i < s ; i++)
    	if( !(mask&(1<<i)) )
    	ans = min ( ans , dist[0][store[i]] + tsp( mask|(1<<i) ,i) ) ;
        return ans ;
    } 

    if( dp[mask][last] != -1)
    return dp[mask][last] ; 


   LL ans =1e18 ;
   for ( int i = 0 ; i < s ; i++)
   if( !(mask&(1<<i)) ){
   	 ans = min ( ans ,  dist[id[store[last]]] [store[i]]  + tsp( mask|(1<<i ) , i) );
   }
  //cout << mask <<" "<<last <<" "<<ans<<endl;
   return dp[mask][last] = ans ;
}

int main(){
   int i , j , k, l, u ,v ; LL w;
   scanint(test);
   while( test--){
   	  scanint(n) ; scanint(m);
      for(  i = 0 ; i < n ; i++)
      adj[i].clear() ;
      for (  i = 0  ; i < m ; i++){
      	 scanint(u) ;scanint(v); scanf("%lld",&w) ;
      	 adj[u].pb(il(v,w)); adj[v].push_back(il(u,w));
      }
      scanint(s); store.clear() ; id.clear() ;
      id[0] = 0 ; 
      for ( i = 1 ; i <= s ;i++){
      	 scanint(u) ; store.push_back(u); id[u] = i ;
      	 //cout << u <<" : "<<id[u]<<endl;
      }
      for ( i = 0 ; i <= s ; i++)
      for ( j = 0 ; j <= n ; j++)
      dist[i][j] = 1e18 ;

      dij(0);
      for( i = 0 ; i < store.size() ; i++)
      dij( store[i] );
      /*
      for( i = 0 ; i <= s; i++){
      	 cout << i <<" -> ";
      	 for( j = 0 ; j <= n ; j++)
      	 cout<<j<<"("<< dist[i][j] <<") ";;
      	cout << endl;
      }
      */
      for ( i = 0 ; i <= (1<<s) ; i++)
      for( j = 0 ; j <= s ; j++)
      dp[i][j] = -1 ;

      LL ans = tsp (0, -1);
      printf("%lld\n",ans);
  }


	return 0;
}

/*
1
1
7 12
0 1 10
0 2 20
0 3 30
0 4 40
0 5 50
0 6 60
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 1 1
6
1
2
3
4
5
6
// -> 26
*/
