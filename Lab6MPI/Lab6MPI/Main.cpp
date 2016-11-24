//	  Lab6
//    Student: Bogdan Kaftanatiy
//    Group:   IP-42
//
//    F1: c = MAX(MA*MB)*(A*B)
//    F2: MF = MAX(MG)*(MH*MK)
//    F3: T= SORT(O + P)*TRANS(MR*MS)
#pragma warning(disable:4996)

#include "Data.h"

#include <windows.h>
#include <iostream>
#include <mpi.h>

#define N 1000

void Thread1();
void Thread2();
void Thread3();

using namespace std;

int main(int argc, char** argv)
{
	MPI_Init(&argc, &argv);
	#pragma comment(linker, "/STACK:400000000")

	int tid;

	MPI_Comm_rank(MPI_COMM_WORLD, &tid);

	switch (tid)
	{
	case 0:
		Thread1();
		break;
	case 1:
		Thread2();
		break;
	case 2:
		Thread3();
		break;
	}

	MPI_Finalize();

	cout << "Main thread finished execution!\n";
	system("pause");
	return 0;
}

void Thread1()
{
	cout << "Thread 1 started!\n";

	Vector* A = new Vector(N, true);
	Vector* B = new Vector(N, true);
	Matrix* MA = new Matrix(N, true);
	Matrix* MB = new Matrix(N, true);


	int c = (*MA * *MB)->getMaxElement() * (*A * *B);
	delete A, B, MA, MB;
	Sleep(1000);
	printf("F1 = %d\n", c);

	cout << "Thread 1 finished execution!\n";
}

void Thread2()
{
	cout << "Thread 2 started!\n";

	Matrix* MG = new Matrix(N, true);
	Matrix* MH = new Matrix(N, true);
	Matrix* MK = new Matrix(N, true);


	Matrix* MF = *(*MH * *MK) * MG->getMaxElement();

	Sleep(100);
	cout << "F2 = \n" << MF->getString() << endl;

	delete MG, MH, MK, MF;

	cout << "Thread 2 finished execution!\n";
}

void Thread3()
{
	cout << "Thread 3 started!\n";

	Vector* O = new Vector(N, true);
	Vector* P = new Vector(N, true);
	Matrix* MR = new Matrix(N, true);
	Matrix* MS = new Matrix(N, true);

	Vector* T = *((*MR * *MS)->transpose()) * *((*O + *P)->sort());

	delete O, P, T, MR, MS;
	cout << "F3 = \n" << T->getString() << endl;

	cout << "Thread 3 finished execution\n";
}