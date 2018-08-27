import os,json

baseDirIn = "/home/ucl/cp3/delcourt/storage/HH_HLLHC/DELPHES_YR/"
baseDirOut = "/home/ucl/cp3/delcourt/storage/HH_HLLHC/CP3_NTUPLES_YR/"
dumpDir    = baseDirOut+"dump/"

dirList = []
for f in os.listdir(baseDirIn):
  if "GluGlu" in f:
    continue
  else:
    dirList.append(f)
#dirList = ["GluGluToHHTo2B2VTo2L2Nu_node_SM_14TeV-madgraph_200PU"]

pList = []
print dirList
for d in dirList:
  if not os.path.isdir(baseDirIn+d):
    continue
  dirPath = baseDirIn+d+"/"
  for f in os.listdir(dirPath):
    if f[:4]=="p2nt" and f[-5:]==".root":
      pList.append([dirPath+f , baseDirOut + d + "/" + f.replace(".root","_cp3.root")])



filesPerJob = 200
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


print "Writing postProcess"
if "postSlurm.sh" in os.listdir("."):
  os.system("rm postSlurm.sh")

postProcess = ""
for job in jobList:
  for p in job:
    postProcess += "mv %s/%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1])

with open("postSlurm.sh","w") as f:
  f.write(postProcess)
