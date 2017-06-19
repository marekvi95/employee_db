#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

typedef struct employee     // employee record
{
  char  name[20];           // name of employee
  char  position[10];          // working position
  char isemp;                // is active Y or N
  int   wage;                // salary
  int   year;               // year since employed
  int   month;              // month since employed
  int   day;              // day since employed
} T_employee;

void corrstr(char *str);
int ini_db(T_employee **rec, int num);			// function for db initialization by few employees
void print_record(T_employee *premp);                // function for printing of paramaters of chosen employee
void print_db(T_employee **rec, int num);         // function for printing of db content
void save_erase_db(T_employee **rec, int num);    // function for saving and deleting of all records
void print_employees_selected(T_employee **rec, int wg_lo, int wg_hi, char emp, int yr_lo, int yr_hi, int num); // function for printing employees with selected ranges of params.
int add_employee(T_employee **rec, int num);              // function for adding of new employee

#endif // DATABASE_H_INCLUDED
