# Bankers-Algorithm

The Bankers.cpp program takes a given amount of processes with given resource types, allocations, max, and avaiablity of said resources
Then it allows process to execute according to avaiable resources
It will not allow a process to overdraw, as it has no resources to give
It then stores the order that the processes execute, and then returns the status of the algorithm and states the order of completion

The program wasn't difficult to implement, fairly straightforward as no abstract objects were needed
Resources were also plentiful on the topic, so fixing issues was not a problem

Can be compiled with g++ bankers.cpp -o bankers

Then exectued with ./bankers

![image](https://github.com/Bluehippo321/Bankers-Algorithm/assets/149278207/5da42091-fe47-46a8-95f9-a653fed5cda1)

![image](https://github.com/Bluehippo321/Bankers-Algorithm/assets/149278207/7b16de4c-9366-4441-a860-cf8f812f6fbd)

####################################

BankersFail.cpp is a copy of the Bankers.cpp program, but the avaiable resources are insufficient, so the process fails
This program is an example of what happens when a process doesn't have correct information to carry out a task

Can be compiled with g++ bankersFail.cpp -o bankersFail

Then exectued with ./bankersFail

![image](https://github.com/Bluehippo321/Bankers-Algorithm/assets/149278207/cce1eb35-1543-43f6-9f29-91d66d5cd352)

![image](https://github.com/Bluehippo321/Bankers-Algorithm/assets/149278207/e46e7237-4db3-4337-b16d-9129cab18737)
