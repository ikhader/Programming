--require 'middleclass.init'
DummyClass = {}
--DummyClass = class('DummyClass')
DummyClass._test = 10

function DummyClass:initialize(m)
  self.msg = m
  print("constructor" .. self.msg)
end

function DummyClass:print_msg(msg)
  print(msg)
end

return DummyClass


