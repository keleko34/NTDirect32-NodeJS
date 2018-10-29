#include <napi.h>

namespace api {
    Napi::Value AskWrapper(const Napi::CallbackInfo& info);
    Napi::Value AskPlaybackWrapper(const Napi::CallbackInfo& info);
    Napi::Value AvgEntryPriceWrapper(const Napi::CallbackInfo& info);
    Napi::Value AvgFillPriceWrapper(const Napi::CallbackInfo& info);
    Napi::Value BidWrapper(const Napi::CallbackInfo& info);
    Napi::Value BidPlaybackWrapper(const Napi::CallbackInfo& info);
    Napi::Value BuyingPowerWrapper(const Napi::CallbackInfo& info);
    Napi::Value CashValueWrapper(const Napi::CallbackInfo& info);
    Napi::Value CommmandCANCELLALLORDERSWrapper(const Napi::CallbackInfo& info);
    Napi::Value CommmandCLOSESTRATEGYWrapper(const Napi::CallbackInfo& info);
    Napi::Value CommmandCLOSEPOSITIONWrapper(const Napi::CallbackInfo& info);
    Napi::Value CommmandCANCELWrapper(const Napi::CallbackInfo& info);
    Napi::Value CommmandCHANGEWrapper(const Napi::CallbackInfo& info);
    Napi::Value CommmandPLACEWrapper(const Napi::CallbackInfo& info);
    Napi::Value ConfirmOrdersWrapper(const Napi::CallbackInfo& info);
	Napi::Value ConnectedWrapper(const Napi::CallbackInfo& info);
    Napi::Value FilledWrapper(const Napi::CallbackInfo& info);
    Napi::Value LastWrapper(const Napi::CallbackInfo& info);
    Napi::Value LastPlaybackWrapper(const Napi::CallbackInfo& info);
    Napi::Value MarketDataWrapper(const Napi::CallbackInfo& info);
    Napi::Value MarketPositionWrapper(const Napi::CallbackInfo& info);
    Napi::Value NewOrderIdWrapper(const Napi::CallbackInfo& info);
    Napi::Value OrderStatusWrapper(const Napi::CallbackInfo& info);
    Napi::Value RealizedPnLWrapper(const Napi::CallbackInfo& info);
    Napi::Value SetUpWrapper(const Napi::CallbackInfo& info);
    Napi::Value StopOrdersWrapper(const Napi::CallbackInfo& info);
    Napi::Value StrategiesWrapper(const Napi::CallbackInfo& info);
    Napi::Value StrategyPositionWrapper(const Napi::CallbackInfo& info);
    Napi::Value SubscribeMarketDataWrapper(const Napi::CallbackInfo& info);
    Napi::Value TargetOrdersWrapper(const Napi::CallbackInfo& info);
    Napi::Value TearDownWrapper(const Napi::CallbackInfo& info);
    Napi::Value UnsubscribeMarketDataWrapper(const Napi::CallbackInfo& info);
    Napi::Value Config(const Napi::CallbackInfo& info);
    Napi::Value Host(const Napi::CallbackInfo& info);
    Napi::Value Port(const Napi::CallbackInfo& info);
    Napi::Value Account(const Napi::CallbackInfo& info);
    Napi::Value Instrument(const Napi::CallbackInfo& info);
	Napi::Object Init(Napi::Env env, Napi::Object exports);
}