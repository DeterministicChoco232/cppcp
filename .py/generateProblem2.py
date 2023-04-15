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

mainstr=""
with open(".stor/"+contest+".txt", 'r') as f:
	mainstr=str(f.read())

texToPlain = {
	"$" : "",
	"_ ": "",
	"\\ldots" : "...",
	"\\dots" : "...",
	"\\cdots" : "...",
	"\\max" : "max",
	"\\\\{" : "{",
	"\\\\}" : "}",
	"\\leq" : "<=",
	"\\le " : "<=",
	"\\le" : "<=",
	"\\geq" : ">=",
	"\\ge " : ">=",
	"\\ge" : ">=",
	"\\lt" : "<",
	"\\gt" : ">",
	"\\times " : "*",
	"\\times" : "*",
	"\\cdot" : "*",
	"\\rightarrow" : "-->",
	"\\leftarrow" : "<--",
	"\\mp" : "-+",
	"\\pm" : "+-",
	"\\div" : "/",
	"\\neq" : "=/=",
	"\\not=" : "=/=",
	"\\aprox" : "~=~",
	"\\ll" : "<<",
	"\\gg" : ">>",
	"\\lvert" : "|",
	"\\rvert" : "|",
	"\\lceil" : "ceil(",
	"\\rceil" : ")",
	"\\lfloor" : "floor(",
	"\\rfloor" : ")"
}
for tx in texToPlain:
	mainstr=mainstr.replace(tx, texToPlain[tx])
with open(".stor/"+contest+".txt", 'w') as f:
	f.write(mainstr)
