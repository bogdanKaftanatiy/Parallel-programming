//	  Lab4
//    Student: Bogdan Kaftanatiy
//    Group:   IP-42
//    Date:    23/10/2016
//
//    F1: c = MAX(MA*MB)*(A*B)
//    F2: MF = MAX(MG)*(MH*MK)
//    F3: T= SORT(O + P)*TRANS(MR*MS)
#pragma warning(disable:4996)

#include "Data.h"

#include <windows.h>
#include <iostream>

#define THREAD_STACK_SIZE 1000000 // 1 MB
#define N 1000

void Thread1();
void Thread2();
void Thread3();

using namespace std;

int main()
{
	DWORD Tid1, Tid2, Tid3;
	HANDLE T1 = CreateThread(NULL, THREAD_STACK_SIZE, (LPTHREAD_START_ROUTINE)Thread1, NULL, CREATE_SUSPENDED, &Tid1);
	HANDLE T2 = CreateThread(NULL, THREAD_STACK_SIZE, (LPTHREAD_START_ROUTINE)Thread2, NULL, CREATE_SUSPENDED, &Tid2);
	HANDLE T3 = CreateThread(NULL, THREAD_STACK_SIZE, (LPTHREAD_START_ROUTINE)Thread3, NULL, CREATE_SUSPENDED, &Tid3);

	SetThreadPriority(T1, 1);
	SetThreadPriority(T2, 2);
	SetThreadPriority(T3, 3);

	ResumeThread(T1);
	ResumeThread(T2);
	ResumeThread(T3);

	WaitForSingleObject(T1, INFINITE);
	WaitForSingleObject(T2, INFINITE);
	WaitForSingleObject(T3, INFINITE);

	CloseHandle(T1);
	CloseHandle(T2);
	CloseHandle(T3);

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