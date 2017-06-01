module MultiplByBind (multipl) where

multipl :: Int -> [Int]
multipl n = [1..n] >>= \x -> map (x*) [1..n]

{-
  С помощью оператора >>= опишите функцию, которая для данного числа n 
  создает список из всех попарных произведений чисел от 1 до n.
  (Т.е. что-то такое: [1*1, 1*2, 1*3, …, 1*n, 2*1, 2*2, …, n*n] - всего n*n элементов).

  Пример:
  *MultiplByBind> multipl 3
  
  [1,2,3,2,4,6,3,6,9]
-}