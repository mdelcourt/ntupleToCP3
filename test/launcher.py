import os,json

baseDirIn = "/home/ucl/cp3/delcourt/storage/HH_HLLHC/DELPHES_YR/"
baseDirOut = "/home/ucl/cp3/delcourt/storage/HH_HLLHC/CP3_NTUPLES_YR/"
dumpDir    = baseDirOut+"dump/"

#dirList = []
#for f in os.listdir(baseDirIn):
#  if "GluGlu" in f:
#    continue
#  else:
#    dirList.append(f)
dirList = ["GluGluToHHTo2B2VTo2L2Nu_node_SM_14TeV-madgraph_200PU"]
#dirList = os.listdir(baseDirIn)


pList = []
print dirList
for d in dirList:
  if not os.path.isdir(baseDirIn+d):
    continue
  dirPath = baseDirIn+d+"/"
  for f in os.listdir(dirPath):
    if f[:4]=="p2nt" and f[-5:]==".root":
      pList.append([dirPath+f , baseDirOut + d + "/" + f.replace(".root","_cp3.root")])



filesPerJob = 10
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
ntp = 0
for job in jobList:
  ntp+=len(job)

pp = 0
for job in jobList:
  for p in job:
    postProcess += "mv %s/%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1])
    if "TT" in p[1].split("/")[-1] or "GluGluToHH" in  p[1].split("/")[-1]:
      postProcess += "mv %s/JECUPA_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpA/p2ntuple"))
      postProcess += "mv %s/JECDOWNA_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownA/p2ntuple"))
      postProcess += "mv %s/JECUPB_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpB/p2ntuple"))
      postProcess += "mv %s/JECDOWNB_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownB/p2ntuple"))
      postProcess += "mv %s/JECUPC_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpC/p2ntuple"))
      postProcess += "mv %s/JECDOWNC_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownC/p2ntuple"))
      postProcess += "mv %s/JECUPD_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpD/p2ntuple"))
      postProcess += "mv %s/JECDOWND_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownD/p2ntuple"))
      postProcess += "mv %s/JECUPE_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpE/p2ntuple"))
      postProcess += "mv %s/JECDOWNE_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownE/p2ntuple"))
      postProcess += "mv %s/JECUPF_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpF/p2ntuple"))
      postProcess += "mv %s/JECDOWNF_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownF/p2ntuple"))
      postProcess += "mv %s/JECUPG_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecUpG/p2ntuple"))
      postProcess += "mv %s/JECDOWNG_%s %s\n"%(dumpDir,p[1].split("/")[-1],p[1].replace("/p2ntuple","_jecDownG/p2ntuple"))
    pp = pp+1
    if ((pp%500) == 0):
      postProcess+= "echo '%s / %s (%s%%)'\n"%(pp,ntp,int(100*pp*1./ntp))
with open("postSlurm.sh","w") as f:
  f.write(postProcess)
