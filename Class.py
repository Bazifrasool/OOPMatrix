# -*- coding: utf-8 -*-
"""
Created on Sat Aug 29 10:56:21 2020

@author: Bazif
"""
#addition
#subtraction
#multiplication
#dot_product
import numpy as np

class Matrix:
    
    def __init__(self,rows,cols,list_matr=None):
        self.matrix=np.zeros((rows,cols))
        self.shape=(rows,cols)
        if(list_matr!=None):
            self.fill_list(list_matr)
        print("Created Matrix of {},{}\n".format(rows,cols))
        
    def fill_list(self,list_matr):
        
        self.matrix = np.array(list_matr)
        self.shape = self.matrix.shape
        
    def fill_(self):
        for i,each in enumerate(self.matrix):
            for j,every in enumerate(each):
                self.matrix[i][j]=input("Enter the value")
                
    def print_(self):
        for i,each in enumerate(self.matrix):
            for j,every in enumerate(each):
                print("|",self.matrix[i][j],"|",end=" ")
            print("\n")
    
    def __add__(self,other):
        if(other.shape==self.shape):
            result = Matrix(self.shape[0], self.shape[1])
            for i,each in enumerate(self.matrix):
                result.matrix[i]=self.matrix[i]+other.matrix[i]
            return result
        
    def __sub__(self,other):
        if(other.shape==self.shape):
            result = Matrix(self.shape[0], self.shape[1])
            for i,each in enumerate(self.matrix):
                result.matrix[i]=self.matrix[i]-other.matrix[i]
            return result
        
    def multiply(self,b):
        result = Matrix(self.shape[0], b.shape[1])
        if(b.shape[0]==self.shape[1]):
            for i in range(0,self.shape[0]):
                for j in range(0,b.shape[1]):
                    sum_t = 0
                    for k in range(0,self.shape[1]):
                        sum_t+=self.matrix[i][k]*b.matrix[k][j]
                    result.matrix[i][j]=sum_t
            return result
                    
    
class Vector(Matrix):
    
    def __init__(self,dim,list_matr):
       Matrix.__init__(self,dim,1,list_matr)
    
    def dot_prod(self,b):
        resultant=self.matrix*b.matrix
        return(np.sum(resultant))
       
#matrixA = Matrix(3,3)
#matrixA.fill_()
#matrixA.print_()
list_vector=[[1],[10]]
vectorA = Vector(3,list_vector)
#vectorA.fill_list(list_vector)
#vectorA.print_()
#matrixB = matrixA+matrixA
#matrixB.print_()
#vectorB= vectorA+vectorA
#vectorB.print_()
#print(vectorA.dot_prod(vectorA))
a = [[2,2],[2,2]]
matrA = Matrix(2,2,a)
matrB = matrA.multiply(matrA)
matrB.print_()
vectorA.print_()
res = matrA.multiply(vectorA)
res.print_()