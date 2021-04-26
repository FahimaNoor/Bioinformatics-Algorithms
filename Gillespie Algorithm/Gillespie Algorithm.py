import numpy as np
import matplotlib
matplotlib.use('tkagg')
import matplotlib.pyplot as plt
import random
#how the Gillispie Algorithm works is that at some time t, (t+tau) is the time of next that is happening. We chooose that time as well as the the event that will be happening(randomly)
#We keep on doing this like a loop till the end of the simulation

#Dynamic Array
X = [0] #Event Array. Will store the evens for every time t #everytime reaction happens, the values of the event will append to the array
t = [0]

tend = 1000  #End Time for the Algorithm

#need production rate and degradation rate
k=2
gamma=0.1 # this will remain constant
while t[-1] <  tend:
    current_X = X[-1]  #the value of X is dynamic and keeps on changing. As we need to work with the instantaneous value of X

    rates = [k, gamma*current_X]
    rate_sum=sum(rates)
    #time_point of next even(t+tau)
    #tau is a random draw from an exponential distribution
    
    tau=np.random.exponential( scale = 1/rate_sum )  #scale parameter is 1/lamda
    t.append(t[-1]+tau)

    rand = random.uniform(0,1)  #PRODUCT OF RANDOM DECIMAL

#event
    #production event
    if rand* rate_sum > 0 and rand * rand * rate_sum < rates[0]:    #rates[0]=K, RANGE: 0<RAND<k  #WHAT THIS LINE IS TRYING TO SAY THAT IF THE RANDOMLY GENERATED RATE FALLS WITHIN THIS RANGE THEN EXECUTE THE NEXT LINE
        X.append(X[-1]+ 1)           #EVENT 1 WILL GET APPENDED TO THE EVENT ARRAY
   #decay event
    elif  rand* rate_sum > rates[0] and rand * rand * rate_sum < rates[0] + rates[1]:  #PRODUCT GREATER THAN K BUT LESS THAN THE SUM OF k + gAMMA*X
        X.append(X[-1] - 1)          #EVENT 2 WILL GET APPENDED TO THE EVENT ARRAY

    #plotting
plt.plot(t,X)
plt.xlabel("time")
plt.ylabel("mRNA quantity")
plt.show()
