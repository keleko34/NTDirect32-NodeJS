#include "api.h"

Napi::Object Initialize(Napi::Env env, Napi::Object exports) {
	return api::Init(env, exports);
}

NODE_API_MODULE(NTDirect32, Initialize)