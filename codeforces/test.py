def KFrequency(s, K):
	alphaList = [0]*26
	for i  in range(0, len(s)):
		alphaList[ord(s[i])-ord('a')] += 1

	newSet = set(alphaList)

	if(K >= len(newSet)):
		return "-1"
	value = newSet[len(newSet)-K]
	if(value == 0):
		return "-1"

	finalResult=0
	for i in range(0, len(alphaList)):
		if(alphaList[i] == value):
			finalResult = i
			break

	return chr(ord('a')+finalResult)


s = input()
K = int(input())

print(KFrequency(s, K))


