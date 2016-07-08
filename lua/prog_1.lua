
print "Hello world!!!"


--variable usage
a = "Hello world"
print ("Variable is:", a)

-- conditional checking
a = 30
if(a == 10) then
  print "a is 10"
elseif a ~= 20 then
  print "a is NOT 20"
else
  print "in the else"
end

--conditional check for multiple variables
a = 10
b = 20
if (a == 10 and  b == 20) then
  print("a is 10 && b == 10")
else 
  print("a is NOT 10 && b NOT 10")
end
if (a == 10 or  b == 20) then
  print("a is 10 or b == 10")
else 
  print("a is NOT 10 && b NOT 10")
end

-- loops time
print("printing 0 to 3")
for i = 0, 3, 1 do 
   print(i) 
end
print("printing 3 to 0")
for i = 3, 0, -1 
do
  print (i)
end


