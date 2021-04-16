#!/bin/python3
from collections import namedtuple
from typing import List
from ctypes import *
import pathlib
import sys

Point = namedtuple('Point', ['x', 'y'])
libPath = pathlib.Path().absolute() / "lib/libLongestSequence.so"

def readFile(path: str):
    """
    Reads a file from a given path, and returns its contents as a list of strings
    :param path: the path to file, containing the input for the program
    :return: List of strings, with the contents of the file
    """
    print("\n" + path + "\n")
    res = []
    with open(path, 'r') as reader:
        for line in reader.readlines():
            res.append(line)
    return res

def parseFileInput(data: List[str]):
    """
    From a List of strings, converts the user input to 2d matrix of integers, and a point (the size of the matrix)
    :param userInput:
    :return 2d matrix of ints and Point structure:
    """
    rowsAndCols = data[0].strip().split(' ')
    rows = int(rowsAndCols[0])
    cols = int(rowsAndCols[1])

    res = ''
    for line in data[1:]:
        for item in line.strip().split(' '):
            res += item

    return res, [rows, cols]

def libSetup(path):
    """
    Takes the path to the shared library, performs functions setup and returns the ready to use library.
    :param path:
    :return CDLL Library:
    """
    lib = CDLL(path)
    lib.visitPoints.argtypes = [c_int, c_int, c_char_p]
    lib.visitPoints.restype = c_int
    return lib

def execute(pathToFile):
    """
    Takes the path to the provided command line argument/file and executes the rest of the program functions.
    :param path to file:
    :return C lang shared library return:
    """
    lib = libSetup(libPath)
    data = readFile(pathToFile)
    parsedData = parseFileInput(data)
    matrix = c_char_p(parsedData[0].encode('utf-8'))

    return lib.visitPoints(parsedData[1][0], parsedData[1][1], matrix)

if __name__ == '__main__':
    """
    The starting point of the program. Takes the supplied command line arguments
    and passes them to run()
    """
    for arg in sys.argv[1:]:
        print(execute(arg))