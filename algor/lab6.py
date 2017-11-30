def d(arr):
 if (len(arr)>1):
 #####Divide#####
  l1=[]
  l2=[]
  for i in range(len(arr)):
   if(i%2==0):
    l1.append(arr[i])
   else:
    l2.append(arr[i])
  l1 = d(l1)
  l2 = d(l2)

  #####Merge#####
  res = []
  for item in l1:
   res.append(item)
  for item in l2:
   res.append(item)
  arr = res

 return arr

#####Main#####
#prob1
# n = int(input("Enter the Number: "))
# a = range(n+1)
#prob2
a =[]
#a = range(-4,7)
#solute 3
b = input()
mlist = []
str = b.split(' ')
for i in range(len(str)):
    a.append(int(str[i]))
    # a.append(float(str[i]))
stack = []
for i in range(len(a)-1):
    # print(a[i])
    if(a[i]==a[i+1]):
        stack.append(a[i+1])
getter = list(set(a))
# print(stack)
# print(getter)
anslist = d(getter)
print(anslist)
thing = anslist
index = 0
while(index < len(a)):
    print(index)
    i = 0
    while(len(stack)>i):
            if anslist[index] == stack[i]:
            anslist.insert(index,stack[i])
            stack.pop(i)
        i+=1
    index+=1
print(anslist)
#solute4

getter = list(range(int(input())))
miss = (input()).split(" ")

print (getter)
getter = d(getter)
for i in range(len(miss)):
    getter.pop( getter.index(int(miss[i])))
print (getter)
