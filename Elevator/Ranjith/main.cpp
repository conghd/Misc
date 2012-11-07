#include<stdio.h>
#include<stdlib.h>

#define FLOOR 100

void run_test(void);

static int floor[FLOOR];
static int elevator_pos;
static int elevator_person;
 
void move_elevator(int n)
{
    elevator_pos = n;
}

int get_floor(void)
{
return floor[elevator_pos];
}

void load_elevator(void)
{
    elevator_person     = floor[elevator_pos];
    floor[elevator_pos] = -1;
}

void unload_elevator(void)
{
    floor[elevator_pos] = elevator_person;
}

void exchange_elevator(void)
{
		int tmp = floor[elevator_pos];
    floor[elevator_pos] = elevator_person;
    elevator_person     = tmp;

	
}

void build_data(void)
{
for (int c = 0; c < FLOOR; c++) floor[c] = c;

for (int c = 0; c < FLOOR * FLOOR; c++)
    {
int i1 = rand() % FLOOR;
int i2 = rand() % FLOOR;

int tmp   = floor[i1];
        floor[i1] = floor[i2];
        floor[i2] = tmp;
    }

    elevator_pos = 0;

	for(int i=0;i<FLOOR;i++)
	{
		printf("THE Floor[ %d ] to Floor %d \n",i,floor[i]);
	}
}

void main(void)
{
for (int l = 0; l < 1; l++)
    {
        build_data();
		printf("calling the run");
        run_test();
		printf("called over");
    }
}
