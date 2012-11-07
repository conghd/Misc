#define SIZE 1000
/*
Assumption made(to understand the comments) : top-left node is (0,0) and can be known as north-most and west-most node.
Assumption made(for code to run) : NONE.
*/


bool chkRect(const char map[SIZE][SIZE], int x1, int y1, int x2, int y2){
	int i=0, j=0;
	
	for(i=x1;i<=x2;i++){
		if(map[i][y1]==0 || map[i][y2]==0)
			return false;
	}
	
	for(i=y1;i<=y2;i++){
		if(map[x1][i]==0 || map[x2][i]==0)
			return false;
	}
	//here the filling is checked for continous 0's
	for(i=x1+1;i<x2;i++){
		for(j=y1+1;j<y2;j++){
			if(map[i][j]==1)
				return false;
		}
	}
	//any voilation of the above conditions would say that its not a rectangle
	//otherwise its a rectangle
	return true;
}

//main method that will be called from main.cpp 10 times with 10 different matrices
int run_test(const char map[SIZE][SIZE])
{
	int noOfRect = 0;
	//traverse through entire map
	for(int a=0; a < SIZE; a++){
		for(int b = 0; b < SIZE; b++){
			//check the value of current cell for 1
			//then check if 2 points are present in east and south
			//then check if immediate south east point is 0 or not
			//then check if immediate 2 east and 2 south points are 1 or not
			if(map[a][b] == 1 && a+2 < SIZE && b+2 < SIZE && 
				map[a+1][b+1] == 0 && 
				map[a+1][b] == 1 && map[a+2][b] == 1 && 
				map[a][b+1] == 1 && map[a][b+2] == 1){
					//now from current point find the next best eligible point for the rectangle calculation
					for(int c = a+2; c < SIZE; c++){
						for(int d = b+2; d < SIZE; d++){
							//check if the current candidate node is 1 or not
							//then check if immediate north-west node is 0 or not
							//then check if immediate 2 north and 2 west points are 1 or not
							//then if all correct, check if its a rectangle or not.
							if(map[c][d] == 1 && map[c-1][d-1] == 0 && map[c-1][d] == 1 && map[c-2][d] == 1 && 
								map[c][d-1] == 1 && map[c][d-2] == 1 && chkRect(map, a, b, c, d)){
									//so finally its a rectangle, increase the count by 1
									noOfRect++;
							}
						}
					}
			}
		}
	}
	return noOfRect; // returning the number of rectangles
}