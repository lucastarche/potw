using System;

namespace FezzBozz
{
    internal static class Program
    {
        private static string[] ReadSplitLine() =>
            Console.ReadLine()!.Split((string[]?)null, StringSplitOptions.RemoveEmptyEntries);

        private static void Main() => Solve();

        private static void Solve()
        {
            string[] input = ReadSplitLine();
            int n = int.Parse(input[0]), m = int.Parse(input[1]);
            (int value, string replacement)[] entries = new (int value, string replacement)[m];
            for (int i = 0; i < m; i++)
            {
                input = ReadSplitLine();
                entries[i] = (int.Parse(input[0]), input[1]);
            }

            for (int i = 1; i <= n; i++)
            {
                bool match = false;
                foreach ((int value, string replacement) in entries)
                {
                    if (value > i) break;
                    if (i % value != 0) continue;
                    match = true;
                    Console.Write(replacement);
                }

                if (!match) Console.Write(i);
                Console.WriteLine();
            }
        }
    }
}
