using System;
using System.IO;

// https://adventofcode.com/2020/day/4

namespace _Arbitrary
{
    class Program
    {
        static readonly string[] requiredFields = { "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid" };

        static void Main()
        {
            string raw = File.ReadAllText(@".\d04\04.txt");
            int validCount = 0;
            string[] lines = raw.Split('\u000d');

            string buffer = "";
            foreach (string line in lines)
            {
                if (line != "\n")
                {
                    buffer += " " + line;
                }
                else
                {
                    if (Check(buffer))
                    {
                        validCount++;
                    }

                    buffer = "";
                }
            }

            Console.WriteLine(validCount);
        }

        static bool Check(string passport)
        {
            string[] fields = passport.Split();
            foreach (string req in requiredFields)
            {
                bool reqSatisfied = LoopFields(req, fields);
                if (!reqSatisfied) { return false; }
            }
            return true;
        }

        static bool LoopFields(string req, string[] fields)
        {
            foreach (string f in fields)
            {
                if (req == f.Split(':')[0])
                {
                    return true;
                }
            }
            return false;
        }
    }
}
