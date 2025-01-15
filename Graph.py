import matplotlib.pyplot as plt
 
f=open('stats.txt','r')
str=f.read()

list=str.split(',')
list.pop(len(list)-1)

x=[]	#input
y=[]	#time

for i in range(len(list)):
	if(i%2==0):
		x.append(int(list[i]))
	else:
		y.append(float(list[i]))

plt.plot(x,y)

plt.xlabel('Number')
plt.ylabel('Time')
 
plt.title('Fibonacci Generator Analysis')
plt.show() 
plt.savefig('stats.png')
