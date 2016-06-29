#pragma once
#include "Participant.h"

class GlassCannon :	public Participant
{
public:
	GlassCannon();
	virtual ~GlassCannon();

	virtual int Attack();
};

