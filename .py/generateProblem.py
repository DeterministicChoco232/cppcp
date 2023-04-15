from bs4 import BeautifulSoup
import requests

contest = ""
with open(".stor/source.txt", 'r') as f:
	contest=str(f.read())
contest=contest[:contest.find('\n')]
i = 0
while (contest[i].isdigit()):
	i+=1
contestNum=contest[:i]
contestProb=contest[i:]

url = requests.get("https://codeforces.com/contest/"+contestNum+"/problem/"+contestProb).text
soup = BeautifulSoup(url, 'html.parser')
problem = soup.find_all(class_="problem-statement")[0]
useless = problem.find_all(class_=["time-limit", "memory-limit"])
for uselessDiv in useless:
	uselessDiv.decompose()


def remove_empty_lines(string):
    # Split the string into lines
    lines = string.split("\n")

    # Remove empty lines or lines with only spaces
    filtered_lines = filter(lambda line: not line.strip() == "", lines)

    # Join the non-empty lines back into a string
    filtered_string = "\n".join(filtered_lines)

    return filtered_string

mainstr=str(problem)

with open(".stor/"+contest+".html", 'w') as f:
	f.write(mainstr)

inpChildren = problem.find_all(class_="input")

for i in range(len(inpChildren)):
	inp=inpChildren[i]
	inpstr = ""
	for child in inp.pre:
		inpstr += child.text + '\n'
	with open(".stor/"+contest+"_input"+str(i)+".txt", 'w') as f:
		f.write(remove_empty_lines(inpstr))

outChildren = problem.find_all(class_="output")
for i in range(len(outChildren)):
	out=outChildren[i]
	outstr = ""
	for child in out.pre:
		outstr += child.text + '\n'
	if outstr[-2]=='\n':
		outstr=outstr[:-1]
	with open(".stor/"+contest+"_output"+str(i)+".txt", 'w') as f:
		f.write(remove_empty_lines(outstr))


