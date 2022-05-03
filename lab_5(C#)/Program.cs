namespace ConsoleApp1;

public partial class Program
{
    private static void Main()
    {
        Console.WriteLine("---------------------------INT2 CONVERT---------------------------\n");
        var int2List = CreateInt2List();

        Console.WriteLine("\n\n-------------------------INT8 CONVERT-------------------------\n");
        var int8List = CreateInt8List();

        Console.WriteLine("\n\n-------------------------INT2 INCREMENT-----------------------");
        IncrementInt2(int2List);

        Console.WriteLine("\n\n------------------------INT8 DECREMENT------------------------");
        DecrementInt8(int8List);

        Console.WriteLine($"\nSmallest number:\t{FindMin(int2List, int8List)}");
    }

    static List<TIntNumber2> CreateInt2List()
    {
        var int2List = new List<TIntNumber2>();

        while (true)
        {
            Console.Write("Enter INT2 number(press ctrl + X to stop)-> ");
            string? line = Console.ReadLine();

            if (line != null && line[0] != 24)
            {
                var int2 = new TIntNumber2(line);
                int2List.Add(int2);
                Console.WriteLine($"INT2: {int2.BinNumber} --> {int2.Number}\n");
            }
            else { break; }
        }

        return int2List;
    }

    static List<TIntNumber8> CreateInt8List()
    {
        var int8List = new List<TIntNumber8>();

        while (true)
        {
            Console.Write("Enter INT8 number(press ctrl + X to stop)-> ");
            var line = Console.ReadLine();

            if (line != null && line[0] != 24)
            {
                TIntNumber8 int8 = new TIntNumber8(line);
                Console.WriteLine($"INT8: {int8.BinNumber} --> {int8.Number}\n");
                int8List.Add(int8);
            }
            else { break; }
        }

        return int8List;
    }

    static void IncrementInt2(List<TIntNumber2> int2Array)
    {
        for (var i = 0; i < int2Array.Count; i++)
        {
            int2Array[i].inc();
            Console.Write($"[{i}] ");
            int2Array[i].ShowData();
        }
    }

    static void DecrementInt8(List<TIntNumber8> int8Array)
    {
        for (var i = 0; i < int8Array.Count; i++)
        {
            int8Array[i].dec();
            Console.Write($"[{i}] ");
            int8Array[i].ShowData();
        }
    }

    static int FindMin(List<TIntNumber2> int2Array, List<TIntNumber8> int8Array)
    {
        int min = int2Array[0].Number;

        foreach (var item in int2Array)
        {
            if (item.Number < min)
            {
                min = item.Number;
            }
        }

        foreach (var item in int8Array)
        {
            if (item.Number < min)
            {
                min = item.Number;
            }
        }

        return min;
    }
}