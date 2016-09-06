using UnityEngine;
using System.Collections;

public class Cube : MonoBehaviour {

    public int maxHealth = 200;
    private int currentHealth;
    private float maxMass;

    private Rigidbody objRef = null;

	// Use this for initialization
	void Start ()
    {
        currentHealth = maxHealth;
        objRef = gameObject.GetComponent<Rigidbody>();
        maxMass = objRef.mass;
	}
	
    void OnCollisionEnter(Collision collision)
    {
        if(collision.collider.tag == "Bullet")
        {
            currentHealth -= collision.gameObject.GetComponent<Bullet>().damage;
        }
    }

	// Update is called once per frame
	void Update ()
    {
	    if(objRef != null && currentHealth < maxHealth)
        {
            objRef.mass = maxMass * ((float)currentHealth / (float)maxHealth);
        }
	}
}
