import unittest
from calculator_main import add
from calculator_main import multi
from calculator_main import power


class prog_test_class(unittest.TestCase):
    def test_add(self):
        self.assertEqual(add(0,0),0)
        self.assertEqual(add(1,0),1)
        self.assertEqual(add(0,1),1)
        self.assertEqual(add(1,1),2)
        self.assertEqual(add(2,3),5)
    def test_multi(self):
        self.assertEqual(multi(0,0),0)
        self.assertEqual(multi(1,0),0) 
        self.assertEqual(multi(0,1),0)
        self.assertEqual(multi(1,1),1)
        self.assertEqual(multi(2,3),6)
    def test_power(self):
        self.assertEqual(power(0,0),1)
        self.assertEqual(power(1,0),1)
        self.assertEqual(power(0,1),0)
        self.assertEqual(power(1,1),1)
        self.assertEqual(power(2,3),8)



if __name__ == '__main__':
    unittest.main()
