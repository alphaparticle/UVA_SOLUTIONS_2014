#include <bits/stdc++.h>
using namespace std ;

#define MAXV 1111
int res[MAXV][MAXV] ;
int s , t , mf , f ,n ;
vector < int > p ;
map < string , int > dic;
map < int , string > rev ;
typedef vector < string > vs ;
vector < vs > adj ;

void augment( int v , int minedge){
	if( p[v] == -1){ f = minedge ; return ;}
    else{ augment(p[v] , min(minedge , res[p[v]][v])) ; 
           res [p[v]][v] -= f ;
           res [v][p[v]] += f ;
      }
}

void flow(){
	mf = f = 0 ;
	while(1){
		f = 0;
		bitset < MAXV > vis ; p.clear() ; 
		vis.set(s) ; queue <int> q ; p.assign(t+1,-1);
		q.push(s) ; vis.set(s) ;
		while(!q.empty()){
			int u = q.front(); q.pop() ; if( u == t)break ;
			for( int i = 0 ; i <= t ; i++)
		    if( !vis.test(i) && res[u][i] > 0){
		    	q.push(i) ; vis.set(i) ; p[i] = u ;
		    }
		}
	  if( vis.test(t) )
	  augment( t , 1e9) ;
       if( f == 0 || f == 1e9 )break;
       mf += f;
	}
}
int main(){
   int test , i , j , k;
   string a ;
   cin >> test ;
   for( int kase = 1 ; kase <= test ; kase++){
   	 cin >> n ;
   	 dic.clear() ; rev.clear() ; int cnt = 1;memset ( res , 0 ,sizeof res);
   	 for( i = 1 ; i <= n ; i++){
   	 	cin >> j ;
   	 	for( k = 1 ; k <= j ; k++){
   	 		cin >> a; 
   	 		for ( int l = 0 ; l < a.length() ; l++)
   	 		a[l] = tolower( a[l] );
   	 	    a[0] = a[0] - 'a' + 'A' ;
   	 	    if( dic.count(a) == 0){
   	 	    	dic[a] = cnt; rev[cnt] = a ; cnt++;
   	 	    }
   	 	    int v = dic[a] + n;
   	 	    res[i][v] = 1 ;
   	 	}
   	 }
     s  = 0 ; t = n + dic.size() + 26 + 1 ;
     for ( i = 1 ; i <= n ; i++)
     res[s][i] = 1 ;

     for ( i = n+dic.size()+1  ; i < t ; i++)
     res[i][t]= 1 ;

          map < string , int > :: iterator it  ;
          map < int , string > :: iterator fit ;   

     for( it = dic.begin() ; it != dic.end() ; it++){
     	string temp = (*it).first;
     	int u = (*it).second ; 
        u += n ;
     	int v = temp[0] - 'A' + n + dic.size()+1 ;
     	res[u][v] = 1 ;
     }
    /*
     for ( i = 0 ; i <= t ; i++)
     {
     	 for( j = 0 ;  j <= t ; j++)
     	 cout << res[i][j]<<" ";
     	cout << endl;
     }
    */
     flow();

     //cout << mf << endl; 

     cout <<"Case #"<<kase<<":\n";
     /*
     for ( it = dic.begin() , fit = rev.begin() ; it != dic.end() && fit != rev.end(); it++ , fit++){
     	cout << (*it).first <<" "<<(*it).second <<" "<<(*fit).first<<" "<<(*fit).second << endl;
     }*/
     /*
     for ( i = n+dic.size()+1 ; i < t ; i++)
     if( res[i][t] == 0 && res[t][i] > 0){
     	cout << char ( i - ( n + dic.size()+1 ) + 'A' )<< endl;
     }
     */
     vector < string > ans ; bool used[130] ; memset ( used ,false ,sizeof used);
     
     for ( i = n+1 ; i <= n+dic.size() ; i++ )
     for ( j = n+dic.size()+1 ; j < t ; j++)
     {
         string t = rev[i-n] ; 
         //cout << t <<" "<< char ( j - ( n + dic.size()+1 ) + 'A' )<<" "<<res[i][j] <<" "<<res[j][i] << endl;
         //cout << t << endl;
         if ( !used[ t[0] ] && res[i][j] == 0 && res[j][i] > 0 ){
         	ans.push_back(t) ; used[t[0]] = true ; break ;
         }
     }
     sort( ans.begin() , ans.end());
     for( i = 0 ; i < ans.size() ; i++)
     cout << ans[i]<<"\n";
   }

	return 0;
}
