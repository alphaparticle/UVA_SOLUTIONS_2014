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

typedef vector < int > vi ;
int cost [55][33];
//int maxprofit [55];
int w , n[55] ;
int main(){
    int i , j, k, l ;
    int kase = 1 ;
    bool first = true ;
    while (1){
       scanint(w);
       if( w == 0) break ;
       if( kase > 1)
       printf("\n");
        
     
      for ( i = 0 ; i < w ; i++){
      	 scanint(n[i]);
      	 for ( j = 0 ; j < n[i] ; j++)
      	 scanint(cost[i][j]) , cost[i][j] = 10 - cost[i][j];
      }

      for ( i = 0 ; i < w ; i++){
      	
      	  for ( j = 1 ; j < n[i] ; j++)
      	  cost[i][j] += cost[i][j-1] ;
      	  
     }

     vector < vi > pos ;pos.clear() ;
     int ans = 0 ;
     vector < int > temp ; set < int> temp1 ;
      for ( i = 0 ; i < w ; i++)
      {
      	    int z = -1000 ; 
      	    for ( j = 0 ; j < n[i] ; j++)
      	    z = max( z , cost[i][j]);

      	    if( z  > 0){
      	    	ans += z ;
      	    	 pos.push_back(vi());
      	    	 int sz = pos.size() -1 ;
      	    	 for ( j = 0 ; j < n[i] ; j++){
      	    	 	 if( cost[i][j] == z ){
      	    	 	   pos[sz].push_back(j+1);
      	    	 	 }
      	    	 }
      	    }
      	    else if( z == 0){
      	    	vector < int > temp2 ;temp2.clear() ;
      	    	//cout << i <<" zero profit ";
      	    	 for ( j = 0 ; j < n[i] ; j++){
      	    	 	 if( cost[i][j] == z ){
      	    	 	   temp2.push_back(j+1);//, cout <<" "<< j+1 ;
      	    	 	 }
      	    	 }
      	    	 //cout << endl;
                
      	    	set < int > copy ; copy.clear();
      	    	for ( set < int > :: iterator it = temp1.begin() ; it != temp1.end() ; it++)
                for ( j = 0 ; j < temp2.size() ; j++)
                copy.insert( (*it) + temp2[j]) ;//, cout<<"1",assert( (*it)+temp2[j] > 0);
                for ( j = 0 ; j < temp2.size() ; j++)
                temp1.insert( temp2[j]);// , cout<<"2",assert( temp2[j] > 0);
                for ( set < int > :: iterator it = copy.begin() ; it != copy.end() ; it++)
                temp1.insert( (*it));// cout<<"3",assert( (*it) > 0 );
                
                
      	    }
      }
      
      /* 
      for ( i = 0 ; i < pos.size() ; i++){
      	 cout << "workstation "<< i <<": ";
      	 for ( j = 0 ; j < pos[i].size() ; j++)
      	 cout << pos[i][j] <<" ";
      	cout << endl;
      }
      */
      temp.clear();
      if( pos.size() > 0)
      for ( i = 0 ; i < pos[0].size() ; i++)
      temp.push_back(pos[0][i]);// , cout<<"4",assert(pos[0][i] > 0);

      for ( i = 1 ; i < pos.size() ; i++){
      	  vector < int > ppp ; ppp.clear() ;
      	  for ( j = 0 ; j < pos[i].size() ; j++)
      	  for ( k = 0 ; k < temp.size() ; k++)
      	  ppp.push_back( temp[k]+pos[i][j]);//, cout<<"5",assert( temp[k]+pos[i][j] > 0) ;
      	 temp.clear() ;
      	 for ( j = 0 ; j < ppp.size() ;j++)
      	 temp.push_back(ppp[j]);
      }
      
      //cout <<"faltu \n";
      /* for ( set < int > :: iterator it = temp1.begin() ; it != temp1.end() ; it++)
       cout << *it <<" ";
     cout << endl;
      */
      
      set < int > s ; 
      s.clear() ;
      for ( i = 0 ; i < temp.size() ; i++) s.insert(temp[i]);
      //cout << "temp "<< temp.size() <<" temp1 "<<temp1.size()<< endl;
      if( temp.size() > 0){
       for ( set < int > :: iterator it = temp1.begin() ; it != temp1.end() ; it++)
       for ( j = 0 ; j < temp.size() ; j++)
       s.insert( (*it)+temp[j]);// , cout<<"6",assert( (*it)+temp[j] > 0);
     }
      else{
		         s.insert(0);
		      	 for ( set < int > :: iterator it = temp1.begin() ; it != temp1.end() ; it++){
		          s.insert((*it));//, cout<<"7",assert( (*it) > 0);
		         }
	  }
	  if(s.size() == 0)
	  s.insert(0);
      
     assert( (int)s.size() > 0);
      //if ( s.size() == 0)
      //s.insert(0);
      printf("Workyards %d\n",kase++);
      printf("Maximum profit is %d.\n",ans);
      printf("Number of pruls to buy:");
      i = 10 ;

      for ( set < int > :: iterator it = s.begin() ; it != s.end() && i-- ; it++ )
      printf(" %d",*it);
      //if(s.size() == 0)
      //printf(" 0");
      printf("\n");

    }
	return 0;
}
