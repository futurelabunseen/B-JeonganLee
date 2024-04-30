// Fill out your copyright notice in the Description page of Project Settings.


#include "person.h"
#include "Card.h"

Uperson::Uperson()
{
	Name = TEXT("이정안");
	Card = CreateDefaultSubobject<UCard>(TEXT("NAME_Card"));
}
