module Searching (search) where

search :: [Integer] -> Integer -> Integer
search list value = searchHelper list value 1
    where
        searchHelper (headOfList:tailOfList) value n
            | headOfList == value  = n 
            | tailOfList == []     = -1
            | otherwise            = searchHelper tailOfList value (n + 1)
