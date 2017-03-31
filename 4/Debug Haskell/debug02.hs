module FindMaxNeighbors (findMax) where
import Debug.Trace

findMax :: [Int] -> Integer
findMax string = findHelper string 1 minBound (-1)
    where
        findHelper :: [Int] -> Integer -> Int -> Integer -> Integer
        findHelper (hd:tl) currentPos currentMax result 
            | trace ("findHelper: hd = " ++ show hd ++ ", lt = " ++ show tl ++ 
                     ", currPos: " ++ show currentPos ++ ", currMax: " ++ show currentMax ++ 
                     ", currResult: " ++ show result) False = undefined
            | tl == []                   = result
            | hd + head tl > currentMax  = findHelper tl (currentPos + 1) (hd + head tl) currentPos
            | otherwise                  = findHelper tl (currentPos + 1) currentMax result

{-
  Вывести первую позицию в списке, на которой сумма двух соседних элементов максимальна.
  Например, для [1, 5, 6, 2] функция должно вернуть значение 2.
-}
