# -*- coding: utf-8 -*-
"""
Created on Thu Nov 16 10:05:19 2017

@author: Isa
"""
from person import Person

class Staff(Person):
    
    def __init__(self,name, address, school, pay):
        super().__init__(name, address)
        self.school= school
        self._pay = float(pay)
        
    def getSchool(self):
        return self.school 
    
    def setSchool(self, school):
        self.school = school
        
    def getPay(self):
        return self._pay
    
    def setPay(self, pay):
        self._pay = pay
        
    def __str__(self):
        
        return "".join("Staff[Person[name="+self._name+",address="+self._address+"],school="+self.school+",pay=%.2f" % round(self._pay)+"]")
                       
                      