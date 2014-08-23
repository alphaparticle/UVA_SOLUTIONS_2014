#include <bits/stdc++.h>
using namespace std; 

static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

	// fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
	inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;


int test ;
char s[100]; 

typedef pair < int , int > ii ;
typedef vector < ii > vii ;

vector < vii > adjlist ( 30 , vii());
int dist [30] ;

void out () {
	int i , j ;
	for ( i = 0 ; i < 30 ;i++)
	{
		 cout << i  <<"-->" ;
		 for( j = 0 ;  j < adjlist[i].size() ; j++)
		 cout << adjlist[i][j].first  << "(" << adjlist[i][j].second <<") " ;

		 cout << endl; 
	}
}


int dij ( int source ){

	priority_queue < ii , vector < ii > , greater <ii> > pq ;
	int i , j , u , v , w;
	for ( i = 0 ; i < 30 ; i++)
	dist[i] = 1e9 ;
    
    dist[ source ] = 0 ;
    pq.push( ii( 0 , source)) ;

    while ( !pq.empty() ){
    	ii NODE = pq.top() ; pq.pop() ;
    	u = NODE.second ;
    	if( dist[u] == NODE.first ){
    		for( i = 0 ; i < adjlist[u].size() ; i++){
    			 v = adjlist[u][i].first ;
    			 w = -1 * adjlist [u][i].second ;
    			 if( dist[u] + w < dist[v]  ){
    			 	dist[v] = dist[u] + w ;
    			 	pq.push(ii(dist[v] , v)) ;
    			 }
    		}
    	}
    }
//  for ( i = 0 ;i < 30 ; i++)
//  cout << i <<" "<<abs(dist[i])<<endl;
  int ans =0 ;
  for ( i = 0 ; i < 26 ; i++)
  if( abs(dist[i]) < 1e9)
  ans= max( ans , abs(dist[i])) ;

  return ans ;
}

int solve () {
   int i , j, w , u , v  , source ;

   for (i = 0 ; i  < 30 ; i++){
   	 adjlist[i].clear() ;
   }
    
 

   while ( gets(s) ){
       //cout << "--> " ; puts(s);      
       int len = strlen(s) ;
       if( len < 2)
       break ;
      
       v = s[0] - 'A' ;
       w = 0 ;
       
       bool f = false ;

       for ( i = 2 ; i < len  ; i++)
       if( s[i] >= '0' && s[i] <= '9' ){
       	 w = w*10 + ( s[i] - '0' ) ;
       }
       else{ break ; }
      
      for (  ; i < len ; i++)
      if( s[i] >= 'A' && s[i] <= 'Z' )
      { 
         f = true ; 
      	 u = s[i] - 'A' ;
      	 adjlist[u].push_back ( ii ( v , w)) ;
      }

      if( !f ){
      	 adjlist[26].push_back(ii(v,w)) ;
      	 f = true ;
      }

   }
  
  // out () ;
   
   return dij (26) ;

}





int main(){

  cin >> test ;
  getchar() ;
  while ( test--){
  	 cout << solve()<<"\n" ;
  	 if(test)
  	 cout<<"\n";
  }


	return 0 ;
}
