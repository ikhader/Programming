
#from abc import ABCMeta, abstractmethod
import abc

class Animal:
  __metaclass__ = abc.ABCMeta

  @abc.abstractmethod
  def saysomething(self, t): 
    raise NotImplementedError("Subclass must implement abstract method")


class Cat(Animal):
  def saysomething(self):
    self.name = "changed"
    return "miauuuuu!!!"

  def __init__(self, name):
    self.name = name
    self.__name = name
    print "Cat--constructor", self.name

  def __del__(self):
    print "Cat--desstructor public var:", self.name, "priv var: ", self.__name

a = Cat("tom")
print a.saysomething()

print "out of class name: ", a.name

a = "hello"
print a
