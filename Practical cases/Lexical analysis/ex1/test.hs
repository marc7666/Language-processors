-- Haskell comment example
main = do
    putStrLn $ show $ divides_by_3 3000

-- Checks recursively for division by 3
divides_by_3 :: Int -> Bool
divides_by_3 0 = True
divides_by_3 x
    | x < 0 = False
    | otherwise = divides_by_3 (x-3)
    
testing_string' = "Very nice string :: Sus"

sus_string = "When the imposter does not close the string

