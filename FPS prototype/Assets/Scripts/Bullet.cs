using UnityEngine;
using System.Collections;

public class Bullet : MonoBehaviour {

    public int damage = 5;

	// Use this for initialization
	void Start ()
    {
	
	}
	
    void OnCollisionEnter()
    {
        gameObject.SetActive(false);
    }

	// Update is called once per frame
	void Update ()
    {
	
	}
}
