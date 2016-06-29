
#include "IBehaviour.h"
class Wander :
	public IBehaviour
{
public:
	Wander();
	~Wander();

	virtual void update(Agent* agent, float dt);

private:
	float radius;
	float jitter;
	float distance;
	float decisionTime;
};
