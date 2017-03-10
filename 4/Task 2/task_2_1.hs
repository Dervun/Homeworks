module Reversing (rev) where

rev :: [a] -> [a]
rev = foldl (flip (:)) []
