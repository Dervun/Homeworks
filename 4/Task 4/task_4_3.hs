module TreeVisiting (toValues) where

data Tree a = Empty | Leaf a | Node (Tree a) a (Tree a)

instance Foldable Tree where
   foldr f z Empty = z
   foldr f z (Leaf x) = f x z
   foldr f z (Node l k r) = foldr f (f k (foldr f z r)) l

toValues :: (Foldable t) => t a -> [a]
toValues = foldr (:) []

{-
  По дереву получить список его значений при некотором обходе. Использование рекурсии не допускается.
  
  Пример работы:
  *TreeVisiting> toValues $ Node (Node (Leaf (-5)) (-3) (Leaf (-4))) 0 (Node Empty 3 (Leaf 5))

  [-5,-3,-4,0,3,5]
-}
