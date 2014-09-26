#include <bits/stdc++.h>
using  namespace std ;
int  n , a , m ;
int inuse[111111] ;
vector < int > adj [111111] ;
int order [111111] ;
typedef pair < int , int > ii ;
#define P first
#define Q second
int main(){
    int  i , j, k, l , ans ;
    ans= 0 ; 
  // freopen("o.txt" , "w" , stdout) ;
   while (  scanf("%d %d %d", &n , &a , &m) != EOF ) { ;
    if( n == 0 && a == 0 && m == 0)
    break ;
    ans = 0 ; memset ( inuse , false , sizeof inuse) ;
    for ( i = 0 ; i <= a ; i++)
    adj[i].clear() ;
    for ( i = 0 ; i < m ; i++)
    {
         scanf("%d",&order[i]);
         adj[ order[i] ].push_back(i) ;
    }
int cap = 0 ;
priority_queue < ii , vector  < ii > , less <ii> > pq ;
    for ( i = 0 ; i < m ; i++){
      int x = order[i] ;  
        if( inuse[x] )
        {
            vector < int > :: iterator it ;
            it = lower_bound( adj[x].begin() , adj[x].end() , i+1) ;
            if( it != adj[x].end())
            pq.push(ii(*it,x));
            else
            pq.push(ii(1e9,x)) ;
          
            continue ;
        }

        if ( cap < n ){
            inuse[x] = true ;
            ans++ ; cap++ ; 
            vector < int > :: iterator it ;
            it = lower_bound( adj[x].begin() , adj[x].end() , i+1) ;
            if( it != adj[x].end())
            pq.push(ii(*it,x)) ;
            else
            pq.push(ii(1e9,x)) ;
          
            continue ;
        }
       ans++ ;
       
       ii y = pq.top() ; pq.pop() ;
       
       inuse[y.Q] = false ; inuse[x] = true ;
       vector<int> :: iterator it ;
       it = lower_bound( adj[x].begin() , adj[x].end() , i+1);
       if( it != adj[x].end())
       pq.push(ii(*it,x)) ;
       else
       pq.push(ii(1e9,x)) ;
      
    }
  printf("%d\n",ans) ;
}
  return 0 ;
}
