#include <bits/stdc++.h>
using namespace std ;

#define MAXV 105
int res [MAXV][MAXV] ;
int s , t , mf , f ,  M , W ;
vector < int > p ;

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
	int i , j, k, l,c;
    while ( scanf("%d %d",&M ,&W)){
    	if( M == 0 && W == 0)
    	break ;
       s = 3; t = 2*M ;
       memset ( res , 0, sizeof res);
       for ( i = 0 ; i < M-2 ; i++){
       	 scanf("%d  %d",&j , &c);
       	 res[2*j][2*j+1] = c ;
       }

       for ( i = 0 ; i < W ; i++){
       	 scanf("%d %d %d",&j, &k ,&c);
       	 res[2*j+1][2*k] = res[2*k+1][2*j] = c;
       }
       maxflow();
       printf("%d\n",mf);
    }
	return 0;
}
