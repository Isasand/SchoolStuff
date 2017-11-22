# -*- coding: utf-8 -*-
"""
Created on Thu Nov 16 10:49:10 2017

@author: Isa
"""

from functools import reduce

class Program(object):
    
    def __init__(self, name):
        self.students = []
        self._name = name
        
    def getTotalstudentsfee(self):
        return float(reduce(lambda x,y: x.fee+y.fee, self.students))
    
    def add_student(self, student):
        self.students.append(student)
        
    def getStudents(self):
        return reduce(lambda x,y: str(x)+str(y), self.students) 
    
    def getName(self):
        return self._name 
    
    def __str__(self):
        return "".join("Program[name="+self._name+"]")
    