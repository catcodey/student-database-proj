import numpy as np
import matplotlib.pyplot as plt

studentroll=input("enter roll")
f=open("data.txt","r")
a=0
l=[]
l1=[]
c=0
b=0
for i in f.readlines():
    
    x=i.split()
    if x[0]!=studentroll:
        c=c+1
        a=a+int(x[5])+int(x[6])+int(x[7])
    else:
        b=b+int(x[5])+int(x[6])+int(x[7])
#print(a)
outof100=a/((c)*3)
outof100_1=b/3
l.append(outof100)

l1.append(outof100_1)


# creating the dataset

courses = ['Your average','Class average']
values = [l1[0],l[0]]

fig = plt.figure(figsize = (10, 5))

# creating the bar plot
plt.bar(courses, values, color ='maroon',
		width = 0.4)

#plt.xlabel("Courses offered")
plt.ylabel("Marks Percentage")
plt.title("Your Performace")
plt.show()
