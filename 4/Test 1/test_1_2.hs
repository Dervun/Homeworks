matrix :: Int -> [[Int]]
matrix n = helper [1..n] n 0
    where
        helper :: [Int] -> Int -> Int -> [[Int]]
        helper list n i | i == n - 1  = [incr list i]
                        | otherwise   = (incr list i) : helper (incr list i) n (i + 1)

incr list 0 = list
incr list n = (head list + 1) : incr (tail list) (n - 1)

{-
  Пусть матрица — списков из списков. 
  Описать функцию, которая для данного n возвращает такой список для матрицы n на n,
  содержащий числа от 1 до n, раcположенные "уголоком".

  Например, для n = 4 надо вернуть:
  [[1, 2, 3, 4],
  [2, 2, 3, 4],
  [3, 3, 3, 4]
  [4, 4, 4, 4]]
-}
