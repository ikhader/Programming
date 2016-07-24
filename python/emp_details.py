
from utils.util import logger
from database.csqlite import EmpDetails
from datetime import datetime, timedelta
import datetime


class Employe_details:

  def __init__(self, log):
    self.log = log
    self.log.log("employedetails:  init")
    self.__emp_dets = EmpDetails(log)
   

  def add_emp_details(self):
    d = {}
    cnt = 1
    while (cnt < 5):
      y = datetime.date.fromordinal(datetime.date.today().toordinal()-cnt).strftime("%F")
      d[y] = cnt * 10;
      cnt = cnt + 1
    st = {
          1: {"name" : "name_1", "password" : "name_1", "phone" : "4697735274", "mail" : "name_1@name_1.com", "Vendor" : "v1@v1.com", "sec_q1" : "degree passout", "sec_q1_a" : "2003", "sec_q2" : "school name", "sec_q2_a" : "abcd"},
          2: {"name" : "name_2", "password":"name_2", "phone" : "4697735273", "mail" : "name_2@name_2.com", "Vendor": "v2@v2.com", "sec_q1" :"degree passout", "sec_q1_a" : "2003", "sec_q2" : "school name", "sec_q2_a" : "abcd"},
          3: {"name" : "name_3", "password":"name_3", "phone" : "4697735272", "mail" : "name_3@name_3.com", "Vendor": "v3@v3.com", "sec_q1" :"degree passout", "sec_q1_a" : "2003", "sec_q2" : "school name", "sec_q2_a" : "abcd"}
       }
    for k, s in st.iteritems():
      s['emp_id'] = self.__emp_dets.add_emp_record(s['name'], s['password'], s['phone'], s['mail'], s['Vendor'], s['sec_q1'], s['sec_q1_a'], s['sec_q2'], s['sec_q2_a'])
      self.__emp_dets.add_work_hours(s['emp_id'], s['password'], d) 


l = logger()
e = Employe_details(l)
e.add_emp_details()   
