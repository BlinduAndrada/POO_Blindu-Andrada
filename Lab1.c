// Laborator1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning (disable : 4996)
#include <iostream>
#include <fstream>
using namespace std;

int str_to_num(char* str) {
    int num = 0;

    while (*str != '\0') {
        num = num * 10 + (*str - '0');
        str++;
    }

    return num;
}

int main() {
    FILE* fp;
    int num, sum = 0;

    fp = fopen("text.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.");
        return 1;
    }

    while (fscanf(fp, "%d", &num) != EOF) {
        sum += num;
    }

    printf("%d\n", sum);

    fclose(fp);
    return 0;
}
