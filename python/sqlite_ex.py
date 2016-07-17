#! /usr/bin/python

import sqlite3 as lite
import sys

con = None

print ("sqlite3 examples", con)

con = lite.connect("test.db")
cars = (
           (4, "maruthi", 111),
           (5, "Tata", 222),
           (6, "Honda", 333)
       )

with con:
  cur = con.cursor()
  cur.execute("DROP TABLE IF EXISTS Cars")
  cur.execute("CREATE TABLE Cars(Id INT, Name TEXT, Price INT)")
  cur.execute("INSERT INTO Cars VALUES(1,'Audi',52642)")
  cur.execute("INSERT INTO Cars VALUES(9,'Audi',52555)")
  cur.execute("INSERT INTO Cars VALUES(2,'Mercedes',57127)")
  cur.execute("INSERT INTO Cars VALUES(3,'Skoda',9000)")
  cur.executemany("INSERT INTO Cars VALUES(?, ?, ?)", cars)

  cur.execute("SELECT * FROM Cars")
  rows = cur.fetchall()
  for row in rows:
    print row

  print("delete prices less than 1000")
  cur.execute("DELETE FROM Cars WHERE Price < 1000")
  cur.execute("SELECT * FROM Cars")
  rows = cur.fetchall()
  for row in rows:
    print row

  print("print all 'Audi' cars")
  ca = "Audi"
  cur.execute("SELECT * FROM Cars WHERE Name = 'Audi'")
  rows = cur.fetchall()
  for row in rows:
    print row


  print("print all 'Skoda' cars")
  ca = "Skoda"
  cur.execute("SELECT * FROM Cars WHERE Name = '%s'" % ca)
  rows = cur.fetchall()
  for row in rows:
    print row

  #cur.execute('SELECT SQLITE_VERSION()')
  #data = cur.fetchone()
  #print "SQLite version: %s" % data                

''' #this also works
try: 
  con = lite.connect("test.db")

  cur = con.cursor()
  cur.execute('SELECT SQLITE_VERSION()')
  data = cur.fetchone()
  print "SQLite version: %s" % data                
    
except lite.Error, e:
    print "Error %s:" % e.args[0]
    sys.exit(1)
    
finally:
  if con:
    print "closing connetion"
    con.close()
'''
