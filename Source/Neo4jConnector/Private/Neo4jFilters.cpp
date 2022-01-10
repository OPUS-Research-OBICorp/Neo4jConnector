// Fill out your copyright notice in the Description page of Project Settings.


// Fill out your copyright notice in the Description page of Project Settings.


#include "Neo4jFilters.h"

//TODO: add safeguards for empty nodes
int UNeo4jFilters::FilterIntProperty(FNeo4jNode inNode, FString property)
{

	
	if(inNode.properties.Contains(property))
	{
		return inNode.properties.Find(property)->ToSharedRef()->AsNumber();
	}

	UE_LOG(LogTemp,Error,TEXT("Error trying to access integer property: %s"),*property)
	return -1;

}

FString UNeo4jFilters::FilterStringProperty(FNeo4jNode inNode, FString property)
{
	if(inNode.properties.Contains(property))
	{
		return inNode.properties.Find(property)->ToSharedRef()->AsString();
		
	}
	
	UE_LOG(LogTemp,Error,TEXT("Error trying to access string property: %s"),*property)
	return "null";
}

bool UNeo4jFilters::FilterBoolProperty(FNeo4jNode inNode, FString property)
{
	if(inNode.properties.Contains(property))
	{
		return inNode.properties.Find(property)->ToSharedRef()->AsBool();
	}
	
	
	UE_LOG(LogTemp,Error,TEXT("Error trying to access bool property: %s"),*property)
	return false;
	
}

float UNeo4jFilters::FilterFloatProperty(FNeo4jNode inNode, FString property)
{
	if(inNode.properties.Contains(property))
		return inNode.properties.Find(property)->ToSharedRef()->AsNumber();
	
	UE_LOG(LogTemp,Error,TEXT("Error trying to access float property: %s"),*property)
	return -1.0f;
}

