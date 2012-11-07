#define FLOOR 100 //Do not do this declaration as this is violation

void move_elevator(int n);
int  get_floor(void);
void load_elevator(void);
void unload_elevator(void);
void exchange_elevator(void);


void run_test(void)
{
	int personTargetFloor;
	for(int currentFloor=0;currentFloor<FLOOR;currentFloor++){//Hardcode FLORR->100.
		move_elevator(currentFloor);
		personTargetFloor=get_floor();
		//Proceed only if person belongs to other floor..
		if(personTargetFloor!=currentFloor){
			//Load him to elevator..
			load_elevator();
			//Iterate till no person moved to elevator..
			while(personTargetFloor!=-1){
				move_elevator(personTargetFloor);
				personTargetFloor=get_floor();
				exchange_elevator();
			}
		}

	}
}
