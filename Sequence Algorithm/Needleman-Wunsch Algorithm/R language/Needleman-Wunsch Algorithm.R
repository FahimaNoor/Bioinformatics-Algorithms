start_time <- Sys.time()
Match <- 1
MisMatchPenalty <- -1
GapPenalty <- -1

#creating matrix and initializing with alphabets
matrix<- matrix(0, nrow=8,ncol=8)
colnames(matrix) = c("X","A","T","C","G","G","A","G")
rownames(matrix) = c("X","A","T","G","G","C","A","A")

#mismatch function
match_mismatch <- function(i,j){
  if(colnames(matrix)[j]==rownames(matrix)[i]){
    return(Match)
  }else{
    return(MisMatchPenalty)
  }
}

#maximum function
maximum<-function(i,j){
  max<- -999 #such value is used only to ensure that this value does not affect other
  value1<-0
  value2<-0
  value3<-0
  
  if(i==1){
    return(matrix[i,j-1] + GapPenalty) 
  }
  if(j==1){
    return(matrix[i-1,j] + GapPenalty) 
  }
  value1 <-matrix[i-1,j-1] + match_mismatch(i,j) 
  value2 <-matrix[i-1,j] + GapPenalty
  value3 <-matrix[i,j-1] + GapPenalty
  
  if(value1 >= max)  max<-value1
  if(value2 >= max)  max<-value2
  if(value3 >= max)  max<-value3
  return(max)
}

#main function happens here

matrix[i,j]=0
for(i in 1:nrow(matrix)){
  for(j in 1:ncol(matrix)){
    if(i==1 & j==1){
      matrix[i,j]<-0
    }else{
      matrix[i,j]<-maximum(i,j)
    }
  }
}
matrix  #prints the matrix

end_time <- Sys.time()
end_time-start_time
