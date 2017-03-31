module Sum (sumOfDigits) where
import Debug.Trace

sumOfDigits :: Integer -> Integer
sumOfDigits n = sumHelper 0 (abs n)
    where
        sumHelper :: Integer -> Integer -> Integer
        sumHelper s n | trace ("sumHelper: s = " ++ show s ++ 
                           ", n = " ++ show n) False = undefined
                      | n == 0     = s
                      | otherwise  = sumHelper (s + mod n 10) (div n 10)

-- Реализовать функцию, которая вычисляет сумму цифр данного числа
