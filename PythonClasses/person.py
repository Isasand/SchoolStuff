# -*- coding: utf-8 -*-
"""
Created on Thu Nov 16 09:59:26 2017

@author: Isa
"""

class Person(object):
    
    def __init__(self, name, address):
        self._name = name 
        self._address = address
    
    def getName(self):
        return self._name

    def getAddress(self):
        return self._address
    
    def setAddress(self, address):
        self._address = address
        
    def __str__(self):
        return str("Person[name=" + self._name+ ",address="+ self._address+"]")
    