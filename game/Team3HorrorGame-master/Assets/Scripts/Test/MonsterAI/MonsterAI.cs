using UnityEngine;
using System.Collections;

public class MonsterAI : MonoBehaviour
{
    public Transform target;

    NavMeshAgent agent;

    public float radius = 5;
    public float jitter = 10;
    public float distance = 10;
    public Vector3 displacement = new Vector3(Random.Range(-10, 10), 
                                                0, 
                                                Random.Range(-10, 10)).normalized;

    public float visionRange = 5;
    [Tooltip("Field of view in degrees")]
    public float FOV = 90;

    private SphereCollider head;
    private float huntTimer = 0;
   

    // Use this for initialization
    void Start ()
    {
        agent = GetComponent<NavMeshAgent>();
        head = GetComponentInChildren<SphereCollider>();
        // Converting FOV from deg to rad
        FOV /= 2; // needs to be halved due to how the angle will be calculated
        FOV = FOV / 180 * Mathf.PI; // formula for rad to deg conversion

	}
	
	// Update is called once per frame
	void Update ()
    {
        //RaycastHit[] hit = Physics.SphereCastAll(head.transform.position, head.radius, target.position - head.transform.position, visionRange);

        //foreach (RaycastHit ray in hit)
        //{
        //    if(ray.collider.tag == "Player")
        //        Debug.Log("Player found !");
        //}
        


            RaycastHit hit;

        if (Physics.SphereCast(head.transform.position, head.radius, target.position - head.transform.position, out hit, visionRange))
            if (hit.collider.tag == "Player")
            {
                // Finding angle between monster's forward facing direction and player
                if (Mathf.Acos(Vector3.Dot(head.transform.forward.normalized, target.transform.position.normalized)) < FOV)
                {
                    agent.SetDestination(target.position);
                    huntTimer = .5f;
                    Debug.Log("Chasing Player");
                }                
            }

        if (huntTimer <= 0)
            wander();
        else
            huntTimer -= Time.deltaTime;

        Debug.Log(head.transform.position);
    }

    public void wander()
    {
        displacement = displacement + new Vector3(Random.Range(-10, 10), 0, Random.Range(-10, 10)).normalized * jitter;

        displacement = displacement.normalized * radius;

        Vector3 target = new Vector3(agent.transform.forward.x, agent.transform.forward.y, agent.transform.forward.z) * distance + displacement;

        agent.SetDestination(target);

        

        //Debug.Log(target);
    }
}
