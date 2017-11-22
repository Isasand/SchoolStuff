# -*- coding: utf-8 -*-
"""
Created on Thu Nov 16 10:05:47 2017

@author: Isa
"""
from person import Person

class Student(Person):
    def __init__(self, name, address, program, year, fee):
        super().__init__(name, address)
        self.program = program 
        self.year = year 
        self.fee = float(fee)
        
    def getProgram(self):
        return self.program
    
    def setProgram(self, program):
        self.program = program 
        
    def getYear(self):
        return self.year
    
    def setYear(self, year):
        self.year = year
        
    def getFee(self):
        return self.fee
    
    def setFee(self, fee):
        self.fee = fee
        
    def __str__(self):
        return "".join("Student[Person[name="+self._name+",address="+self._address+"],program="+self.program + ",year=" +str(self.year)+ ",fee=%.2f" % round(self.fee)+"]")
