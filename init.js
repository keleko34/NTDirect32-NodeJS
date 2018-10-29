/* REQUIRES */
var fs = require('fs'),
    NTDirect32 = require('./build/Release/NTDirect32.node');

/* load local config if it exists */
var base = process.cwd().replace(/\\/,'/'),
    file = base+"/config.json",
    encoding = {encoding: 'utf8'};

if(fs.statSync(file)) NTDirect32.config(JSON.parse(fs.readFileSync(file, encoding)));

module.exports = NTDirect32;