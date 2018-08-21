import os,json

baseDirIn = "/home/ucl/cp3/delcourt/storage/HH_HLLHC/DELPHES_YR/"
dumpDir    = baseDirIn+"issues/"

dirList = os.listdir(baseDirIn)

pList = []
print dirList
for d in dirList:
  if not os.path.isdir(baseDirIn+d):
    continue
  dirPath = baseDirIn+d+"/"
  for f in os.listdir(dirPath):
    if f[:4]=="p2nt" and f[-5:]==".root":
      pList.append([dirPath+f , dumpDir+"summary_"+f])


filesPerJob = 100
jobList = []
job = []
for p in pList:
  job.append(p)
  if len(job)==filesPerJob:
    jobList.append(job)
    job = []

if len(job) > 0:
  jobList.append(job)

with open("config.json","w") as f:
  json.dump(jobList,f)

print "%s jobs written to json"%len(jobList)

print "Preparing executable..."
if "EXEC" in os.listdir("."):
  os.system("rm -r EXEC")
  os.system("mkdir EXEC")
os.system("cp -r ../include EXEC/include")
os.system("cp ../Makefile EXEC")
os.system("mkdir EXEC/src")
os.system("cp ../src/*.cc EXEC/src")
os.system("cp -r ../plugins EXEC")
os.system("mkdir EXEC/bin")
os.system("cd EXEC; make clean")


print "Check unicity of short file names"

shortList = []
for job in jobList:
  for p in job:
    short = p[1].split("/")[-1]
    shortList.append(short)
print "List : %s, set: %s"%(len(shortList),len(set(shortList)))
assert len(set(shortList)) == len(shortList)

