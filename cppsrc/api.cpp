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
  size_t len = info.Length();
  
  char* instrument = (len == 3 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  double price = 0;
  int size = 0;
  
  if(len == 2) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      price = info[0].ToNumber().DoubleValue();
    }
    else {
      TypeError::New(env, "Price param was not passed::ask").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[1].IsNumber() != false || info[1].IsString() != false) {
      size = info[1].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Size param was not passed::ask").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    price = info[1].ToNumber().DoubleValue();
  }
  else {
    TypeError::New(env, "Price param was not passed::ask").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  if(info[2].IsNumber() != false || info[2].IsString() != false) {
    size = info[2].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Size param was not passed::ask").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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
  size_t len = info.Length();
  
  char* instrument = (len == 4 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  double price = 0;
  int size = 0;
  char* timestamp = "";
  
  if(len == 3) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      price = info[0].ToNumber().DoubleValue();
    }
    else {
      TypeError::New(env, "Price param was not passed::askPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[1].IsNumber() != false || info[1].IsString() != false) {
      size = info[1].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Size param was not passed::askPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[2].IsString() != false) {
      timestamp = getCharFromString(info[2].ToString().Utf8Value());
    }
    else {
      TypeError::New(env, "Timestamp param was not passed::askPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    price = info[1].ToNumber().DoubleValue();
  }
  else {
    TypeError::New(env, "Price param was not passed::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if(info[2].IsNumber() != false || info[2].IsString() != false) {
    size = info[2].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Size param was not passed::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if(info[3].IsString() != false) {
    timestamp = getCharFromString(info[3].ToString().Utf8Value());
  }
  else {
    TypeError::New(env, "Timestamp param was not passed::askPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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
  size_t len = info.Length();
  
  char* instrument = (len == 3 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  double price = 0;
  int size = 0;
  
  if(len == 2) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      price = info[0].ToNumber().DoubleValue();
    }
    else {
      TypeError::New(env, "Price param was not passed::bid").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[1].IsNumber() != false || info[1].IsString() != false) {
      size = info[1].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Size param was not passed::bid").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    price = info[1].ToNumber().DoubleValue();
  }
  else {
    TypeError::New(env, "Price param was not passed::bid").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  if(info[2].IsNumber() != false || info[2].IsString() != false) {
    size = info[2].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Size param was not passed::bid").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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
  size_t len = info.Length();
  
  char* instrument = (len == 4 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  double price = 0;
  int size = 0;
  char* timestamp = "";
  
  if(len == 3) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      price = info[0].ToNumber().DoubleValue();
    }
    else {
      TypeError::New(env, "Price param was not passed::bidPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[1].IsNumber() != false || info[1].IsString() != false) {
      size = info[1].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Size param was not passed::bidPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[2].IsString() != false) {
      timestamp = getCharFromString(info[2].ToString().Utf8Value());
    }
    else {
      TypeError::New(env, "Timestamp param was not passed::bidPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    price = info[1].ToNumber().DoubleValue();
  }
  else {
    TypeError::New(env, "Price param was not passed::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if(info[2].IsNumber() != false || info[2].IsString() != false) {
    size = info[2].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Size param was not passed::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if(info[3].IsString() != false) {
    timestamp = getCharFromString(info[3].ToString().Utf8Value());
  }
  else {
    TypeError::New(env, "Timestamp param was not passed::bidPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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

Value api::CommmandCANCELLALLORDERSWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = NULL;
  char* account = NULL;
  char* instrument = NULL;
  char* action = NULL;
  int quantity = NULL;
  char* ordertype = NULL;
  double limitprice = NULL;
  double stopprice = NULL;
  char* timeinforce = NULL;
  char* oco = NULL;
  char* orderid = NULL;
  char* strategy = NULL;
  char* strategyid = NULL;
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "CommandName param was not passed:CANCELALLORDERS|FLATTENEVERYTHING::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  command = getCharFromString(info[0].ToString().Utf8Value());
  
  string cmd = info[0].ToString().Utf8Value();
  
  if(cmd == "CANCELALLORDERS" || cmd == "FLATTENEVERYTHING") {
    int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
    return Number::New(env, returnvalue);
  }
  else {
    TypeError::New(env, "CommandName param was not passed:CANCELALLORDERS|FLATTENEVERYTHING::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }
}

Value api::CommmandCLOSESTRATEGYWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = "CLOSESTRATEGY";
  char* account = NULL;
  char* instrument = NULL;
  char* action = NULL;
  int quantity = NULL;
  char* ordertype = NULL;
  double limitprice = NULL;
  double stopprice = NULL;
  char* timeinforce = NULL;
  char* oco = NULL;
  char* orderid = NULL;
  char* strategy = NULL;
  char* strategyid = NULL;
  
  /* REQUIRED */
  if(info[0].IsString() == false) {
    TypeError::New(env, "Strategy ID param was not passed:CLOSESTRATEGY::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  strategyid = getCharFromString(info[0].ToString().Utf8Value());

  int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
  return Number::New(env, returnvalue);
}

Value api::CommmandCLOSEPOSITIONWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = "CLOSEPOSITION";
  char* account = NULL;
  char* instrument = NULL;
  char* action = NULL;
  int quantity = NULL;
  char* ordertype = NULL;
  double limitprice = NULL;
  double stopprice = NULL;
  char* timeinforce = NULL;
  char* oco = NULL;
  char* orderid = NULL;
  char* strategy = NULL;
  char* strategyid = NULL;
  
  /* REQUIRED */
  account = (info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : AccountConfig);

  instrument = (info[1].IsString() != false ? getCharFromString(info[1].ToString().Utf8Value()) : InstrumentConfig);

  int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
  return Number::New(env, returnvalue);
}

Value api::CommmandCANCELWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = "CANCEL";
  char* account = NULL;
  char* instrument = NULL;
  char* action = NULL;
  int quantity = NULL;
  char* ordertype = NULL;
  double limitprice = NULL;
  double stopprice = NULL;
  char* timeinforce = NULL;
  char* oco = NULL;
  char* orderid = NULL;
  char* strategy = NULL;
  char* strategyid = NULL;
  
  /* REQUIRED */
  if(info[0].IsString() == false) {
    TypeError::New(env, "Order ID param was not passed:CANCEL::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  orderid = getCharFromString(info[0].ToString().Utf8Value());

  /* OPTIONAL */
  if(info[1].IsString() != false) {
    strategyid = getCharFromString(info[2].ToString().Utf8Value());
  }
  
  int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
  return Number::New(env, returnvalue);
}

Value api::CommmandCHANGEWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = "CHANGE";
  char* account = NULL;
  char* instrument = NULL;
  char* action = NULL;
  int quantity = NULL;
  char* ordertype = NULL;
  double limitprice = NULL;
  double stopprice = NULL;
  char* timeinforce = NULL;
  char* oco = NULL;
  char* orderid = NULL;
  char* strategy = NULL;
  char* strategyid = NULL;
  
  /* REQUIRED */
  if(info[0].IsString() == false) {
    TypeError::New(env, "Order ID param was not passed:CHANGE::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  orderid = getCharFromString(info[0].ToString().Utf8Value());

  /* OPTIONAL */
  if(info[1].IsString() != false || info[1].IsNumber() != false) {
    quantity =  info[1].ToNumber().Int32Value();
  }

  if(info[2].IsString() != false || info[2].IsNumber() != false) {
    limitprice = info[2].ToNumber().DoubleValue();
  }

  if(info[3].IsString() != false || info[3].IsNumber() != false) {
    stopprice = info[3].ToNumber().DoubleValue();
  }

  if(info[4].IsString() != false) {
    strategyid = getCharFromString(info[4].ToString().Utf8Value());
  }

  int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
  return Number::New(env, returnvalue);
}

Value api::CommmandPLACEWrapper(const CallbackInfo& info)
{
  Napi::Env env = info.Env();
  
  char* command = NULL;
  char* account = NULL;
  char* instrument = NULL;
  char* action = NULL;
  int quantity = NULL;
  char* ordertype = NULL;
  double limitprice = NULL;
  double stopprice = NULL;
  char* timeinforce = NULL;
  char* oco = NULL;
  char* orderid = NULL;
  char* strategy = NULL;
  char* strategyid = NULL;
  
  if(info[0].IsString() == false) {
    TypeError::New(env, "CommandName param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  command = getCharFromString(info[0].ToString().Utf8Value());
  
  string cmd = info[0].ToString().Utf8Value();
  
  if(cmd == "PLACE" || cmd == "REVERSEPOSITION") {
    /* REQUIRED */
    if(info[1].IsString() == false) {
      TypeError::New(env, "Account param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    account = getCharFromString(info[1].ToString().Utf8Value());
    
    if(info[2].IsString() == false) {
      TypeError::New(env, "Instrument param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    instrument = getCharFromString(info[2].ToString().Utf8Value());
    
    if(info[3].IsString() == false) {
      TypeError::New(env, "Action param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    action = getCharFromString(info[3].ToString().Utf8Value());
    
    if(info[4].IsString() != false || info[4].IsNumber() != false) {
      quantity = info[4].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Qty param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[5].IsString() == false) {
      TypeError::New(env, "Order type param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    ordertype = getCharFromString(info[5].ToString().Utf8Value());
    
    if(info[6].IsString() == false) {
      TypeError::New(env, "TIF param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    timeinforce = getCharFromString(info[6].ToString().Utf8Value());
    
    /* OPTIONAL */
    if(info[7].IsString() != false || info[2].IsNumber() != false) {
      limitprice = info[7].ToNumber().DoubleValue();
    }
    
    if(info[8].IsString() != false || info[2].IsNumber() != false) {
      stopprice = info[8].ToNumber().DoubleValue();
    }
    
    if(info[9].IsString() != false) {
      oco = getCharFromString(info[9].ToString().Utf8Value());
    }
    
    if(info[10].IsString() != false) {
      orderid = getCharFromString(info[10].ToString().Utf8Value());
    }
    
    if(info[11].IsString() != false) {
      strategy = getCharFromString(info[11].ToString().Utf8Value());
    }
    
    if(info[12].IsString() != false) {
      strategyid = getCharFromString(info[12].ToString().Utf8Value());
    }
    
    int returnvalue = (Command(command, account, instrument, action, quantity, ordertype, limitprice, stopprice, timeinforce, oco, orderid, strategy, strategyid) == -1 ? 0 : 1);
    return Number::New(env, returnvalue);
  }
  else {
    TypeError::New(env, "CommandName param was not passed:PLACE|REVERSEPOSITION::command").ThrowAsJavaScriptException();
    return env.Undefined();
  }
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
  size_t len = info.Length();
  
  char* instrument = (len == 3 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  double price = 0;
  int size = 0;
  
  if(len == 2) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      price = info[0].ToNumber().DoubleValue();
    }
    else {
      TypeError::New(env, "Price param was not passed::last").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[1].IsNumber() != false || info[1].IsString() != false) {
      size = info[1].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Size param was not passed::last").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    price = info[1].ToNumber().DoubleValue();
  }
  else {
    TypeError::New(env, "Price param was not passed::last").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
  if(info[2].IsNumber() != false || info[2].IsString() != false) {
    size = info[2].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Size param was not passed::last").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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
  size_t len = info.Length();
  
  char* instrument = (len == 4 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  double price = 0;
  int size = 0;
  char* timestamp = "";
  
  if(len == 3) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      price = info[0].ToNumber().DoubleValue();
    }
    else {
      TypeError::New(env, "Price param was not passed::lastPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[1].IsNumber() != false || info[1].IsString() != false) {
      size = info[1].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Size param was not passed::lastPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
    
    if(info[2].IsString() != false) {
      timestamp = getCharFromString(info[2].ToString().Utf8Value());
    }
    else {
      TypeError::New(env, "Timestamp param was not passed::lastPlayback").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    price = info[1].ToNumber().DoubleValue();
  }
  else {
    TypeError::New(env, "Price param was not passed::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if(info[2].IsNumber() != false || info[2].IsString() != false) {
    size = info[2].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Size param was not passed::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }

  if(info[3].IsString() != false) {
    timestamp = getCharFromString(info[3].ToString().Utf8Value());
  }
  else {
    TypeError::New(env, "Timestamp param was not passed::lastPlayback").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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
  size_t len = info.Length();
  
  char* instrument = (len == 2 && info[0].IsString() != false ? getCharFromString(info[0].ToString().Utf8Value()) : InstrumentConfig);
  int type = 0;
  
  if(len == 1) {
    if(info[0].IsNumber() != false || info[0].IsString() != false) {
      type = info[0].ToNumber().Int32Value();
    }
    else {
      TypeError::New(env, "Type param was not passed::marketData").ThrowAsJavaScriptException();
      return env.Undefined();
    }
  }
  
  if(info[1].IsNumber() != false || info[1].IsString() != false) {
    type = info[1].ToNumber().Int32Value();
  }
  else {
    TypeError::New(env, "Type param was not passed::marketData").ThrowAsJavaScriptException();
    return env.Undefined();
  }
  
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
  exports.Set("cancelAllOrders", Function::New(env, api::CommmandCANCELLALLORDERSWrapper));
  exports.Set("flattenEverything", Function::New(env, api::CommmandCANCELLALLORDERSWrapper));
  exports.Set("closeStrategy", Function::New(env, api::CommmandCLOSESTRATEGYWrapper));
  exports.Set("closePosition", Function::New(env, api::CommmandCLOSEPOSITIONWrapper));
  exports.Set("cancelOrder", Function::New(env, api::CommmandCANCELWrapper));
  exports.Set("changeOrder", Function::New(env, api::CommmandCHANGEWrapper));
  exports.Set("placeBuyOrder", Function::New(env, api::CommmandPLACEWrapper));
  exports.Set("placeSellOrder", Function::New(env, api::CommmandPLACEWrapper));
  exports.Set("reverseBuyPosition", Function::New(env, api::CommmandPLACEWrapper));
  exports.Set("reverseSellPosition", Function::New(env, api::CommmandPLACEWrapper));
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
  exports.Set("tearDown", Function::New(env, api::TearDownWrapper));
  exports.Set("unsubscribeMarketData", Function::New(env, api::UnsubscribeMarketDataWrapper));
  exports.Set("config", Function::New(env, api::Config));
  exports.Set("host", Function::New(env, api::Host));
  exports.Set("port", Function::New(env, api::Port));
  exports.Set("account", Function::New(env, api::Account));
  exports.Set("instrument", Function::New(env, api::Instrument));
  return exports;
}