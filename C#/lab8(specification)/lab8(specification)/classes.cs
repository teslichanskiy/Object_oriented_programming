using System;

namespace Lab_8
{
    public class Queue<T>
    {
        private Node<T> head;
        private Node<T> tail;
        private int count;

        // Внутренний класс узла очереди
        private class Node<T>
        {
            public T Data { get; set; }
            public Node<T> Next { get; set; }

            public Node(T data)
            {
                Data = data;
                Next = null;
            }
        }

        // Проверка пустоты очереди
        public bool IsEmpty()
        {
            return count == 0;
        }

        // Добавление элемента в очередь
        public void Push(T data)
        {
            Node<T> newNode = new Node<T>(data);

            if (IsEmpty())
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail.Next = newNode;
                tail = newNode;
            }

            count++;
        }

        // Удаление элемента из очереди
        public T Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException("Очередь пуста");
            }

            T removedData = head.Data;
            head = head.Next;

            count--;

            return removedData;
        }

        // Возвращает первый элемент в очереди, не удаляя его
        public T Peek()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException("Очередь пуста");
            }

            return head.Data;
        }

        // Вывод всех элементов очереди
        public void PrintQueue()
        {
            if (IsEmpty())
            {
                Console.WriteLine("Очередь пуста");
                return;
            }

            Node<T> currentNode = head;

            while (currentNode != null)
            {
                Console.Write(currentNode.Data + " ");
                currentNode = currentNode.Next;
            }

            Console.WriteLine();
        }
    }
}