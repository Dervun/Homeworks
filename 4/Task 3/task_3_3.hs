module FindMaxNeighbors (findMax) where

findMax :: [Int] -> Integer
findMax string = findHelper string 1 minBound (-1)
    where
        findHelper :: [Int] -> Integer -> Int -> Integer -> Integer
        findHelper (hd:tl) currentPos currentMax result 
            | tl == []                   = result
            | hd + head tl > currentMax  = findHelper tl (currentPos + 1) (hd + head tl) currentPos
            | otherwise                  = findHelper tl (currentPos + 1) currentMax result
