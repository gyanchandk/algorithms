#bash script to process file
filename=$1
cat filename |grep "Question ID" >questions
cat filename | grep Status >status
cat filename |grep "Chosen \| Given" >myanswer
#==============================

#python script to generate result
answerList=[]
statusList=[]
questionList=[]
keyList=[]

def printList(tlist):
	for item in tlist:
		print(item)

def createList(fileName,listName):

	file=open(fileName)
	
	for line in file:
		tmp=line.split()
		listName.append(tmp)
	
	file.close()


createList("questions",questionList)
createList("status",statusList)
createList("myanswer",answerList)



printList(questionList)
printList(statusList)
printList(answerList)

sequence=0
answer_map={}
for item in questionList:
	answer_map[item[3]]=statusList[sequence][2],answerList[sequence][3]
	sequence+=1

fileOutput=open("resulttmp","w")
for i in sorted(answer_map):
	print (i,answer_map[i])
	output= str(i)+":"+ str(answer_map[i])+"\n"
	fileOutput.write(output)

fileOutput.close()
