main = do
      putStrLn $ show $ fac 6

fac :: Int -> Int
fac n | n < 0 = error "Are you stupid?"
      | n == 0 = 1
      | n == 1 = 1
      | n > 1 = n * fac ( n - 1)













