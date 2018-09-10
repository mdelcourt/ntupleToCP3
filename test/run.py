import sys,json,os

print "RUNNING run.py... Args :"
for x in sys.argv:
  print x

jobList = []
with open("config.json","r") as f:
  jobList = json.loads(f.read())

assert len(sys.argv) == 2
assert sys.argv[-1].isdigit()
jobId = int(sys.argv[-1]) - 1
assert jobId < len(jobList)

job = jobList[jobId]

print "Running job %s"%jobId
print "Will process %s files"%len(job)

def shortName(name):
  if name[-1] == "/":
    name = name[:-1]
  return(name.split("/")[-2]+"/"+name.split("/")[-1])

print "COMPILING..."
os.system("cd EXEC; make; cp Dic* ..; cd ..")

for j in job:
  print "%s --> %s"%(shortName(j[0]),shortName(j[1]))
  cmd = "./EXEC/bin/ntupleToCp3.out %s %s"%(j[0],j[1].split("/")[-1])
  print cmd
  os.system(cmd)
  cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUP_%s 1.035"%(j[0],j[1].split("/")[-1])
  print cmd
  os.system(cmd)
  cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWN_%s 0.965"%(j[0],j[1].split("/")[-1])
  print cmd
  os.system(cmd)
