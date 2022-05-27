namespace Lab_6
{
    //Клас для реалізації вузла дерева
    internal class Node
    {
        public Node(int data)
        {
            this.data = data;
        }
        public Node()
        {
            data = 0;
            left = null;
            right = null;
        }

        public int data { get; private set; }
        public Node? left { get; set; }
        public Node? right { get; set; }
    }
}