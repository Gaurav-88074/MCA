file1  = open("assignment2.txt",'r')
res = []
d = file1.readlines()
for i in d:
    line = i.strip()
    a="SELECT"
    b = "select"
    c = "Select"
    if a in line :
        index = line.index(a)
        res+=line[index:]+"\n"
    elif b in line:
        index = line.index(b)
        res+=line[index:]+"\n"
    elif c in line:
        index = line.index(c)
        res+=line[index:]+"\n"
    # print(line)
file2  = open("output.txt",'w')
file2.write("".join(res))

#  select distinct(dept.deptno),(select count(emp.empno) from emp where emp.deptno=dept.deptno) as noOfEmployees ,(select avg(sal) from emp where emp.deptno=dept.deptno) as avg from dept;