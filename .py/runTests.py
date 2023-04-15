
contest = ""
with open(".stor/source.txt", 'r') as f:
	contest=f.read()

contest=str(contest)
contest=contest[:contest.find('\n')]
i = 0
while (contest[i].isdigit()):
	i+=1
contestNum=contest[:i]
contestProb=contest[i:]
