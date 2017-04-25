#include <iostream>
#include <limits.h>
#include "mpi.h"

using namespace std;

const int N = 600;

void inputMatrix(int matrix[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = 1;
		}
	}
}
void outputMatrix(int matrix[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void inputVector(int vector[N])
{
	for (int i = 0; i < N; i++)
	{
		vector[i] = 1;
	}
}
void outputVector(int vector[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

int maxElement(int vector[N], int from, int to)
{
	int result = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		if (vector[i] > result)
			result = vector[i];
	}
	return result;
}



int main(int argc, char* argv[])
{

	MPI_Init(&argc, &argv);

	int rank, size;

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int P = size;
	int H = N / P;

	int A[N], B[N], E[N], Z[N];
	int MO[N][N], MK[N][N];
	int d, a;
	MPI_Status status;

	if (rank == 0)
	{
		inputVector(Z);
		inputVector(E);

		MPI_Send(Z + H, H * 2, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(E + H, H * 2, MPI_INT, 1, 0, MPI_COMM_WORLD);

		MPI_Send(Z + (H * 3), N - (H * 3), MPI_INT, 3, 0, MPI_COMM_WORLD);
		MPI_Send(E + (H * 3), N - (H * 3), MPI_INT, 3, 0, MPI_COMM_WORLD);


		MPI_Recv(B, N, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N*N, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);


		MPI_Recv(&d, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MO, N*N, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
	}
	else if (rank == 1)
	{
		MPI_Recv(Z + H, H * 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + H, H * 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

		MPI_Send(Z + 2 * H, H, MPI_INT, 2, 0, MPI_COMM_WORLD);
		MPI_Send(E + 2 * H, H, MPI_INT, 2, 0, MPI_COMM_WORLD);


		MPI_Recv(B, N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N * N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);

		MPI_Send(B, N, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Send(MK, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD);


		MPI_Recv(&d, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MO, N*N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);

		MPI_Send(&d, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	else if (rank == 2)
	{
		inputVector(B);
		inputMatrix(MK);

		MPI_Recv(Z + 2 * H, H, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 2 * H, H, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);


		MPI_Send(B, N, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(MK, N * N, MPI_INT, 1, 0, MPI_COMM_WORLD);

		MPI_Send(B, N, MPI_INT, 5, 0, MPI_COMM_WORLD);
		MPI_Send(MK, N * N, MPI_INT, 5, 0, MPI_COMM_WORLD);



		MPI_Recv(&d, 1, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MO, N*N, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);

		MPI_Send(&d, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else if (rank == 3) {
		MPI_Recv(Z + 3 * H, N - (H * 3), MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 3 * H, N - (H * 3), MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

		MPI_Send(Z + 4 * H, N - (H * 4), MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(E + 4 * H, N - (H * 4), MPI_INT, 4, 0, MPI_COMM_WORLD);


		MPI_Recv(B, N, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N * N, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);


		MPI_Recv(&d, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MO, N*N, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
	}
	else if (rank == 4)
	{
		MPI_Recv(Z + 4 * H, N - (H * 4), MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 4 * H, N - (H * 4), MPI_INT, 3, 0, MPI_COMM_WORLD, &status);

		MPI_Send(Z + 5 * H, N - (H * 5), MPI_INT, 5, 0, MPI_COMM_WORLD);
		MPI_Send(E + 5 * H, N - (H * 5), MPI_INT, 5, 0, MPI_COMM_WORLD);


		MPI_Recv(B, N, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N * N, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);

		MPI_Send(B, N, MPI_INT, 3, 0, MPI_COMM_WORLD);
		MPI_Send(MK, N * N, MPI_INT, 3, 0, MPI_COMM_WORLD);


		MPI_Recv(&d, 1, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MO, N*N, MPI_INT, 5, 0, MPI_COMM_WORLD, &status);

		MPI_Send(&d, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 3, 0, MPI_COMM_WORLD);

	}
	else if (rank == 5)
	{
		d = 1;
		inputMatrix(MO);

		MPI_Recv(Z + 5 * H, N - (H * 5), MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 5 * H, N - (H * 5), MPI_INT, 4, 0, MPI_COMM_WORLD, &status);


		MPI_Recv(B, N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N * N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);

		MPI_Send(B, N, MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(MK, N * N, MPI_INT, 4, 0, MPI_COMM_WORLD);



		MPI_Send(&d, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 2, 0, MPI_COMM_WORLD);

		MPI_Send(&d, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 4, 0, MPI_COMM_WORLD);
	}

	int startIndex = rank*H;
	int endIndex = rank == P - 1 ? N : (rank + 1) * H;

	int a_i = maxElement(Z, startIndex, endIndex);

	MPI_Allreduce(&a_i, &a, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);

	for (int i = startIndex; i < endIndex; i++)
	{
		int tempV[N];
		for (int j = 0; j < N; j++)
		{
			int M = 0;
			for (int k = 0; k < N; k++)
			{
				M += MK[i][k] * MO[k][j];
			}
			tempV[j] = M;
		}

		int resultNumber = 0;
		for (int j = 0; j < N; j++)
		{
			resultNumber += tempV[i] * B[i];
		}

		A[i] = a * E[i] + d * resultNumber;
	}


	if (rank == 5)
	{
		MPI_Send(A + (H * 5), N - (H * 5), MPI_INT, 4, 0, MPI_COMM_WORLD);
	}
	else if (rank == 4)
	{
		MPI_Recv(A + (H * 5), N - (H * 5), MPI_INT, 5, 0, MPI_COMM_WORLD, &status);

		MPI_Send(A + (H * 4), N - (H * 4), MPI_INT, 3, 0, MPI_COMM_WORLD);
	}
	else if (rank == 3)
	{
		MPI_Recv(A + (H * 4), N - (H * 4), MPI_INT, 4, 0, MPI_COMM_WORLD, &status);

		MPI_Send(A + (H * 3), N - (H * 3), MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	else if (rank == 2)
	{
		MPI_Send(A + (H * 2), H, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else if (rank == 1)
	{
		MPI_Recv(A + (H * 2), H, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);

		MPI_Send(A + H, 2 * H, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}
	else if (rank == 0)
	{
		MPI_Recv(A + H, 2 * H, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);

		MPI_Recv(A + (H * 3), N - (H * 3), MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
	}


	//output
	if (rank == 0)
	{
		cout << "Result A:" << endl;
		if (N <= 15)
			outputVector(A);
		else
			cout << "Vector is too large." << endl;
	}

	MPI_Finalize();
	return 0;
}