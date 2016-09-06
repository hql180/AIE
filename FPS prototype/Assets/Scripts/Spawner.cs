using UnityEngine;
using System.Collections.Generic;
using System.Collections;

public class Spawner : MonoBehaviour
{

    public Transform prefab;

    public int length = 10;

    private Transform[] pool;

	// Use this for initialization
	void Start ()
    {
        pool = new Transform[length];
        for(int i = 0; i < length; ++i)
        {
            Transform thing = Instantiate(prefab);
            pool[i] = thing;
            thing.gameObject.SetActive(false);
            thing.hideFlags = HideFlags.HideInHierarchy;
        }
	}

	// Update is called once per frame
	void Update ()
    {
        Debug.Log("Updating");
	    if(Input.GetButtonDown("Jump"))
        {
            Debug.Log("Jumping");
            Transform thing = null;
            for (int i = 0; i < pool.Length; ++i)
            {
                Debug.Log("Looping");
                if (!pool[i].gameObject.activeSelf)
                {                                    
                    thing = pool[i];
                    pool[i].gameObject.SetActive(true);
                    Debug.Log("Activating");
                    break;
                }
            }

            if (thing != null)
            {
                Debug.Log("Positioning");
                thing.position = transform.position;
                thing.rotation = transform.rotation;
                
            }        

        }
	}
}
