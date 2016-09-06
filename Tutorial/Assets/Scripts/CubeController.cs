﻿using UnityEngine;
using System.Collections;

public class CubeController : MonoBehaviour {

    public float maxTorque = 100;
    private Rigidbody m_rigidbody;

	// Use this for initialization
	void Start ()
    {
        m_rigidbody = GetComponent<Rigidbody>();
	}
	
	// Update is called once per frame
	void Update ()
    {
        float movementX = Input.GetAxis("Horizontal");
        float movementZ = Input.GetAxis("Vertical");

        m_rigidbody.AddTorque(movementX * 100, 0, movementZ * 100);
	}
}
