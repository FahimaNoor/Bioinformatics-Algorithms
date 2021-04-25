import numpy
import time

start_time = time.time()
time.sleep(1)

# Scores
Match = 2
MisMatchPenelty = -3
GapPenalty = -2

# Values Assigned to Characters
A = 1
T = 2
G = 3
C = 4

# Initializing Variables
value1 = 0
value2 = 0
value3 = 0

#Creating 2D Array
x = 10
matrix = numpy.zeros(shape=(x, x))  # int matrix[9][9];

# Assigning Variables into 2D array
matrix[0,] = [0, 0,A,T,G,C,A,T,C,C]
s1 = [0, 0, T,C,T,A,T,A,T,C]
for i in range(0, x):
    matrix[i, 0] = s1[i]

#Function to return the MisMatch Score
def match_mismatch(i, j):
    if matrix[i, 0] == matrix[0, j]:
        return Match
    else:
        return MisMatchPenelty


def maximum(i, j):
    max = 0

    value1 = matrix[i - 1][j - 1] + match_mismatch(i, j)
    value2 = matrix[i - 1][j] + GapPenalty
    value3 = matrix[i][j - 1] + GapPenalty

    if value1 >= max:
        max = value1
    if value2 >= max:
        max = value2
    if value3 >= max:
        max = value3

    return max


def main():
    matrix[0, 0] = -99
    matrix[0, 1] = -99
    matrix[1, 0] = -99


for i in range(1, x):
    for j in range(1, x):
        if (i == 1 or j==1) and (i!= 0 and j!=0):
            matrix[i, j] = 0
        else:
            matrix[i, j] = maximum(i, j)

print(matrix)

end = time.time()
print("--- %s seconds ---" % (time.time() - start_time))
