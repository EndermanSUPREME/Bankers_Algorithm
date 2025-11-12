#include "bankers.hpp"

// calculate need based on max processes and max resources
void CalculateNeed(int need[][MAXRESOURCES]) {
    for (int i = 0; i < MAXPROCESSES; i++) {
        for (int j = 0; j < MAXRESOURCES; j++) {
            // compute the need for each process (i)
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }
}

// test whether the system is in a safe/unsafe state
bool SafeCheck() {
    DisplaySetting();

    int need[MAXPROCESSES][MAXRESOURCES];

    // generate the need-matrix
    CalculateNeed(need);

    bool finish[MAXPROCESSES] = {false};
    std::vector<int> safeSequence;

    // tracks available resources
    int work[MAXRESOURCES];
    for (int i = 0; i < MAXRESOURCES; i++) {
        work[i] = available[i];
    }

    // track number of completed processes
    int completed = 0;

    while (completed < MAXPROCESSES) {
        bool found = false;

        for (int i = 0; i < MAXPROCESSES; i++) {
            if (!finish[i]) {
                // if a process_i did not finish we check if it can be given the
                // necessary resources needed to complete its task
                bool can_allocate = true;
                for (int j = 0; j < MAXRESOURCES; j++) {
                    if (need[i][j] > work[j]) { 
                        // if need exceeds available work, it cannot be allocated
                        can_allocate = false;
                        break;
                    }
                }

                // otherwise the process can be allocated resources
                // we update work array and finish the process_i
                if (can_allocate) {
                    for (int j = 0; j < MAXRESOURCES; j++) {
                        // give the allocations back to available work
                        work[j] += allocated[i][j];
                    }

                    // push process index into safe-sequence
                    safeSequence.push_back(i);

                    // process was able to finish successfully
                    finish[i] = true; completed++;

                    // mark we found a proc to allocate
                    found = true;
                }
            }
        }

        // deduced we are in an unsafe state
        // inform the user
        if (!found) {
            UnsafeState();
            return false;
        }
    }

    // output that we are within a safe-state
    SafeState(safeSequence);

    return true;
}

// displays the environment Bankers Algorithm is being applied within
void DisplaySetting() {
    std::cout << "[*] Running Environment" << std::endl;
    std::cout << " |___ Max Processes -> " << MAXPROCESSES << std::endl;
    std::cout << " |___ Max Resources -> " << MAXRESOURCES << std::endl;
}

// display when in a safe-state and prints out the safe-sequence
void SafeState(const std::vector<int>& safeSequence) {
    std::cout << GREEN << "[+] System is in a Safe state." << std::endl;
    std::cout << " |__ safe-sequence: ";

    for (size_t i = 0; i < safeSequence.size(); ++i) {
        std::cout << "P" << safeSequence[i];
        
        if (i < safeSequence.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << DEFAULT << std::endl;
}
// display when in an unsafe-state
void UnsafeState() {
    std::cout << RED << "[-] System is in an Unsafe state." << DEFAULT << std::endl;
}