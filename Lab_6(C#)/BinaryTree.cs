namespace Lab_6
{
    //Клас для реалізації дерева
    internal class BinaryTree
    {
        //Корінь дерева
        public Node? head { get; private set; }

        //Метод для додавання елементів у дерево(обгортка)
        public void Add(int value)
        {
            if (head is null) { head = new Node(value); }
            else { AddTo(head, value); }
        }

        //Метод для додавання елементу у дерево
        private void AddTo(Node node, int value)
        {
            if (value < node.data)
            {
                if (node.left is null) { node.left = new Node(value); }
                else { AddTo(node.left, value); }
            }
            else
            {
                if (node.right is null) { node.right = new Node(value); }
                else { AddTo(node.right, value); }
            }
        }

        //Метод для генерації дерева
        public static void GenerateTree(BinaryTree tree, int quantity)
        {
            int value;

            for (int i = 0; i < quantity; i++)
            {
                Console.Write($"Enter value for {i + 1} node-> ");
                value = Convert.ToInt32(Console.ReadLine());

                tree.Add(value);
            }
        }

        //Метод для виведення дерева
        public static void PrintTree(Node? node, string pref = "", bool left = false)
        {
            if (node is not null)
            {
                string av;
                Console.WriteLine(pref + "|- " + $"{node.data}");

                if (left) { av = "|   "; }
                else { av = "    "; }

                PrintTree(node.left, pref + av, true);
                PrintTree(node.right, pref + av, false);
            }
        }

        //Метод для визначення кількості від'ємних елементів
        public int GetNegElementsCount()
        {
            int count = 0;

            foreach (var item in this)
            {
                if (item < 0) { count++; }
            }

            return count;
        }

        //Метод для визначення кількості додатніх елементів
        public int GetPosElementsCount()
        {
            int count = 0;

            foreach (var item in this)
            {
                if (item > 0)
                {
                    count++;
                }
            }

            return count;
        }

        //Реалізація інтерфейсу IEnumerator для перегляду елементів дерева у циклі без
        //використання додаткових методів
        public IEnumerator<int> GetEnumerator()
        {
            return InOrderTraversal();
        }
        public IEnumerator<int> InOrderTraversal()
        {
            if (head is not null)
            {
                Stack<Node> stack = new Stack<Node>();
                Node current = head;

                bool ifNext = true;

                stack.Push(current);

                while (stack.Count > 0)
                {
                    if (ifNext)
                    {
                        while (current.left is not null)
                        {
                            stack.Push(current);
                            current = current.left;
                        }
                    }

                    yield return current.data;

                    if (current.right is not null)
                    {
                        current = current.right;
                        ifNext = true;
                    }
                    else
                    {
                        current = stack.Pop();
                        ifNext = false;
                    }
                }
            }
        }
    }
}
