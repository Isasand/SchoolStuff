# -*- coding: utf-8 -*-
"""
Created on Thu Nov 16 10:54:23 2017

@author: Isa
"""
from functools import reduce

class School(object):
    
    def __init__(self, name, address):
        self._name= name
        self._address = address
        self.staff = []
        self.programs = []

    def getName(self):
        return self._name
    
    def gtAddress(self):
        return self.__address
    
    def add_program(self, program):
        self.programs.append(program)
    
    def add_staff(self, staff):
        self.staff.append(staff)
        
    def get_staff(self):
        return reduce(lambda x,y: str(x)+str(y), self.staff) 
    
    def get_totalpay(self):
        return reduce(lambda x,y: x.getPay()+y.getPay(), self.staff)
        
    def gain_or_loss(self):
        studentsfee = 0
        for program in self.programs:
            studentsfee += program.getTotalstudentsfee()
        
        if self.get_totalpay() > studentsfee:
            return "gain: %.2f" % round(self.get_totalpay() - studentsfee)
        else:
            return "loss: %.2f" % round(studentsfee - self.get_totalpay())
        
    def __str__(self):  
        return str("School[name=" + self._name+ ",address="+ self._address+"]")
    