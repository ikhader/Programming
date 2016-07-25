#! /usr/bin/python
from datetime import datetime, timedelta
import datetime

#comments
# print on console
print "Hello Wolrd"


# if elif else
# conditinoal statment

a = "HELLO"

if a == "hello":
  print "a has lowercase" 
  print a
elif a == "HELLO":
  print "a has all caps" 
else :
  print "bad bad bad"



#loop
cnt = 0
while (cnt < 5):
  print "value is %d" % cnt
  cnt = cnt + 1


#function 
def msg( var ):
  print "this is func msg"
  #loops on string, list
  for l in var:
    print "letter is: ", l

def list_print(li):
   for l in li:
    print "val is: ", l

msg( "helllo")

#list examples
alphabets = [ "a", "b", "c", "d"]
msg(alphabets)

print "alphabets have abcd"
list_print(alphabets)

print "alphabets delete b"
del alphabets[1]
list_print(alphabets)

print "alphabets add 'e' && over writting at index one"
alphabets[1] = 'z' 
alphabets.append("e")
list_print(alphabets)

#tupple examples
t = ("t1", "t2", "t3")
print("Tupples is")
list_print(t)


a = "HELLO"
b = "WORLD"

ka = "test '%s' '%s' example" 
t = ka % (a , b)
print t


#dictonary examples
dict_dict = {
              1: {"name" : "Khader", "age" : 30, "height": 6},
              2: {"name" : "Basha", "age" : 32, "height": 2}
            }
print dict_dict

print "&&&&&&&&&&&&&&&&&&&&&"
for key, value in dict_dict.iteritems() :
    print value
print "&&&&&&&&&&&&&&&&&&&&&"
d = {}

cnt = 1
while (cnt < 5):
  y = datetime.date.fromordinal(datetime.date.today().toordinal()-cnt).strftime("%F") 
  d[y] = cnt * 10;
  cnt = cnt + 1

print d

cnt = "hello"
if type(cnt) is int:
  print "cnt is integer"
else:
  print "not integer"


