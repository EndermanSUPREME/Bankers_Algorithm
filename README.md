# Bankers Algorithm

## Banker’s Algorithm for deadlock avoidance
Considering a system with five processes P\_0 through P\_4 and three resources of type A, B, C.
Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at
time t0 following snapshot of the system has been taken:

![snapshot at time T_0](t_0_snapshot.png)

## Goal of this Repository
Implement the Banker’s algorithm to answer the following question：Is the system in a safe state?
If Yes, then what is the safe sequence?

## Expected Outputs
#### Output during Safe State
```
./bankers
Enter the input file name: data1.txt
System is in a safe state, safe sequence is: P1 -> P3 -> P4 -> P0 -> P2
```

#### Output during Unsafe State
```
./bankers
Enter the input file name: data2.txt
System is not in a safe state, Banker's algorithm cannot be applied safely.
```

## Proof of Concept


## Deep Dive into Banker's Algorithm
According to [geeksforgeeks](https://www.geeksforgeeks.org/operating-systems/bankers-algorithm-in-operating-system-2/):

Banker's Algorithm is a resource allocation and deadlock avoidance algorithm used in operating systems.
It ensures that a system remains in a safe state by carefully allocating resources to processes while
avoiding unsafe states that could lead to deadlocks.

- The Banker's Algorithm is a smart way for computer systems to manage how programs use resources, like memory or CPU time.
- It helps prevent situations where programs get stuck and can not finish their tasks. This condition is known as deadlock.
- By keeping track of what resources each program needs and what's available, the banker algorithm makes sure that programs only get what they need in a safe order.


#### Components of the Banker's Algorithm
The following Data structures are used to implement the Banker’s Algorithm:
Let `n` be the number of processes in the system and `m` be the number of resource types.

1. Available
- It is a 1-D array of size `m` indicating the number of available resources of each type.
- Available[ j ] = k means there are `k` instances of resource type R\_j

2. Max
- It is a 2-d array of size `n*m` that defines the maximum demand of each process in a system.
- Max[ i, j ] = k means process P\_i may request at most `k` instances of resource type R\_j.

3. Allocation
- It is a 2-d array of size `n*m` that defines the number of resources of each type currently allocated to each process.
- Allocation[ i, j ] = k means process P\_i is currently allocated `k` instances of resource type R\_j

4. Need
- It is a 2-d array of size `n*m` that indicates the remaining resource need of each process.
- Need [ i, j ] = k means process P\_i currently needs `k` instances of resource type R\_j
- Need [ i, j ] = Max [ i, j ] – Allocation [ i, j ]

Allocation specifies the resources currently allocated to process P\_i and Need specifies the additional resources that process P\_i may still request to complete its task.

#### Key Concepts in Banker's Algorithm
`Safe` State: There exists at least one sequence of processes such that each process can obtain the needed resources, complete its execution, release its resources, and thus allow other processes to eventually complete without entering a deadlock.

`Unsafe` State: Even though the system can still allocate resources to some processes, there is no guarantee that all processes can finish without potentially causing a deadlock.

### Input Files
Contents from [data3.txt](data3.txt)
```text
0 1 2
2 0 1
1 2 1
3 0 0
1 1 1
7 5 3
6 4 2
5 3 3
4 3 3
4 2 2
3 3 2
```

- The first 5 rows represent the Allocation Matrix.
- The next 5 rows represent the Maximum Demand Matrix.
- The last row represents the Available Resources.