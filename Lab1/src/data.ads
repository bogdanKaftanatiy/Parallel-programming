generic
   n: Integer;
package data is
   type Vector is private;
   type Matrix is private;

   procedure Vector_Generate(A: out Vector;size, number: in Integer);
   procedure Vector_Print(A: in Vector);
   procedure Matrix_Generate(A: out Matrix;size, number: in Integer);
   procedure Matrix_Print(A: in Matrix);

   function Vector_Sum(A,B: in Vector) return Vector;
   function Vector_Multiplication(A,B : in Vector) return Integer;
   function Matrix_Multiplication(A,B : in Matrix) return Matrix;
   function Vector_Number_Multiplication(A: in Vector; S: in Integer) return Vector;
   function Matrix_Number_Multiplication(A : in Matrix; S: in Integer) return Matrix;
   function Vector_Matrix_Multiplication(A: in Vector; B: in Matrix) return Vector;
   function Vector_Sorting(A: in out Vector) return Vector;
   function Matrix_Trans(A: in out Matrix) return Matrix;
   function Matrix_MAX(A: in Matrix) return Integer;

   function Func1(MA, MB : in Matrix; A,B: in Vector) return Integer;
   function Func2(MG,MH,MK : in Matrix) return Matrix;
   function Func3(O,P: in Vector;MR,MS : in Matrix) return Vector;

private
   type Vector is array(1..n) of Integer;
   type Matrix is array(1..n) of Vector;

   end data;
