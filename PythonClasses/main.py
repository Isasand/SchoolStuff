
import unittest

from person import Person
from staff import Staff
from student import Student
from program import Program
from school import School 

class TestPerson(unittest.TestCase):
    def test_person_01_constructor( self ):
        p = Person("Mark", "Min Gata 1")
        self.assertEqual( str(p), "Person[name=Mark,address=Min Gata 1]" )

    def test_person_02_get_name( self ):
        p = Person("Mark", "Min Gata 1")
        self.assertEqual( p.getName(), "Mark" )

    def test_person_03_get_address( self ):
        p = Person("Mark", "Min Gata 1")
        self.assertEqual( p.getAddress(), "Min Gata 1" )

    def test_person_04_set_address( self ):
        p = Person("Mark", "Min Gata 1")
        p.setAddress( "Annan Gata 2" )
        self.assertEqual( p.getAddress(), "Annan Gata 2" )

class TestStudent(unittest.TestCase):
    def test_student_01_constructor( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        self.assertEqual( str(p), "Student[Person[name=Mark,address=Min Gata 1],program=IoT,year=17,fee=50000.00]" )

    def test_student_02_get_program( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        self.assertEqual( p.getProgram(), "IoT" )

    def test_student_03_set_program( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        p.setProgram( "3D Design" )
        self.assertEqual( p.getProgram(), "3D Design" )

    def test_student_04_get_year( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        self.assertEqual( p.getYear(), 17 )

    def test_student_05_set_year( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        p.setYear(16)
        self.assertEqual( p.getYear(), 16 )

    def test_student_06_get_fee( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        self.assertEqual( p.getFee(), 50000 )

    def test_student_07_set_fee( self ):
        p = Student("Mark", "Min Gata 1", "IoT", 17, 50000)
        p.setFee( 125.66 )
        self.assertEqual( p.getFee(), 125.66 )

class TestStaff(unittest.TestCase):
    def test_staff_01_constructor( self ):
        p = Staff("Mark", "Min Gata 1", "Nackademin", 50)
        self.assertEqual( str(p), "Staff[Person[name=Mark,address=Min Gata 1],school=Nackademin,pay=50.00]" )

    def test_staff_02_get_school( self ):
        p = Staff("Mark", "Min Gata 1", "Nackademin", 50)
        self.assertEqual( p.getSchool(), "Nackademin" )

    def test_staff_03_set_school( self ):
        p = Staff("Mark", "Min Gata 1", "Nackademin", 50)
        p.setSchool( "Medieinstitutet" )
        self.assertEqual( p.getSchool(), "Medieinstitutet" )

    def test_staff_04_get_pay( self ):
        p = Staff("Mark", "Min Gata 1", "Nackademin", 50)
        self.assertEqual( p.getPay(), 50 )

    def test_staff_05_set_pay( self ):
        p = Staff("Mark", "Min Gata 1", "Nackademin", 50)
        p.setPay( 125.66 )
        self.assertEqual( p.getPay(), 125.66 )

class TestProgram(unittest.TestCase):
    def test_program_01_constructor( self ):
        p = Program("IoT")
        self.assertEqual( str(p), "Program[name=IoT]" )

    def test_program_02_get_name( self ):
        p = Program("IoT")
        self.assertEqual( p.getName(), "IoT" )

    def test_program_03_getstudent(self):
        p = Program("IoT")
        p.add_student(Student("Mark", "Min Gata 1", "IoT", 17, 50000))
        p.add_student(Student("Isa", "Min andra gata", "IoT", 17, 50000))
        self.assertEqual( p.getStudents(), "Student[Person[name=Mark,address=Min Gata 1],program=IoT,year=17,fee=50000.00]Student[Person[name=Isa,address=Min andra gata],program=IoT,year=17,fee=50000.00]" )
    
    def tets_program_04_getTotalfee(self):
        p = Program("IoT")
        p.add_student(Student("Mark", "Min Gata 1", "IoT", 17, 5200))
        p.add_student(Student("Isa", "Min andra gata", "IoT", 17, 4200))
        self.assertEqual( p.getTotalstudentsfee(), 9400)
                      
class TestSchool(unittest.TestCase):
    def test_school_01_constructor(self):
        s = School("Nackademin", "Tomtebodavägen 7B")
        self.assertEqual( str(s), "School[name=Nackademin,address=Tomtebodavägen 7B]" )
      
    def test_school_02_getStaff(self):
        s = School("Nackademin", "Tomtebodavägen 7B")
        s.add_staff(Staff("Mark", "Min Gata 1", "Nackademin", 50))
        s.add_staff(Staff("Isa", "Min andra gata", "Nackademin", 1000))
        self.assertEqual(s.get_staff(), "Staff[Person[name=Mark,address=Min Gata 1],school=Nackademin,pay=50.00]Staff[Person[name=Isa,address=Min andra gata],school=Nackademin,pay=1000.00]")
    
    def test_school_03_loss(self):
        p = Program("IoT")
        p.add_student(Student("Mark", "Min Gata 1", "IoT", 17, 50000))
        p.add_student(Student("Isa", "Min andra gata", "IoT", 17, 50000))
        s = School("Nackademin", "Tomtebodavägen 7B")
        s.add_program(p)
        s.add_staff(Staff("Mark", "Min Gata 1", "Nackademin", 50))
        s.add_staff(Staff("Isa", "Min andra gata", "Nackademin", 1000))
        self.assertEqual(s.gain_or_loss(),"loss: 98950.00")
        
    def test_school_04_gain(self):
        p = Program("IoT")
        p.add_student(Student("Mark", "Min Gata 1", "IoT", 17, 50))
        p.add_student(Student("Isa", "Min andra gata", "IoT", 17, 50))
        s = School("Nackademin", "Tomtebodavägen 7B")
        s.add_program(p)
        s.add_staff(Staff("Mark", "Min Gata 1", "Nackademin", 500))
        s.add_staff(Staff("Isa", "Min andra gata", "Nackademin", 1000))
        
        self.assertEqual(s.gain_or_loss(),"gain: 1400.00")
        
if __name__ == '__main__':
    unittest.main(verbosity=2)
