module BinarySearchTree where

import System.Random

data BinarySearchTree a = Null | Node a (BinarySearchTree a) (BinarySearchTree a)

instance (Show a) => Show (BinarySearchTree a) where
    show Null = "_"
    show (Node x Null Null) = show x ++ " _ _"
    show (Node x Null r) = show x ++ " _ (" ++ show r ++ ")"
    show (Node x l Null) = show x ++ " (" ++ show l ++ ") _"
    show (Node x l r) = show x ++ " (" ++ show l ++ ") (" ++ show r ++ ")"

add x Null = Node x Null Null
add x (Node a l r) | x < a      = Node a (add x l) r
                   | x == a     = Node a l r
                   | otherwise  = Node a l (add x r)

remove _ Null = Null
remove x (Node a l r)
    | x < a      = Node a (remove x l) r
    | x > a      = Node a l (remove x r)
    | otherwise  = case (l, r) of 
        (Null, Null)                           -> Null
        (Null, Node _ _ _)                     -> r
        (Node _ _ _, Null)                     -> l
        (Node _ _ _, Node b Null r')           -> Node b l r'
        (Node _ _ _, Node _ rl@(Node _ _ _) _) -> Node mn l (remove mn r)
            where
                mn = minNode rl
                minNode (Node x Null _)  = x
                minNode (Node _ l' _)    = minNode l'

contains _ Null = False
contains x (Node a l r) | x == a     = True
                        | x < a      = contains x l
                        | otherwise  = contains x r

count Null         = 0
count (Node _ l r) = count l + 1 + count r

height Null         = 0
height (Node _ l r) = max (height l) (height r) + 1

randomRefresh :: BinarySearchTree Int -> BinarySearchTree Int
randomRefresh Null = Null
randomRefresh (Node x l r) = Node (fst $ randomR (-20, 20) (mkStdGen $ x * 7)) (randomRefresh l) (randomRefresh r) 

{-
  Реализовать тип данных BinarySearchTree и соответствующие функции для работы с ним:
  добавление, удаление, поиск, размер (число элементов), высота.
  Реализовать функцию, которая заменяет значение в каждом узле дерева на случайное целое число.

  Примеры:

  *BinarySearchTree> add 2 $ add 7 $ add 3 $ add 5 $ Null
  5 (3 (2 _ _) _) (7 _ _)
  
  *BinarySearchTree> remove 5 $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  7 (3 (2 _ _) _) _

  *BinarySearchTree> contains 4 $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  False
  *BinarySearchTree> contains 7 $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  True

  *BinarySearchTree> count $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  4

  *BinarySearchTree> height $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  3

  *BinarySearchTree> randomRefresh $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  10 (-3 (11 _ _) _) (-18 _ _)
  *BinarySearchTree> randomRefresh $ randomRefresh $ add 2 $ add 7 $ add 3 $ add 5 $ Null
  -19 (12 (8 _ _) _) (-7 _ _)
-}
