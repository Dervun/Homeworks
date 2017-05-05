module Decomposition (decomposition) where

decomposition :: Int -> [[Int]]
decomposition n = helper n 1 where
    helper n k | n == 0     = [[]]
               | n < 0      = error "Expected positive argument"
               | otherwise  = concatMap (\x -> map (x:) (helper (n-x) x)) [k..n] 


{-
  Реализовать функцию, которая по заданному числу n выводит разложения его на положительные слагаемые 
  (с точностью до порядка разложения).

  Пример:
  *Decomposition> decomposition 5

  [[1,1,1,1,1],[1,1,1,2],[1,1,3],[1,2,2],[1,4],[2,3],[5]]
-}
