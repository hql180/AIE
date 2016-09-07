using UnityEngine;
using System.Collections;

public class Bullet : MonoBehaviour {

    public int damage = 5;

    private float maxLifeTime = 5;

    public float lifeTime;

	// Use this for initialization
	void Start ()
    {
        lifeTime = maxLifeTime;
	}
	
    void OnCollisionEnter()
    {
        gameObject.SetActive(false);
    }

    public void ResetLifeTime()
    {
        lifeTime = maxLifeTime;
    }

	// Update is called once per frame
	void Update ()
    {
        if(gameObject.activeSelf)
            lifeTime -= Time.deltaTime;
            if (lifeTime <= 0)
                gameObject.SetActive(false);
	}
}
