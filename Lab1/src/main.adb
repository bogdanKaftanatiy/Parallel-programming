with Ada.Text_IO, Data;

procedure Main is
   n:Integer:=10;
   package data1 is new data (n);
   use data1;


   procedure Run_Task1 is
      task Task1 is
         pragma CPU(0);
         pragma Priority(10);
      end Task1;
      task body Task1 is
         A,B: Vector;
         MA,MB: Matrix;
         Func1_answer: Integer;
      begin
          Matrix_Generate(MA,n,6);
          Matrix_Generate(MB,n,3);
          Vector_Generate(A,n,1);
          Vector_Generate(B,n,5);
          Func1_answer:=Func1(MA  => MA,
                         MB  => MB,
                         A  => A,
                         B => B);
         Ada.Text_IO.Put_Line("First function:   c = MAX(MA*MB) * (A*B)");
         Ada.Text_IO.Put_Line("" & Integer'Image(Func1_answer));
      end Task1;
   begin
      null;
   end Run_Task1;


   procedure Run_Task2 is
      task Task2 is
         pragma CPU(1);
         pragma Priority(10);
      end Task2;
      task body Task2 is
         MG,MH,MK: Matrix;
         Func2_answer: Matrix;
      begin
         Matrix_Generate(MG,n,4);
         Matrix_Generate(MH,n,8);
         Matrix_Generate(MK,n,1);
         Func2_answer:=Func2(MG => MG,
                          MH => MH,
                          MK => MK);
         Ada.Text_IO.Put_Line("  ");
         Ada.Text_IO.Put_Line("Second function:   MF = MAX(MG) * (MH*MK) ");
         Matrix_Print(Func2_answer);
      end Task2;
   begin
      null;
   end Run_Task2;

   procedure Run_Task3 is
      task Task3 is
         pragma CPU(2);
         pragma Priority(10);
      end Task3;
      task body Task3 is
      O,P: Vector;
      MR,MS: Matrix;
      Func3_answer: Vector;
      begin
         Matrix_Generate(MR,n,6);
         Matrix_Generate(MS,n,3);
         Vector_Generate(O,n,5);
         Vector_Generate(P,n,1);

          Func3_answer:=Func3(O  => O,
                          P => P,
                          MR => MR,
                          MS => MS);
      Ada.Text_IO.Put_Line("Third function:    T = SORT(O+P)*TRANS(MR *MS) ");
      Vector_Print(Func3_answer);
      end Task3;
   begin
      null;
   end Run_Task3;





begin
   Run_Task2;
   delay 1.0;
   Run_Task1;
   delay 1.0;
   Run_Task3;
end Main;
