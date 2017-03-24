print "Hello World!\n"
class Employee:
  def __init__ (self, first, last):
    self.first = first
    self.last = last
    #self.email = first + '.' + last +'@email.com'
  
  #clousures
  @property
  def email(self):
    return "{}.{}@email.com".format(self.first, self.last)
  def fullname(self):
    return "{} {}".format(self.first, self.last)

e1 = Employee("John", "simith")
print e1.fullname()
#email was supposed to be a vairable but changed to method later..
#earlier usage of people used "email" as a varaible. Method to prefixed "property"will act as a varaible
print e1.email
