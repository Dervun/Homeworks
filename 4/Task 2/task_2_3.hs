module Sum (sumOfDigits) where

sumOfDigits :: Integer -> Integer
sumOfDigits n = sumHelper 0 (abs n)
    where
        sumHelper :: Integer -> Integer -> Integer
        sumHelper s n | n == 0     = s
                      | otherwise  = sumHelper (s + mod n 10) (div n 10)
