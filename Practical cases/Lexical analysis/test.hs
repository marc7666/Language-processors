-- Haskell comment example
main = do
    putStrLn $ show $ divides_by_3 3000

divides_by_3 :: Int -> Bool
divides_by_3 0 = True
divides_by_3 x
    | x < 0 = False
    | otherwise = divides_by_3 (x-3)

