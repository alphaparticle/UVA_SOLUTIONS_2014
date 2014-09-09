#include <bits/stdc++.h>
using namespace std ;

int preorder [555555] ;
int sttree   [555555] ;
int height , K , n ;
char TREE [1111111] ;

int dp [555555][22] ;

int build ( int p , int index , int h  ){
    if ( h > height )
    return index ;
  //  cout << p <<" "<<index <<" "<<h << endl;
    sttree[p] = preorder [index] ;
    int y = build(p*2 , index+1 , h+1);

  //  cout << p <<" "<<index<<" "<<h <<" y  "<<y << endl;
    int z = build(p*2 + 1 , y , h+1) ;
  //  cout << p <<" "<<index<<" "<<h <<" z  "<<z << endl; 
    return z ;
}


int rec ( int p , int nodestobreak , int h ){
	 if( h > height || p >= n )
	 return -1e9 ;
     
	if( dp[p][nodestobreak] != -1 ){ return dp[p][nodestobreak] ;}
    //cout << p <<" "<< nodestobreak <<" "<< h << endl;
    if ( nodestobreak == 1){ dp[p][nodestobreak] = sttree[p] ; 
       // cout << p <<" "<< nodestobreak <<" "<<h <<" "<< dp[p][nodestobreak]<<endl;
    	return dp[p][nodestobreak] ; }
  
   dp[p][nodestobreak] = sttree[p] ;
   int a = -1e9 ;
   for ( int i = 1 ; i < nodestobreak ;i++){
     a = max ( a , rec(p*2,i,h+1) + rec(p*2 +1 , nodestobreak-i , h+1)) ;
  }
   dp[p][nodestobreak] = max(a,dp[p][nodestobreak]) ;
   //cout << p <<" "<<nodestobreak <<" "<< h<< " " << dp[p][nodestobreak] <<endl;
   return dp[p][nodestobreak] ;
}

int main(){
   int i , j, k ; 
    while ( gets(TREE) ){
    	if( TREE[0] == '-' && TREE[1] == '1' )
    	break ;
        int len = strlen( TREE ) ;
        char *ptr ;
        ptr = strtok ( TREE , " " );
        height = K = -1 ; n = 1 ;
        while ( ptr != NULL ){
        	if( height == -1){ 
        	sscanf(ptr,"%d", &height); ptr = strtok( NULL ," "); continue ;}
        	if( K == -1)
        	{ sscanf(ptr,"%d",&K) ; ptr = strtok( NULL ," "); continue ; }
            sscanf ( ptr  , "%d", &preorder[n++] ) ;            
        	ptr = strtok( NULL ," ");
        }
       
       /*
       cout << height <<" "<<K << endl;
       for ( i = 1;  i < n ; i++ )
       cout <<" "<<preorder[i] ;
       cout << endl;
       */
       int z = build ( 1 , 1 , 0) ; 
        // RUNTIME ERROR CHECK to check if the new tree build is correct
       if( z != n ){ cout << preorder[123456789] ; }
       /*
       cout << z <<" "<<n << endl;
       for ( i = 1 ; i < n ; i++)
       cout <<" "<<sttree[i] ;
       cout << endl;
       */
      for ( i = 1 ; i <= n ; i++)
      for ( j = 0 ; j <= K ; j++)
      dp[i][j] = -1 ;
       //cout <<"sabsahi\n" ;
       int ans = rec (1,K,0) ;
       printf("%d\n",ans) ;
    }
}
