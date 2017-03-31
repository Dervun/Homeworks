import Debug.Trace

myFunc a b | trace ("myFunc: a - " ++ show a ++ ", b - " ++ show b) False = undefined
myFunc a b = 42
