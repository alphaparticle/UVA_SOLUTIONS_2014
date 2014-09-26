#include <bits/stdc++.h>
using namespace std;
int n , m  ,s ,mf ,f, t; double v , times ;
double gopher[111][2] ;
double holes [111][2] ;
int res[211][211] ;

bool check ( int index1 , int index2 ){
//	cout << index1 <<" "<<index2 <<" ";
	double dis = sqrt( (gopher[index1][0]-holes[index2][0])*(gopher[index1][0]-holes[index2][0]) + (gopher[index1][1]-holes[index2][1])*(gopher[index1][1]-holes[index2][1]) );
//	cout << dis <<" "<<dis/v<<" "<<times<<endl;
	if( dis <= times*v )
	return true ;
    else
    return false ;
}

vector <int> p ;
void augment( int v , int edge){ if(p[v] == -1){ f = edge;return;}
        else{
        	 augment(p[v] , min(edge,res[p[v]][v]));
        	 res[p[v]][v] -= f ; res[v][p[v]] += f ;
        }
}
void maxflow(){
	f=  mf = 0 ;
	while(1){
		f = 0 ; bitset<211>vis ; vis.set(s) ; queue<int> q; q.push(s);
		p.assign(t+1,-1);
		while(!q.empty()){ int u = q.front(); q.pop();
              if( u == t)break ;
              for( int i = 0 ; i <= t ; i++)
              if( !vis.test(i) && res[u][i] > 0){ q.push(i);vis.set(i);p[i]=u;}
		}
		augment(t,1e9); if( f == 0 || f == 1e9 ){ break ;}
		mf += f ;
	}
}

int main(){
  int i , j, k, l ;
  while ( scanf("%d %d %lf %lf",&n,&m,&times,&v) != EOF ){
        s = 0 ; t  = n+m+1 ;
        for ( i = 1 ; i <= n ; i++)
        scanf("%lf %lf",&gopher[i][0] , &gopher[i][1]);
        for ( j = 1 ; j <= m ; j++)
        scanf("%lf %lf",&holes[j][0],&holes[j][1]);
        
        for ( i = 0; i <= t ; i++)for(j=0;j<=t;j++) res[i][j] =0 ;
        for ( i = 1 ; i <= n ; i++)
        res[s][i] = 1 ;
        for ( i = 1 ; i <= m ; i++)
        res[n+i][t] = 1 ;

        for ( i = 1 ; i <= n ; i++ )
        for ( j = 1 ; j <= m ; j++)
        if( check(i,j)){
          res[i][n+j] = 1 ;
         // cout << i <<" "<<j << endl;
       }
       maxflow();	//cout <<mf << endl;
       printf("%d\n",n-mf); 
  }
 
	return 0 ;
}
