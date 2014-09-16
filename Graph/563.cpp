#include <bits/stdc++.h>
using namespace std ;

#define MAXV 5050
#define P first
#define Q second

typedef pair < int , int> ii ;
typedef vector < ii > vii ;
vector < vii > adjlist ;

int street ,avenue ,bank ;


int res[MAXV][MAXV] ;
vector < int > p ;
ii vertex[55][55] ;

int s , f ,mf , t ;
int dx[]= {-1,1,0,0};
int dy[]={0,0,1,-1} ;

bool valid ( int x ,int y){ return (x>=1&&x<=street&&y>=1&&y<=avenue);}

void augment( int v , int minedge ){
    if( p[v] == -1){ f = minedge ; return ;}
    else{
         augment( p[v] , min ( minedge , res[p[v]][v]));
         res[p[v]][v] -= f ; res[v][p[v]] += f;
    }
}

void maxflow(){
    mf = f = 0 ;
    while(1){
        f = 0 ;
        queue < int > q ; p.assign(t+1 , -1) ; bitset < MAXV > vis; vis.set(s);
        q.push(s);
       
        while(!q.empty()){
           int u = q.front();q.pop();
           if( u == t)break;
           for( int i = 0 ; i < adjlist[u].size() ; i++)
           {
              ii x = adjlist[u][i] ;
              if( !vis.test(x.P) && res[u][x.P] > 0){
                q.push(x.P) ; vis.set(x.P) ; p[x.P] = u ;
              }
           }
        }
      augment(t,1e9);
     
      if( f == 0 || f == 1e9) break ;
      mf += f ;
      if( mf >= bank)
        break ;
    }
}

int main(){
    int test , i, j, k, l ;
    scanf("%d",&test);
    while(test--){
       adjlist.clear();
       scanf("%d %d %d",&street , &avenue , &bank);
       
       int c = 1 ;

       for ( i = 1 ; i <= street ; i++)
       for( j = 1 ; j <= avenue ; j++)
       { vertex[i][j].P = c++ ; vertex[i][j].Q = c++ ;}
       
       s = 0 ;t = c ;
      
       adjlist.assign(t+1,vii());

       for ( i = 1; i <= street ; i++)
       for ( j = 1 ; j <= avenue ; j++)
       {
          int u1 = vertex[i][j].P ; int v1 = vertex[i][j].Q ;
          adjlist[u1].push_back(ii(v1,1));
          for ( k = 0 ; k < 4 ; k++){
             int a = i + dx[k] ; int b = j + dy[k] ;
             if( valid(a,b) ){
                int u2  = vertex[a][b].P ; int v2 = vertex[a][b].Q;
                adjlist[v1].push_back(ii(u2,1e6));
             }
          }
          if ( i == 1 || i == street || j ==1 || j == avenue )
          {
              adjlist[v1].push_back(ii(t,1e6));
          }
       }

       for ( i = 0 ; i < bank ; i++){
         scanf("%d %d",&j ,&k);
            int u1 = vertex[j][k].P ; int v1 = vertex[j][k].Q ;
            adjlist[s].push_back(ii(u1,1e6));
       }

       for ( i = 0 ; i <= t ; i++){
      
          for ( j = 0 ; j < adjlist[i].size(); j++){
            ii x = adjlist[i][j] ;
            res[i][x.P] = x.Q ;
          
          }
         
       }
       maxflow();
       
       if( mf >=  bank ){
         puts("possible");
       }
       else
        puts("not possible");

    }
    return 0;
}
