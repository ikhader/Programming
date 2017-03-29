

#decorators takes a function (as a funciton argument) and add soem "decoration" then return it
# decorating functions/outermost function, accecpts function pointer(first class function) as an argument
# This first class function will be used in inner functions and invoked from this inner function
#But in closures, both innner & outer functinos will have same argument list(strings as example)
# Then this inner function will use that outermost func arguments(strings as example)

# Common things in closure & decorators:
#  @ both have nested functions
#  @ both retunrs inner most functions


def make_pretty(func):
  def inner():
    print("I am  decorated in 'inner'")
    func()
  return inner

def ordinary():
  print("I am ordinary")

f = make_pretty(ordinary)
f()

