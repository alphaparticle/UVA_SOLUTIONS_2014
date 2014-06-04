
// Suffix Array ( nlogn )
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;

#define MAXN 100010
char T[MAXN], P[MAXN];
int n, m;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN], phi[MAXN];
int LCP[MAXN], PLCP[MAXN];

void countSort(int k) {
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for (i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for (i = sum = 0; i < maxi; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for (i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
	for (i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void makeSA() {
	int i, k, r;
	for (i = 0; i < n; i++) {
		RA[i] = T[i];
		SA[i] = i;
	}
	for (k = 1; k < n; k <<= 1) {
		countSort(k);
		countSort(0);
		tempRA[SA[0]] = r = 0;
		for (i = 1; i < n; i++)
			tempRA[SA[i]] =
					(RA[SA[i]] == RA[SA[i - 1]]
							&& RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
		for (i = 0; i < n; i++)
			RA[i] = tempRA[i];
	}
}

int main() {
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%s", P);
		m = strlen(P);
		T[0] = '\0';
		strcat(T, P);
		strcat(T, P);
		strcat(T, "{");
		n = strlen(T);
		makeSA();

		for (int i = 0; i <= n; i++) {
			if (SA[i] < m) {
				printf("%d\n", SA[i] + 1);
				break;
			}
		}
	}

	return 0;
}

// TLE Suffix Array ( nlognlogn )

/*
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

#define MAXN 100010
#define MAXLG 50

char A[MAXN];
char temp [MAXN] ;

struct entry {
int nr[2], p;
} L[MAXN];

int P[MAXLG][MAXN], N, i, stp, cnt;

int cmp(struct entry a, struct entry b)
{
return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}



int main(void)
{
     int test ;
     cin >> test ;
     getchar() ;
         while ( test -- ){
           gets(temp) ;
        N = strlen ( temp) ;
        for ( i = 0 ; i  < N ; i++)
        A[i] = temp [i] ;
        int j = N ;
        for ( i = 0 ; i < N ; i++)
        A[j++] = temp[i] ;
    //    A[j] = '\0' ;
      //  printf("%s\n",A);

          N  = strlen ( A ) ;
        // cout << N << endl;

            for ( i = 0; i < N; i ++)
            P[0][i] = A[i] - 'a';

                for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
                {
                        for (i = 0; i < N; i ++)
                        {
                            L[i].nr[0] = P[stp - 1][i];
                            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
                            L[i].p = i;
                        }
                        sort(L, L + N, cmp);

                        for (i = 0; i < N; i ++)
                        P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
                }

         // cout <<stp << endl;

  //       for( i = 0 ; i < strlen(temp) ; i++)
    //     cout << " " << P[stp-1][i] ;
      //   cout << endl;
        int index , ans ;
        ans =  N ; index = 0 ;

         for ( i = 0 ; i < strlen(temp) ; i++ )
         if( P[stp-1] [i] < ans){
             ans = P[stp-1][i] ;
             index = i ;
         }

         cout << index + 1 << endl;


      // for ( i = 0  ; i <  N ; i++){
      //      string x ;
      // int index = P [stp-1][i] ;
      //      for( int j  =  index  ; j <  N ; j++){
      //          x += A[j] ;
      //      }
      //  cout << x << endl;
      //    }


     }

         return 0;
}

*/
