#include <bits/stdc++.h>
using namespace std ;
#define P first
#define Q second
#define pb push_back
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
typedef pair < int , int > ii ;
vector < ii > adj [11111] , adj2[11111] ;
int dis [11111] ;
int n , m ,s , t , p ;
int d [11111] ;

int dij1(){
   dis[s] = 0 ;
   
   priority_queue < ii , vector < ii > , greater <ii> > pq ;
   pq.push(ii(0,s)) ;
   while ( !pq.empty() ){
   	  ii u = pq.top() ;pq.pop();
   	  if( dis[u.Q] == u.P )
   	  for ( int i = 0 ; i < adj[u.Q].size() ; i++)
   	  {
   	  	 ii v = adj[u.Q][i] ;
   	  	 if( dis[v.P] >  dis[u.Q] + v.Q ){
   	  	 	 dis[v.P] = dis[u.Q] + v.Q ;
   	  	 	 pq.push(ii(dis[v.P] , v.P));
   	  	 }
   	  }
   }
  return dis[t] ;
}

void dij2(){
   d[t] = 0 ;
   priority_queue < ii , vector < ii > , greater <ii> > pq ;
   pq.push(ii(0,t)) ;
   while ( !pq.empty() ){
   	  ii u = pq.top() ;pq.pop();
   	  if( d[u.Q] == u.P )
   	  for ( int i = 0 ; i < adj2[u.Q].size() ; i++)
   	  {
   	  	 ii v = adj2[u.Q][i] ;
   	  	 if( d[v.P] >  d[u.Q] + v.Q ){
   	  	 	 d[v.P] = d[u.Q] + v.Q ;
   	  	 	 pq.push(ii(d[v.P] , v.P));
   	  	 }
   	  }
   }
  
}


void solve(){
	int i , j, u , v , w;
	scanint(n);scanint(m);scanint(s);scanint(t);scanint(p);
	for ( i = 0 ; i <= n ; i++)
	adj[i].clear() , adj2[i].clear()  ;
   
    for ( i = 0 ; i < m ; i++){
    	 scanint(u);scanint(v);scanint(w);
    	 adj[u].pb(ii(v,w)) ;
    	 adj2[v].pb(ii(u,w)) ;
    }

    for ( i = 0 ; i <= n ; i++ )
    dis[i] = d[i] =  1e9 ;
     int ans = dij1();
    if( ans <= p)
    {   
    	dij2() ;
    	ans = 0 ;
    	for ( i = 1 ; i <= n ; i++)
    	for ( j = 0 ;  j < adj[i].size() ; j++){
    	    ii v = adj[i][j] ;
    	    if( dis[i] + v.Q + d[v.P] <= p)
    	    ans = max( ans , v.Q) ;
    	}
    	printf("%d\n",ans) ;
    }
else
	puts("-1") ;
}

int main(){
   int test ;
  scanint(test) ;
    while ( test-- ){
   	 solve() ;
    }
	return 0;
}

/*
sample test

1
9 14 1 5 14
1 2 1
1 6 11
1 7 11
2 3 2
6 2 2
6 4 11
3 4 8
4 5 1
10 4 11
10 5 11
9 10 11
9 3 11
7 9 11
7 3 11
ans : 8

1
8 9 1 5 26
1 2 1
2 3 2
3 4 3
4 5 4
1 6 5
6 7 6
7 8 7
8 5 8
6 2 30
ans: 8

1
8 9 1 5 26
1 2 1
2 3 2
3 4 3
4 5 4
1 6 5
6 7 6
7 8 7
8 5 8
6 2 9
ans: 9

*/
