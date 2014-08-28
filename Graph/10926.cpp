#include <bits/stdc++.h>
using namespace std ;

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


bool depend [111][111] ;
int n ;

typedef vector  <int> vi ;
vector < vi > adjlist ;

void dfs ( int root , int  u){
	depend [root][u] = true ;
	for(int i = 0; i < adjlist[u].size() ; i++)
    {
    	 int v = adjlist[u][i] ;
    	 if( !depend[root] [v] ){
    	 	 dfs ( root , v) ;
    	 }
    }
}

int solve(){
   int i , j, k, l ;
   for ( i = 0 ; i <= n ; i++)
   for( j = 0 ; j <= n ; j++)
   depend[i][j] = false ;
   
   adjlist.clear() ;
   adjlist.assign(n+1,vi()) ;

   for ( i = 1 ; i <= n ; i++){
   	   cin >> j ;
   	   for ( k = 0 ; k < j ; k++){
   	   	   cin >> l ;
   	   	   adjlist[l].push_back ( i ) ;
   	   }
   }

   for ( i = 1 ; i <= n ; i++){
   	 dfs ( i , i) ;
   	 // cout << i << "- \n" ;
   }

   int ans , maxi = 0 ;
   /* for ( i = 1 ; i <= n ; i++){
   	  for( j = 1 ; j <= n ; j++)
   	  cout << depend[i][j] <<" " ;
   	  cout << endl;
   } */

   for ( i = 1 ; i <= n ; i++)
   {
   	   int temp = 0 ; 
   	   for( j = 1 ; j <= n ; j++)
   	   if( depend[j][i] )
   	   temp++ ;

   	  if( temp > maxi){
   	  	  maxi = temp ; ans = i ;
   	  }
   }

   return ans ;

}

int main(){
   
    while ( cin >> n ){
    	if( n == 0)
    	break ;
       cout << solve() <<"\n" ;
    }

	return 0 ;
}
