module PhoneBook (launchPhoneBook) where

import System.IO
import Control.Exception

launchPhoneBook :: IO ()
launchPhoneBook = do 
    hSetBuffering stdin LineBuffering
    doLoop []

doLoop :: [(String, Integer)] -> IO ()
doLoop currentList = do
    instructions
    command <- getLine
    case command of
        '0':_ -> return ()
        '1':_ -> do
            putStrLn "Enter name:"
            name <- getLine
            putStrLn "Enter phone number:"
            phone <- getLine
            doLoop ((name, (read phone :: Integer)) : currentList)
        '2':_ -> do
            putStrLn "Enter name:"
            name <- getLine
            putStrLn $ "Phone of " ++ name ++ " - " ++ (findPhone currentList name)
            doLoop currentList
        '3':_ -> do
            putStrLn "Enter phone"
            phone <- getLine
            putStrLn $ "Name for " ++ phone ++ " is " ++ (findName currentList (read phone :: Integer))
            doLoop currentList
        '4':_ -> do
            putStrLn "Enter file name:"
            fileName <- getLine
            doWrite fileName currentList
            doLoop currentList
        '5':_ -> do
            putStrLn "Enter file name:"
            name <- getLine
            readFromFile name >>= doLoop
        _ -> doLoop currentList


instructions :: IO ()
instructions = do
    putStrLn "Enter one of the following digits:"
    putStrLn "0 - exit"
    putStrLn "1 - add record (Name, phone)"
    putStrLn "2 - find phone"
    putStrLn "3 - find name"
    putStrLn "4 - save current data in file"
    putStrLn "5 - read data from file"

findPhone :: [([Char], Integer)] -> [Char] -> [Char]
findPhone [] _         = "Not found"
findPhone (hd:tl) name = if fst hd == name then show $ snd hd else findPhone tl name

findName :: [([Char], Integer)] -> Integer -> [Char]
findName [] _          = "Not found"
findName (hd:tl) phone = if snd hd == phone then fst hd else findName tl phone

doWrite :: FilePath -> [(String, Integer)] -> IO ()
doWrite fileName list = do
   bracket (openFile fileName WriteMode) hClose
       (\h -> writeList h list)

writeList :: Handle -> [(String, Integer)] -> IO ()
writeList _ [] = return ()
writeList h (hd:tl) = do
    hPutStrLn h $ fst hd
    hPutStrLn h $ show $ snd hd
    writeList h tl

readFromFile :: FilePath -> IO [(String, Integer)]
readFromFile name = do
    content <- readFile name
    return $ convertToList content

convertToList :: String -> [(String, Integer)]
convertToList content = helper $ lines content
    where
        helper [] = []
        helper (a:b:list) | list == []  = [(a, read b :: Integer)]
                          | otherwise   = (a, read b :: Integer) : helper list

{-
  Написать программу - телефонный справочник. 
  Она должна уметь хранить имена и номера телефонов, в интерактивном режиме осуществлять следующие операции:
  0 - выйти
  1 - добавить запись (имя и телефон)
  2 - найти телефон по имени
  3 - найти имя по телефону
  4 - сохранить текущие данные в файл
  5 - считать данные из файла
  Формат представления данных в файле придумать самостоятельно

  Формат представления данных в файле - на каждую запись 2 строчки, в первой - имя, во второй - телефон.
-}