{
  "targets": [
    {
        "target_name": "hello",
        "include_dirs": ["include", "<!@(node -p \"require('node-addon-api').include\")"],
        "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
        "sources": [ "./source/hello.cc" ],
        "xcode_settings": {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
        },
        "msvs_settings": {
            'VCCLCompilerTool': { 'ExceptionHandling': 1 },
        },
    }
  ]
}