#include <stdio.h>
#include "database.h"

int main(void)
{
    T_employee   *employee[200];     // ptrs. to employees
    int     cnt=0;           // number of recorded employess
    int     lwage, hwage, lyear, hyear;
    char    cmd, iem;


    cnt = ini_db(employee, cnt);
    printf("\n\nInsert command: 'q' = quit, 'p' = print all employees in database, 'a' = add new employee, 's' = print selected employees\n");
	scanf("%c", &cmd); fflush(stdin);
	while (cmd != 'q')						// if not quit
	{
		switch (cmd)
		{
		case 'p': print_database(employee, cnt); break;
		case 'a': cnt=add_employee(employee, cnt); break;
		case 's': {
					printf("\nSelect low limit of wage:");
					scanf("%d", &lwage); fflush(stdin);
					printf("\nSelect high limit of wage:");
					scanf("%d", &hwage); fflush(stdin);
					printf("\nIs employed:");
					scanf("%c", &iem); fflush(stdin);
					printf("\nSelect low limit of year since employed:");
					scanf("%d", &lyear); fflush(stdin);
					printf("\nSelect high limit of year since employed:");
					scanf("%d", &hyear); fflush(stdin);


					print_employees_selected(employee, lwage, hwage, iem, lyear, hyear, cnt);
				  }
		}
        printf("\n\nInsert command: 'q' = quit, 'p' = print all employees in database, 'a' = add new employee, 's' = print selected employees\n");
        scanf("%c", &cmd); fflush(stdin);
	};
	save_erase_database(employee, cnt); // deleting of all recods
    return 0;
}
