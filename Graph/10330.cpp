#include <bits/stdc++.h>
using namespace std;
#define MAXV 205
int res [MAXV][MAXV] ;

int s , t , mf , f ;
int n , m , b , d ;
vector < int> p;
void out(){
	cout << endl;
	 for(int i = 1 ;i <= t ;i++){
	 	 for(int j = 1 ; j <= t ; j++)
	 	 cout << res[i][j]<<" ";
	 	cout << endl;
	 }
}
void augment ( int v ,int minedge){ if( p[v] == -1){ f=  minedge; return ;}
      else{ augment(p[v] , min(minedge,res[p[v]][v]) );
          res[p[v]][v] -= f;
          res[v][p[v]] += f;
       }
}
void maxflow(){
	f =mf = 0 ;
	while(1){
		p.assign(t+1,-1);
		bitset<MAXV> vis ; queue<int> q ; vis.set(s); q.push(s);
		while(!q.empty()){ int u = q.front(); q.pop(); if( u == t)break;
               for( int i = 1 ; i<= t ; i++)
               if( !vis.test(i) && res[u][i] > 0){
               	 q.push(i) ; vis.set(i);p[i]=u;
               }
		}
		augment(t,1e9 );
		//cout <<"->"<<f<<endl;
		if( f== 0 || f == 1e9){ break ;}
		mf += f;
	}
}
int main(){
  int i , j, k, l;
  while( scanf("%d",&n) != EOF ){
  	  s = 1 ;
      memset ( res , 0 ,sizeof res);
      for ( i = 1 ; i <= n ; i++){
      	 scanf("%d",&j);
      	 res[2*i][(2*i) + 1] = j ;
      }
      scanf("%d",&m);
      while ( m--){
      	 scanf("%d %d %d", &i , &j ,&k);
      	 res[2*i + 1][2*j] = k;
      }
      scanf("%d %d",&b,&d);
      while(b--){
      	scanf("%d",&i); res[1][2*i] = 1e6 ;
      }
      t = 1+2*n+1 ;
      while(d--){
      	scanf("%d",&i); res[2*i+1][t] = 1e6 ;
      }
      //out();
      maxflow();
      //out();
      printf("%d\n",mf);
  }
  return 0;
}
