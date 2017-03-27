module Main where

main = do
    doLoop []

instructions :: IO ()
instructions = do
    putStrLn "Enter one of the following digits:"
    putStrLn "0 - for exit"
    putStrLn "1 - for add value to sorted list"
    putStrLn "2 - for remove value from list"
    putStrLn "3 - for print list:"

doLoop :: [Integer] -> IO ()
doLoop list = do
    putStrLn (show list) --Удобно, чтобы не надо было каждый раз вручную выводить список.
    instructions
    command <- getLine
    case command of
        '0':_ -> return ()
        '1':_ -> do
            putStrLn "Enter your value for add:"
            value <- getLine
            doLoop (addToList list (read value :: Integer))
        '2':_ -> do
            putStrLn "Enter your value for remove:"
            value <- getLine
            doLoop (removeFromList list (read value :: Integer))
        '3':_ -> do
            putStrLn (show list)
            doLoop list
        _     -> doLoop list


addToList :: [Integer] -> Integer -> [Integer]
addToList [] value = [value]
addToList (x:xs) value | value <= x  = value:x:xs
                       | otherwise   = x:(addToList xs value)

removeFromList :: [Integer] -> Integer -> [Integer]
removeFromList [] value = []
removeFromList (x:xs) value | value < x   = x:xs
                            | value == x  = xs
                            | otherwise   = x:removeFromList xs value

{-
Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
0 - exit
1 - add value to sorted list
2 - remove value from list
3 - print list
Все операции должны сохранять сортированность. Начинаем с пустого списка.
-}
