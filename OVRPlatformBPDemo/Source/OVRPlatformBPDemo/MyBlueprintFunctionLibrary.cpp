// Copyright 2021 InnerLoop LLC


#include "MyBlueprintFunctionLibrary.h"

FDateTime UMyBlueprintFunctionLibrary::FromUnixTimestamp(const int64 UnixTimestamp)
{
	return FDateTime::FromUnixTimestamp(UnixTimestamp);
}
