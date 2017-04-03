module Brackets (check, check') where

check :: [Char] -> [Char]
check string | check' string  = "Correct"
             | otherwise      = "Incorrect"

check' :: [Char] -> Bool
check' string = helper string []
    where
        helper [] stack | stack == []  = True
                        | otherwise    = False
        helper (headOfString:tailOfString) stack
            | isOpenBr headOfString                  = helper tailOfString (headOfString:stack)
            | isCloseBr headOfString && stack == []  = False
            | isCloseBr headOfString                 = if equalBr (head stack) headOfString
                                                           then helper tailOfString (tail stack)
                                                           else False
            | otherwise                              = helper tailOfString stack

isOpenBr '(' = True
isOpenBr '[' = True
isOpenBr '{' = True
isOpenBr _   = False

isCloseBr ')' = True
isCloseBr ']' = True
isCloseBr '}' = True
isCloseBr _ = False

equalBr '(' ')' = True
equalBr '[' ']' = True
equalBr '{' '}' = True
equalBr _   _   = False
