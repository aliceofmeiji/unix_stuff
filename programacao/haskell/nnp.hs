encode :: Int -> String
encode number
	| number 

main :: IO ()
main = do
	line <- getLine
	let number = (read line :: Int)
	encode number
