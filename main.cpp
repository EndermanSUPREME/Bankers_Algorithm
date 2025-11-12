#include "bankers.hpp"

// given a filename try to parse the integer columns and extract
// the contents of the following matrices:
//      Allocation, Maximum Demand, and Available Resources
bool ParseDataFile(const char* filename) {
    std::ifstream bankers_file(filename);

    if (!bankers_file) {
        std::cout << "[-] Error: Cannot open " << filename << std::endl;
        return false;
    }

    std::cout << "[*] Reading " << filename << std::endl;

    // Read allocated resources matrix
    for (int i = 0; i < MAXPROCESSES; ++i) {
        for (int j = 0; j < MAXRESOURCES; ++j) {
            bankers_file >> allocated[i][j];
        }
    }

    // Read maximum resources matrix
    for (int i = 0; i < MAXPROCESSES; ++i) {
        for (int j = 0; j < MAXRESOURCES; ++j) {
            bankers_file >> maximum[i][j];
        }
    }

    // Read available resources
    for (int i = 0; i < MAXRESOURCES; ++i) {
        bankers_file >> available[i];
    }

    bankers_file.close();

    std::cout << "[+] Finished reading " << filename << std::endl;

    return true;
}

void ShowHelp(const char* bin) {
    std::cout << "Usage: " << bin << " [input file]\n\n";
    std::cout << "Examples:" << std::endl;
    std::cout << "  ./" << bin << " data1.txt" << std::endl;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        if (ParseDataFile(argv[1])) {
            SafeCheck();
        } else {
            return 1;
        }
    } else {
        ShowHelp(argv[0]);
        return 1;
    }

    return 0;
}