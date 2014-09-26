#include <bits/stdc++.h>
using namespace std ;

map < string , int > plug ;
map < string , int > device ;

vector < int > adj[510] ;

int res [510][510] ;
int s ,  t , f , mf ; 
vector < int > p ;
void augment (int v ,int e){ if(p[v] == -1){ f = e ; return; }
     else{
       augment( p[v] , min(e , res[p[v]][v]));
       res[p[v]][v] -= f; res[v][p[v]] += f ;
     }
}

void maxflow (){
  f = mf = 0 ; 
  while(1){
     bitset<510>vis ; vis.set(s) ; p.assign(t+1,-1) ; queue<int>q ; q.push(s); f =0;
     while(!q.empty()){ int u = q.front(); q.pop() ; if(u == t)break ;
            for ( int i = 0 ; i < adj[u].size() ; i++){
              int v = adj[u][i];
              if( !vis.test(v) && res[u][v] > 0){
                q.push(v) ; p[v] = u ; vis.set(v) ;
              }
            }
     }
  augment(t,1e9); if( f == 0 || f == 1e9 ){ break ; }
  mf += f;
  }
}

int main(){
  int test ,N ,M ,K , i, j ;
  int n , m  ,u , v; 
  string a , b  ;
   scanf("%d", &test);
   while ( test-- ){ 
       scanf("%d", &N) ;
       plug.clear() ;
       for( i = 0 ; i <= 505 ; i++)
       adj[i].clear() ;
       n = 101; s = 0 ; t = 505 ;
       memset ( res , 0 ,sizeof res) ; 

       for ( i = 0 ; i < N ; i++){
          cin >> a ;
          if( plug.count(a) == 0)
          plug[ a ] = n++ ;
         u = plug[ a ] ;
         adj [ u ] . push_back ( t ) ; adj[t].push_back(u) ;
         res [ u ] [ t ] = 1 ;
       }

       device.clear() ;
       scanf("%d", &M) ;
       m = 1 ;
       for ( i = 0 ; i < M ;i ++){
         cin >> a >> b ;
         if( plug.count(b) == 0)
         plug[b] = n++ ;
         if( device.count(a) == 0)
         device[a] = m++;
          u = device [a] ;
          v = plug[b] ;
         adj [s] .push_back ( u ) ; 
         adj [u] .push_back ( s ) ;
         res[s][u] = 1 ;
         adj [u].push_back (v); adj[v].push_back(u) ; 
         res[u][v] = 1 ; 
       }
       scanf("%d", &K);
       for ( i= 0 ; i < K ; i++){
         cin >> a >> b ;
         if( plug.count(a) == 0)
         plug[a] = n++;
         if( plug.count(b) == 0)
         n++ ;
         u = plug[a] ; v = plug[b] ;
         adj[u].push_back(v) ; adj[v].push_back(u) ;
         res[u][v] = 1e5 ;
       }
      maxflow() ;
   //  cout << device.size() <<" "<<plug.size() << " "<<adj[t].size() << endl;
   //  cout << mf << endl;
      printf("%d\n", (int)device.size() - mf) ;
      if(test)
      printf("\n");
   }
  return 0;
}
