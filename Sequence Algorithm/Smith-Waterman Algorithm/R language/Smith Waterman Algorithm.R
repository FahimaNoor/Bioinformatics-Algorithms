start_time <- Sys.time()
Match <- 2
MisMatchPenalty <- -3
GapPenalty <- -2
#creating matrix and initializing with alphabets
matrix<- matrix(0, nrow=9,ncol=9)
colnames(matrix) = c("X","A","T","G","C", "A","T","C","C")
rownames(matrix) = c("X","T","C","T","A","T","A","T","C")

#mismatch function
match_mismatch <- function(i,j){
  #if(matrix[i,1]==matrix[1,j]){   #can you use == sign?
  if(colnames(matrix)[j]==rownames(matrix)[i]){
            return(Match)
  }else{
            return(MisMatchPenalty)
  }
}
#maximum function
maximum<-function(i,j){
  max<-0
  value1<-0
  value2<-0
  value3<-0
  
  value1 <-matrix[i-1,j-1] + match_mismatch(i,j)  #can I use >= sign?
  value2 <-matrix[i-1,j] + GapPenalty
  value3 <-matrix[i,j-1] + GapPenalty
  
  if(value1 >= max)  max<-value1
  if(value2 >= max)  max<-value2
  if(value3 >= max)  max<-value3
  return(max)
}

#main function happens here 
  for(i in 2:nrow(matrix)){
    for(j in 2:ncol(matrix)){
      matrix[i,j]<-maximum(i,j)
    }
  }
matrix  #prints the matrix

end_time <- Sys.time()
end_time-start_time

