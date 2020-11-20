import sys
import os
import datetime

var = 'E_mu_canc'
xmin = 0.2
xmax = 4.8
flag = 'v1_moreStat'
cut = '04'
FRValue = 0.7910354
production_tag = datetime.date.today().strftime('%Y%b%d')

#for the jpsi pi 
path_data = '/pnfs/psi.ch/cms/trivcat/store/user/friti/dataframes_2020Nov19/data_pichannel_sel1.root'
path_pi = '/pnfs/psi.ch/cms/trivcat/store/user/friti/dataframes_2020Nov19/BcToXToJpsi_is_jpsi_pi_merged.root'

#for rjpsi
path_dir = var+ "_" + production_tag + "_cut"+cut
path_pyrk = "/work/friti/new/CMSSW_10_2_15/src/pyrk/scripts/"

if not os.path.exists(path_dir):
# if there si already one it does not delete it
    os.makedirs(path_dir)
    print("Made directory "+ path_dir)
else:
    print("Directory already exists! ")
    sys.exit("WARNING: the folder "+ path_dir + " already exists!")

passrootfileName =  var + "Pass_cut" + cut + ".root"
os.system("cp "+ path_pyrk + "rootFiles/" + passrootfileName +" "+ path_dir + "/")
print("Copied root File " + passrootfileName)

failrootfileName = var + "Fail_cut" + cut + ".root"
os.system("cp "+ path_pyrk + "rootFiles/" + failrootfileName +" " + path_dir+ "/")
print("Copied root File " + failrootfileName)

datacardfailName = "datacard_" + var + "_Fail.txt"
os.system("cp "+ path_pyrk + "datacards/datacard_" + var + "_Fail.txt " + path_dir+ "/")
print("Copied datacard   datacard_" + var + "_Fail.txt" )

datacardpassName = "datacard_" + var + "_Pass.txt"
os.system("cp "+ path_pyrk + "datacards/datacard_" + var + "_Pass.txt " + path_dir+ "/")
print("Copied datacard   datacard_" + var + "_Fail.txt" )

#workspace
fin = open("workspace_v2.C", "rt")
fout = open("%s/workspace.C"%(path_dir),"wt")
for line in fin:
    if 'REPLACE' in line:
        newline = line.replace('REPLACE_FILE_FAIL', '%s'%(var + "Fail_cut" + cut + ".root"))
        newline = newline.replace('REPLACE_FILE_PASS', '%s'%(var + "Pass_cut" + cut + ".root"))
        newline = newline.replace('REPLACE_FR', '%s'%(FRValue))
        newline = newline.replace('REPLACE_VAR', '%s'%(var))
        newline = newline.replace('REPLACE_XMIN', '%s'%(xmin))
        newline = newline.replace('REPLACE_XMAX', '%s'%(xmax))
        #newline = newline.replace('REPLACE_PATH_DATA', '%s'%(path_data))
        #newline = newline.replace('REPLACE_PATH_MCPI', '%s'%(path_pi))
        fout.write(newline)
       
    else:
        fout.write(line)
fout.close()
fin.close()

fin_pi = open("workspace_pi_v1.py", "rt")
fout_pi = open("%s/workspace_pi.py"%(path_dir),"wt")
for line_pi in fin_pi:
    if 'REPLACE' in line_pi:
        newline_pi = line_pi.replace('REPLACE_PATH_DATA', '%s'%(path_data))
        newline_pi = newline_pi.replace('REPLACE_PATH_MCPI', '%s'%(path_pi))
        fout_pi.write(newline_pi)

    else:
        fout_pi.write(line_pi)
fout_pi.close()
fin_pi.close()

print("Created workspaces" )

#entering the right directory
os.chdir(path_dir)

# create the workspaces
os.system("python workspace_pi.py")
os.system("root -l -q workspace.C")

#combine cards
os.system("combineCards.py " + datacardpassName + " " + datacardfailName + " datacard_jpsipi.txt >& datacard.txt")

'''
#fit command
os.system("combine -M FitDiagnostics --plots --robustFit 1 --saveShapes --cminDefaultMinimizerStrategy 0 --saveNormalizations --maxFailedSteps 20 --saveWithUncertainties --robustHesse 1  --ignoreCovWarning datacard.txt")


#yields
os.system("python $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit/test/mlfitNormsToText.py -u fitDiagnostics.root")
output = os.popen("python $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit/test/mlfitNormsToText.py -u fitDiagnostics.root").readlines()


for line in output:
    if 'ch1' in line:
        if 'mc_comb' in line:
            splittedLine = line.split(" ")
            smartLine = []
            for piece in splittedLine:
                if piece != '':
                    smartLine.append(piece)
            preComb = smartLine[2]
            preCombUnc = smartLine[4]
            postComb  = smartLine[5]
            postCombUnc = smartLine[7]

        if 'mc_mu' in line:
            splittedLine = line.split(" ")
            smartLine = []
            for piece in splittedLine:
                if piece != '':
                    smartLine.append(piece)
            preMu = smartLine[2]
            preMuUnc = smartLine[4]
            postMu  = smartLine[5]
            postMuUnc = smartLine[7]

        if 'mc_tau' in line:
            splittedLine = line.split(" ")
            smartLine = []
            for piece in splittedLine:
                if piece != '':
                    smartLine.append(piece)
            preTau = smartLine[2]
            preTauUnc = smartLine[4]
            postTau  = smartLine[5]
            postTauUnc = smartLine[7]

ratioComb = float(postComb)/ float(preComb)
ratioMu = float(postMu) / float(preMu)
ratioTau = float(postTau) / float(preTau)

print("The ratios are: ")
print("- Factor for mu sample = %s"%(ratioMu))
print("- Factor for tau sample = %s"%(ratioTau))
print("- Factor for comb sample = %s"%(ratioComb))

'''
