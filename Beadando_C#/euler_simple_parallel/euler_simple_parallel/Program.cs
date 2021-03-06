using System;
using System.Threading;
using System.Threading.Tasks;

namespace eluer_simple_parallel
{
    class Program
    {
        static void Main(string[] args)
        {
            double begin = 0.0;
            double end = 2.0;
            double y0 = 1.0;
            int pointsNum = 8;
            /*Mérés kezdete*/
            DateTime StartDateTime = DateTime.Now;
            EulerSimple(begin, end, y0, pointsNum);
            DateTime EndDateTime = DateTime.Now;
            /*Mérés vége*/
            TimeSpan span = EndDateTime - StartDateTime;
            double s = span.TotalSeconds;

            Console.WriteLine(@"Parallel runtime is {0} seconds ", s);

        }

        /* A függvény amelyet az euler módszer fog kiszámolni*/
        static double Function(double x, double y)
        {
            return (y * y * y) / (x + 3);
        }

        /* Euler módszer implementálása*/
        static void EulerSimple(double begin, double end, double y0, int pointsNum)
        {
            double y;
            double y1;
            double x = 0;
            double h;
            double[,] result = new double[2, pointsNum];
            h = (end - begin) / pointsNum;
            y1 = y0;
            y = 0;
            //Limiting the maximum degree of parallelism to n
            var options = new ParallelOptions()
            {
                MaxDegreeOfParallelism = 8
            };
            Parallel.For(0, pointsNum, options, i =>
            {
                y = y1 + h * Function(x, y);
                y1 = y;
                x = x + h;
                result[0, i] = x;
                result[1, i] = y;
                //Console.WriteLine("The results are : x = {0} , y = {1}", result[0, i], result[1, i]);
            });

            



        }
    }
}