module Brackets (check, check') where

check :: [Char] -> [Char]
check string | check' string  = "Correct"
             | otherwise      = "Incorrect"

check' :: [Char] -> Bool
check' string = helper string 0 0 0
    where
        helper [] bal1 bal2 bal3 | bal1 == 0 && bal2 == 0 && bal3 == 0  = True
                                 | otherwise                            = False
        helper (headOfString:tailOfString) bal1 bal2 bal3
            | bal1 < 0 || bal2 < 0 || bal3 < 0  = False
            | headOfString == '('  = helper tailOfString (bal1 + 1) bal2 bal3
            | headOfString == ')'  = helper tailOfString (bal1 - 1) bal2 bal3
            | headOfString == '['  = helper tailOfString bal1 (bal2 + 1) bal3
            | headOfString == ']'  = helper tailOfString bal1 (bal2 - 1) bal3
            | headOfString == '{'  = helper tailOfString bal1 bal2 (bal3 + 1)
            | headOfString == '}'  = helper tailOfString bal1 bal2 (bal3 - 1)
            | otherwise            = helper tailOfString bal1 bal2 bal3
