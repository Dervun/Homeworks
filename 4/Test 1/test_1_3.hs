rhombus :: Int -> IO ()
rhombus n = print1 n >> print2 n

print1 n = helper n 1
    where
        helper n i | i == n * 2 - 1  = putStrLn (replicate i 'x')
                   | otherwise       = putStrLn (xLine (n * 2 - 1) i) >> helper n (i + 2)

print2 1 = return ()
print2 n = helper n (n * 2 - 3)
    where
        helper n i | i == 1     = putStrLn (xLine (n * 2 - 1) i)
                   | otherwise  = putStrLn (xLine (n * 2 - 1) i) >> helper n (i - 2)



xLine n i = replicate (div (n - i) 2) ' ' ++ replicate i 'x' ++ replicate (div (n - i) 2) ' '

{-
  Реализовать функцию, которая выводит ромб из символов 'x' с стороной n. Так, для n = 4 будет выведено:
  
     x 
    xxx
   xxxxx
  xxxxxxx
   xxxxx
    xxx
     x
-}
