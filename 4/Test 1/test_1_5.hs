check' :: Eq a => [a] -> (a -> Bool) -> Bool
check' list cond | list == []  = True
                 | otherwise   = if cond (head list) then check' (tail list) cond else False

check [] cond = error "empty list"
check list cond = check' list cond

-- Проверить, что все элементы списка удовлетворяют некоторому условию (условие передается как параметр).
