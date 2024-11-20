
#include <iostream>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <omp.h>
//solve
extern "C"
{
 extern void zgesv_(int*N,int*Nrds, std::complex<double>*A,int*ldA,int *Iput, std::complex<double>*B,int*ldB,int *info);
}

int main() 
{
    int Nrhs = 1;  
    int lda, ldb, info;       
    int* ipiv;
    
    std::complex<double>* A;
    std::complex<double>* A2;
    std::complex<double>* B;
    std::complex<double>* B2;
    std::complex<double>* error;

    std::srand(std::time(nullptr));

    for (int N = 1000; N <= 16000; N *= 2) 
    {  
        lda = ldb = N;
        ipiv = (int*)malloc(N * sizeof(int));
        A = (std::complex<double>*)malloc(N * N * sizeof(std::complex<double>));
        A2 = (std::complex<double>*)malloc(N * N * sizeof(std::complex<double>));
        B = (std::complex<double>*)malloc(N * sizeof(std::complex<double>));
        B2 = (std::complex<double>*)malloc(N * sizeof(std::complex<double>));
        error = (std::complex<double>*)malloc(N * sizeof(std::complex<double>));

        std::cout << "Matrix A for N = " << N << ":" << std::endl;
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < N; ++j) 
            {
                double real = (std::rand() % 201 - 100) / 10.0; 
                double imag = (std::rand() % 201 - 100) / 10.0; 
                A[i * N + j] = {real, imag};
                A2[i * N + j] = A[i * N + j];
            }
        }

       
        std::cout << "Vector B for N = " << N << ":" << std::endl;
        for (int i = 0; i < N; ++i) {
            double real = (std::rand() % 201 - 100) / 10.0; 
            double imag = (std::rand() % 201 - 100) / 10.0; 
            B[i] = {real, imag};
            B2[i] = B[i];
        }

        
        double start_time = omp_get_wtime();
        
        zgesv_(&N, &Nrhs, A, &lda, ipiv, B, &ldb, &info);
        
        double end_time = omp_get_wtime();
        std::cout << "Time for N = " << N << " is " << end_time - start_time << " seconds" << std::endl;

        // A2 * B - B2 = error
        for (int i = 0; i < N; ++i) 
        {
            error[i] = {0.0, 0.0}; 
            for (int j = 0; j < N; ++j)
            {
                error[i] += A2[j * N + i] * B[j];  // A2 * B
            }
            error[i] -= B2[i];  // A2 * B - B2
        }

        // Норма ошибки
        double norm = 0.0;
        for (int i = 0; i < N; ++i) 
        {
            norm += std::norm(error[i]);
        }
        norm = std::sqrt(norm); 

        std::cout << "2-norm of the error for N = " << N << ": " << norm << std::endl;

        free(A);
        free(A2);
        free(B);
        free(B2);
        free(ipiv);
        free(error);
        std::cout << std::endl;
    }

    return 0;
}


