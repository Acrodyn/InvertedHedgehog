#pragma once

#define IH_MODULE(Type, Name) \
private: Type* Name##Module;\
private: IH_API const Type* Get##Name##Module() { return Name##Module; }; \
public: IH_API static const Type* Get##Name() { return IH_Engine::Get()->Get##Name##Module(); };

#define REGISTER_MODULE(Type, Name) \
Name##Module = new Type(); \
RegisterModule(Name##Module);

#define CTXT(Char) \
std::string(Char)

#define DTXT(Num) \
std::to_string(Num)

#define IH_PTR_CHECK_VOID(Ptr) \
if (!Ptr) return;

#define IH_PTR_CHECK_RETURN(Ptr, ReturnValue) \
if (!Ptr) return ReturnValue;