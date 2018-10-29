{
    "targets": [{
        "target_name": "NTDirect32",
        "cflags": [
            "-std=c++11"
        ],
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [
            "-fno-rtti",
            "-fno-exceptions"
        ],
        "sources": [
            "cppsrc/main.cpp",
			"cppsrc/api.cpp"
        ],
        "include_dirs": [
            "<!@(node -p \"require('node-addon-api').include\")",
            "<(module_root_dir)"
        ],
        "libraries": [ "<(module_root_dir)/NtDirect.lib" ],
        "dll_files": [ "<(module_root_dir)/NtDirect.dll" ],
        "dependencies": [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}