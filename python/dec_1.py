
#decorators takes a function (as a funciton argument) and add soem "decoration" then return it

def make_pretty(func):
  def inner():
    print("I am  decorated in 'inner'")
    func()
  return inner

def ordinary():
  print("I am ordinary")

f = make_pretty(ordinary)
f()
