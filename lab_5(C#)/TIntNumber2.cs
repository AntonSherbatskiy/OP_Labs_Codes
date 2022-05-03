namespace ConsoleApp1;

public class TIntNumber2 : TIntNumber
{
    public TIntNumber2(string binaryNumber) : base(binaryNumber)
    {
        var exponent = 0;
        
        for (var i = binaryNumber.Length - 1; i >= 0; i--)
        {
            if (binaryNumber[i] == '1') { Number += Convert.ToInt32(Math.Pow(2, exponent)); }
            else if(binaryNumber[i] > '1') { throw new FormatException("Invalid format!"); }
            exponent++;
        }
    }

    public override void ShowData()
    {
        Console.WriteLine("Int2: {0, 7}\tInt:{1, 7}", binNumber, int10);
    }

    public override void dec()
    {
        base.dec();
        binNumber = Convert.ToString(int10, 2);
    }

    public override void inc()
    {
        base.inc();
        binNumber = Convert.ToString(int10, 2);
    }
}
