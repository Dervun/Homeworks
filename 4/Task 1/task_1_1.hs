module Factorial (factorial) where

factorial :: Integer -> Integer
factorial n | n == 0    = 1
            | n > 0     = n * factorial (n - 1)
            | otherwise = error "expected positive argument"
