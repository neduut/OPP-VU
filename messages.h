#ifndef MESSAGES_H
#define MESSAGES_H
#include "common.h"

//prompt messages
const string ENTER_FIRST_NAME = "Enter first name: ";
const string ENTER_LAST_NAME = "Enter last name: ";
const string ENTER_MARK = "Enter mark: ";
const string ENTER_EXAM_MARK = "Enter exam mark: ";

//error messages
const string INVALID_FIRST_NAME_ERROR = "Error: First name is not valid.";
const string INVALID_LAST_NAME_ERROR = "Error: Last name is not valid.";
const string INVALID_MARK_ERROR = "Error: The mark must be an integer within the range [1-10].";
const string INVALID_EXAM_MARK_ERROR = "Error: The exam mark must be an integer within the range [1-10].";

#endif