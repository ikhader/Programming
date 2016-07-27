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
from datetime import datetime, timedelta
import datetime
import calendar 
import time

'''
  EmDetails stores employe details in database
  1. employee number (auto increment)
  2. employe name
  3. password
  4. phone number
  5. mailid
  6. secret question (1)
  7. scret q(1) answer
  8. secret question (2)
  9. scret q(2) answer
'''
class EmpDetails:
  #default varaibles
  default_table_name = "employee_info"
  default_database_name = "employe.db"
  default_emp_start = 1001
  default_table_vals = "(employee_id INTEGER PRIMARY KEY AUTOINCREMENT, emp_name TEXT, emp_password TEXT, emp_phonenum TEXT, emp_mailid TEXT, vendor_mailid TEXT, secret_q1 TEXT, q1_ans TEXT, secret_q2 TEXT, q2_ans TEXT)"

  '''
    initialize all details
  '''
  def __init__ (self, log, t_name = default_table_name, f_name = default_database_name):
    self.__table_name = t_name
    self.__file_name = f_name
    self.__file_name = f_name
    print "db name", self.__table_name
    print "file name", self.__file_name
    self.log = log
    self.__create_database()
    self.empdetails = EmpWorkHours(self.log)

  '''
    create tables if not found; set all the required feilds
  '''
  def __create_database(self):
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
  def add_emp_record(self, userid, passwd, phone_number, mailid, ven_mailid, q1, q1_ans, q2, q2_ans):
    con = None
    lid = -1
    qur = "INSERT INTO " + self.__table_name + " VALUES(null, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s')" 
    query = qur %(userid, passwd, phone_number, mailid, ven_mailid, q1, q1_ans, q2, q2_ans)
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)
      lid = cur.lastrowid

    self.empdetails.create_employe_entry(lid)
    return lid 

  def add_work_hours(self, userid, passwd, work_hours):
    if(not self.validate_credentials(userid, passwd) ):
      print "INVALID CREDENTIALS TO ADD WORK HOURS"
      return False;
    self.empdetails.add_work_hours(userid, work_hours)

  def get_total_work_hours(self, userid, passwd, month):
    if(not self.validate_credentials(userid, passwd) ):
      print "INVALID CREDENTIALS TO ADD WORK HOURS"
      return False;
    self.empdetails.get_total_work_hours(userid, month)

  '''
    validates employe number & password returns bool
  '''
  def validate_credentials(self, emp_name, passwd):
    qur = "select * FROM " + self.__table_name + " where employee_id = %s"
    query = qur %(emp_name) 
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
  TODO: Make this class accessible with in the file; 
'''
class EmpWorkHours:
  default_table_name = "employee_workhours"
  default_database_name = "employe.db"
  default_table_vals = "(employee_id INTEGER, billing_date DATE, billing_hours REAL )"

  '''
    initialize all details
  '''
  def __init__ (self, log, t_name = default_table_name, f_name = default_database_name):
    self.__table_name = t_name
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
    except lite.Error, e:
      print "Error %s:" % e.args[0]
      sys.exit(1)
    finally:
      if conn:
        print "closing database"
        conn.close()

  def create_employe_entry(self, emp_id):
    con = None
    qur = "INSERT INTO " + self.__table_name + " VALUES('%d', null, null)"
    query = qur %(emp_id)
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)
      con.commit()

  '''
    add record with all details; no validation is done here
  '''
  def add_work_hours(self, emp_num, date_hours):

    if len(date_hours) == 0:
      print "working hours cannot be 0"
      return False

    qur = "INSERT INTO " + self.__table_name + " VALUES('%d', '%s', '%s')"
    con = None
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      for k, v in date_hours.iteritems():
        query = qur %(emp_num, k, v)
        cur.execute(query)
        con.commit()

    return True

  '''
    gets total work hours of emp_num for month(1-12)
  def get_total_work_hours_of_month(self, emp_num, month):

    total_work_hours = 0
    #if type(month) is not int:
    #  print("anversion need to be done")
    #  return total_work_hours

    qur = "select * FROM  %s where Date(billing_date) between '2016-07-01' and  '2016-07-30' and employee_id = %s "
    query = qur %(self.__table_name, emp_num)
    print query
    #qur = "select * from employee_workhours where  Date(billing_date) between  '2016-07-01' and  '2016-07-30' and employee_id = 1"
    con = None
    con = lite.connect(self.__file_name)
    with con:
      cur = con.cursor()
      cur.execute(query)
      rows = cur.fetchall()
      for row in rows:
        print row

    self.get_total_work_hours(emp_num, month)
  '''  

  def get_total_work_hours(self, emp_num, month):
    qur = "select sum(billing_hours) FROM  %s where Date(billing_date) between '%s' and  '%s' and employee_id = %s "
    year = time.strftime("%Y")
    con = None
    con = lite.connect(self.__file_name)
    cur = con.cursor()

    for i in month:
      start_date = ("%s-%s-%s" %(year, str(i).zfill(2), "01"))
      end_date = ("%s-%s-%s" %(year, str(i), calendar.monthrange(int(year), i)[1]))
      query = qur % (self.__table_name, start_date, end_date, emp_num)
    with con:
      cur.execute(query)
      total_work_hours =  cur.fetchone()
      print "total work hours: %d" %total_work_hours
     

