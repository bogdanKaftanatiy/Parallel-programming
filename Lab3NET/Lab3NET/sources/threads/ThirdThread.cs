using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab3NET.sources.primitives;

namespace Lab3NET.sources.threads
{
    class ThirdThread : FunctionsThread
    {
        private static int size = 5;
        private static int maxValue = 20;
        private Vector O = new Vector(size);
        private Vector P = new Vector(size);
        private Matrix MR = new Matrix(size);
        private Matrix MS = new Matrix(size);

        public override void generateElements()
        {
            O.generate(maxValue);
            P.generate(maxValue);
            MR.generate(maxValue);
            MS.generate(maxValue);
            Console.WriteLine("Function 3 arguments generate\nO:\n" + O + "\nP:\n" + P + "\nMR:\n" + MR + "\nMS:\n" + MS);
        }

        public override void calculateFunction()
        {
            Vector result;
            Vector sortVector = (O.sumVectors(P)).sortVector();
            Matrix transMatrix = (MR.multipleMatrix(MS)).trasparentMatrixs();
            result = sortVector.multipleMatrix(transMatrix);
            Console.WriteLine("Function 3 calculated\nFunction 3 result = \n" + result);
        }

        public override void runCalculate()
        {
            generateElements();
            calculateFunction();
        }
    }
}
