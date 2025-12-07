cmake_minimum_required(VERSION 3.27)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_library(LinkedList STATIC linkedList/SinglyLinkedList.c
        linkedList/CircularDoublyLinkedList.c
        linkedList/DoublyLinkedLists.c
        linkedList/CircularLinkedList.c
        stack/LinkedStack.c
        stack/Stack.c
        queue/LinearQueue.c
        queue/LinkedQueue.c
        queue/CircularQueue.c
        tree/SequantialTree.c
        tree/LinkedTree.c
        tree/RedBlackTree.c)
