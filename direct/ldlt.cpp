#include <iostream>
#include <fstream>
#include <string>
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
int n;
void get_matrixA(char* fileA){
	ifstream myfile;
	string line;
	myfile.open(fileA);
	int i,j = 0;
	double a;
	if (myfile.is_open())
 	{
    	//while ( getline (myfile,line) )
    	while(myfile >> a)
    	{
    		A[i][j] = a;
      		//A[i][j] = stod(line);      		
      		//cout << A[i][j] << " ";
      		j++;
      		if(j==n){
      			i++;
      			j=0;
      		//	cout << endl;
      		}
      		
    	}
    	myfile.close();
  	}
}

void get_vectorB(char* fileB){
	ifstream myfile;
	string line;
	myfile.open(fileB);
	int i = 0;
	if (myfile.is_open())
 	{
    	while ( getline (myfile,line) )
    	{
      		b[i] = stod(line);      		
      		//cout << A[i][j] << " ";
      		i++;
      		
    	}
    	myfile.close();
  	}
}

void LDLt(){
	// storing in A;

	int v[n];
	rep(i,0,n-1){
		v[i] = 0;
	}
	//cout << "LU" << endl;
	rep(j,0,n-1){
		rep(i,0,j-1){
			v[i] = A[j][i]*A[i][i];
		}

		//cout << "v1" << endl;
		rep(i,0,j-1){
			A[j][j] = A[j][j] - A[j][i]*v[i];
		}

		//cout << "Ad2" << endl;
		int temp[n];
		rep(k,j+1,n-1){
			temp[k]=0;
			rep(i,0,j-1){
				temp[k]+=A[k][i]*v[i];
			}
		}
		//cout << "temp3" << endl;
		rep(i, j+1,n-1){
			A[i][j] = (A[i][j] - temp[i])/A[j][j];
		}
		//cout << "4f" << endl;

	}
double y = 0;
	// A = LDLt 
	// L(a) = b; Dy = a; Ltx= y

	//L(a) = b
	//aij = Lij if i>j
	b[0] = b[0];
	//b[1] = b[1]-b[0]*[1][0];
	rep(i,1,n-1){
		y=0;
		rep(j,0,i-1){
			y+=A[i][j]*b[j];
		}
		b[i]=(b[i]-y);
	}

	// Dy = a;
	rep(i,0,n-1){
		b[i] = A[i][i]*b[i];
	}

	rep(i,0,n-2){
		rep(j,i+1,n-1){
			A[i][j] = A[j][i];
		}
	}

	//Ltx = y
	b[n-1] = b[n-1];
	repd(i,n-2,0){
		y=0;
		rep(j,i+1,n-1){
			y+=A[i][j]*b[j];
		}
		b[i] = b[i]-y;
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

    LDLt();

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << duration << endl;

/*
	rep(i,0,n-1){
		cout << b[i] << endl;
	}*/
}