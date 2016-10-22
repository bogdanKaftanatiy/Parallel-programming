using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab3NET.sources.primitives;

namespace Lab3NET.sources.threads
{
    class FirstThread : FunctionsThread
    {
        private static int size = 5;
        private static int maxValue = 20;
        private Matrix MA = new Matrix(size);
        private Matrix MB = new Matrix(size);
        private Vector A = new Vector(size);
        private Vector B = new Vector(size);

        public override void generateElements()
        {
            MA.generate(maxValue);
            MB.generate(maxValue);
            A.generate(maxValue);
            B.generate(maxValue);
            Console.WriteLine("Function 1 arguments generate\nMA:\n" + MA + "\nMB:\n" + MB + "\nA\n" + A + "\nB\n" + B);
        }

        public override void calculateFunction()
        {
            int result;
            Matrix maxMatrix = MA.multipleMatrix(MB);
            result = maxMatrix.getMaxElement() * A.multipleVectors(B);
            Console.WriteLine("Function 1 calculated\nFunction 1 result = " + result);
        }

        public override void runCalculate()
        {
            generateElements();
            calculateFunction();
        }
    }
}
