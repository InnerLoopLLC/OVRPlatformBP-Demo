// Copyright 2021 InnerLoop LLC

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OVRPLATFORMBPDEMO_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// Returns the date from Unix time (seconds from midnight 1970-01-01)
	UFUNCTION(BlueprintPure, Category = "Your Project")
		static FDateTime FromUnixTimestamp(const int64 UnixTimestamp);
};
