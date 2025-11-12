#ifndef BANKERS
#define BANKERS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

inline const int MAXPROCESSES = 5;
inline const int MAXRESOURCES = 3;

inline const char* GREEN = "\033[32m";
inline const char* RED = "\033[31m";
inline const char* DEFAULT = "\033[0m";

inline int available[MAXRESOURCES];
inline int maximum[MAXPROCESSES][MAXRESOURCES];
inline int allocated[MAXPROCESSES][MAXRESOURCES];

void CalculateNeed(int need[][MAXRESOURCES]);
bool SafeCheck();

void SafeState(const std::vector<int>& safeSequence);
void UnsafeState();
void DisplaySetting();

#endif