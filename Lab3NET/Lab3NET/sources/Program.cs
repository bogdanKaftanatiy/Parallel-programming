using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Lab3NET.sources.primitives;
using Lab3NET.sources.threads;

namespace Lab3NET.sources
{
    class Program
    {
        static void Main(string[] args)
        {
            FunctionsThread f1 = new FirstThread();
            FunctionsThread f2 = new SecondThread();
            FunctionsThread f3 = new ThirdThread();

            Thread t1 = new Thread(f1.runCalculate);
            Thread t2 = new Thread(f2.runCalculate);
            Thread t3 = new Thread(f3.runCalculate);

            t1.Start();
            t2.Start();
            t3.Start();

            t1.Join();
            t2.Join();
            t3.Join();

            Console.ReadKey();
        }
    }
}
