
#include "IBehaviour.h"
class Wander :
	public IBehaviour
{
public:
	Wander();
	~Wander();

	virtual void update(Agent* agent, float dt);

	void setAngle(Vector3& displacement, float angleInDeg);

	Vector3 wander(Agent* agent);

private:
	float radius;
	float jitter;
	float distance;


};
