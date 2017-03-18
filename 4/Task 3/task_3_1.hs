module Homework (func, func', func'', func''', func4) where

func x l = map (\y -> y*x) l
                                 -- f x = g x  <=>  f = g
func' x = map (\y -> y*x)
                                 -- (\y -> y*x)  <=>  (*x)
func'' x = map (*x)
                                 -- map (*x)  <=>  (map . (*)) x
func''' x = (map . (*)) x
                                 -- f x = g x  <=>  f = g 
func4 = map . (*)
