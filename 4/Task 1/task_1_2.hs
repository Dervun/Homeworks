module Fibonacci (fibonacci) where

fibonacci :: Integer -> Integer
fibonacci n | n == 0   = 0
            | n == 1   = 1
            | n > 1    = helper 0 1 n
            | n < 0    = (-1)^(1 - n) * fibonacci (-n)
    where
        helper :: Integer -> Integer -> Integer -> Integer
        helper previous current i | i == 1     = current
                                  | otherwise  = helper current (previous + current) (i - 1)
