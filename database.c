#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"

void corrstr(char *str)
{
    int n;

    for(n = 0; str[n] != '\n'; n++);
    str[n] = '\0';
}


int ini_db(T_employee **rec, int num)			// function for store initialization by chosen goods
{
	T_employee  *new_employee;
    FILE   *ptrf;
    char    nm[20], ps[10], ie;
    int     wg, m, yr, d, no_rec, n;

    ptrf = fopen("database.txt","r");

    if(ptrf != NULL)
    {
        fscanf(ptrf, "%d\n", &no_rec);
        if(no_rec > 0)
        {
          for(n = 0; n<no_rec; n++)
          {
              fgets(nm, 20, ptrf);
              corrstr(nm);
              fgets(ps, 10, ptrf);
              corrstr(ps);
              fscanf(ptrf, "%c\n", &ie);
              fscanf(ptrf, "%d\n", &wg);
              fscanf(ptrf, "%d\n", &yr);
              fscanf(ptrf, "%d\n", &m);
              fscanf(ptrf, "%d\n", &d);
              new_employee = (T_employee*)malloc(sizeof(T_employee));
              strcpy(new_employee->name, nm);
              strcpy(new_employee->position, ps);
              new_employee->isemp = ie;
              new_employee->wage = wg;
              new_employee->year = yr;
              new_employee->month = m;
              new_employee->day = d;
              rec[num++] = new_employee;
          }
        }
        else
            printf("\n No employees in database.txt file\n");
    }
	else
        printf("\n File database.txt was not searched\n");
    fclose(ptrf);
    return num;
}

void print_record(T_employee *premp)
{
    printf("Name: %s\nPosition: %s\n", premp->name, premp->position);
    if(premp->isemp=='Y')
       printf("employed since %d.%d.%d", premp->day, premp->month, premp->year);
    else if(premp->isemp=='N')
       printf("not employed");
    printf("Wage: %d\n", premp->wage);
}



void print_database(T_employee **rec, int num)
{
    int n;

    for(n=0; n<num; n++)
        print_record(rec[n]);
}


void save_erase_database(T_employee **rec, int num)
{
  int n = 0;
  FILE   *ptrf;

   ptrf = fopen("database.txt","w");

    if(ptrf != NULL)
    {
        fprintf(ptrf, "%d\n", num);
        if(num > 0)
        {
          for(n = 0; n<num; n++)
          {
              fputs(rec[n]->name, ptrf);
              fputc('\n', ptrf);
              fputs(rec[n]->position, ptrf);
              fputc('\n', ptrf);
              fprintf(ptrf, "%c\n", rec[n]->isemp);
              fprintf(ptrf, "%d\n", rec[n]->wage);
              fprintf(ptrf, "%d\n", rec[n]->year);
              fprintf(ptrf, "%d\n", rec[n]->month);
              fprintf(ptrf, "%d\n", rec[n]->day);
              free(rec[num]);
          }
        }
    }
	fclose(ptrf);
	printf("All employees have been saved and deleted");

}



void print_employees_selected(T_employee **rec, int wg_lo, int wg_hi, char emp, int yr_lo, int yr_hi, int num)
{
    int n;

    for(n=0; n<num; n++)
        if((rec[n]->wage >= wg_lo) && (rec[n]->wage <= wg_hi) &&
           (rec[n]->isemp == emp) &&
           (rec[n]->year >= yr_lo) && (rec[n]->year <= yr_hi))
             print_record(rec[n]);
}

int add_employee(T_employee **rec, int num)
{
    T_employee   *new_employee;
    char    str[20], ch;
    int     val;

    new_employee = (T_employee*)malloc(sizeof(T_employee));
    printf("\nNew employee \nInsert name: ");
    gets(str); fflush(stdin);
    strcpy(new_employee->name, str);
    printf("\nInsert position: ");
    gets(str); fflush(stdin);
    strcpy(new_employee->position, str);
    printf("\nIs employed: ");
    scanf("%c", &ch); fflush(stdin);
    new_employee->isemp = ch;
    printf("\nInsert wage: ");
    scanf("%d", &val); fflush(stdin);
    new_employee->wage = val;
    printf("\nInsert year: ");
    scanf("%d", &val); fflush(stdin);
    new_employee->year = val;
    printf("\nInsert month: ");
    scanf("%d", &val); fflush(stdin);
    new_employee->month = val;
    printf("\nInsert day: ");
    scanf("%d", &val); fflush(stdin);
    new_employee->day = val;
    rec[num++] = new_employee;

	return num;
}
