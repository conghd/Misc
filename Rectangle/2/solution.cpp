// DO NOT INCLUDE ANY FILES

#define SIZE 1000
bool is_valid_rectangle(const char map[SIZE][SIZE],int,int);//User defined
/*
//Usual way by traversing entire array by iterating row X column vice.
int run_test(const char map[SIZE][SIZE])
{
	int no_of_rectangle=0;
	int tem_row,tem_col,tem_ht,tem_wd,ht,wd;
	for(int row=0;row<SIZE-2;row++){
		for(int col=0;col<SIZE-2;col++){
			tem_row=tem_col=0;
			if(map[row][col]==1){
				//check row and column simultaneously for rectangle
				tem_ht=tem_wd=0;
				tem_row=row;
				tem_col=col;
				while(tem_row<SIZE && map[tem_row++][col])
					tem_ht++;
				while(tem_col<SIZE && map[row][tem_col++])
					tem_wd++;
				ht=tem_ht;
				wd=tem_wd;
				//Check for another side..iff rectangle height & width is greater than or equal to 3
				if( ht>2 && wd>2){
					tem_row=row;
					tem_col=col;
					tem_ht=tem_wd=0;
					while(tem_row<SIZE && map[tem_row++][col+wd-1])
						tem_ht++;
					while(tem_col<SIZE && map[row+ht-1][tem_col++])
						tem_wd++;

					//Finally..iff lenght & breadth of rectangle are equal.
					if(tem_ht==ht && tem_wd==wd && ht>2 && wd>2)//You may remove >2 check..
					{
						//found a valid rectangle..
						//So evaluate for 0's presence..
						for(int x=row+1;x<row+tem_ht;x++){
							for(int y=col+1;y<col+tem_wd;y++){
								if(map[x][y]==0) {
									no_of_rectangle++;
									x=row+tem_ht+1;//to break outer loop..:P
									break;
								}//inner
							}//outer
						}
						
						//you may optimize here by skipping next wd columns!
						//as this rectangle is no longer valid and overlapping is not happening,
						//you may skip to the end of this rectangle's width
						//i.e col+=wd;
						

					}//if closed..

				}//Outer if closed..
								
				
			}//COLUMN interation..
		}//ROW iteration..

	}

	return no_of_rectangle;// the number of rectangle
}
*/



//This is second approach: Traversing diagonally through the array..
int run_test(const char map[SIZE][SIZE])
{
	int no_of_rectangle=0;
	
	//Check diagonally..
	for(int diagonal=0;diagonal<SIZE-2;diagonal++){

		//Check row wise..VERTICALLY
		for(int row=diagonal;row<SIZE-2;row++)
			if(map[row][diagonal]==1){
				if(is_valid_rectangle(map,row,diagonal))
					no_of_rectangle++;
			}//Outer if closed..
		
		//Check column wise..
		for(int col=diagonal+1;col<SIZE-2;col++)
			if(map[diagonal][col]==1){
				if(is_valid_rectangle(map,diagonal,col))
					no_of_rectangle++;
			}//Outer if closed..
			
			
	}

	return no_of_rectangle;// the number of rectangle
}

//Seperate module to evaluate a valid rectangle.
//You may optimize further by adding one more flag parameter which 
//indicates whether height/width of rectangle should be returned. & 
//return of type int-height/width to skip.
bool is_valid_rectangle(const char map[SIZE][SIZE],int row,int col){

	int tem_row,tem_col,tem_ht,tem_wd,ht,wd;

	tem_row=tem_col=0;

	tem_ht=tem_wd=0;
	tem_row=row;
	tem_col=col;
	while(tem_row<SIZE && map[tem_row++][col])
		tem_ht++;
	while(tem_col<SIZE && map[row][tem_col++])
		tem_wd++;
	ht=tem_ht;
	wd=tem_wd;
	//Check for another side..iff
	if( ht>2 && wd>2){
		tem_row=row;
		tem_col=col;
		tem_ht=tem_wd=0;
		while(tem_row<SIZE && map[tem_row++][col+wd-1])
			tem_ht++;
		while(tem_col<SIZE && map[row+ht-1][tem_col++])
			tem_wd++;

		//Finally..
		if(tem_ht==ht && tem_wd==wd && ht>2 && wd>2)
		{
			//found a valid rectangle..
			//So evaluate for 0's presence..
			for(int x=row+1;x<row+tem_ht;x++){
				for(int y=col+1;y<col+tem_wd;y++){
					if(map[x][y]==0)
						return true;
						//You may return height/width of the rectangle depending on a flag
						//so that you can skip unnecessary iteration[as per req: no rect overlaps]
					}//inner
				}//outer
			}
		}//if closed..
		return false;
}
