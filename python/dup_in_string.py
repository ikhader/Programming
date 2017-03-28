
#
# 1. we will split each word on white space.
# 2. if word does not exist
#      add to hash
#      append to string
# 3. return string

def get_strings_space_sep(s):
  return s.split(' ')

def remove_duplicates(s):
  print ("input: " + s)
  sub_strings = get_strings_space_sep(s)
  d = {}
  output = ""
  for strs in sub_strings:
    if not d.has_key(strs):
      d[strs] = 1
      output += strs
      output += " "

  print str(d.keys())
  print output


remove_duplicates("Hello World Hello World")
