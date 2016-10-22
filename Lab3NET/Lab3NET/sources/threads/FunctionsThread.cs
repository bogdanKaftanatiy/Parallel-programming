using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3NET.sources.threads
{
    abstract class FunctionsThread
    {
        abstract public void generateElements();
        abstract public void calculateFunction();
        abstract public void runCalculate();
    }
}
