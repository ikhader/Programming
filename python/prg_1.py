#! /usr/bin/python

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

print "&&&&&&&&&&&&&&&&&&&&&"
ka = "test '%s' '%s' example" 
t = ka % (a , b)
print t
