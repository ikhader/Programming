#
#In a nested funcs using local varaibles of topmost func in inner funcs
#
# Common things in closure & decorators:
#  @ both have nested functions
#  @ both retunrs inner most functions
#
#decorators takes a function (as a funciton argument) and add soem "decoration" then return it
# decorating functions/outermost function, accecpts function pointer(first class function) as an argument
# This first class function will be used in inner functions and invoked from this inner function
#But in closures, both innner & outer functinos will have same argument list(strings as example)
# Then this inner function will use that outermost func arguments(strings as example)

def print_msg(m):
  def log():
    print ("Accessing variable 'print_msg' Hello world: {}", m)
  return log()

print_msg("test message - 1")

def print_msg_1(m):
  hello = "go to hell!!!"
  def log():
    print ("variable 'print_msg_1': {} {}", m, hello)
  return log # this is changed from the upper on

t = print_msg_1("test message - 2")
t()
~
~
