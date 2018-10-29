#include <iostream>
#include <string>
#include "ninja.h"
#include "api.h"

using namespace Napi;
using namespace std;

/* PRIVATE USED VARIABLES */
char* HostConfig = "localhost";
int PortConfig = 36973;
char* AccountConfig = "";
char* InstrumentConfig = "";

/* PRIVATE USED METHODS */
char* getCharFromString(string input)
{
  char* S = new char[input.length() + 1];
  
  strcpy(S,input.c_str());
  
  return S;
}

/* PUBLIC METHODS */
Value api::AskWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Price param was not passed::ask").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  double price = info[1].ToNumber().DoubleValue();
  
  if(info[2].IsNumber() == false) {
    TypeError::New(env, "Size param was not passed::ask").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int size = info[2].ToNumber().Int32Value();
  
  if(price == 0 || size == 0) {
    TypeError::New(env, "Price or Size param can not be 0::ask").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int returnValue = (Ask(instrument, price, size) == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::AskPlaybackWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Price param was not passed::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  double price = info[1].ToNumber().DoubleValue();
  
  if(info[2].IsNumber() == false) {
    TypeError::New(env, "Size param was not passed::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int size = info[2].ToNumber().Int32Value();
  
  if(info[3].IsString() == false) {
    TypeError::New(env, "Timestamp param was not passed::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* timestamp = getCharFromString(info[3].ToString().Utf8Value());
  
  if(price == 0 || size == 0) {
    TypeError::New(env, "Price or Size param can not be 0::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int returnValue = (AskPlayback(instrument, price, size, timestamp) == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::AvgEntryPriceWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  char* account = (info[1].IsString() == false ? AccountConfig : getCharFromString(info[1].ToString().Utf8Value()));
  
  double returnValue = AvgEntryPrice(instrument, account);
  
  return Number::New(env, returnValue);
}

Value api::AvgFillPriceWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "OrderId param was not passed::avgFillPrice").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* orderid = getCharFromString(info[0].ToString().Utf8Value());
  
  double returnValue = AvgFillPrice(orderid);
  
  return Number::New(env, returnValue);
}

Value api::BidWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Price param was not passed::bid").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  double price = info[1].ToNumber().DoubleValue();
  
  if(info[2].IsNumber() == false) {
    TypeError::New(env, "Size param was not passed::bid").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int size = info[2].ToNumber().Int32Value();
  
  if(price == 0 || size == 0) {
    TypeError::New(env, "Price or Size param can not be 0::bid").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int returnValue = (Bid(instrument, price, size) == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::BidPlaybackWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Price param was not passed::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  double price = info[1].ToNumber().DoubleValue();
  
  if(info[2].IsNumber() == false) {
    TypeError::New(env, "Size param was not passed::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int size = info[2].ToNumber().Int32Value();
  
  if(info[3].IsString() == false) {
    TypeError::New(env, "Timestamp param was not passed::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* timestamp = getCharFromString(info[3].ToString().Utf8Value());
  
  if(price == 0 || size == 0) {
    TypeError::New(env, "Price or Size param can not be 0::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int returnValue = (BidPlayback(instrument, price, size, timestamp) == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::BuyingPowerWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* account = (info[0].IsString() == false ? AccountConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  double returnValue = BuyingPower(account);
  
  return Number::New(env, returnValue);
}

Value api::CashValueWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* account = (info[0].IsString() == false ? AccountConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  double returnValue = CashValue(account);
  
  return Number::New(env, returnValue);
}

/* Does not work, do not know how to overload or call properly */
Value api::CommmandWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = "";
  char* account = "";
  char* instrument = "";
  char* action = "";
  int quantity = 0;
  char* ordertype = "";
  double limitprice = 0;
  double stopprice = 0;
  char* timeinforce = "";
  char* oco = "";
  char* orderid = "";
  char* strategy = "";
  char* strategyid = "";
  
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "CommandName param was not passed::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  command = getCharFromString(info[0].ToString().Utf8Value());
  if(command == "CANCELALLORDERS" || command == "FLATTENEVERYTHING") {
    int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
    cout << returnvalue;
    return Number::New(env, returnvalue);
  }
  
  if(command == "CLOSESTRATEGY") {
    
    if(info[1].IsString() == false) {
      TypeError::New(env, "Strategy ID param was not passed:CLOSESTRATEGY::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    strategyid = getCharFromString(info[1].ToString().Utf8Value());
    
    int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
    return Number::New(env, returnvalue);
  }
  
  if(command == "CLOSEPOSITION") {
    
    if(info[1].IsString() == false) {
      TypeError::New(env, "Account param was not passed:CLOSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    account = getCharFromString(info[1].ToString().Utf8Value());
    
    if(info[2].IsString() == false) {
      TypeError::New(env, "Instrument param was not passed:CLOSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    instrument = getCharFromString(info[2].ToString().Utf8Value());
    
    int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
    return Number::New(env, returnvalue);
  }
  
  if(command == "CANCEL") {

    if(info[1].IsString() == false) {
      TypeError::New(env, "Order ID param was not passed:CANCEL::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    orderid = getCharFromString(info[1].ToString().Utf8Value());
    
    if(info[2].IsString() == false) {
      int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
      return Number::New(env, returnvalue);
    }
    
    strategyid = getCharFromString(info[2].ToString().Utf8Value());
    
    int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
    return Number::New(env, returnvalue);
  }
  
  /* THE OVERLOADS FOR THESE ARE ANNOYING */
  
  return env.Undefined();
}

Value api::ConfirmOrdersWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  int param = 0;
  if (info.Length() > 0 && info[0].IsNumber()) {
      param = info[0].ToNumber().Int32Value();
  }

  int returnValue = (ConfirmOrders(param) == -1 ? 0 : 1);

  return Number::New(env, returnValue);
}

Value api::ConnectedWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  int param = 0;
  if (info.Length() > 0 && info[0].IsNumber()) {
      param = info[0].ToNumber().Int32Value();
  }

  int returnValue = (Connected(param) == -1 ? 0 : 1);

  return Number::New(env, returnValue);
}

Value api::FilledWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "OrderId param was not passed::cashValue").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* orderid = getCharFromString(info[0].ToString().Utf8Value());
  
  double returnValue = Filled(orderid);
  
  return Number::New(env, returnValue);
}

Value api::LastWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Price param was not passed::last").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  double price = info[1].ToNumber().DoubleValue();
  
  if(info[2].IsNumber() == false) {
    TypeError::New(env, "Size param was not passed::last").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int size = info[2].ToNumber().Int32Value();
  
  if(price == 0 || size == 0) {
    TypeError::New(env, "Price or Size param can not be 0::last").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int returnValue = (Last(instrument, price, size) == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::LastPlaybackWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Price param was not passed::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  double price = info[1].ToNumber().DoubleValue();
  
  if(info[2].IsNumber() == false) {
    TypeError::New(env, "Size param was not passed::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int size = info[2].ToNumber().Int32Value();
  
  if(info[3].IsString() == false) {
    TypeError::New(env, "Timestamp param was not passed::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* timestamp = getCharFromString(info[3].ToString().Utf8Value());
  
  if(price == 0 || size == 0) {
    TypeError::New(env, "Price or Size param can not be 0::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int returnValue = (LastPlayback(instrument, price, size, timestamp) == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::MarketDataWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  if(info[1].IsNumber() == false) {
    TypeError::New(env, "Type param was not passed::marketData").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  int type = info[1].ToNumber().Int32Value();
  
  double returnValue = MarketData(instrument, type);
  
  return Number::New(env, returnValue);
}

Value api::MarketPositionWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  char* account = (info[1].IsString() == false ? AccountConfig : getCharFromString(info[1].ToString().Utf8Value()));
  
  switch(MarketPosition(instrument, account)) {
    case -1: return String::New(env, "short");
    case 0: return String::New(env, "flat");
    case 1: return String::New(env, "long");
  }
  
  return env.Undefined();
}

Value api::NewOrderIdWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  string returnValue = NewOrderId();
  
  return String::New(env, returnValue);
}

Value api::OrderStatusWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "Order Id param was not passed::OrderStatus").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* orderid = getCharFromString(info[0].ToString().Utf8Value());
  
  string returnValue = OrderStatus(orderid);
  
  return String::New(env, returnValue);
}

Value api::RealizedPnLWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* account = (info[0].IsString() == false ? AccountConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  double returnValue = RealizedPnL(account);
  
  return Number::New(env, returnValue);
}

Value api::SetUpWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* host = (info[0].IsString() == false ? HostConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  int port = (info[1].IsNumber() == false ? PortConfig : info[1].ToNumber().Int32Value());
  
  int returnValue = SetUp(host, port);
  
  return Number::New(env, returnValue);
}

Value api::StopOrdersWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "Strategy ID param was not passed::stopOrders").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* strategyid = getCharFromString(info[0].ToString().Utf8Value());
  
  string returnValue = StopOrders(strategyid);
  
  return String::New(env, returnValue);
}

Value api::StrategiesWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* account = (info[0].IsString() == false ? AccountConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  string returnValue = Strategies(account);
  
  return String::New(env, returnValue);
}

Value api::StrategyPositionWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "Strategy ID param was not passed::strategyPosition").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* strategyid = getCharFromString(info[0].ToString().Utf8Value());
  
  switch(StrategyPosition(strategyid)) {
    case -1: return String::New(env, "short");
    case 0: return String::New(env, "flat");
    case 1: return String::New(env, "long");
  }
  
  return env.Undefined();
}

Value api::SubscribeMarketDataWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  int returnvalue = (SubscribeMarketData(instrument) == -1 ? 0 : 1);
  
  return Number::New(env, returnvalue);
}

Value api::TargetOrdersWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "Strategy ID param was not passed::targetOrders").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  char* strategyid = getCharFromString(info[0].ToString().Utf8Value());
  
  string returnvalue = TargetOrders(strategyid);
  
  return String::New(env, returnvalue);
}

Value api::TearDownWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  int returnValue = (TearDown() == -1 ? 0 : 1);
  
  return Number::New(env, returnValue);
}

Value api::UnsubscribeMarketDataWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* instrument = (info[0].IsString() == false ? InstrumentConfig : getCharFromString(info[0].ToString().Utf8Value()));
  
  int returnvalue = (UnsubscribeMarketData(instrument) == -1 ? 0 : 1);
  
  return Number::New(env, returnvalue);
}

Value api::Config(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  if(info[0].IsObject() == false) {
    TypeError::New(env, "config param was not passed::config").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  Object config = info[0].ToObject();
  
  if(config.Has("host")) {
    HostConfig = getCharFromString(config.Get("host").ToString().Utf8Value());
  }
  
  if(config.Has("port")) {
    PortConfig = config.Get("port").ToNumber().Int32Value();
  }
  
  if(config.Has("account")) {
    AccountConfig = getCharFromString(config.Get("account").ToString().Utf8Value());
  }
  
  if(config.Has("instrument")) {
    InstrumentConfig = getCharFromString(config.Get("instrument").ToString().Utf8Value());
  }
    
  return env.Undefined();
}

Value api::Host(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if(info[0].IsString() != false) HostConfig = getCharFromString(info[0].ToString().Utf8Value());
  return String::New(env, HostConfig);
}

Value api::Port(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if(info[0].IsNumber() != false) PortConfig = info[0].ToNumber().Int32Value();
  return Number::New(env, PortConfig);
}

Value api::Account(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if(info[0].IsString() != false) AccountConfig = getCharFromString(info[0].ToString().Utf8Value());
  return String::New(env, AccountConfig);
}

Value api::Instrument(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  if(info[0].IsString() != false) InstrumentConfig = getCharFromString(info[0].ToString().Utf8Value());
  return String::New(env, InstrumentConfig);
}

Object api::Init(Env env, Object exports)
{
  exports.Set("ask", Function::New(env, api::AskWrapper));
  exports.Set("askPlayback", Function::New(env, api::AskPlaybackWrapper));
  exports.Set("avgEntryPrice", Function::New(env, api::AvgEntryPriceWrapper));
  exports.Set("avgFillPrice", Function::New(env, api::AvgFillPriceWrapper));
  exports.Set("bid", Function::New(env, api::BidWrapper));
  exports.Set("bidPlayback", Function::New(env, api::BidPlaybackWrapper));
  exports.Set("buyingPower", Function::New(env, api::BuyingPowerWrapper));
  exports.Set("cashValue", Function::New(env, api::CashValueWrapper));
  /* Does not work, do not know how to overload or call properly */
  // exports.Set("command", Function::New(env, api::CommmandWrapper));
  exports.Set("confirmOrders", Function::New(env, api::ConfirmOrdersWrapper));
  exports.Set("connected", Function::New(env, api::ConnectedWrapper));
  exports.Set("filled", Function::New(env, api::FilledWrapper));
  exports.Set("last", Function::New(env, api::LastWrapper));
  exports.Set("lastPlayback", Function::New(env, api::LastPlaybackWrapper));
  exports.Set("marketData", Function::New(env, api::MarketDataWrapper));
  exports.Set("marketPosition", Function::New(env, api::MarketPositionWrapper));
  exports.Set("getNewOrderId", Function::New(env, api::NewOrderIdWrapper));
  exports.Set("orderStatus", Function::New(env, api::OrderStatusWrapper));
  exports.Set("realizedPnL", Function::New(env, api::RealizedPnLWrapper));
  exports.Set("setUp", Function::New(env, api::SetUpWrapper));
  exports.Set("stopOrders", Function::New(env, api::StopOrdersWrapper));
  exports.Set("strategies", Function::New(env, api::StrategiesWrapper));
  exports.Set("strategyPosition", Function::New(env, api::StrategyPositionWrapper));
  exports.Set("subscribeMarketData", Function::New(env, api::SubscribeMarketDataWrapper));
  exports.Set("targetOrders", Function::New(env, api::TargetOrdersWrapper));
  exports.Set("teardown", Function::New(env, api::TearDownWrapper));
  exports.Set("unsubscribeMarketData", Function::New(env, api::UnsubscribeMarketDataWrapper));
  exports.Set("config", Function::New(env, api::Config));
  exports.Set("host", Function::New(env, api::Host));
  exports.Set("port", Function::New(env, api::Port));
  exports.Set("account", Function::New(env, api::Account));
  exports.Set("instrument", Function::New(env, api::Instrument));
  return exports;
}