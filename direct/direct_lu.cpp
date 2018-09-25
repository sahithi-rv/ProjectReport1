#include<bits/stdc++.h>
#include <chrono>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define RI(a) scanf("%d",&a);
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define TR(a,t) for(__typeof(a.begin()) t=a.begin();t!=a.end();t++)
#define rep(i,l,h) for(int i=(l); i<=(h);i++)
#define repd(i,h,l) for(int i=(h);i>=(l);i--)
#define ALL(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define PRSNT(a,e) (a.find(e) != a.end())
#define MINH priority_queue<int, vector<int>, greater<int> >
#define output1(x) cout << #x << " " << x << endl;
#define output2(x,y) cout <<x<<" "<<y <<endl;
#define inp1(x) cin >> x;
#define inp2(x,y) cin >> x >> y;
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define N 1100

using namespace std;
using namespace std::chrono;
double A[N][N],  b[N];
int n; string fa, fb; 
void get_matrixA(string fileA){

	ifstream myfile(fileA);
	rep(i,0,n-1){
		rep(j,0,n-1){
			myfile >> A[i][j];
		}
	}
	myfile.close();

}

void get_vectorB(string fileB){

  	ifstream myfile(fileB);
	rep(i,0,n-1){
		myfile >> b[i];
	}
	myfile.close();
}

void LU(){
	// storing in A;
	//cout << "LU" << endl;
	rep(k,0,n-1){
		rep(h,k+1, n-1){
			A[h][k] = A[h][k]/A[k][k];
		}

		rep(i,k+1,n-1){
			rep(j,k+1,n-1){
				A[i][j] = A[i][j] - A[i][k]*A[k][j];
			}
		}
	}

	// solve Ly = b; - fwd substitution
	// storing back in b
	b[0] = b[0]/A[0][0];
	double y = 0;
	rep(i,1,n-1){
		y=0;
		rep(j,0,i-1){
			y+=A[i][j]*b[j];
		}
		b[i] = (b[i]-y);//A[i][i];
	}

	//solve for Ux = b - bwd substitution
	// storing back in b
	b[n-1] = b[n-1]/A[n-1][n-1];
	repd(i,n-2,0){
		y=0;
		rep(j,i+1,n-1){
			y+=A[i][j]*b[j];
		}
		b[i] = (b[i]-y)/A[i][i];
	}
}

int main(int argc, char *argv[]){

	if(argc<3){
		printf("Enter 3 arguments: input file for matrix A, input file for vector B,  matrix size\n");
		return 0;		
	}

	n = atoi(argv[3]);
	get_matrixA(argv[1]);
	get_vectorB(argv[2]);

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

    LU();

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;

	/*rep(i,0,n-1){
		cout << b[i] << endl;
	}*/
}