module Two (twoPow) where

twoPow :: Integer -> [Integer]
twoPow n | n < 1      = error "expected argument >= 1"
         | otherwise  = for [] 2 n
    where
        for :: [Integer] -> Integer -> Integer -> [Integer]
        for currentList currentValue i | i == 0     = currentList
                                       | otherwise  = for (currentList ++ [currentValue]) (currentValue * 2) (i - 1)
