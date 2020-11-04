#define _CRT_SECURE_NO_WARNINGS
#include <process.h>
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");
    FILE* f = fopen(argv[1], "r");
    char* pEnd;
    char c, ch[50];
    int counter = -1, max = strtoll(argv[2], &pEnd, 10);
    cout << "Original file:\n";
    while (true)
    {
        counter++;
        ch[counter] = fgetc(f);
        if (ch[counter] == EOF)
            break;
        cout << ch[counter] << " ";
    }
    fclose(f);
    f = fopen(argv[1], "w");
    cout << "\nNew file:\n";
    for (int i = 0; i < counter; i++) {
        if (i == max) {
            fprintf(f, "Z");
            cout << "Z ";
        }
        fprintf(f, "%c", ch[i]);
        cout << ch[i] << " ";
    }
    fclose(f);
}
