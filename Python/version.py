# Version: y2015m03d27

import getopt
import os
import sys
import time

PYTHON_EXTENSIONS = ('py')
CPP_EXTENSIONS = ('cpp','hpp', 'c', 'h')
TAG = 'Version:'

def makeVersion(mtime):
    # t = ['Text Day', 'Month', 'Num day', 'time', 'year']
    t = time.ctime(mtime).split()

    year = t[4]
    month = int(time.strptime(t[1], '%b').tm_mon)
    day = t[2]

    if (month < 10):
        new_version = 'y{0}m0{1}d{2}'.format(year, month, day)
    else:
        new_version = 'y{0}m{1}d{2}'.format(year, month, day)

    return new_version

def isVersion(line):
    if (len(line) > 1 and line[1] == TAG):
        return True
    else:
        return False

def makeComment(version, file_extension):
    postfix = '{0} {1}\n'.format(TAG, version)
    if (file_extension in PYTHON_EXTENSIONS):
        return '# {0}'.format(postfix)
    elif (file_extension in CPP_VERSIONS):
        return '// {0}'.format(postfix)

def makePythonComment(mtime):
    new_version = makeVersion(mtime)
    return makeComment(new_version, 'py')

def updateCppVersion(mtime, old_version, lines):
    new_version = makeVersion(mtime)
    
    if (len(old_version) != 0 and old_version[1] == 'Version:'):
        if (old_version[2] != new_version):
            lines.append('// Version: {0}\n'.format(new_version))
    else:
        lines.append('// Version: {0}\n'.format(new_version))

def updateFile(file_name):
   
    file_extension = file_name.split('.')[1]
    file_object = open(file_name, 'r')
    file_lines = []
    # get date of last modification
    file_date = os.path.getmtime(file_name)

    updated = False
    # Python file
    if (file_extension in PYTHON_EXTENSIONS):
        for line in file_object:
            if (updated == False):
                check_line = line.strip().split()
                if (isVersion(check_line)):
                    # get date of last modification
                    #mtime = os.path.getmtime(file_name)
                    file_lines.append(makePythonComment(file_date))
                    updated = True
                else:
                    file_lines.append(line)
            else:
                file_lines.append(line)

    # C++ file
    elif (file_extension in CPP_EXTENSIONS):
        pass

    # No version tag found, insert one
    if (updated == False):
        if (file_extension in PYTHON_EXTENSIONS):
            file_lines = ['# Version: {0}\n'.format(makeVersion(file_date))] + file_lines
        elif (file_extension in CPP_EXTENSIONS):
            file_lines = ['// Version: {0}\n'.format(makeVersion(file_date))] + file_lines

    w = open(file_name, 'w')
    w.writelines(file_lines)

    '''

    updated = False
    for line in file_object:
        # Check for version tag until it is found
        if (updated == False):
            check_line = line.strip().split()
            if (len(check_line) >= 2):
                # Found version tag, update it
                if (ext in py_ext):
                    if (check_line[0] == '#' and check_line[1] == 'Version:'):
                        python_update_version(mtime, check_line[2], lines)
                        print "Updated: {0}".format(file_name)
                        updated = True
                elif (ext in cpp_ext):
                    print ext, line
                    if (check_line[0] == '\\\\' and check_line[1] == 'Version:'):
                        cpp_update_version(mtime, check_line[2], lines)
                        print "Updated: {0}".format(file_name)
                        update = True
                else:
                    lines.append(line)
            else:
                lines.append(line)
        else:
            lines.append(line)

    # No version tag found, insert one
    if (updated == False):
        if (ext in py_ext):
            lines = ['# Version: {0}\n'.format(make_version(mtime))] + lines
        elif (ext in cpp_ext):
            lines = ['\\\\ Version: {0}\n'.format(make_version(mtime))] + lines

    w = open(file_name, 'w')
    w.writelines(lines)
    '''

def updateFolder(folder_name):
    files = os.listdir(folder_name)

    for f in files:
        updateFile(f)

def main(argv):
    # Parse command line
    try:
      opts, args = getopt.getopt(argv,"hf:d:",["help=", "file=", 'directory='])
    except getopt.GetoptError:
        print "Please type 'version.py -h' for usage."
        sys.exit(1)
    
    if (not argv):
        print "Use version.py with command line. Please type 'version.py -h' for usage."
        sys.exit(1)

    for opt, arg in opts:
        # Help
        if opt in ("-h", "--help"):
            print 'version.py -f <file> -d <directory> [-h <help>]'
            sys.exit()

        # Update specific file (if supported file type)
        elif opt in ("-f", "--file"):
            if (os.path.exists(arg) and os.path.isfile(arg)):
                updateFile(arg)
            else:
                print "File ({0}) does not exist!".format(arg)
                sys.exit(2)

        # Update directory (all supported files)
        elif opt in ("-d", "--directory"):
            if (os.path.exists(arg) and os.path.isdir(arg)):
                updateFolder(arg)
            else:
                print "Directory ({0}) does not exist!".format(arg)
                sys.exit(3)

if __name__ == '__main__':
    main(sys.argv[1:])
