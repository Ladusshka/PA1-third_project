# PA1-third_project
The task is to implement two functions (not the whole program, only two functions) that will facilitate the calculation of working days in a given data interval. The required functions have the following interfaces:

bool isWorkDay ( int y, int m, int d )
This function decides whether the specified day is a work day or not. The parameters are the year, month and the day to be checked. The return value is true if the specified day is a working day, or false if the specified day is a day off (Saturday, Sunday, holiday) or an invalid date was specified.

TResult countDays ( int y1, int m1, int d1, int y2, int m2, int d2 )
This function calculates the number of days and working days in the specified interval. The interval is given by the year, month, and start (y1, m1, d1) and end (y2, m2, d2) days. We consider the interval closed, so we include both boundary days in the calculation. The return value of the function is a structure with components m_TotalDays (number of days in the specified interval) and m_WorkDays (number of working days in the specified interval). If the function receives invalid parameter values (see below), the function will return a structure where both components are set to -1.

TResult structure is declared in the test environment, your implementation will use it but must not change the declaration. The structure contains two components:
  m_TotalDays - the total number of days and
  m_WorkDays - the number of working days.

The correct values of the input parameters must meet:

    the year is greater than 2000 (all data before 2000 are considered invalid),
    the month is valid (1 to 12),
    day is valid (1 to the number of days in the month),
    in the countDays function, the date of the beginning of the interval ≤ the date of the end of the interval.
Submit a source file that contains an implementation of the required isWorkDay and countDays functions. Add your other supporting functions that are called from these functions to the source file. The functions will be called from the test environment, so it is important to follow the specified function interface exactly. Use the code from the attached file as a basis for implementation. Missing from the code are the bodies of the required functions (and any additional support functions). The sample contains a test function main, the values given are used in the basic test. Note that the header file insertion and the main function are wrapped in a conditional compilation block (#ifdef/#endif). Please leave the conditional translation blocks in the committed source file as well. Conditional translation will simplify your work. When compiled on your machine, you can run and test the program normally. When compiling on Progtest, the main function and the header file insertion "disappear", i.e. they will not interfere with the header files and the main function of the test environment.


Traditionally, we consider Monday to Friday as working days. In addition, we do not consider public holidays as working days. We consider public holidays as follows:

    1.1, 1.5, 8.5, 5.7, 6.7, 28.9, 28.10, 17.11, 24.12, 25.12 a 26.12
   
Easter is missing from the list. The day of Easter is determined by the phase of the moon, the exact calculation is more complicated. Therefore, we will not consider Easter in this problem.

We consider the Gregorian calendar when calculating the time. Thus, months always have 30 or always 31 days, the exception being February, which has 28 days (nonleap year) or 29 days (leap year). According to the Gregorian calendar:

years are not leap years,
except for years divisible by 4, which are leap years,
except for years divisible by 100, which are not leap years,
except for years divisible by 400, which are leap years,
except for years divisible by 4000, which are not leap years.
Thus, the years 2001, 2002, 2003, 2005, ... are not leap years (rule 1), the years 2004, 2008, ..., 2096, 2104, ... are leap years (rule 2), the years 2100, 2200, 2300, ... are not leap years (rule 3), the years 2000, 2400, ..., 3600, 4400, ... are leap years (rule 4) and the years 4000, 8000, ... are not leap years (rule 5).
