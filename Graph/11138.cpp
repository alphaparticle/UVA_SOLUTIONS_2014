#include <bits/stdc++.h>
using namespace std ; 
#define MAXV 1011
int res [MAXV][MAXV] ;
int s , t , f , mf ,test , bolts , nuts;

typedef vector < int > vi ;
vector  < vi > adj ;
vi parent ;
void augment ( int v , int minedge){
	if( parent[v] == -1){ f= minedge ; return ;}
	else{ augment(parent[v] , min(minedge , res[parent[v]][v]) );
      res[ parent[v] ][v] -= f ;
      res[v][ parent[v] ] += f ;
	 }
}

void maxflow(){
	f = mf =0 ;
	while (1){ f = 0 ; parent.assign(t+1,-1) ;
		bitset<MAXV> vis ; vis.set(s) ; queue<int>q; q.push(s) ;
		while(!q.empty()){ 
             int u = q.front() ; q.pop() ;if( u == t){ break ;}
             for ( int i = 0 ; i < adj[u].size() ; i++)
             if( !vis.test(adj[u][i]) && res[u][adj[u][i]] ){
              parent[adj[u][i]]=u; vis.set(adj[u][i]) ; q.push(adj[u][i]) ;
             }
		}
		augment(t,1e9); if( f == 0 || f == 1e9){ break ;}
		mf += f ;
	}
}
int main(){
 int x ;
 adj.assign(MAXV,vi()) ;
 scanf("%d",&test);
 for( int kase = 1 ; kase <= test ; kase++){
 	scanf("%d %d",&bolts,&nuts) ; 
 	s = 0 ; t = nuts+bolts+1 ;
 	for( int i = 0 ; i <= t ; i++)
 	for( int j = 0 ; j <= t ; j++)
 	res[i][j] = 0 ;
    
    for (int i = 0 ; i <=t  ;i++ )
    adj[i].clear() ;
    for ( int i = 1 ; i <= bolts ; i++)
    for ( int j = bolts+1 ; j < t ; j++){
           scanf("%d",&x) ;
           if( x == 1 ){
           	 adj[i].push_back(j);
           	 adj[j].push_back(i) ; res[i][j]  = 1 ;
           }
    }
    for (int i = 1 ; i <= bolts ; i++)
    adj[s].push_back(i), adj[i].push_back(s),res[s][i] =  1 ;
    for (int i = bolts+1 ; i < t ; i++)
    adj[i].push_back(t),adj[t].push_back(i),res[i][t] = 1 ;
    maxflow() ;
    printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n",kase , mf) ;
 }

	return 0 ;
}
