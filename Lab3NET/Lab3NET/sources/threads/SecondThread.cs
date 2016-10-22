using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lab3NET.sources.primitives;

namespace Lab3NET.sources.threads
{
    class SecondThread : FunctionsThread
    {
        private static int size = 5;
        private static int maxValue = 20;
        private Matrix MG = new Matrix(size);
        private Matrix MH = new Matrix(size);
        private Matrix MK = new Matrix(size);

        public override void generateElements()
        {
            MG.generate(maxValue);
            MH.generate(maxValue);
            MK.generate(maxValue);
            Console.WriteLine("Function 2 arguments generate\n MG:\n" + MG + "\nMH:\n" + MH + "\nMK:\n" + MK);
        }

        public override void calculateFunction()
        {
            Matrix result;
            Matrix multipleMatrix = MH.multipleMatrix(MK);
            result = multipleMatrix.multipleNumber(MG.getMaxElement());
            Console.WriteLine("Function 2 calculated\nFunction 2 result = \n" + result);
        }

        public override void runCalculate()
        {
            generateElements();
            calculateFunction();
        }
    }
}
