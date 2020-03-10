const path = require('path');
const binary = require('node-pre-gyp');
const binding_path = binary.find(path.resolve(path.join(__dirname,'./package.json')));
const hello = require(binding_path);

module.exports = hello;