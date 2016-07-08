
--function to pring message
function print_msg(m)
  print (m)
end

--function pointers
pm = function (msg)
  print(msg)
end
function add (a, b, msg)
  msg("call back function")
  return a + b
end

print_msg("Hello world!!!")
print_msg(add(10, 20, pm))
