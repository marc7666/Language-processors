main = do
    putStrLn $ show $ magnitude 0
    putStrLn $ show $ magnitude 123
    putStrLn $ show $ magnitude (-123)

magnitude :: Int -> String
magnitude n
      | n == 0 = "Zero"
      | n > 0 = "Positive integer"
      | n < 0 = "Negative integer"
      | otherwise = "You must enter a positive integer, a negative one or a zero"
