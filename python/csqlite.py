#! /usr/bin/python

import sqlite3 as lite
import sys

class Sqlite:
  #default varaibles
  default_table_name = "employee_info"
  default_database_name = "employe.db"
  #default_table_vals = "(Id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Password TEXT, Phonenum INT, Mailid TEXT)"
  default_table_vals = "(Name TEXT)"

  def __init__ (self, t_name = default_table_name, f_name = default_database_name):
    self.__table_name = t_name
    self.__file_name = f_name
    self.__file_name = f_name
    print "db name", self.__table_name
    print "file name", self.__file_name
    self.create_database()

  def create_database(self):
    query = "create table if not exists " + self.__table_name + " " + self.default_table_vals
    conn = None
    try:
      conn = lite.connect(self.__file_name)
      conn.execute(query)
      conn.commit()
    except lite.Error, e:
      print "Error %s:" % e.args[0]
      sys.exit(1)
    finally:
      if conn:
        print "closing database"
        conn.close()

  def add_record(self, userid, passwd, phone_number, mailid):
    con = None
    #qur = "INSERT INTO " + self.__table_name + " VALUES( '%s', '%s', '%d', '%s' )" 
    qur = "INSERT INTO " + self.__table_name + " VALUES('%s')" 
    print qur
    u = "userid"
    p = "password"
    query = qur % userid  #% phone_number % mailid 
    print query
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)
      data = cur.fetchone()
      print "SQLITE version: %s" % data
  

def main():
  st = (
          ("name_1", "name_1", 4697735274, "name_1@name_1.com"),
          ("name_2", "name_2", 4697735271, "name_2@name_2.com"),
          ("name_3", "name_3", 4697735272, "name_3@name_3.com")
       )
  sq = Sqlite()
  sq.add_record("a", "b", "123", "a@b.com")
  for s in st:
    sq.add_record(s[0], s[1], s[2], s[3])

if __name__ == "__main__":
  main()

