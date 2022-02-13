import os


def FlushToFile(fromFileName, resultFileName = 'SourceCodeFile.txt'):
    try:
        with open(fromFileName, "r") as fromFile:
            fileText = str("---------------" + fromFileName + "--------------- \n") + fromFile.read()
            with open(resultFileName, "a") as toFile:
                toFile.write('\n'+fileText)
    except FileNotFoundError:
        return 0

resultFileName = 'SourceCodeFile.txt'
with open(resultFileName, "w") as myfile:
    myfile.truncate()

FlushToFile("EkIT1.cpp")

thisdir = os.getcwd()
for r, d, f in os.walk(thisdir):
    for file in f:
        tempFileBegin = ''
        if file.endswith(".h"):
            tempFileBegin = file[:-2]
            cppFileName = tempFileBegin + ".cpp"
            FlushToFile(file)
            FlushToFile(cppFileName)








allWords = list()