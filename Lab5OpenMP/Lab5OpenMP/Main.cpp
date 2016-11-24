//	  Lab5
//    Student: Bogdan Kaftanatiy
//    Group:   IP-42
//
//    F1: c = MAX(MA*MB)*(A*B)
//    F2: MF = MAX(MG)*(MH*MK)
//    F3: T= SORT(O + P)*TRANS(MR*MS)
#pragma warning(disable:4996)

#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <omp.h>

#include "Data.h"



#define N 1000

void Task1();
void Task2();
void Task3();

using namespace std;

int main()
{
#pragma omp parallel num_threads(3)
	{
		int i = omp_get_thread_num();
		if (i == 0)
			Task1();
		if (i == 1)
			Task2();
		if (i == 2)
			Task3();
	}

	cout << "Main thread finished execution!\n";
	system("pause");
	return 0;
}

void Task1()
{
	cout << "Thread 1 started!\n";

	Vector* A = new Vector(N, true);
	Vector* B = new Vector(N, true);
	Matrix* MA = new Matrix(N, true);
	Matrix* MB = new Matrix(N, true);


	int c = (*MA * *MB)->getMaxElement() * (*A * *B);
	delete A, B, MA, MB;
	printf("F1 = %d\n", c);

	cout << "Thread 1 finished execution!\n";
}

void Task2()
{
	cout << "Thread 2 started!\n";

	Matrix* MG = new Matrix(N, true);
	Matrix* MH = new Matrix(N, true);
	Matrix* MK = new Matrix(N, true);


	Matrix* MF = *(*MH * *MK) * MG->getMaxElement();

	cout << "F2 = \n" << MF->getString() << endl;

	delete MG, MH, MK, MF;

	cout << "Thread 2 finished execution!\n";
}

void Task3()
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