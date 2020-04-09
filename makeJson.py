

file=open("fibNumbersUpto500.txt","r")
raw=file.readlines()

result=open("rawjson.txt","w")
result.write("{")
for line in raw:
    tmpList=list(line.split(":"))
    print(tmpList)
    tmpString='"'+tmpList[0]+ '":'+\
                '{"fibNumber":"'+tmpList[1]+'","numberOfDigits":"'+tmpList[2]+'"}'
    result.write(tmpString)
    if(line!=raw[-1]):
        result.write(",")    
    result.write("\n")

result.write("}")
result.close()
file.close()
