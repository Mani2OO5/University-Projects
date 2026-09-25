import unittest
from MainProg import is_word
from MainProg import Sort

class StringCheck(unittest.TestCase):
    def test_isword(self):
        self.assertEqual(is_word(""), 0)
        self.assertEqual(is_word("Hello"), 1)
        self.assertEqual(is_word("Whats up?"), 2)
        self.assertEqual(is_word("this is a good program"), 5)

    def test_Sort(self):
        self.assertEqual(Sort(""), [])
        self.assertEqual(Sort("Hello"), ["Hello"])
        self.assertEqual(Sort("whats up?"), ["up?", "whats"])
        self.assertEqual(
            Sort("this is a good program"), ["a", "good", "is", "program", "this"]
        )


if __name__ == "__main__":
    unittest.main()
