# The algorithms in C++

The algorithms below, written by me, **are given as an example**. Many of them are implemented in the standard library of the C++ language, they are much more productive. Thanks!

## Data Structures
- ### Singly linked list
    - Performance

        |   Method   | Working time |
        |:----------:|:------------:|
        | push_back  |     O(1)     |
        | push_front |     O(1)     |
        |  pop_back  |     O(n)     |
        | pop_front  |     O(1)     |
        |   insert   |     O(n)     |
        |   erase    |     O(n)     |
        |   getAt    |     O(n)     |
- ### Doubly linked list
    - Performance

      |   Method   | Working time |
      |:----------:|:------------:|
      | push_back  |     O(1)     |
      | push_front |     O(1)     |
      |  pop_back  |     O(1)     |
      | pop_front  |     O(1)     |
      |   insert   |     O(n)     |
      |   erase    |     O(n)     |
      |   getAt    |     O(n)     |

## Dynamic programming
| Algorithm | Working time |
|:---------:|:------------:|
| Fibonacci |  O(log(n))   |

## Graph

|      Algorithm       |
|:--------------------:|
| Breadth-First Search |
|  Depth-First Search  |
| Dijkstra's algorithm |

## Search

|         Algorithm          | Data structure | Time complexity on average case | Time complexity in the worst case |
|:--------------------------:|:--------------:|:-------------------------------:|:---------------------------------:|
|       Binary search        |  Sorted array  |            O(log(n))            |             O(log(n))             |
| Block interpolation search |  Sorted array  |         θ(log(log(n)))          |            θ(sqrt(n))             |
|    Interpolation search    |  Sorted array  |         θ(log(log(n)))          |               θ(n)                |
|     Left binary search     |  Sorted array  |            O(log(n))            |               O(1)                |
|       Linear search        |     Array      |              O(n)               |               O(n)                |
|    Right binary search     |  Sorted array  |            O(log(n))            |               O(1)                |

## Sorting

|  Algorithm  | Data structure | Time complexity at best | Time complexity on average case | Time complexity in the worst case |
|:-----------:|:--------------:|:-----------------------:|:-------------------------------:|:---------------------------------:|
| Bubble sort |     Array      |          O(n)           |             O(n^2)              |              O(n^2)               |
| Insert sort |     Array      |          O(n)           |             O(n^2)              |              O(n^2)               |
| Merge Sort  |     Array      |      O(n log (n))       |           O(n log(n))           |            O(n log(n))            |
| Quick sort  |     Array      |       O(n log(n))       |           O(n log(n))           |              O(n^2)               |
| Shell sort  |     Array      |         θ(n^2)          |             θ(n^2)              |              θ(n^2)               |


**I will add other algorithms over time.**