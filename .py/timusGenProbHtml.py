from bs4 import BeautifulSoup
import requests

probNum = ""
with open(".stor/source.txt", 'r') as f:
	probNum=str(f.read())[1:-1]

url = requests.get("https://timus.online/problem.aspx?num="+probNum).text
soup = BeautifulSoup(url, 'html.parser')
probtxthtml = soup.find_all(class_="problem_content")[0].find("div", {"id":"problem_text"})
inpout = probtxthtml.table.extract().find_all("td")
useless = probtxthtml.find_all(class_=["problem_source", "problem_subtitle"])
for uselessTag in useless:
	uselessTag.decompose()
 
def remove_empty_lines(string):
	# Split the string into lines
	lines = string.split("\n")

	# Remove empty lines or lines with only spaces
	filtered_lines = filter(lambda line: not line.strip() == "", lines)

	# Join the non-empty lines back into a string
	filtered_string = "\n".join(filtered_lines)

	return filtered_string

mainstr=str(probtxthtml)

def chunk(seq, size):
    return (seq[pos:pos + size] for pos in range(0, len(seq), size))

for i, (inp, out) in zip(range(int(len(inpout)/2)), chunk(inpout, 2)):
	mainstr+="<div></div>Input:<div></div>"+inp.text+"<div></div>Output:<div>"+out.text+"</div>"
	with open(".stor/inp"+str(i)+".txt", 'w') as f:
		f.write(inp.text)
	with open(".stor/out"+str(i)+".txt", 'w') as f:
		f.write(out.text)
 
with open(".stor/problemstatement.html", 'w') as f:
	f.write(mainstr)
#
# inpChildren = problem.find_all(class_="input")
# 
# for i in range(len(inpChildren)):
# 	inp=inpChildren[i]
# 	inpstr = ""
# 	for child in inp.pre:
# 		inpstr += child.text + '\n'
# 	with open(".stor/inp"+str(i)+".txt", 'w') as f:
# 		f.write(remove_empty_lines(inpstr))
# 
# outChildren = problem.find_all(class_="output")
# for i in range(len(outChildren)):
# 	out=outChildren[i]
# 	outstr = ""
# 	for child in out.pre:
# 		outstr += child.text + '\n'
# 	if outstr[-2]=='\n':
# 		outstr=outstr[:-1]
# 	with open(".stor/out"+str(i)+".txt", 'w') as f:
# 		f.write(remove_empty_lines(outstr))
# 
# 
