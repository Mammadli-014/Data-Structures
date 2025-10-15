cmake_minimum_required(VERSION 3.27)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_library(LinkedList STATIC linkedList/SinglyLinkedList.c
        linkedList/CircularLinkedList.c
        linkedList/DoublyLinkedLists.c
        linkedList/CircularDoublyLinkedList.c)
