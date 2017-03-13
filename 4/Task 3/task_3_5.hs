module Fibonacci (fibonacci) where

fibonacci :: Integer -> Integer
fibonacci n | n == 0   = 0
            | n == 1   = 1
            | n > 1    = for 0 1 n
            | otherwise    = (-1)^(1 - n) * fibonacci (-n)
    where
        for previous current i | i == 1     = current
                                  | otherwise  = for current (previous + current) (i - 1)
