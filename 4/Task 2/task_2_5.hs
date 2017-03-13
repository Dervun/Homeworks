module Sum (summ) where
import Data.List

summ :: Num b => [b] -> [b] -> [b] -> [b]
summ x y z = map sum $ transpose [x, y, z]
