#!/usr/bin/env python
from collections import defaultdict
import re
import xml.etree.ElementTree as ET
import yaml

def to_yml(filename):
    with open(filename, 'r') as f:
        data = f.read()

    data = re.sub(' xmlns="[^"]+"', '', data, count=1)
    xml = ET.fromstring(data)

    typemap = xml.find('typemap')
    types = {}
    for t in typemap:
        name = t.get('typename')
        types[name] = t.get('C-lang', name)

    defs = xml.find('functions').find('function-defs')
    functions = defaultdict(dict)
    for f in defs.findall('function'):
        cat = f.get('category')
        ret = f.get('return')
        func = f.get('name')

        params = []
        for param in f.findall('param'):
            typ = param.get('type')
            typ = types.get(typ, typ)
            name = param.get('name')
            p = '{} {}'.format(typ, name)
            p = p.replace('* ', '*')
            params.append(p)

        args = [ret]
        args.extend(params)
        functions[cat][func] = args

    yml = yaml.dump(dict(functions))
    with open(filename.replace('xml', 'yml'), 'w') as o:
        o.write(yml)

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        print 'Usage: {} <file.xml> [file.xml...]'.format(sys.argv[0])
        sys.exit(1)
    
    for name in sys.argv[1:]:
        to_yml(name)

