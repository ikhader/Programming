#
# in this file we do:
# base class + derived class implementaions
# from derived calss invocation of base class constructor & destructors
# in derived class we have both pubilc & private varaibles
# mutable/immutable: static varaibles in a derived class
# mutable varaibles are like static variables. Values exist across different instaces of a class
#


#from abc import ABCMeta, abstractmethod
import abc

class Animal:
  __metaclass__ = abc.ABCMeta

  @abc.abstractmethod
  def saysomething(self, t):
    raise NotImplementedError("Subclass must implement abstract method")

  @abc.abstractmethod
  def legs(self, t):
    raise NotImplementedError("Subclass must implement abstract method")

  def __init__(self):
    print "Basecalss-Animal--constructor"

  def __del__(self):
    print "BaseCalss Animal--destructor"

class Cat(Animal):

  #class variable, shared by all instances
  #strings are mutable-if we change in one instance, this will not reflect in others
  #in short untill the instance varaibel dont tweek this 'sound' all instance will have same value
  sound = "miauuuuu!!!"
  #immutable-must have same value across instances
  eyes = [1, 2, 4, 6]

  def saysomething(self):
    return self.sound

  def __init__(self, name):
    Animal.__init__(self) #before we start intialize base class constructor
    self.name = name   #public vairable, can be changed with instance of a class
    self.__name = name #private varaible; cannot be accessed by non-member func, __ (double underscore)
    print "Cat--constructor", self.name

  def __del__(self):
    print "Cat--desstructor public var:", self.name, "priv var: ", self.__name
    Animal.__del__(self)#invoke base calss destructor

  def legs(self):
    print("legs are 4")

  def print_sound(self):
    print("Sound is: {} address is: {}".format(self.sound, id(self.sound)))

  def print_eyes(self):
    print("eyes are: {} address is: {}".format(self.eyes, id(self.eyes)))

  def change_sound(self):
    self.sound = "Bow!!!!!"

a = Cat("tom")
print a.saysomething()
a.legs()

b = Cat("tom")
print b.saysomething()

print
print
print("checking immutable strings")
a.print_sound()
b.print_sound()

b.change_sound()

print("after changing shared varaible")
a.print_sound()
b.print_sound()

print
print
print("checking for immutable list: eyes")
a.print_eyes()
b.print_eyes()
print("After changing in one instance")

b.eyes[0] = 22

a.print_eyes()
b.print_eyes()

print("End of class")

