, 			read user input (y or n)

> ++++++++++ 		put 10 in @2		\
[ @2						|
	< ----------- 	sub 11 from @1		|__sub 110('n') from @1
	> -		sub 1 from @2		|
]						/

+++++++++++ >		put 11 in @2		\
++++++++++ 		put 10 in @3		|
[ @3						|__put 121('y') in @2
	- <		sub 1 from @3		|
	+++++++++++ > 	add 11 to @2		|
]						/

<< 			back to @1		\
[ @1						|__check if @1 is 'y'(not 'n'); print y indefinetly
	> . <		print @2; go back to @1 |
]						/
