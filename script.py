import glob, os , sys
import shutil
import subprocess
import re
import filecmp
passed = 1

def run_cmd(cmd , verbos = 1):
    if verbos == 1:
        print("running: " ,cmd)
    try:
        proc = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE , stderr=subprocess.PIPE)
        proc.wait()
        if proc.returncode != 0:
           #raise Exception(" failed p.returncode= " + str(proc.returncode))
           print(" failed p.returncode= " + str(proc.returncode))
           return -1
        return 0
    except Exception as inst:
        print("command failed")
        print(inst)
        exit(1)

def main():

    run_cmd("make clean")
    run_cmd("git add -A ")
    run_cmd("git commit -m \"some commit\"")
    run_cmd("git push -u origin")   


if __name__ == "__main__":
    main()
