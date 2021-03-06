//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabCppBaseModel.h"

namespace PlayFab
{
namespace LocalizationModels
{

    struct PLAYFABCPP_API FGetLanguageListRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        FGetLanguageListRequest() :
            FPlayFabCppRequestCommon()
            {}

        FGetLanguageListRequest(const FGetLanguageListRequest& src) :
            FPlayFabCppRequestCommon()
            {}

        FGetLanguageListRequest(const TSharedPtr<FJsonObject>& obj) : FGetLanguageListRequest()
        {
            readFromValue(obj);
        }

        ~FGetLanguageListRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FGetLanguageListResponse : public PlayFab::FPlayFabCppResultCommon
    {
        // [optional] The list of allowed languages, in BCP47 two-letter format
        TArray<FString> LanguageList;
        FGetLanguageListResponse() :
            FPlayFabCppResultCommon(),
            LanguageList()
            {}

        FGetLanguageListResponse(const FGetLanguageListResponse& src) :
            FPlayFabCppResultCommon(),
            LanguageList(src.LanguageList)
            {}

        FGetLanguageListResponse(const TSharedPtr<FJsonObject>& obj) : FGetLanguageListResponse()
        {
            readFromValue(obj);
        }

        ~FGetLanguageListResponse();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

}
}
