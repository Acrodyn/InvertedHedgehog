#pragma once

#define IH_MODULE(Type, Name) \
private: Type* Name##Module;\
private: const Type* Get##Name##Module() { return Name##Module; }; \
public: static const Type* Get##Name() { return IH_Engine::Get()->Get##Name##Module(); };

#define CTXT(Char) \
std::string(Char)

#define DTXT(Num) \
std::to_string(Num)