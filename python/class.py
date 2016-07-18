
#from abc import ABCMeta, abstractmethod
import abc

class Animal:
  __metaclass__ = abc.ABCMeta

  @abc.abstractmethod
  def saysomething(self, t): pass


class Cat(Animal):
  def saysomething(self):
    return "miauuuuu!!!"


a = Cat()
print a.saysomething()
