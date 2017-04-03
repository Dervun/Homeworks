module EvenDigits (countOfEven1, countOfEven2, countOfEven3) where
import Foreign.Marshal.Utils

countOfEven1 :: [Integer] -> Integer
countOfEven1 = sum . map (fromBool . even)

countOfEven2 :: [Integer] -> Int
countOfEven2 = length . filter even

countOfEven3 :: [Integer] -> Integer
countOfEven3 = foldr (\x y -> if even x then y + 1 else y) 0
