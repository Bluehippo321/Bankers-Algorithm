
// Andrew Trautzsch

#include <iostream>

int main(){

    int i, j, k, y; // used for for loops
    int n, m;

    /*
        Inside can be edited to change given information for different sequence
    */
    n = 5; // Amount of processes in example
    m = 3; // Amount of types of resources (A, B, C)

    // Allocation matrix, defines allocation for each process
    int allocation[5][3] = { 
                             {0, 1, 0}, // P0
                             {2, 0, 0}, // P1
                             {3, 0, 2}, // P2
                             {2, 1, 1}, // P3
                             {0, 0, 2}  // P4
                           };
    
    // Max matrix, defines allocation for each process
    int max[5][3] =        { 
                             {7, 5, 3}, // P0
                             {3, 2, 2}, // P1
                             {9, 0, 2}, // P2
                             {2, 2, 2}, // P3
                             {4, 3, 3}  // P4
                           };
    
    // Available resources
    int available[3] = {1, 1, 0};

    /*
        Inside can be edited to change given information for different sequence
    */
    
    // tracks progress of processes' completion
    int f[n];

    // tracks order of completion of processes
    int answer[n];
    
    // tracks location in answer array
    int index = 0;

    // Variable to indicate if there is issue, 
    int flag = 0;

    // sets tracker to 0
    for (k = 0; k < n; k++){
        f[k] = 0;
    }

    // vector to hold needed resources by each process
    int need[n][m];

    // calculates the needed resources for each process
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) need[i][j] = max[i][j] - allocation[i][j];
    }

    //starts loop to determine if processes are valid and gives required resources
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {

            //checks if current process is complete
            if (f[i] == 0) {

                // sets boolean int to false
                flag = 0;

                // checks if the processes break
                // compares the needed resources to available resources
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]){
                        flag = 1;
                        break;
                    }
                }

                // if process passes check, resources are allocated to the process
                if (flag == 0) {
                    answer[index++] = i;
                    for (y=0; y < m; y++) {
                        available[y] += allocation[i][y];
                    }
                    f[i] = 1; // marks process as completed
                }

            }
        }
    }

    flag = 1;

    // checks for process completion to determine if the sequence is safe
    for(i = 0; i < n; i++){
        if(f[i] == 0) {
            flag = 0;
            std::cout << "The sequence is NOT safe" << std::endl;
            break;
        }
    }

    // returns if sequence is safe and the order of completion
    if(flag == 1) {
        std::cout << "The sequence is SAFE" << std::endl;
        for (i = 0; i < n; i++) {
            std::cout << "P" << answer[i];
            if (i+1 != n) std::cout << " -> ";
        }
        std::cout << std::endl;
    }

    // ends process
    return 0;

}