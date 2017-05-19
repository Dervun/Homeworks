module FindFirstMax (firstMax) where

import Control.Monad

firstMax :: [Int] -> Maybe Int
firstMax (x:y:z:list) = mplus (if (y > x && y > z) then Just y else mzero) (firstMax (y:z:list))
firstMax _            = mzero

{-
  Используя монадичесие функции, опишите фунцию, которая ищет в списке первый элемент, 
  больший своих соседей (предыдущего и следующего).

  Пример:
  *FindFirstMax> firstMax [1,2,3,4,1,33,5,6]
  
  Just 4
-}
