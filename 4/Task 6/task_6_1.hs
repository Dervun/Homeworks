module Polynom where
import Data.List
import Control.Monad


data Polynom = Polynom [Integer]

infixl 6 .+.
(.+.) :: Polynom -> Polynom -> Polynom
Polynom p1 .+. Polynom p2 = Polynom $ zipWith (+) (extend p1 maxLen) (extend p2 maxLen)
    where
        maxLen = max (length p1) (length p2)
        extend p maxLen | length p >= maxLen  = p
                        | otherwise           = replicate (maxLen - (length p)) 0 ++ p

infixl 7 .*.
(.*.) :: Polynom -> Polynom -> Polynom
Polynom p1 .*. Polynom p2 = Polynom $ map snd $ simplify $ getAllSummands p1 p2
    where
        getAllSummands :: [Integer] -> [Integer] -> [(Integer, Integer)]
        getAllSummands p1 p2 = liftM2 (\(i1, a1) (i2, a2) -> (i1 + i2, a1 * a2)) 
                                      (zip [0..] p1) (zip [0..] p2)
        simplify :: [(Integer, Integer)] -> [(Integer, Integer)]
        simplify [] = []
        simplify (x:list) = (fst x, (snd x + counter (fst x) list 0))
            : (simplify $ filter ((/= fst x).fst) list)
            where
                counter x [] n = n
                counter x (hd:list) n | fst hd == x  = counter x list (n + snd hd)
                                      | otherwise    = counter x list n

{-
  Функция getAllSummands возвращает список пар, в котором первое значение - идентификатор, 
  соответствующий некоторой степени, второе - коэффициент при этой степени.
  То есть функция перемножает каждый элемент из первого многочлена с каждым элементом из второго
  и возвращает все полученные слагаемые в списке.

  Функция simplify занимается тем, что объединяет подобные слагаемые, то есть 
  если в выражении был список [x^2, -3x, x, 1], то получится [x^2, -2x, 1].
-}

instance Show Polynom where
    show (Polynom p) = concat $ intersperse " + " (getExpressionList p)

getExpressionList :: [Integer] -> [[Char]]
getExpressionList p = filter (/= "#") $ helper (reverse [0 .. length p - 1]) p
    where
        helper exponents p = map convert $ zip exponents p
        convert (_, 0) = "#"
        convert (0, a) = show a
        convert (i, a) = coeff a ++ power i
            where
                coeff 1 = ""
                coeff a = show a
                power 1 = "x"
                power i = "x^" ++ show i

{-
  Описать тип, позволяющий хранить информацию о многочленах с одной переменной, 
  и реализовать для него сложение, умножение и show.

  Примеры:
  *Polynom> show $ Polynom [7,0,2,3,-2,-1] .+. Polynom [-1,1,2,2]
  "7x^5 + x^3 + 4x^2 + 1"

  *Polynom> show $ Polynom [1,2,3] .*. Polynom [4,3,2,1] 
  "4x^5 + 11x^4 + 20x^3 + 14x^2 + 8x + 3"

  *Polynom> show $ Polynom [2,3,0,7]
  "2x^3 + 3x^2 + 7"
-}
