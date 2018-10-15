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
  if "TT" in shortName(j[0]) or "GluGluToHH" in shortName(j[0]):
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPA_%s 1.001"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPB_%s 1.002"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPC_%s 1.005"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPD_%s 1.0075"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPE_%s 1.01"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPF_%s 1.02"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECUPG_%s 1.035"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWNA_%s 0.999"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWNB_%s 0.998"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWNC_%s 0.995"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWND_%s 0.9925"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWNE_%s 0.99"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWNF_%s 0.98"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
    cmd = "./EXEC/bin/ntupleToCp3_jec.out %s JECDOWNG_%s 0.965"%(j[0],j[1].split("/")[-1])
    print cmd
    os.system(cmd)
