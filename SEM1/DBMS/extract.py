file1  = open("assignment1.txt",'r')
res = []
d = file1.readlines()
for i in d:
    line = i.strip()
    a="SELECT"
    if a in line:
        index = line.index(a)
        res+=line[index:]+"\n"
    # print(line)
file2  = open("output.txt",'w')
file2.write("".join(res))
