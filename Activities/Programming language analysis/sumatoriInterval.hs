main = do
     putStrLn $ show $ sumatori 6 10


sumatori :: Int -> Int -> Int
sumatori a b
    |a < b = a + sumatori (a + 1) b
    |a == b = b
    |otherwise = error "The first argument is greater than the second one"




