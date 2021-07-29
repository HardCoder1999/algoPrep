# def solution():
# 	(A, D, N) = map(int, input().split())

# 	sumVal = A*N + ((N-1)*N*D)//2
# 	return sumVal

def solution():
	words = list(input().split(" "))
	words.reverse()
	s = ""
	for word in words:
		s += word
		s += "."
	return s[:-1]

print(solution())