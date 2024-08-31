import sys
from os import walk, system
from os.path import join, split, splitext
import re

sys.stdin.reconfigure(encoding='utf-8')
sys.stdout.reconfigure(encoding='utf-8')

splitter = '\\' if sys.platform == "win32" else '/'

RequireOptionDict = {
    ".cpp": "inputcode",
    ".py":  "includepy",
    ".tex": "includetex"
}


def toLatex(string):
    string = string.replace('_', " ")
    string = string.replace('&', "\\&")
    string = string.replace('%', "\\%")
    return string


def replace(string):
    string = string.replace('\\', "/")
    return string

def get_numeric_prefix(filename):
    # Extract the numeric prefix from the filename without changing the name
    match = re.match(r'^(\d+)', filename)
    if match:
        return int(match.group(1))
    return float('inf')  # Return infinity if no numeric prefix is found

def strip_numeric_prefix(filename):
    # Use a regular expression to remove the numeric prefix
    return re.sub(r'^\d+ ', '', filename)

def PrepareFileDict(CurPath):
    FileDict = {}

    for root, _, files in walk(CurPath):
        for filename in files:
            fullpath = join(root, filename)
            name, file_extension = splitext(filename)
            if file_extension not in RequireOptionDict:
                continue
            if fullpath[0:3] == "." + splitter + ".":
                continue
            if root == CurPath:
                continue
            DirName = toLatex(split(root)[-1])
            if DirName not in FileDict:
                FileDict[DirName] = []
            FileDict[DirName].append(
                (file_extension, toLatex(name), replace(fullpath)))
    return FileDict


def texCodeGen(out, FileDict):
    for key in sorted(FileDict.keys(), key=get_numeric_prefix):
        out.write("\\section{" + strip_numeric_prefix(key) + "}\n")
        for (file_extension, name, path) in FileDict[key]:
            out.write(
                "  \\" + RequireOptionDict[file_extension] + "{" + name + "}{" + path + "}\n")


if __name__ == '__main__':
    print("[#] Start Processing Code Book List...")
    print("[1] Get Codes...")

    FileDict = PrepareFileDict("./codes")

    print("    There are", len(FileDict), "file(s)")
    print("[2] Prepare Codes...")
    with open('list.tex', 'w', encoding="utf-8") as fout:
        texCodeGen(fout, FileDict)
    
    command = "xelatex -synctex=1 -interaction=nonstopmode --extra-mem-bot=10000000 --shell-escape codebook.tex"
    system(command)
    system(command)
