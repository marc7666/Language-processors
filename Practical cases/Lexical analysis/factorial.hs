main = do
     putStrLn $ show $ fact 6

fact :: Int -> Int
fact 0 = 1
fact n = n * fact(n - 1)
