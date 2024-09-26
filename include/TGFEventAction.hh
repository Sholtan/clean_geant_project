#ifndef TGFEventAction_HH
#define TGFEventAction_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"

#include "TGFRunAction.hh"



class TGFEventAction : public G4UserEventAction
{
public:
	TGFEventAction(TGFRunAction*);
	~TGFEventAction();


	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);


private:
};

#endif


