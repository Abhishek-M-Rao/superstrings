// superstrings <Project1.cpp>
// EE 312 Project 1 submission by
// Abhishek Rao
// amr7999
// Slip days used: 0
// Fall 2021
// Include the contents of this file at the top of every file that you submit, replacing the fields within <>.
// Do not keep the <>.

/*
 * Project1.cpp
 *
 * Name: Ima Student
 * EE312 Summer 2020
 * SuperStrings
 */

#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <string.h>
/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/
void firstLettersArray(char targets []);
void numSSfunc(char candidates[]);
void SetSSArray(char candidates[]);
void GetStrWord(char targets[]);
void PartialTest(char candidates[], char targets[]);

int globSSCount = 0;
int globStrCount = 0;
int Count = 0;
char SSWord[21];
char firstLetters[5002];
char numLetters[5002];
char strWord[21];
char lenSS[5002];

void printSuperStrings(char targets [], char candidates []) {
    numSSfunc(candidates);
    firstLettersArray(targets);
    PartialTest(candidates, targets);
    globSSCount = 0;
    globStrCount = 0;
    Count = 0;
}

void firstLettersArray(char targets []) {
    int i = 0;
    int j = 0;
    while(targets[i] != '\0') {
        if ((targets[i] == 32) || (targets[i] == '\n') || (targets[i] == '\t')){
            i++;
        } else {
            firstLetters[j] = targets[i];
            numLetters[j] = targets[i];
            j++;
            for(int p = 0; p < (j-1); p++){
                if(firstLetters[p] == firstLetters[j-1]){
                    firstLetters[j-1] = 0;
                }
            }
            while ((targets[i] != 32) && (targets[i] != '\n') && (targets[i] != '\t')) {
                i++;
                if (targets[i] == '\0') {
                    firstLetters[j] = 0;
                    break;
                }
            }
        }
    }
}

void numSSfunc(char candidates[]){
    int i = 0;
    int j = 0;
    while(candidates[i] != '\0') {
        if ((candidates[i] == 32) || (candidates[i] == '\n') || (candidates[i] == '\t')){
            i++;
        } else {
            lenSS[j] = candidates[i];
            j++;
            while ((candidates[i] != 32) && (candidates[i] != '\n') && (candidates[i] != '\t')) {
                i++;
                if (candidates[i] == '\0') {
                    lenSS[j] = 0;
                    break;
                }
            }
        }
    }
}

void SetSSArray(char candidates[]){
    int i = 0;
    while ((candidates[globSSCount] == 32) || (candidates[globSSCount] == '\n') || (candidates[globSSCount] == '\t')) {
        globSSCount++;
    }
    while ((candidates[globSSCount] != 32) && (candidates[globSSCount] != '\n') && (candidates[globSSCount] != '\t')) {
        if ((candidates[globSSCount] == '\n') || (candidates[globSSCount] == '\0') || (candidates[globSSCount] == '\t') || (candidates[globSSCount] == 32)) {
            SSWord[i] = 0;
            break;
        } else {
            SSWord[i] = candidates[globSSCount];
            i++;
            globSSCount++;
            if ((candidates[globSSCount] == 32) || (candidates[globSSCount] == '\n')|| (candidates[globSSCount] == '\t')) {
                SSWord[i] = 0;
                break;
            }
        }
    }
}

//second-to-last function should grab the first word in the string, then the next, till the end
void GetStrWord(char targets[]) {
    int i = 0;
    while ((targets[globStrCount] == 32) || (targets[globStrCount] == '\n') || (targets[globStrCount] == '\t')) {
            globStrCount++;
        if (targets[globStrCount] == '\0') {
            strWord[i] = 0;
            break;
        }
    }
    while ((targets[globStrCount] != 32) && (targets[globStrCount] != '\n') && (targets[globStrCount] != '\t')) {
        if (targets[globStrCount] == '\0') {
            strWord[i] = 0;
            break;
        } else {
            strWord[i] = targets[globStrCount];
            i++;
            globStrCount++;
            if ((targets[globStrCount] == 32) || (targets[globStrCount] == '\n') || (targets[globStrCount] == '\t')) {
                strWord[i] = 0;
                break;
            }
        }
    }
}

void PartialTest(char candidates[], char targets[]) {
    int ptr1;
    int ptr2;
    int superLen = strlen(lenSS);
    int stringLen = strlen(numLetters);
    for (int j = 0; j < stringLen; j++) {
        globSSCount = 0;
        GetStrWord(targets);
        SetSSArray(candidates);
        for (int i = 0; i < superLen; i++) {
            ptr1 = 0;
            ptr2 = 0;
            while ((SSWord[ptr1] != 0) && (strWord[ptr2] != 0)) {
                if (SSWord[ptr1] == strWord[ptr2]) {
                    ptr1++;
                    ptr2++;
                } else {
                    ptr1++;
                }
            }
            if (strWord[ptr2] == 0) {
                printf("%s\n", SSWord);
                Count++;
                SetSSArray(candidates);
            } else{
                SetSSArray(candidates);
            }
        }
    }
}
//change this