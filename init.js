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
    targetOrders = NTDirect32.targetOrders,
    subscribeMarketData = NTDirect32.subscribeMarketData,
    unsubscribeMarketData = NTDirect32.unsubscribeMarketData;

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

NTDirect32.subscribeMarketData = function(instrument)
{
  if(instrument && typeof instrument == 'object' && instrument.length)
  {
    var success = [],
        x = 0,
        len = instrument.length,
        index;
    for(x;x<len;x++)
    {
      success.push(subscribeMarketData.call(this, instrument[x]));
    }
    index = success.indexOf(0);
    if(index !== -1) {
      console.error(new Error("There was an issue subscribing:" + instrument[index] + "::subscribeMarketData"));
      return 0;
    }
    return 1;
  }
  return subscribeMarketData.call(this, instrument);
}

NTDirect32.unsubscribeMarketData = function(instrument)
{
  if(instrument && typeof instrument == 'object' && instrument.length)
  {
    var success = [],
        x = 0,
        len = instrument.length,
        index;
    for(x;x<len;x++)
    {
      success.push(unsubscribeMarketData.call(this, instrument[x]));
    }
    index = success.indexOf(0);
    if(index !== -1) {
      console.error(new Error("There was an issue unsubscribing:" + instrument[index] + "::unsubscribeMarketData"));
      return 0;
    }
    return 1;
  }
  return unsubscribeMarketData.call(this, instrument);
}

process.on('exit', NTDirect32.tearDown);
process.on('uncaughtException', function(err){
  console.error(err);
  return process.exit(0);
});

/* load local config if it exists */
var base = process.cwd().replace(/\\/g,'/'),
    file = base+"/config.json",
    encoding = {encoding: 'utf8'};

try {
  if(fs.statSync(file).isFile()) NTDirect32.config(JSON.parse(fs.readFileSync(file, encoding)));
} catch(e){}

module.exports = NTDirect32;