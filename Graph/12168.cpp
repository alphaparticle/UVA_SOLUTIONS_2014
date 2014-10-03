#include <bits/stdc++.h>
using namespace std ;
#define MAX 111111
#define P first
#define Q second

typedef pair < int , int > ii ;
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

int boss[MAX] ;
int sons[MAX] ;

bool done [MAX] ;
int N , T;


int employee[MAX] ;

vector < int > adj [MAX] ;
vector < ii > final [MAX] ;
vector < int > degree [MAX] ;

void  dfs ( int u ){
   if(!done[u])
   return ;
 // cout <<" removed "<< u << endl; 
   done[u]= false ;
	for ( int i = 0 ; i < adj[u].size() ; i++)
	if( done[ adj[u][i]] )
	dfs( adj[u][i] ) ;
}


int main(){
  int i , j, k, l , u , v ;
  while ( scanf("%d %d", &N ,&T) ){
         if( N == 0 && T == 0)
         break ;
    

      for ( i = 0 ; i <= N ; i++ )
      sons[i] = 0 , done[i] = false , employee[i] =0 , final[i].clear() , adj[i].clear() , degree[i].clear() ;
     
      int maxi = 0 ; 
     for ( i  = 1 ; i <= N ; i++){
     	scanint(j) ; boss[i]  = j ; 
     	sons [ boss[i] ] ++ ; 
     	adj[boss[i]].push_back( i ) ;
   
     	maxi  = max ( sons[ boss[i] ] , maxi) ;
     }
   
    for ( i = 0 ; i <= N ; i++)
    {
    	 degree[ sons[i] ].push_back( i ) ;
    	 if( sons[i] == 0)
    	 employee[i] = 1 ; 
    }

    bool degreedone [maxi+1] ; memset ( degreedone , false ,sizeof degreedone) ;

    int finish = 0 ;
    vector < int > rem ;
    while ( finish < N+1){
    
      for ( i = 0 ; i <= maxi ; i++)
    	if( !degreedone[i] ){
    		      degreedone[i] = true ;
			    	for ( j = 0 ; j < degree[i].size() ; j++){
			    		int e = degree[i][j] ;
			    		int b = boss [e] ;
			    	    if( !done[e] )
					    {	    
					    	    bool operate = true ;

					            for ( k = 0 ; k < adj[e].size() ; k++)
					            if( !done[ adj[e][k] ] ){ operate = false ; break ;}
			                     
			                    if( !operate){
			                    	degreedone[i] = false ;
			                    	continue ;
			                    }
			                   
			                    int sz = (int)ceil( (adj[e].size()  * T * 1.0)/(100.00) ) ;
			                    sort ( final[e].begin() , final[e].end() );
			                  //cout <<"=============  " << e << endl;     
			                    for ( k = 0 ; k < sz && k < final[e].size() ; k++)
			                    employee[e] += final[e][k].P ;//,  cout << " u " << final[e][k].Q<<endl;

			                    for ( k = sz ; k < final[e].size() ; k++)
			                    rem.push_back(final[e][k].Q) ;//, cout <<" nu "<<final[e][k].Q << endl;;
			                 
			                  done[e] = true ;
			                 // cout <<"--> done  "<< e <<" "<<finish<< endl; 
			                  finish++ ;
			                  final[b].push_back(ii(employee[e],e));		    		
			    	   }
			   
			     }
        }
 }

  for ( i = 0 ; i < rem.size() ; i++)
  {  
  //	 cout <<"--> "<<rem[i] << endl;
  	 dfs( rem[i]) ;
  }

  int ans = 0 ;
  for ( i = 1 ; i <= N ; i++)
  if( done[i] && adj[i].size() == 0){
  	 ans++ ;
  }

  printf("%d\n",ans) ;
}
return 0 ;
}
