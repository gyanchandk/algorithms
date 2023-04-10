	
magicList=[]
keys=[]
characters="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()1234567890+-/=<>[]{}"
#newKey="v&8{BMXit^7]JLWhsu6[IKVgr#%>HSUfq@$5GRTep!24<Qbdoz13=Facny)+/EPkmx(0-DOZJlw*9}CNYj"
newKey="v&8{BMXitJlw*9}CNYj^7]JLWhsu6[IKVgr#%>HSUfq@$5GRTep!24<Qbdoz13=Facny)+/EPkmx(0-DOZ"


def keyGeneration():
	f = open("ms2.txt", "r")
	for line in f:
		content=line.split()
		for value in content:
			magicList.append(int(value))
	print(magicList)
	
	ls=list(characters)
	for item in ls:
		keys.append(item)
	
	newKey=""
	for index in magicList:
		newKey+=keys[index]
		print(keys[index])
	
	print(newKey)
	
def myCode(mykey,offset):
	
	ls=list(characters)
	for item in ls:
		keys.append(item)
	
	ls2=list(newKey)
	for item in ls2:
		index=keys.index(item)
		magicList.append(index+offset)
		#print(index)
	
	num=""
	for key in mykey:
		index=keys.index(key)
		num+=str(magicList[index])

	print(num)



def myDecode(num):
	n=2
	chunks = [num[i:i+n] for i in range(0, len(num), n)]
	code=""
	for item in chunks:
		index=magicList.index(int(item))
		code+=keys[index]
	
	print(code)


#keyGeneration()
offset=input()
myCode("abc",int(offset))
eKey=input()
myDecode(str(eKey))


#just space comments
