#!/usr/bin/env python

import pystache
import re
from yaml import load

split_re = re.compile(r'^(?P<type>.*?)\s*(?P<name>\w+)$')

def split_arg(arg):
    match = split_re.match(arg)
    if match:
        return match.groupdict()

def gen(files, template, headers):
    funcs = []
    formats = []
    unique_formats = set()
    for data in files:
        for name, args in sorted(data.items()):
            props = {}
            if args:
                ret = args.pop(0)
            else:
                ret = 'void'

            args = [split_arg(arg) for arg in args if not arg == 'void']
            if args:
                args[0]['first'] = True
                args[-1]['last'] = True

            for i, arg in enumerate(args):
                arg['index'] = i

            types = '_'.join(
                arg['type'].replace(' ', '_').replace('*', '__GENPT__')
                for arg in [{'type': ret}] + args)

            props.update({
                'return': ret,
                'name': name,
                'args': args,
                'types': types,
                'void': ret == 'void',
            })
            if not types in unique_formats:
                unique_formats.add(types)
                formats.append(props)

            funcs.append(props)

    return pystache.render(template,
        {'functions': funcs, 'formats': formats, 'headers': headers}
    ).rstrip('\n')

if __name__ == '__main__':
    import sys

    if len(sys.argv) >= 3:
        files = []
        for name in sys.argv[1].split(','):
            with open(name) as f:
                data = load(f)
                if data:
                    files.append(data)

        with open(sys.argv[2]) as f:
            template = f.read()

        headers = []
        if len(sys.argv) > 3:
            headers = sys.argv[3:]

        print gen(files, template, headers)
    else:
        print 'Usage: %s <yaml> <template> [header...]'
        sys.exit(1)
