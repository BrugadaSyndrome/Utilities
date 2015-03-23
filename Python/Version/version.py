# Version: y2015m03d21
import os
import time
import sys
import getopt

def make_version(mtime):
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

def update_version(mtime, old_version, lines):
    new_version = make_version(mtime)
    
    if (len(old_version) != 0 and old_version[1] == 'Version:'):
        if (old_version[2] != new_version):
            lines.append('# Version: {0}\n'.format(new_version))
    else:
        lines.append('# Version: {0}\n'.format(new_version))

    '''
    print '---old: ', old_version
    print '---new: ', new_version
    '''

def update_file(file_name):
    mtime = os.path.getmtime(file_name)
    lines = []

    file_object = open(file_name, 'r')

    updated = False
    for line in file_object:
        # Check for version tag until it is found
        if (updated == False):
            check_line = line.strip().split()
            if (len(check_line) >= 2):
                # Found version tag, update it
                if (check_line[0] == '#' and check_line[1] == 'Version:'):
                    update_version(mtime, check_line[2], lines)
                    updated = True
                else:
                    lines.append(line)
            else:
                lines.append(line)
        else:
            lines.append(line)

    # No version tag found, insert one
    if (updated == False):
        lines = ['# Version: {0}\n'.format(make_version(mtime))] + lines

    w = open(file_name, 'w')
    w.writelines(lines)

def update_folder(folder_name):
    files = os.listdir(folder_name)

    for f in files:
        if (f.split('.')[1] == 'py'):
            update_file(folder_name + '\\' + f)
            print 'updated: ' + f

def main(argv):
    # Parse command line
    try:
      opts, args = getopt.getopt(argv,"hf:d:",["help=", "file="])
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

        # Update specific file  
        elif opt in ("-f", "--file"):
            if (os.path.exists(arg) and os.path.isfile(arg)):
                update_file(arg)
            else:
                print "File ({0}) does not exist!".format(arg)
                sys.exit(2)

        # Update directory (all *.py files)
        elif opt in ("-d", "--directory"):
            if (os.path.exists(arg) and os.path.isdir(arg)):
                update_folder(arg)
            else:
                print "Directory ({0}) does not exist!".format(arg)
                sys.exit(3)

if __name__ == '__main__':
    main(sys.argv[1:])
