#include <bits/stdc++.h>
using namespace std ;
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
// double st = clock() ;
 //cout << ((clock()-st)*1.0)/(CLOCKS_PER_SEC * 1.0) << endl;
bool p[11111];
map < string , int > id ;
map < int , string > di ;
vector < int > prime ;
int dist [1100] ;
vector < int > adj [1100] ;
int check ( string a , string b){
   int diff = 0 ;
   for (int i = 0 ; i < 4 ; i++)
   if( a[i] != b[i] )
   diff++;
   return diff ;
}
void seive( ){
	memset ( p , true ,sizeof p);
	int c = 0;
	for (int i = 2 ; i < 1e4 ; i++)
	if(p[i]){
		if( i >= 1000){
		 prime.push_back(i) ;
		 int x = i ; string s ;
		 while( x > 0){ s += x%10 + '0' ; x /= 10 ;}
	     reverse(s.begin(), s.end());
	     id[s] = c++ ;// di[c] = s ; c++ ;
	    }
	    for( int j = i*i ; j < 1e4 ; j += i)
	    p[j] = false; 
	}
    //cout << c << endl;
    map < string , int > :: iterator it , fit ;
    for( it = id.begin() ; it != id.end() ; it++){
    	 fit = it; fit++;
    	 for( ; fit != id.end() ; fit++ )
    	 if( check( it->first , fit->first) == 1 ){
            adj[ it->second ] .push_back ( fit -> second);
            adj[ fit->second] .push_back( it ->second);
    	 }
    }
    /*
    for(int i = 0 ; i < c ; i ++)
    {
    	 cout <<di[i] <<"->";
    	 for(int j = 0 ; j < adj[i].size()  ; j++)
    	 cout <<" "<< di [adj[i][j]];
         cout << endl;
    }
    */

}


int main(){
    ios::sync_with_stdio(0);
    seive() ;
    int test ; string  a , b ;
    cin >> test ;
    while ( test-- ){ 
       cin >> a >> b ;
       memset (dist , -1 ,sizeof dist);
       queue< int> q ;
       dist[ id[a] ] = 0;
       q.push( id[a]);
       while( !q.empty()){
       	 int u = q.front() ; q.pop();
       	 for ( int i = 0 ; i < adj[u].size() ; i++)
       	 if ( dist[adj[u][i]] == -1){
       	 	q.push( adj[u][i]);
       	 	dist[adj[u][i]] = dist[u] + 1; 
       	 }
       }
      int ans =dist[ id[b]];
      if( ans == -1)
      cout <<"Impossible";
      else
      cout <<ans<<"\n";
    }
    return 0 ;
}
