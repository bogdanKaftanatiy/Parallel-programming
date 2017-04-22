#include <iostream>
#include "mpi.h"

using namespace std;

const int N = 6;
const int P = 6;
const int H = N / P;

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



int main(int argc, char* argv[])
{

	MPI_Init(&argc, &argv);

	int rank;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int A[N], B[N], E[N], Z[N];
	int MO[N][N], MK[N][N];
	int d, a;
	MPI_Status status;

	cout << "Thread N_" << rank << endl;

	if (rank == 0)
	{
		inputVector(Z);
		inputVector(E);

		MPI_Send(Z + H, H * 2, MPI_INT, 1, 0, MPI_COMM_WORLD);
		MPI_Send(E + H, H * 2, MPI_INT, 1, 0, MPI_COMM_WORLD);

		MPI_Send(Z + (H * 3), H * 3, MPI_INT, 3, 0, MPI_COMM_WORLD);
		MPI_Send(E + (H * 3), H * 3, MPI_INT, 3, 0, MPI_COMM_WORLD);


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
		MPI_Recv(Z + 3 * H, 3 * H, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 3 * H, 3 * H, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

		MPI_Send(Z + 4 * H, 2 * H, MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(E + 4 * H, 2 * H, MPI_INT, 4, 0, MPI_COMM_WORLD);


		MPI_Recv(B, N, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N * N, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);


		MPI_Recv(&d, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MO, N*N, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
	}
	else if (rank == 4)
	{
		MPI_Recv(Z + 4 * H, 2 * H, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 4 * H, 2 * H, MPI_INT, 3, 0, MPI_COMM_WORLD, &status);

		MPI_Send(Z + 5 * H, H, MPI_INT, 5, 0, MPI_COMM_WORLD);
		MPI_Send(E + 5 * H, H, MPI_INT, 5, 0, MPI_COMM_WORLD);


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

		MPI_Recv(Z + 5 * H, H, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(E + 5 * H, H, MPI_INT, 4, 0, MPI_COMM_WORLD, &status);


		MPI_Recv(B, N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);
		MPI_Recv(MK, N * N, MPI_INT, 2, 0, MPI_COMM_WORLD, &status);

		MPI_Send(B, N, MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(MK, N * N, MPI_INT, 4, 0, MPI_COMM_WORLD);



		MPI_Send(&d, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 2, 0, MPI_COMM_WORLD);

		MPI_Send(&d, 1, MPI_INT, 4, 0, MPI_COMM_WORLD);
		MPI_Send(MO, N*N, MPI_INT, 4, 0, MPI_COMM_WORLD);
	}

	/*if (rank == 4)
	{
		cout << "Thread N_" << rank << endl;
		cout << "Int d: " << d << endl;
		cout << "Vector Z:" << endl;
		outputVector(Z);
		cout << "Vector E:" << endl;
		outputVector(E);
		cout << "Vector B:" << endl;
		outputVector(B);
		cout << "Matrix MO:" << endl;
		outputMatrix(MO);
		cout << "Matrix MK:" << endl;
		outputMatrix(MK);
	}*/



	MPI_Finalize();
	return 0;
}