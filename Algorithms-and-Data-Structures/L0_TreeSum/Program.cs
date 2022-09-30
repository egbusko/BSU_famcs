using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Csharp_L00
{
    class Program
    {
        public static long n = 0;
        public static char[] masBinN;
        public static string binPresentN = "";

        public static void printBinaryform(long number)
        {
            long remainder;
            if (number <= 1)
            {
                binPresentN += number.ToString();
                return;
            }
            remainder = number % 2;
            printBinaryform(number >> 1);
            binPresentN += remainder.ToString();
        }


        static void Main(string[] args)
        {
            string s = "input.txt";
            StreamReader f = new StreamReader(s);
            n = long.Parse(f.ReadLine());                    
            f.Close();
            
            printBinaryform(n);
            masBinN = binPresentN.ToArray();

            
            StreamWriter f2 = new StreamWriter("output.txt");
            for (int i = masBinN.Length - 1; i >= 0; i--)
            {
                if (masBinN[i] == '1')
                {
                    f2.WriteLine(masBinN.Length - 1 - i);
                }
            }
            f2.Close();
        }
    }
}
