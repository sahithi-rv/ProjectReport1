## Project Report1 - Direct Solver and Iterative Solver for discrete Poisson Equation

### File Description
#### Direct Solver
* direct_lu.cpp: LU decomposition code
* ldlt.cpp: LDL^T factorization code
#### Iterative Solver
* cg.cpp: Conjugate Gradient iterative solver code
#### Test Matrices
* full_64.txt - Matrix A (64x64)
* full_256.txt - Matrix A (256x256)
* full_1024.txt - Matrix A (1024x1024)

* b64 - Vector B (64x1)
* b256 - Vector B (256x1)
* b1024 - Vector B (1024x1)

### Compile (using -std=c++11)
module load gcc/5.3.1
* g++ -O2 -std=c++11 direct/direct_lu.cpp - compiles LU code
* g++ -O2 -std=c++11 direct/ldlt.cpp - compiles LDL^T code

* g++ -O2 -std=c++11 iter/cg.cpp - compiles CG code

### Execute
* ./direct/direct_lu test_matrices/full_64.txt test_matrices/b64 64
* ./direct/direct_lu test_matrices/full_256.txt test_matrices/b256 256
* ./direct/direct_lu test_matrices/full_64.txt test_matrices/b64 1024
* ./direct/ldlt test_matrices/full_64.txt test_matrices/b64 64
* ./direct/ldlt test_matrices/full_64.txt test_matrices/b64 64
* ./direct/ldlt test_matrices/full_64.txt test_matrices/b64 64

* ./iter/cg test_matrices/b64 8 % only B vector
* ./iter/cg test_matrices/b256 16
* ./iter/cg test_matrices/b1024 32

### Licence
Please see license.txt for licensing information
