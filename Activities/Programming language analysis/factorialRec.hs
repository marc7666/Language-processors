main = do
      putStrLn $ show $ fac 6

fac :: Int -> Int
fac n | n < 2 = 1
      | otherwise = n * fac (n - 1)
