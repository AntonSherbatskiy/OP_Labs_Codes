namespace ConsoleApp1;

public abstract class TIntNumber
{
    public TIntNumber(string binaryNumber)
    {
        binNumber = binaryNumber;
    }

    protected int int10;
    public int Number
    {
        get { return int10; }
        set { int10 = value; }
    }

    protected string binNumber;
    public string BinNumber
    {
        get { return binNumber; }
        set { binNumber = value; }
    }

    public abstract void ShowData();

    public virtual void inc() { int10++; }
    public virtual void dec() { int10--; }
}