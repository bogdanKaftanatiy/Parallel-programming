with Ada.Text_IO;

package body data is

   ---------------------
   -- Vector_Generate --
   ---------------------

   procedure Vector_Generate (A: out Vector; size, number: in Integer) is
      N: Integer;
   begin
      N:=number;
      for i in 1..size loop
         A(i):= N;
         N:=N+1;
      end loop;
   end Vector_Generate;

   ------------------
   -- Vector_Print --
   ------------------

   procedure Vector_Print (A: in Vector) is
   begin
     for i in 1..n loop
         Ada.Text_IO.Put("" & Integer'Image(A(i)));
         Ada.Text_IO.Put(' ');
     end loop;
   end Vector_Print;

   ---------------------
   -- Matrix_Generate --
   ---------------------

   procedure Matrix_Generate (A: out Matrix; size, number: in Integer) is
      N: Integer;
   begin
      N:=number;
      for i in 1..size loop
         for j in 1..size loop
            A(i)(j):=N;
            N:=N+1;
         end loop;
         N:=number;
     end loop;
   end Matrix_Generate;

   ------------------
   -- Matrix_Print --
   ------------------

   procedure Matrix_Print (A: in Matrix) is
   begin
     for i in 1..n loop
         for j in 1..n loop
            Ada.Text_IO.Put(""& Integer'Image(A(i)(j)));
            Ada.Text_IO.Put(" ");
         end loop;
         Ada.Text_IO.Put_Line(" ");
      end loop;
   end Matrix_Print;

   ----------------
   -- Vector_Sum --
   ----------------

   function Vector_Sum (A,B: in Vector) return Vector is
      S: Vector;
   begin
     for i in 1..n loop
         S(i):=A(i)+B(i);
      end loop;
      return S;
   end Vector_Sum;

   ---------------------------
   -- Vector_Multiplication --
   ---------------------------

   function Vector_Multiplication(A,B : in Vector) return Integer is
      S: Integer;
   begin
      S:=0;
      for i in 1..n loop
         S:=S + A(i)*B(i);
      end loop;
      return S;
   end Vector_Multiplication;

   ---------------------------
   -- Matrix_Multiplication --
   ---------------------------

   function Matrix_Multiplication (A,B : in Matrix) return Matrix is
      P: Matrix;
      S:  Integer;
   begin
       for k in 1..n loop
         for i in 1..n loop
            s:=0;
            for j in 1..n loop
               S:= S + A(k)(j)*B(j)(i);
               P(k)(i):=S;
            end loop;
         end loop;
      end loop;
      return P;
   end Matrix_Multiplication;

   ----------------------------------
   -- Vector_Number_Multiplication --
   ----------------------------------

   function Vector_Number_Multiplication(A: in Vector; S: in Integer) return Vector is
      R: Vector;
   begin
      for i in 1..n loop
         R(i):=A(i)*S;
      end loop;
      return R;
   end Vector_Number_Multiplication;

   ----------------------------------
   -- Matrix_Number_Multiplication --
   ----------------------------------

   function Matrix_Number_Multiplication(A : in Matrix; S: in Integer) return Matrix is
      R: Matrix;
   begin
      for i in 1..n loop
         for j in 1..n loop
            R(i)(j):=A(i)(j) * S;
         end loop;
      end loop;
      return R;
   end Matrix_Number_Multiplication;

   ----------------------------------
   -- Vector_Matrix_Multiplication --
   ----------------------------------

   function Vector_Matrix_Multiplication
     (A: in Vector;
      B: in Matrix)
      return Vector
   is
      P: Vector;
      S: Integer;
   begin
      for i in 1..n loop
         S:=0;
         for j in 1..n loop
            S:=S+A(i)*B(j)(i);
         end loop;
         P(i):=S;
      end loop;
      return P;
   end Vector_Matrix_Multiplication;

   --------------------
   -- Vector_Sorting --
   --------------------

   function Vector_Sorting (A: in out Vector) return Vector is
      S: Integer;
   begin
      for i in 1..n loop
         for j in 1..n loop
            if A(i)>A(j) then
               S:=A(j);
               A(j):=A(i);
               A(i):=S;
            end if;
         end loop;
      end loop;
      return A;
   end Vector_Sorting;

   ------------------
   -- Matrix_Trans --
   ------------------

   function Matrix_Trans (A: in out Matrix) return Matrix is
      S: Integer;
   begin
      for i in 1..n loop
         for j in i..n loop
            S:=A(i)(j);
            A(i)(j):=A(j)(i);
            A(j)(i):=S;
         end loop;
      end loop;
      return A;
   end Matrix_Trans;

   ----------------
   -- Matrix_MAX --
   ----------------

   function Matrix_MAX(A: in Matrix) return Integer is
      S: Integer;
   begin
      S:= -999999;
      for i in 1..n loop
         for j in i..n loop
            if A(i)(j) > S then
               S:= A(i)(j);
               end if;
         end loop;
      end loop;
      return S;
   end Matrix_MAX;

   -----------
   -- Func1 --
   -----------

   function Func1(MA, MB : in Matrix; A,B: in Vector) return Integer is
         M1: Matrix;
         I2: Integer;
         R: Integer;
         I1: Integer;
   begin
         M1:=Matrix_Multiplication(MA, MB);
         I2:=Vector_Multiplication(A, B);
         I1:=Matrix_MAX(M1);
         R:=I1*I2;
         return R;
   end Func1;

   -----------
   -- Func2 --
   -----------

   function Func2(MG,MH,MK : in Matrix) return Matrix is
         MF: Matrix;
         M1: Matrix;
         S: Integer;
   begin
         S:=Matrix_MAX(MG);
         M1:=Matrix_Multiplication(MH, MK);
         MF:=Matrix_Number_Multiplication(M1, S);
         return MF;
   end Func2;

   -----------
   -- Func3 --
   -----------

   function Func3(O,P: in Vector;MR,MS : in Matrix) return Vector is
         V1: Vector;
         V2: Vector;
         M1: Matrix;
         T: Vector;
   begin
         V1:=Vector_Sum(O,P);
         V2:=Vector_Sorting(V1);
         M1:=Matrix_Multiplication(MR, MS);
         T:=Vector_Matrix_Multiplication(V2, M1);
         return T;
   end Func3;

end data;
