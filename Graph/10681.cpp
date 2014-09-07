#include <bits/stdc++.h>
using namespace std; 

typedef vector < int > vi ;
int S , E , D , C , L ;
vector < vi > adj;
bool dpstate [222][111];

void rec( int day , int city )
{ 
    if( day > D || city > C)
    return ;
    if( dpstate[day][city] )
    return ;
    
    dpstate[day][city] = true ;
    for( int i = 0 ;i < adj[city].size() ; i++)
    rec ( day+1 , adj[city][i]) ;
  //cout << day <<" "<<city <<" "<<dpstate[day][city] << endl;
  return ;
}
void solve(){
	 bool ispossible = false ;
	 int i , j, k ;
	 for ( i = 0 ; i < L; i++){
	 	 cin >> j >> k ;
	 	 adj[j].push_back(k) ;
	 	 adj[k].push_back(j);
	 }
	cin >> S >> E >> D ;
	for ( i = 0 ; i <= D ; i++)
	for( j = 0; j <= C; j++)
	dpstate[i][j] = false ;
	rec (0,S) ;
	if( dpstate[D][E])
		cout <<"Yes, Teobaldo can travel.\n";
	else
		cout<<"No, Teobaldo can not travel.\n";
}

int main(){
  adj.assign(111,vi()) ;
   while ( cin >> C >> L){
   	   if( C == 0 && L == 0)
   	   	break ;
   	  for( int i = 0 ; i <= C ;i++)
   	  adj[i].clear() ;
   	  solve() ;
   }
}
