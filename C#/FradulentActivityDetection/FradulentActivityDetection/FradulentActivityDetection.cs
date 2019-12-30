using System;
using System.Collections.Generic;

namespace HackerRank
{
    class Program
    {
        // Complete the activityNotifications function below.
        static void activityNotifications(int[] expenditure, int d)
        {
            //Example
            //exp: {3, 2, 5, 1, 6} d: 3
            int itter = 0;
            int fraudCount = 0;
            List<int> myNum;
            for(int i = d; i < expenditure.Length; i++)
            {
                myNum = new List<int>();
                //Past 3 days
                for(int j = 0; j < d; j++)
                {
                    myNum.Add(expenditure[j+itter]);
                    Console.Write(expenditure[j + itter] + " ");
                }
                Console.WriteLine($"Median: {getMedian(myNum)}");
                //getMedian(myNum);

                //If current day spent is >= 2x median, add fraud
                if (expenditure[i] >= getMedian(myNum) * 2)
                {
                    fraudCount++;
                    Console.WriteLine($"FRAUD DETECTED! Purchase: {expenditure[i]} Median: {getMedian(myNum)}");
                }

                Console.WriteLine("\n");
                itter++;
            }

            Console.WriteLine($"Number of Frauds Detected: {fraudCount}");
        }

        static int getMedian(List<int> num)
        {
            //Sort
            num.Sort();
            //Get middle index num
            return num[num.Count / 2];
        }

        static void Main(string[] args)
        {
            int [] num = { 2, 3, 4, 2, 3, 6, 8, 4, 5 };
            int d = 5;
            activityNotifications(num, d);
        }
    }
}
