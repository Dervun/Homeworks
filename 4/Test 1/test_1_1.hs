infList = 1 : (-1) : infList

result = zipWith (*) [1..] infList

{-
  Описать бесконечный список из чисел [1, -1, 1, -1, 1, -1, 1, -1, …]. 
  С помощью него реализовать функцию, выдающую бесконечный список: [1, -2, 3, -4, 5, -6, …].
-}