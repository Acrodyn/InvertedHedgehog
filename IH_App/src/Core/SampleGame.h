#include "IH_Engine/Core/IH_Application.h"

class SampleGame : public IH_Application
{
protected:
	void Init()	override;
	void Update() override;
	void End()	override;
};