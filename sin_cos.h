//
// Created by Faisal Javed on 13/10/22.
//
#pragma once
#include <iostream>

int sin(int x);
int cos(int x);
int sin0to45(int);
int sin45to90(int);
int polyEval(int, int[], int);
void testCosineValues(int &, int);
void testSineValues(int &, int);
inline void printDashedLine();
inline void printTableHeader(std::string);
inline void printResult(int &, int &, int &, std::string &, std:: string);