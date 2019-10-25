num = int(input("enter number: "))
if num>1:
	for x in range(2,num):
		if(num%x)==0:
			print("not prime")
			break
	else:
		print("prime")
else:
	print("not prime")
