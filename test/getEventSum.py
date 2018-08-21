from ROOT import *
import sys, os

def getWeight(fileName):
  f = TFile(fileName)
  w = f.Get("event_weight_sum")
  return w.GetVal()







assert len(sys.argv) == 2
assert os.path.isdir(sys.argv[-1])

folder = sys.argv[-1]

files = []

for f in os.listdir(folder):
  if f[:9] == "p2ntuple_":
    files.append(folder+"/"+f)

print (len(files))

evtSum = 0

for i in range(len(files)):
  if (i % 10) == 0:
    print ("%s/%s"%(i+1,len(files)))
  f = files[i]
  evtSum += getWeight(f)
print ("done !")
print (evtSum)
