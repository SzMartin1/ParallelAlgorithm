using System;

namespace euler_simple
{
    class Program
    {

        static void Main(string[] args)
        {
            double begin = 0.0;
            double end = 2.0;
            double y0 = 1.0;
            int pointsNum = 6;
            /*Mérés kezdete*/
            DateTime StartDateTime = DateTime.Now;
            EulerSimple(begin, end, y0, pointsNum);
            DateTime EndDateTime = DateTime.Now;
            /*Mérés vége*/
            TimeSpan span = EndDateTime - StartDateTime;
            double s = span.TotalSeconds;

            Console.WriteLine(@"Time Taken to sequentially execute the loop is {0} seconds ", s);

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
            for (int i = 0; i < pointsNum; i++)
            {
                y = y1 + h * Function(x, y);
                y1 = y;
                x = x + h;
                result[0, i] = x;
                result[1, i] = y;
                //if (i == pointsNum - 1)
                //{
                    Console.WriteLine("The results are : x = {0} , y = {1}", result[0,i], result[1,i]);
                //}
            }
            


        }


    }
}