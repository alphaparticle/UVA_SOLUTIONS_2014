#include <bits/stdc++.h>
using namespace std ;
#define P first
#define Q second
#define pb push_back
typedef pair < int , string > is ;
typedef pair < string , string > ss ;
typedef pair < is , ss > isss ;

vector < isss > men , women ;
vector < int > adj [510] ;
vector < int > owner , vis ;
int test , cc , n , m , pupil ;

int mcbm ( int u ){
	if(vis[u]) return 0;
	vis[u] =true ;
	for( int i = 0 ; i < adj[u].size() ; i++){
		 int v = adj[u][i] ;
		 if( owner[v] == -1 || mcbm(owner[v])){
		 	owner[v] = u ; return 1 ;
		 }
	}
  return 0  ;
}

int main(){
	cin.sync_with_stdio(0) ; cin.tie(0) ;
	int i , j, k, l ;
	string sex , music , sport ;
     cin >> test ;
     while ( test-- ){
     	 men.clear() ; women.clear();
     	 cin >> pupil ;
     	 for ( i = 0 ; i < pupil ; i++){
     	 	 cin >> j >> sex >> music >> sport ;
     	 	 if( sex == "M" )
     	 	 men.push_back(isss(is(j,sex),ss(music,sport))) ;
     	 	else
     	 	women.push_back( isss(is(j,sex),ss(music,sport)));
     	 }
     	n = men.size() ; m = women.size() ;
     	cc = 0 ;
     	//cout << n <<" "<<m << endl;

     	for ( i = 0 ; i <= n+m+1 ; i++)
     	adj[i].clear() ;
        
        for ( i = 0 ; i < n ; i++){
             isss u = men[i] ;
	         for ( j = 0 ; j < m ; j++){
	         	isss v = women[j] ;
	         	if( abs(u.P.P-v.P.P) <= 40 && u.Q.P == v.Q.P && u.Q.Q != v.Q.Q )
	         	adj[i].push_back(n+j), adj[n+j].push_back(i);
	         }
        }	
     	owner.assign ( n+m+1 ,-1) ; 
     	for ( i = 0 ; i < n ; i++){
     		 vis.assign(n+m+1,0) ;
     		 cc += mcbm(i) ;
     	}
       cout << n+m-cc <<"\n" ;
     }

	return 0 ;
}
