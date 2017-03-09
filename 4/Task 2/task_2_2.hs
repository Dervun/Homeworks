module Two (twoPow) where

twoPow :: Integer -> [Integer]
twoPow n | n < 1      = error "expected argument >= 1"
         | otherwise  = map (2^) [1..n]
