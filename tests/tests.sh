#!/bin/bash

function clean_tests {
    #glxgears
    if [ -e glxgears.0000008203.png ];then
        rm glxgears.0000008203.png
    fi
    if [ -e glxgears.trace ];then
        rm glxgears.trace
    fi
    #stunt car racer
    if [ -e stuntcarracer.0000118817.png ];then
        rm stuntcarracer.0000118817.png
    fi
    if [ -e stuntcarracer.trace ];then
        rm stuntcarracer.trace
    fi
    #neverball
    if [ -e neverball.0000078750.png ];then
        rm neverball.0000078750.png
    fi
    if [ -e neverball.trace ];then
        rm neverball.trace
    fi
    #foobillardplus
    if [ -e foobillardplus.0000014748.png ];then
        rm foobillardplus.0000014748.png
    fi
    if [ -e foobillardplus.trace ];then
        rm foobillardplus.trace
    fi
    #openra
    if [ -e openra.0000031249.png ];then
        rm openra.0000031249.png
    fi
    if [ -e openra.trace ];then
        rm openra.trace
    fi
    #glsl_lighting
    if [ -e glsl_lighting.0000505393.png ];then
        rm glsl_lighting.0000505393.png
    fi
    if [ -e glsl_lighting.trace ];then
        rm glsl_lighting.trace
    fi
    #diff result
    if [ -e diff.png ];then
        rm diff.png
    fi
}

if [ ! -z "$1" ];then
 export LD_LIBRARY_PATH=$1:$LD_LIBRARY_PATH
fi

export LIBGL_FB=3

TESTS=`dirname "$0"`

pushd "$TESTS" >/dev/null

clean_tests

export LIBGL_ES=1

echo "GLES1.1: glxgears"

tar xf ../traces/glxgears.tgz
apitrace dump-images --calls="8203" glxgears.trace
result=$(compare -metric AE -fuzz 20% ../refs/glxgears.0000008203.png glxgears.0000008203.png diff.png 2>&1)
if [ ! "$result" -lt "25" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

echo "GLES1.1: StuntCarRacer"

tar xf ../traces/stuntcarracer.tgz
apitrace dump-images --calls="118817" stuntcarracer.trace
result=$(compare -metric AE -fuzz 20% -extract 638x478+1+1 ../refs/stuntcarracer.0000118817.png stuntcarracer.0000118817.png diff.png 2>&1)
if [ ! "$result" -lt "20" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

echo "GLES1.1: Neverball"

tar xf ../traces/neverball.tgz
apitrace dump-images --calls="78750" neverball.trace
result=$(compare -metric AE -fuzz 20% -extract 798x478+1+1 ../refs/neverball.0000078750.png neverball.0000078750.png diff.png 2>&1)
if [ ! "$result" -lt "20" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

echo "GLES1.1: Foobillard Plus"

tar xf ../traces/foobillardplus.tgz
apitrace dump-images --calls="14748" foobillardplus.trace
result=$(compare -metric AE -fuzz 20% -extract 798x478+1+1 ../refs/foobillardplus.0000014748.png foobillardplus.0000014748.png diff.png 2>&1)
if [ ! "$result" -lt "20" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

export LIBGL_ES=2

echo "GLES2.0: OpenRA"

tar xf ../traces/openra.tgz
apitrace dump-images --calls="31249" openra.trace
result=$(compare -metric AE -fuzz 20% -extract 638x478+1+1 ../refs/openra.0000031249.png openra.0000031249.png diff.png 2>&1)
if [ ! "$result" -lt "20" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

echo "GLES2.0: glsl_lighting"

tar xf ../traces/glsl_lighting.tgz
apitrace dump-images --calls="505393" glsl_lighting.trace
result=$(compare -metric AE -fuzz 20% -extract 638x478+1+1 ../refs/glsl_lighting.0000505393.png glsl_lighting.0000505393.png diff.png 2>&1)
if [ ! "$result" -lt "20" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi

echo "GLES2.0: glxgears"

tar xf ../traces/glxgears.tgz
apitrace dump-images --calls="8203" glxgears.trace
result=$(compare -metric AE -fuzz 20% ../refs/glxgears.0000008203.png glxgears.0000008203.png diff.png 2>&1)
# Because FlatShader mode is not supported, the image is more different.
if [ ! "$result" -lt "700" ];then
    popd >/dev/null
    echo "error, $result pixels diff"
    exit 1
fi


# cleanup
clean_tests

popd >/dev/null
echo "All done"
exit 0
