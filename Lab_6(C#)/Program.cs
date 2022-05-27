namespace Lab_6;

public class Program
{
    static void Main()
    {
        Console.Write("Enter quatity of tree elements-> ");
        int quantity = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine();

        //Створення дерева
        BinaryTree binaryTree = new BinaryTree();

        //Генерація дерева
        BinaryTree.GenerateTree(binaryTree, quantity);

        //Визначення кількості від'ємних та додатніх елементів
        int negativeElementsCount = binaryTree.GetNegElementsCount();
        int positiveElementsCount = binaryTree.GetPosElementsCount();

        //Виведення дерева
        Console.WriteLine("\nTree:");
        BinaryTree.PrintTree(binaryTree.head);

        Console.WriteLine($"\nPositive elements count: {positiveElementsCount}");
        Console.WriteLine($"Negative elements count: {negativeElementsCount}");
    }
}