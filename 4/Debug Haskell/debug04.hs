qsort [] = []
qsort (a:as) = qsort left ++ [a] ++ qsort right
  where (left,right) = (filter (<=a) as, filter (>a) as)

main = print (qsort [8, 4, 0, 3, 1, 23, 11, 18])
    
{-
:break 2
main
:list
:print left
:print right
:force left
:show bindings
:continue

:break 2
:break 5
:show breaks
:delete 1
:show breaks
:break 5
:delete *

:step main
:list
:set stop :list
:step

:b 1
:trase qsort [3,2,1]
:hist
:forvard

:set -fbreak-on-exception
:trace qsort ("ololo" ++ undefined)
:hist
:force as
:print as
-}