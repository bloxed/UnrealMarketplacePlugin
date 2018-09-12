//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabEventsAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::EventsModels;

UPlayFabEventsAPI::UPlayFabEventsAPI() {}

UPlayFabEventsAPI::~UPlayFabEventsAPI() {}

int UPlayFabEventsAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

FString UPlayFabEventsAPI::GetBuildIdentifier() const
{
    return PlayFabSettings::buildIdentifier;
}

void UPlayFabEventsAPI::SetTitleId(const FString& titleId)
{
	PlayFabSettings::SetTitleId(titleId);
}

void UPlayFabEventsAPI::SetDevSecretKey(const FString& developerSecretKey)
{
    PlayFabSettings::SetDeveloperSecretKey(developerSecretKey);
}

bool UPlayFabEventsAPI::WriteEvents(
    EventsModels::FWriteEventsRequest& request,
    const FWriteEventsDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if (PlayFabSettings::GetEntityToken().Len() == 0) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }
    auto HttpRequest = PlayFabRequestHandler::SendRequest(PlayFabSettings::GetUrl(TEXT("/Event/WriteEvents")), request.toJSONString(), TEXT("X-EntityToken"), PlayFabSettings::GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabEventsAPI::OnWriteEventsResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabEventsAPI::OnWriteEventsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FWriteEventsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    EventsModels::FWriteEventsResponse outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}

