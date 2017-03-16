module Homework (list) where

list :: [Integer]
list = 1 : 7 : 9 : (concatMap (\x -> [x + 1, x + 7, x + 9]) (map (*10) list))
