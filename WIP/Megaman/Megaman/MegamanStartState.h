#pragma once
#include "MegamanState.h"
#include "MegamanStandingState.h"

class MegamanStartState : public MegamanState
{
private:
	int nFrame;
	int counter = 0;

public:
	MegamanStartState(MegamanData * );
	~MegamanStartState();

	void onUpdate();
	
};

