
void move_elevator(int n);
int  get_floor(void);
void load_elevator(void);
void unload_elevator(void);
void exchange_elevator(void);

void run_test(void)
{	
	bool visited[100];	
 	for(int i=0;i<100;i++)
	{
		visited[i]=false;
	}
	bool check_all_interchanged=false;
	int pos_start=0;
    int count_no_visited=0;
	do
	{
		 pos_start=0;
		 count_no_visited=0;
		for(int j=0;j<100;j++)
		{
			if(!visited[j])
			{				
				pos_start=j;
				break;
			}
			else
			{
				count_no_visited++;
			}
			
		}

		

		if(count_no_visited==100)
		{
			check_all_interchanged=true;
		}
		else
		{
			visited[pos_start]=true;
			
			move_elevator(pos_start);
			
			int run_first=1;
			int des_temp=get_floor();
			
			load_elevator();
			while((pos_start!=des_temp))
			{
				move_elevator(des_temp);				
				visited[des_temp]=true;
				des_temp=get_floor();
				exchange_elevator();			
			};
			
			move_elevator(des_temp);
			unload_elevator();
		}


		

	}while((!check_all_interchanged));

	
}
