import os, time

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
    print '---FOUND VERSION'
    print '---old: ', old_version
    print '---new: ', new_version
    '''

def main():
    file_name = 'version_me.txt'
    
    mtime = os.path.getmtime(file_name)
    lines = []

    file_object = open(file_name, 'r')

    updated = False
    for line in file_object:
        # Check for version tag until it is found
        if (updated == False):
            check_line = line.strip().split()
            if (len(check_line)):
                # Found version tag, update it
                if (check_line[1] == 'Version:'):
                    update_version(mtime, check_line[2], lines)
                    updated = True
                else:
                    lines.append(line)
            else:
                lines.append('\n')
        else:
            lines.append(line)

    # No version tag found, insert one
    if (updated == False):
        lines = ['# Version: {0}\n'.format(make_version(mtime))] + lines

    w = open('text.txt', 'w')
    w.writelines(lines)

main()
