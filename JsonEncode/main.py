import unittest
from myjson import json_master

class TestJsonEncode(unittest.TestCase):
    def test01_boolean_true( self ):
        self.assertEqual( json_master( True ), "true" )

    def test02_boolean_false( self ):
        self.assertEqual( json_master( False ), "false" )

    def test03_int( self ):
        self.assertEqual( json_master( 1 ), "1" )

    def test04_float( self ):
        self.assertEqual( json_master( 3.14159 ), "3.14159" )
        self.assertEqual( json_master( 1.0/3.0 ), "0.3333333333333333" )

    def test05_string( self ):
        self.assertEqual( json_master( "Hello World" ), '"Hello World"' )
        self.assertEqual( json_master( "Buy\nmore\npizza" ), '"Buy\\nmore\\npizza"' )
        self.assertEqual( json_master( "Mark's test" ), '"Mark\'s test"' )

    def test06_simple_list( self ):
        self.assertEqual( json_master(  [True,False] ), "[true,false]" )

    def test07_mixed_list( self ):
        self.assertEqual( json_master(  [False,3,3.14159,"Pi"] ), "[false,3,3.14159,\"Pi\"]" )

    def test08_simple_dict( self ):
        self.assertEqual( json_master(  {"hello":"world"} ), '{"hello":"world"}' )

    def test09_mixed_dict( self ):
        self.assertEqual( json_master(  {"name":"Mark", "age":12, "teacher":True} ), '{"name":"Mark","age":12,"teacher":true}' )

    def test10_complex_data( self ):
        complex_data = {
            "name": "Advanced Python Training",
            "date": "October 13, 2012",
            "completed": False,
            "instructor": {
                "name": "Anand Chitipothu",
                "website": "http://anandology.com/"
            },
            "participants": [
                {
                    "name": "Participant 1",
                    "email": "email1@example.com"
                },
                {
                    "name": "Participant 2",
                    "email": "email2@example.com"
                }
            ]
        }
        self.assertEqual( json_master( complex_data ),
                          '{"name":"Advanced Python Training","date":"October 13, 2012","completed":false,"instructor":{"name":"Anand Chitipothu","website":"http://anandology.com/"},"participants":[{"name":"Participant 1","email":"email1@example.com"},{"name":"Participant 2","email":"email2@example.com"}]}' )

    def test11_new_test(self):
        test = {"name": "true",
                "lastname": "True"}
        self.assertEqual(json_master(test), '{"name":"true","lastname":"True"}')

if __name__ == '__main__':
    unittest.main(verbosity=2)

