#include <bits/stdc++.h>
using namespace std;
#define MAXV 1500
int res [MAXV][MAXV];
typedef pair < int , int > ii ;
char sea [35][35] ;
ii vertex [35][35];
int n , m , wood , s , t , f , mf ;

#define P first
#define Q second


int dx [] = { -1 , 1, 0 , 0};
int dy[] = { 0 , 0, -1, 1} ;
vector < int > p ;

bool valid( int x , int y ){  return ( x >= 0 && x < n && y >= 0 && y < m ) ;}
void augment( int v , int minedge){ 
   if( p[v] == -1){ f = minedge ; return ; }
   else{ augment( p[v] , min ( minedge ,res[p[v]][v]) ) ; 
         res[p[v]][v] -= f ; res[v][p[v]] += f ;
   }
}
void maxflow(){
   mf = f = 0 ;
   while(1){
      f = 0 ; bitset<MAXV> vis ; vis.set(s) ; queue<int> q ; q.push(s);p.assign(t+1,-1);
      while(!q.empty()){
          
          int u = q.front() ; q.pop(); if( u == t)break;
          //cout << u <<" "<<s <<" "<<t<< endl;
          for (int i = 0 ; i <= t ; i++)
          if( res[u][i] > 0 && !vis.test(i)){ p[i] = u ; vis.set(i) ; q.push(i);}
      }
      augment(t,1e9);
      //cout << f << endl;
      if(f == 0 || f == 1e9){ break;}
      mf += f;
   }
}

void out(){
  for( int i = 0 ; i <= t ; i++){
  for ( int j = 0 ; j <= t ; j++)
  cout <<" "<<res[i][j];
cout << endl;}
}

int main(){
  int i , j, k, l;
   while( scanf("%d %d %d", &n , &m , &wood) != EOF ){
       int c = 1 ;
       vertex[0][0].P = 0 ; vertex[0][0].Q = 0 ;

       for ( i = 0 ; i < n ; i++)
       scanf("%s",sea[i]);
       s = 0;

       for ( i = 0 ; i < n ; i++)
       for( j = 0 ; j < m ; j++)
       if( sea[i][j] != '~')
       {
          vertex[i][j].P = c++; vertex[i][j].Q =c++;
       }
    
       t = c ;
       //cout << s <<" "<<t<<endl;
       for ( i = 0 ; i <= t ; i++)
       for ( j = 0 ; j <= t ; j++)
       res[i][j] = 0 ;
       
       for ( i = 0 ; i < n ; i++)
       for( j = 0 ; j < m ; j++)
       if( sea[i][j] == '*' ){
          int startu = vertex[i][j].P ; int endu = vertex[i][j].Q ;
          res[startu][endu] = 1 ; res[s][startu] = 1e6 ;
          for ( k = 0 ; k < 4 ;k ++)
          if( valid( i + dx[k] , j + dy[k]) )
          if( sea [i+dx[k]][j+dy[k]] != '~' ){
             int startv = vertex [ i+dx[k] ] [ j+dy[k] ]. P ;
             int endv = vertex [ i+dx[k] ] [ j+dy[k] ]. Q ;
             res[endu][startv] = 1e6 ;
          }
       }
       else if( sea[i][j] == '.' ){
          int startu = vertex[i][j].P ; int endu = vertex[i][j].Q ;
          res[startu][endu] = 1 ;
          for ( k = 0 ; k < 4 ;k ++)
          if( valid( i + dx[k] , j + dy[k]) )
          if( sea [i+dx[k]][j+dy[k]] != '~' ){
             int startv = vertex [ i+dx[k] ] [ j+dy[k] ]. P ;
             int endv = vertex [ i+dx[k] ] [ j+dy[k] ]. Q ;
             res[endu][startv] = 1e6 ;
          }
       }
       else 
       if( sea[i][j] == '@' ){
          int startu = vertex[i][j].P ; int endu = vertex[i][j].Q ;
          res[startu][endu] = 1e6 ; 
          for ( k = 0 ; k < 4 ;k ++)
          if( valid( i + dx[k] , j + dy[k]) )
          if( sea [i+dx[k]][j+dy[k]] != '~' ){
             int startv = vertex [ i+dx[k] ] [ j+dy[k] ]. P ;
             int endv = vertex [ i+dx[k] ] [ j+dy[k] ]. Q ;
             res[endu][startv] = 1e6 ;
          }
       }
       else 
       if( sea[i][j] == '#' ){
          int startu = vertex[i][j].P ; int endu = vertex[i][j].Q ;
          res[startu][endu] = 1e6 ; res[endu][t] = wood ;
          for ( k = 0 ; k < 4 ;k ++)
          if( valid( i + dx[k] , j + dy[k]) )
          if( sea [i+dx[k]][j+dy[k]] != '~' ){
             int startv = vertex [ i+dx[k] ] [ j+dy[k] ]. P ;
             int endv = vertex [ i+dx[k] ] [ j+dy[k] ]. Q ;
             res[endu][startv] = 1e6 ;
          }
       }

       //out();
       maxflow();
       printf("%d\n",mf);
       //out(); 
   }
 
  return 0;
}
