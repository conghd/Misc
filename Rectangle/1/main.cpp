#include<stdio.h>
#include<stdlib.h>


#define SIZE 1000
#define RAND 1000
#define TEST_SIZE 10


static char map[TEST_SIZE][SIZE][SIZE];


int run_test(const char map[SIZE][SIZE]);


void build_map(void)
{
       for (int c = 0; c < TEST_SIZE; c++)
       {
             for (int x = 0; x < SIZE; x++) for (int y = 0; y < SIZE; y++) map[c][x][y] = 0;

             for (int y = 0; y < SIZE; y += 100)
             {
                    for (int x = 0; x < SIZE; x += 100)
                    {
                           int rx = x + (rand() % 10);
                           int ry = y + (rand() % 10);

                           int w =  (rand() % 80) + 2;
                           int h =  (rand() % 80) + 2;

                           for (int cy = ry; cy <= ry + h; cy++)
                           {
                                 if ((rand() % RAND) != 5) map[c][rx][cy] = 1;
                                  if ((rand() % RAND) != 5) map[c][rx+w][cy] = 1;
                           }
                           for (int cx = rx; cx <= rx + w; cx++)
                           {
                                 if ((rand() % RAND) != 5) map[c][cx][ry] = 1;
                                 if ((rand() % RAND) != 5) map[c][cx][ry+h] = 1;
                           }

                    }
             }
       }
}

void print_map(int map_id){
	for(int i=0;i<SIZE;i++){
		printf("\n");
		for(int j=0;j<SIZE;j++)
			printf("%d",map[map_id][i][j]);
	}
}


void main(void)
{
       build_map();
	   //print_map(0);
       for (int count = 0; count < TEST_SIZE; count++)
             printf("\nNo of rectangles:%d", run_test(map[count]));
}
