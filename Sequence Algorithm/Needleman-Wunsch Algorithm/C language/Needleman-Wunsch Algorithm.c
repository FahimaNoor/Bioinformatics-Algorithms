#define Match 1
#define MisMatchPenelty -1
#define GapPenalty -1

/// There can be only three types of maximum vales: value1, value2, value3

///GLOBAL VARIABLE
int matrix[9][9];  //m+2, n+2  STRING LENGHT WAS 8


int match_mismatch(int i, int j){ ///this function checks whether the i index and j index are same or not
    if(matrix[i][0]==matrix[0][j]) return Match;
    else return MisMatchPenelty;
}

int maximum(int i, int j){  /// main algorithm happens here. It check all the four maximum conditions and returns the highest maximum value to the corresponding matrix index
    int max=-999;  ///need a max variable to return a value from this function.
                    ///But it has to be made sure that the value of this max function can never be the maximum value as the maximum value of this algo can also give negative maximum.

    int value1=0,value2=0,value3=0;

     if(i==1) return matrix[i][j-1]+ GapPenalty;  ///only the value_3 algo works for this condition
     if(j==1) return matrix[i-1][j]+ GapPenalty;  ///only the value_2 algo works for this condition

    value1= matrix[i-1][j-1]+ match_mismatch(i,j);
    value2= matrix[i-1][j]+ GapPenalty;
    value3= matrix[i][j-1]+ GapPenalty;

    if(value1>=max) max=value1;   ///now all the conditions will be checked to see which value is highest
    if(value2>=max) max=value2;
    if(value3>=max) max=value3;

return max;
}

void print(){    ///prints the matrix
    for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
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

    char string_1[]="ATCGGAG";   ///Input String_1 //string length 8
    char string_2[]="ATGGCAA";   ///Input String_2 //string length 8
    char c[10]; ///Will delete this line after i say so

    for(int i=0;i<9;i++){   /// initializing the matrix with alphabet equivalent values// the i condition will be +2 to the string length as [0][0] ,[0][1], [1][0] will not be used
            for(int j=0;j<9;j++){
               if(i==0 && j!=0 && j!=1){
                matrix[i][j]= string_1[count_1];  ///string_1 is being put inside the i=0 row, starting from j=2
                count_1++;
               }
               if(j==0 && i!=0 && i!=1){   ///string_2 is being put inside the j=0 row, starting from i=2
                    matrix[i][j]= string_2[count_2];
                    count_2++;
               }
            }
    }

for(int i=1;i<9;i++){   /// initializing values to the index of the matrix  //maximum function will be called from which maximum value will be obtained and kept inside the particular index
            for(int j=1;j<9;j++){
            if(i==1 && j==1) matrix[i][j]=0;
            else matrix[i][j] = maximum(i,j);
            }
    }

    print();  ///prints the matrix
}
