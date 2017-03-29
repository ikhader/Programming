
#generators are nothing but 'yeild'
#Generators functions allow you to declare a function that behaves like an iterator, i.e. it can be used in a for loop.
# this will help in memory, stack will not grow if squares to be caluclated 100000 numbers

def square(n):
  result = []
  for i in n:
    result.append(i*i)
  return result

my_nums = square([1,2,3, 4])
print "Non-genrator format: "
print my_nums



def gen_square(n):
  for i in n:
    yield(i*i)

print "genrator format: "
num = gen_square([1,2,3, 4])
print next(num)
print next(num)
print next(num)
print next(num)

print("If we print one more time of generator we will 'StopIteration' error")

nums = gen_square([10, 20, 30, 40])
print ("Generator usecase -1")
for n in nums:
  print n

import sys
print ('Memory (Before): {0}Mb'.format(sys.getsizeof([])))

print ("Generator usecase -2")
my_nums = (x*x for x in [1,2,3])
print my_nums
for n in my_nums:
  print n

print ("Generator usecase -3")
my_nums = (x*x for x in [1,2,3])
print list(my_nums)


