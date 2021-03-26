#define Match 2
#define MisMatchPenelty -3
#define GapPenalty -2

/// There can be only four types of maximum value1, value2, value3,value4(The fourth type of maximum value is always zero. The matrix
                                                                        ///is initialized as 0 automatically so no need to create another variable for it)

///GLOBAL VARIABLE
int matrix[10][10];  ///m+2, n+2  //the matrix you will declare will be 2+ the length of string sequence


int match_mismatch(int i, int j){ ///this function checks whether the i index and j index are same or not
    if(matrix[i][0]==matrix[0][j]) return Match;
    else return MisMatchPenelty;
}

int maximum(int i, int j){  /// main algorithm happens here. It check all the four maximum conditions and returns the highest maximum value to the corresponding matrix index
    int max=0;
    int value1=0,value2=0,value3=0;

    value1= matrix[i-1][j-1]+ match_mismatch(i,j);
    value2= matrix[i-1][j]+ GapPenalty;
    value3= matrix[i][j-1]+ GapPenalty;

    if(value1>=max) max=value1;   ///now all the conditions will be checked to see which value is highest
    if(value2>=max) max=value2;
    if(value3>=max) max=value3;

return max;
}


void print(){
    for(int i=0;i<10;i++){          ///prints the matrix
            for(int j=0;j<10;j++){
            printf("%d\t ", matrix[i][j]);
            }
            printf("\n\n");
    }
}

void main(){
    matrix[0][0]=-99;  ///this index will not be used in the algorithm
    matrix[0][1]=-99;  ///this index will not be used in the algorithm
    matrix[1][0]=-99;  ///this index will not be used in the algorithm

    int count_1=0;
    int count_2=0;
    int highest_value=0,index_i=0,index_j=0;

    char string_1[]="ATGCATCC";   ///Input String_1 //string length 8
    char string_2[]="TCTATATC";   ///Input String_2 //string length 8


    for(int i=0;i<10;i++){   /// initializing the matrix with alphabet equivalent values// the i condition will be +2 to the string length as [0][0] ,[0][1], [1][0] will not be used
            for(int j=0;j<10;j++){
               if(i==0 && j!=0 && j!=1){
                matrix[i][j]= string_1[count_1];  ///string_1 is being put inside the i=0 row, starting from j=2
                count_1++;
               }
               if(j==0 && i!=0 && i!=1){
                    matrix[i][j]= string_2[count_2]; ///string_2 is being put inside the j=0 row, starting from i=2
                    count_2++;
               }
            }
    }

    for(int i=1;i<10;i++){   /// initializing values to the index of the matrix
            for(int j=1;j<10;j++){
            if((i==1 || j==1) && ( i!=0 &&  j!=0) ) matrix[i][j]=0;  ///exceptional case. The row i=1 and column j=1 are given the value of zero according to algorithm
            else matrix[i][j] = maximum(i,j);
            }
    }

    print();  ///prints the matrix
}
