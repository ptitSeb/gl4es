#!/usr/bin/env python

import argparse
import jinja2
import re
from yaml import load

split_re = re.compile(r'^(?P<type>.*?)\s*(?P<name>\w+)$')
env = jinja2.Environment(loader=jinja2.FileSystemLoader('template'))

def args(args, add_type=True):
    return ', '.join(
        '{} {}'.format(arg['type'], arg['name']) if add_type else arg['name']
        for arg in args
    )
env.filters['args'] = args

def split_arg(arg):
    match = split_re.match(arg)
    if match:
        return match.groupdict()

def gen(files, template, guard_name, headers, deep=False, cats=()):
    funcs = []
    formats = []
    unique_formats = set()
    for data in files:
        if deep:
            functions = []
            for cat, f in data.items():
                if not cats or cat in cats:
                    functions.extend(f.items())
        else:
            functions = data.items()

        for name, args in sorted(functions):
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

    context = {
        'functions': funcs,
        'formats': formats,
        'headers': headers,
        'name': guard_name,
    }

    t = env.get_template(template)
    return t.render(**context).rstrip('\n')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate code with yml/jinja.')
    parser.add_argument('yaml', help='spec files')
    parser.add_argument('template', help='jinja template to load')
    parser.add_argument('name', help='header guard name')
    parser.add_argument('headers', nargs='*', help='headers to include')
    parser.add_argument('--deep', help='nested definitions', action='store_true')
    parser.add_argument('--cats', help='deep category filter')

    args = parser.parse_args()

    files = []
    for name in args.yaml.split(','):
        with open(name) as f:
            data = load(f)
            if data:
                files.append(data)

    print gen(files, args.template, args.name, args.headers, args.deep, args.cats)
