#! /usr/bin/python

'''
TODO:
change default value of employee (primary key) to 1001

secret questions:
1. year of degree passout
2. place of birth
3. first school name
4. fav resturant
5. fav color
'''

import sqlite3 as lite
import sys

class EmpDetails:
  #default varaibles
  default_table_name = "employee_info"
  default_database_name = "employe.db"
  default_emp_start = 1001
  default_table_vals = "(employee_id INTEGER PRIMARY KEY AUTOINCREMENT, emp_name TEXT, emp_password TEXT, emp_phonenum TEXT, emp_mailid TEXT, vendor_mailid TEXT, secret_q1 TEXT, q1_ans TEXT, secret_q2 TEXT, q2_ans TEXT)"

  '''
    initialize all details
  '''
  def __init__ (self, t_name = default_table_name, f_name = default_database_name):
    self.__table_name = t_name
    self.__file_name = f_name
    self.__file_name = f_name
    print "db name", self.__table_name
    print "file name", self.__file_name
    self.create_database()

  '''
    create tables if not found; set all the required feilds
  '''
  def create_database(self):
    query = "create table if not exists " + self.__table_name + " " + self.default_table_vals
    conn = None

    try:
      conn = lite.connect(self.__file_name)
      conn.execute(query)
      conn.commit()
      #query = "ALTER TABLE " +  self.__table_name + " AUTOINCREMENT=1001"
      #print query
      #conn.execute(query)
      #conn.commit()
    except lite.Error, e:
      print "Error %s:" % e.args[0]
      sys.exit(1)
    finally:
      if conn:
        print "closing database"
        conn.close()

  '''
    add record with all details; no validation is done here
  '''
  def add_record(self, userid, passwd, phone_number, mailid, ven_mailid, q1, q1_ans, q2, q2_ans):
    con = None
    qur = "INSERT INTO " + self.__table_name + " VALUES(null, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')" 
    query = qur %(userid, passwd, phone_number, mailid, ven_mailid, q1, q1_ans, q2, q2_ans)
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)

  '''
    validates employe number & password returns bool
  '''
  def validate_credentials(self, emp_num, passwd):
    qur = "select * FROM " + self.__table_name + " where employee_id = %s"
    query = qur %(emp_num) 
    con = None
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)
      rows = cur.fetchall()
      if len(rows) > 1 :
        print "NEVER SEE THIS MESSAGE: more than one employee with same employee number"
        return False
      for row in rows:
        if row[2] == passwd:
          return True
    return False

  
  '''
    validate employe number & secret questions and answers
    5, 7 questions
    6, 8 answers
  '''
  def validate_secretquestion(self, emp_num, q, ans):
    qur = "select * FROM " + self.__table_name + " where employee_id = %s"
    query = qur %(emp_num) 
    con = None
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)
      rows = cur.fetchall()
      if len(rows) > 1 :
        print "NEVER SEE THIS MESSAGE: more than one employee with same employee number"
        return False
      for row in rows:
        if row[6] == q and row[7] == ans:
          return True
        elif row[8] == q and row[9] == ans:
          return True
    return False

  '''
    main to test basic functionality
  '''
def main():
  st = (
          ("name_1", "name_1", "4697735274", "name_1@name_1.com", "v1@v1.com", "degree passout", "2003", "school name", "abcd"),
          ("name_2", "name_2", "4697735271", "name_2@name_2.com", "v2@v2.com", "degree passout", "2013", "school name", "wyzz"),
          ("name_3", "name_3", "4697735272", "name_3@name_3.com", "v3@v3.com", "degree passout", "2123", "fav resturnt", "KFC")
       )

  sq = EmpDetails()
  sq.add_record("a", "b", "123", "a@b.com", "va@va.com", "place of birth", "pilery", "fav resturnt", "KFC")
  for s in st:
    sq.add_record(s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7], s[8])

  if(sq.validate_credentials("1", "b")):
    print("VALID USERID & PASSWORD")
  else: 
    print("INVALID USERID & PASSWORD")

  if(sq.validate_credentials("20000", "name_2")):
    print("VALID USERID & PASSWORD")
  else:
    print("INVALID USERID & PASSWORD")

  if(sq.validate_secretquestion("1", "place of birth", "piler")):
    print("VALID question & answers")
  else:
    print("INVALID question & answers")
   
  if(sq.validate_secretquestion("1", "place of birth", "pilery")):
    print("VALID question & answers")
  else:
    print("INVALID question & answers")

if __name__ == "__main__":
  main()

