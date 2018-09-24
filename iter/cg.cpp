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

int n;

double EPS = 0.0001;
void get_vectorB(char* fileB, double **b){
	ifstream myfile;
	string line;
	myfile.open(fileB);
	int i,j = 0;
	if (myfile.is_open())
 	{
    	while ( getline (myfile,line) )
    	{
      		b[i][j] = stod(line);      		
      		j++;
      		if(j==n){
      			i++;
      			j=0;
      		}
      		
    	}
    	myfile.close();
  	}
}

void matmul(double **b, double **out){
	rep(i,0,n-1){
		rep(j,0,n-1){
			if(i==0 && j==0){
				out[i][j] = 4*b[i][j] - b[i][j+1] - b[i+1][j];
			}else if (i==0 && j==(n-1)){
				out[i][j] = 4*b[i][j] - b[i][j-1] - b[i+1][j];
			}else if (i==(n-1) && j==0){
				out[i][j] = 4*b[i][j] - b[i][j+1] - b[i-1][j];
			}else if (i==(n-1) && j==(n-1)){
				out[i][j] = 4*b[i][j] - b[i][j-1] - b[i-1][j];
			}else if (i==0){
				out[i][j] = 4*b[i][j] - b[i+1][j] - b[i][j-1] - b[i][j+1];
			}else if (j==0){
				out[i][j] = 4*b[i][j] - b[i+1][j] - b[i-1][j] - b[i][j+1];
			}else if (i==(n-1)){
				out[i][j] = 4*b[i][j] - b[i][j-1] - b[i][j+1] - b[i-1][j];
			}else if (j==(n-1)){
				out[i][j] = 4*b[i][j] - b[i-1][j] - b[i+1][j] - b[i][j-1];
			}else{
				out[i][j] = 4*b[i][j] - b[i+1][j] - b[i-1][j] - b[i][j+1] - b[i][j-1];
			}
		}
	}
}

double dot_product(double **l, double **m ){

	double out = 0.0;
	rep(i,0,n-1){
		rep(j,0,n-1){
			out += l[i][j]*m[i][j];
		}
	}
	return out;
}

double dot_product(double **l ){

	double out = 0.0;
	rep(i,0,n-1){
		rep(j,0,n-1){
			out += l[i][j]*l[i][j];
		}
	}
	return out;
}

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Enter  arguments: input file for vector B,  Grid size\n");
		return 0;		
	}
	n = atoi(argv[2]);
	cout << n << endl;
	//double r[n][n], b[n][n], z[n][n], p[n][n], x[n][n];
	double **r, **b, **z, **p, **x;
	
	b = (double **)malloc(sizeof(double*)*n);
	rep(i,0,n-1){
		b[i] = (double *)malloc((sizeof(double))*n);
	}
	r = (double **)malloc(sizeof(double*)*n);
	rep(i,0,n-1){
		r[i] = (double *)malloc((sizeof(double))*n);
	}
	z = (double **)malloc(sizeof(double*)*n);
	rep(i,0,n-1){
		z[i] = (double *)malloc((sizeof(double))*n);
	}
	p = (double **)malloc(sizeof(double*)*n);
	rep(i,0,n-1){
		p[i] = (double *)malloc((sizeof(double))*n);
	}	
	x = (double **)malloc(sizeof(double*)*n);
	rep(i,0,n-1){
		x[i] = (double *)malloc((sizeof(double))*n);
	}
	
	get_vectorB(argv[1], b);
	double del_new = 0,  del_old;
	//init b,p, r,x;
	srand((unsigned)time(0)); 

	
	for(int i = 0;i<n;i++){
   		for(int j = 0;j<n;j++){
   			x[i][j] = 0.1*(rand()%10)+1;
   		}
   	}

   	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for(int i = 0;i<n;i++){
   		for(int j = 0;j<n;j++){
   			r[i][j] = b[i][j];
   			p[i][j] = b[i][j];
   			
        	del_new += b[i][j]*b[i][j];
        }
    }

    del_old = del_new;
	double double1 = del_new;
	double double2 = del_old;
	double double3 = sqrt(abs(double1));
	double put;
    //iterations
    double vv, alpha, beta;
    double leps = log10(EPS);
	put = log10(double3/sqrt(double2) ) ;
    while (put >= leps){

    	matmul(p,z);

    	vv = dot_product(z,p);
    	alpha = del_old/vv;

    	rep(i,0,n-1){
    		rep(j,0,n-1){
    			x[i][j] = x[i][j] + alpha*p[i][j];
    		}
    	}

    	rep(i,0,n-1){
    		rep(j,0,n-1){
    			r[i][j] = r[i][j] - alpha*z[i][j];
    		}
    	}

    	del_new = dot_product(r);

    	beta = del_new/del_old;

    	rep(i,0,n-1){
    		rep(j,0,n-1){
    			p[i][j] = r[i][j] + beta*p[i][j];
    		}
    	}

    	del_old = del_new;
    	double1 = del_new;
    	double3 = sqrt(abs(double1));
		put = log10(double3/sqrt(double2) ) ;
    	cout << put << " ";
   }
    
    cout << endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "exec time:" << duration << endl;
   /* ofstream f;
    f.open("xtemp");
    rep(i,0,n-1){
    	rep(j,0,n-1){
    		f << std::fixed << std::setprecision(8) << x[i][j];
    		f << '\n';
    	}
    }
    f.close();*/
    free(b);
    free(r);
    free(z);
    free(x);
    free(p);

	

}