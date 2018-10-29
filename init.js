/* REQUIRES */
var fs = require('fs'),
    NTDirect32 = require('./build/Release/NTDirect32.node');

/* Private Methods */
var askPlayback = NTDirect32.askPlayback,
    bidPlayback = NTDirect32.bidPlayback,
    lastPlayback = NTDirect32.lastPlayback,
    confirmOrders = NTDirect32.confirmOrders,
    connected = NTDirect32.connected,
    marketData = NTDirect32.marketData,
    stopOrders = NTDirect32.stopOrders,
    strategies = NTDirect32.strategies,
    targetOrders = NTDirect32.targetOrders;

NTDirect32.askPlayback = function()
{
  var d = arguments[(arguments.length - 1)];
  if(!(d instanceof Date))
  { 
    console.error(new Error('A date object param was not passed::askPlayback'));
    return 0;
  }
  
  arguments[(arguments.length - 1)] = d.getYear()+d.getMonth()+d.getDate()+d.getHours()+d.getMinutes()+d.getSeconds();
  
  return askPlayback.apply(this, arguments);
}

NTDirect32.bidPlayback = function()
{
  var d = arguments[(arguments.length - 1)];
  if(!(d instanceof Date))
  { 
    console.error(new Error('A date object param was not passed::bidPlayback'));
    return 0;
  }
  
  arguments[(arguments.length - 1)] = d.getYear()+d.getMonth()+d.getDate()+d.getHours()+d.getMinutes()+d.getSeconds();
  
  return bidPlayback.apply(this, arguments);
}

NTDirect32.lastPlayback = function()
{
  var d = arguments[(arguments.length - 1)];
  if(!(d instanceof Date))
  { 
    console.error(new Error('A date object param was not passed::lastPlayback'));
    return 0;
  }
  
  arguments[(arguments.length - 1)] = d.getYear()+d.getMonth()+d.getDate()+d.getHours()+d.getMinutes()+d.getSeconds();
  
  return lastPlayback.apply(this, arguments);
}

NTDirect32.confirmOrders = function(confirm)
{
  return confirmOrders.call(this, (!confirm ? 0 : 1));
}

NTDirect32.connected = function(showMessage)
{
  return connected.call(this, (!showMessage ? 0 : 1));
}

NTDirect32.marketData = function()
{
  var t = arguments[(arguments.length - 1)];
  
  arguments[(arguments.length - 1)] = ["last","bid","ask"].indexOf(t);
  
  return marketData.apply(this, arguments);
}

NTDirect32.stopOrders = function(){ return stopOrders.apply(this, arguments).split("|"); }
NTDirect32.strategies = function(){ return strategies.apply(this, arguments).split("|"); }
NTDirect32.targetOrders = function(){ return targetOrders.apply(this, arguments).split("|"); }

process.on('exit', NTDirect32.tearDown);
process.on('uncaughtException', process.exit);

/* load local config if it exists */
var base = process.cwd().replace(/\\/,'/'),
    file = base+"/config.json",
    encoding = {encoding: 'utf8'};

if(fs.statSync(file)) NTDirect32.config(JSON.parse(fs.readFileSync(file, encoding)));

module.exports = NTDirect32;