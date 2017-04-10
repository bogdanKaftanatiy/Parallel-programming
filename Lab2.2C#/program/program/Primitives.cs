using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    class Matrix
    {
        private Vector[] matr;

        public Matrix(int len)
        {
            matr = new Vector[len];
        }

        public Matrix(Matrix mat)
        {
            matr = new Vector[mat.getLength()];
            for (int i = 0; i < matr.Length; i++)
            {
                matr[i] = new Vector(mat.getString(i));
            }
        }

        public Vector getString(int i)
        {
            return matr[i];
        }

        public int getElement(int i, int j)
        {
            return matr[i].getElement(j);
        }

        public void setElement(int i, int j, int func)
        {
            matr[i].setElement(j, func);
        }

        public void setString(int i, Vector func)
        {
            matr[i] = func;
        }

        public int getLength()
        {
            return matr.Length;
        }

        public void inputMatrix()
        {
            for (int i = 0; i < matr.Length; i++)
            {
                matr[i] = new Vector(matr.Length);
                matr[i].inputVector();
            }
        }

        public String outputMatrix()
        {
            String s = "";
            for (int i = 0; i < matr.Length; i++)
            {
                s = s + matr[i].outputVector() + "\n";
            }

            return s;
        }

    }

    class Vector
    {
        private int[] vect;

        public Vector(int length)
        {
            vect = new int[length];
        }

        public Vector(Vector vec)
        {
            vect = new int[vec.getLength()];
            for (int i = 0; i < vec.getLength(); i++)
            {
                vect[i] = vec.getElement(i);
            }

        }

        public int getLength()
        {
            return vect.Length;
        }

        public int getElement(int i)
        {
            return vect[i];
        }

        public void setElement(int i, int func)
        {
            vect[i] = func;
        }


        public void sort(int a, int b)
        {
            Array.Sort(vect, a, b);
        }

        public void inputVector()
        {
            for (int i = 0; i < vect.Length; i++ )
            {
                vect[i] = 1;
            }
        }

        public String outputVector()
        {
            String s = "";

            for (int i = 0; i < vect.Length; i++)
            {
                s = s + " " + vect[i];
            }

            return s;
        }
    }
}
