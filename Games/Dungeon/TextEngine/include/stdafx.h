/******************************************************************************
filename    stdafx.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file includes standard system include files, or project-specific
include files that are used frequently, but are changed infrequently.

******************************************************************************/
#pragma once

/* disable warnings for single-line comments, since Microsoft's stdlib, etc use those extensively */
#pragma warning(push)
#pragma warning(disable : 4001)

#define _CRTDBG_MAP_ALLOC /* enable debug heap functions */
#include <stdlib.h> /* NULL, malloc/free */
#include <stdio.h> /* printf, fgets */
#include <stdbool.h> /* bool */
#include <stdarg.h> /* vaargs */
#include <string.h> /* strcmp, strcpy_s, strtok_s */
#include <windows.h> /* sleep, timeGetTime */
#include <crtdbg.h> /* crt*/
#include <math.h> /* sinf, cosf */

/*
* Used to clean /W4 unused parameters for functions that must match a function-pointer type
* NOTE: copied from winnt.h, but we don't want to include that here, otherwise
*/
#define UNREFERENCED_PARAMETER(P) (P)

/* pop the warning-disable */
#pragma warning(pop)