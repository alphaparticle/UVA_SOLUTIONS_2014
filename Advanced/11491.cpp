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

char arr[100011] ;
vector < int > adj [10] ;
int main(){
  int i ,j, k, l , n , d;
  while(1){
  	 scanint(n) ;scanint(d) ;
  	 if( n == 0 && d == 0)
  	 break ;
  	 scanf("%s", arr) ;
     for( i = 0 ; i < 10; i++)
     adj[i].clear();
     for( i = 0 ; i < n ; i++)
     adj[ arr[i] -'0' ].push_back(i);
  	 string ans;
     int dd = n-d ;
     int old ,now; old = now = 0 ; int index = 0 ;
     vector < int > :: iterator it ;
     while(dd){
         now = -1 ;
          index = -1 ;
         for ( i = 9 ; i >= 0 ; i--)
         if( adj[i].size() > 0)
         { 
              it = lower_bound( adj[i].begin() , adj[i].end() ,old);
              if( it == adj[i].end())
              it-- ;
              if( (*it) >= old && (*it) <= n-dd ){
                  now = i ; index = (*it) ; old = (*it)+1 ; break ;   
              }    
         }
          assert( index >= 0 && index < n) ;
          //cout << index <<" "<<old<<" "<<"'"<<arr[index]<<"'"<<endl;
          ans += arr[index]; dd-- ;
     } 
    assert( ans.length() == n-d);
    cout << ans <<"\n";
  }

	return 0 ;
}
