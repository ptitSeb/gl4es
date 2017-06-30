#!/bin/bash

if [ ! -z "$1" ];then
 export LD_LIBRARY_PATH=$1:$LD_LIBRARY_PATH
fi

export LIBGL_FB=3

TESTS=`dirname "$0"`

pushd "$TESTS" >/dev/null

echo "StuntCarRacer"

if [ -e stuntcarracer.0000180445.png ];then
    rm stuntcarracer.0000180445.png
fi
if [ -e stuntcarracer.trace ];then
    rm stuntcarracer.trace
fi
tar xf ../traces/stuntcarracer.tgz
apitrace dump-images --calls="180445" stuntcarracer.trace
result=$(compare -metric AE ../refs/stuntcarracer.0000180445.png stuntcarracer.0000180445.png diff.png 2>&1)
if [ ! "$result" == "0" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

# cleanup
if [ -e stuntcarracer.0000180445.png ];then
    rm stuntcarracer.0000180445.png
fi
if [ -e stuntcarracer.trace ];then
    rm stuntcarracer.trace
fi
if [ -e diff.png ];then
    rm diff.png
fi

popd >/dev/null
echo "All done"
exit 0
