supermap :: [a] -> (a -> [b]) -> [b]
supermap list f = concat $ map f list

{-
  Описать функцию, которая работает как map, только для каждого значения исходного списка можно задать не одно, а несколько значений, на которые его надо заменить. 
  Пример вызова: supermap [1, 2, 3] (\x -> [sin x, cos x] должно возвращать [sin 1, cos 1, sin 2, cos 2, sin 3, cos 3].
-}
