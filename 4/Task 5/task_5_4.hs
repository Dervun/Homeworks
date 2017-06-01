module Expression (deriv) where

deriv :: Expression -> Expression
deriv expr = simplify $ derivative expr

infixl 6 :+:
infixl 6 :-:
infixl 7 :*:
infixl 7 :/:
infixr 8 :^:

data Expression = X | Const Int | Expression :+: Expression | Expression :-: Expression 
                                | Expression :*: Expression | Expression :/: Expression 
                                | Expression :^: Int deriving(Eq, Show)

derivative :: Expression -> Expression
derivative (ft :+: sd) = derivative ft :+: derivative sd
derivative (ft :-: sd) = derivative ft :-: derivative sd
derivative (Const n :*: sd) = Const n :*: derivative sd
derivative (ft :*: sd) = derivative ft :*: sd :+: ft :*: derivative sd
derivative (ft :/: sd) = derivative ft :+: derivative sd
derivative (ft :^: n) = Const n :*: ft :^: (n - 1) :*: derivative ft

derivative (X) = Const 1
derivative (Const _) = Const 0

simplify :: Expression -> Expression
simplify (Const 0 :+: sd) = simplify sd
simplify (Const 0 :-: sd) = simplify sd
simplify (ft :+: Const 0) = simplify ft
simplify (ft :-: Const 0) = simplify ft

simplify (Const 0 :*: sd) = Const 0
simplify (Const 0 :/: sd) = Const 0
simplify (ft :*: Const 0) = Const 0

simplify (Const 1 :*: sd) = simplify sd
simplify (ft :*: Const 1) = simplify ft

simplify (X :^: 0) = Const 1
simplify (X :^: 1) = X

simplify (Const a :+: Const b) = Const (a + b)
simplify (Const a :-: Const b) = Const (a - b)
simplify (Const a :*: Const b) = Const (a * b)

simplify (ft :+: sd) = simplify' $ simplify ft :+: simplify sd
simplify (ft :-: sd) = simplify' $ simplify ft :-: simplify sd
simplify (ft :*: sd) = simplify' $ simplify ft :*: simplify sd
simplify (ft :/: sd) = simplify' $ simplify ft :/: simplify sd
simplify (x :^: n) = simplify x :^: n
simplify x = x

simplify' :: Expression -> Expression
simplify' (Const a :+: (Const b :+: expr)) = Const (a + b) :+: expr
simplify' (Const a :-: (Const b :-: expr)) = Const (a - b) :+: expr
simplify' (Const a :-: (Const b :+: expr)) = Const (a - b) :-: expr
simplify' (Const a :+: (Const b :-: expr)) = Const (a + b) :-: expr

simplify' (Const a :*: (Const b :*: expr)) = Const (a * b) :*: expr
simplify' (Const a :*: (Const b :/: expr)) = Const (a * b) :/: expr

simplify' x = x


{-
  Дано выражение, содержащее переменную, константы, арифметические операции. 
  Посчитать производную этого выражения по этой переменной, 
  провести в полученном выражении для производной возможные упрощения (например, 1*x = x). 
  Подходящий тип данных разработать самостоятельно.

  Примеры:
  *Expression> deriv $ Const 2 :*: X :^: 2 :-: Const 1
  Const 4 :*: X
  
  *Expression> deriv $ Const 5 :*: X :-: Const 4 :*: X :^: 3 :+: Const 7
  Const 5 :-: Const 12 :*: X :^: 2

-}
