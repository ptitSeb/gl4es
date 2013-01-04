#!/usr/bin/env python

import pystache
import re
from yaml import load

split_re = re.compile(r'^(?P<type>.*?)\s*(?P<name>\w+)$')

def split_arg(arg):
    match = split_re.match(arg)
    if match:
        return match.groupdict()

def gen(data, template, headers):
    funcs = []
    for name, args in sorted(data.items()):
        props = {}
        if args:
            props['return'] = args.pop(0)
        else:
            props['return'] = 'void'

        args = [split_arg(arg) for arg in args if not arg == 'void']
        if args:
            args[0]['first'] = True
            args[-1]['last'] = True

        props.update({
            'name': name,
            'args': args,
        })

        funcs.append(props)

    return pystache.render(template,
        {'functions': funcs, 'headers': headers}
    )

if __name__ == '__main__':
    import sys

    if len(sys.argv) >= 3:
        with open(sys.argv[1]) as f:
            data = load(f)

        with open(sys.argv[2]) as f:
            template = f.read()

        headers = []
        if len(sys.argv) > 3:
            headers = sys.argv[3:]

        print gen(data, template, headers)
    else:
        print 'Usage: %s <yaml> <template> [header...]'
        sys.exit(1)
