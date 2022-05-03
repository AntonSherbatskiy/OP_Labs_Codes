namespace ConsoleApp1;

public class TIntNumber8 : TIntNumber
{
    public TIntNumber8(string binaryNumber) : base(binaryNumber)
    {
        for (int i = 0; i < binaryNumber.Length; i++)
        {
            if(binaryNumber[i] <= '7')
            {
                Number += Convert.ToInt32(Math.Pow(8, binaryNumber.Length - i - 1) * int.Parse(binaryNumber[i].ToString()));
            }
            else
            {
                throw new FormatException("Invalid format!");
            }
        }
    }

    public override void ShowData()
    {
        Console.WriteLine("Int8: {0, 7}\tInt10:{1, 7}", BinNumber, int10);
    }

    public override void dec()
    {
        base.dec();
        binNumber = Convert.ToString(int10, 8);
    }

    public override void inc()
    {
        base.inc();
        binNumber = Convert.ToString(int10, 8);
    }
}
