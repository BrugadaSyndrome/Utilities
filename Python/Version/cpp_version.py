# Version: y2015m03d22
def update_version(mtime, old_version, lines):
    new_version = make_version(mtime)
    
    if (len(old_version) != 0 and old_version[1] == 'Version:'):
        if (old_version[2] != new_version):
            lines.append('// Version: {0}\n'.format(new_version))
    else:
        lines.append('// Version: {0}\n'.format(new_version))
