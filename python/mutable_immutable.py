
#string is an immutable object; meaning object cannot be changed after its creation
#Example: string is an immutable; check for address "a" after re-assignment

a = 'corey'
print a
print "address of a is: {}".format(id(a))

a = 'John'
print a
print "address of a is: {}".format(id(a))

#a[0] = 'j' #this will THOROUGH error-'str' object does not support item assignment

#mutable: list
l = [1, 2, 3, 4, 5]
print "{} list address: {}".format(l, id(l))

print("address will remanin unchanged after changes")
l[0] = 6
print "{} list address: {}".format(l, id(l))
