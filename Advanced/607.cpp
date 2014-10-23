#include <bits/stdc++.h>
using namespace std;
#define P first
#define Q second
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
typedef pair < int , int > ii ;
ii dp[1111][555];
int topictime [1111] ;
int n , c, lectime ;

int penalty ( int timeleft){
	if ( timeleft == 0)
	return 0 ;
    if( timeleft <= 10)
    return c*(-1) ;
    else{
    	return (timeleft-10)*(timeleft-10);
    }

}

ii topdown( int topic , int timeleft  ){
	if( topic >= n)
	return ii(0,penalty(timeleft));

    if( dp[topic][timeleft] != ii(-1,-1))
    return dp[topic][timeleft];
    ii ans = ii(1e9,1e9);
    
    if ( timeleft >= topictime[topic] ){
    	ii x = topdown( topic+1,timeleft-topictime[topic]);
    	if( x.P <= ans.P){
    		if( x.P == ans.P)
    		ans.Q = min ( ans.Q , x.Q);
    	    else{
    	    	ans.P = x.P ;
    	    	ans.Q = x.Q ;
    	    }
    	} 
    }
  //  else{
    	ii x = topdown( topic+1, lectime-topictime[topic]);
    	x.P += 1;
    	x.Q += penalty( timeleft );
    	if( x.P <= ans.P){
    		if( x.P == ans.P)
    		ans.Q = min ( ans.Q , x.Q);
    	    else{
    	    	ans.P = x.P ;
    	    	ans.Q = x.Q ;
    	    }
    	} 
   // }
   return dp[topic][timeleft] = ans ;
}

int main(){
	int i , k, j, l,kase =1;
    bool first = true;
    while (1){
       scanint(n);
       if( n == 0)break ;
       if(!first)
       printf("\n");
       else
       first = false;
       scanint(lectime);scanint(c);
       for ( i = 0 ; i < n ; i++)
       scanint(topictime[i]);
       for ( i = 0 ; i <= n ;i++)
       for ( j = 0 ; j <= lectime ; j++)
       dp[i][j].P = dp[i][j].Q = -1 ;
       ii ans = topdown(0,lectime);
       ans.P += 1 ;
       printf("Case %d:\n",kase++);
       printf("Minimum number of lectures: %d\n",ans.P);
      printf("Total dissatisfaction index: %d\n",ans.Q);
      
    }

	return 0 ;
}
