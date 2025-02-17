#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//user prompts
void ENTER_FIRST_NAME();
void ENTER_LAST_NAME();
void ENTER_MARK();

//errors
void INVALID_FIRST_NAME_ERROR();
void INVALID_LAST_NAME_ERROR();
void INVALID_MARK_ERROR();
void INVALID_EXAM_MARK_ERROR();

//checks
bool isNameValid(string name);
bool isMarkValid(string mark);

//program functions
void readInput(vector<Student>& students);
void calculateFinalMark(vector<Student>& students);
void output(vector<Student>& students);

#endif