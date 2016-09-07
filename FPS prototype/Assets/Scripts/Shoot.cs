using UnityEngine;
using System.Collections;
using InControl;

public class Shoot : MonoBehaviour
{
    InputDevice device;

    public Rigidbody projectile;
    public float bulletSpeed = 100f;
    public int bulletCapacity = 20;
    public float fireRate = .1f;

    private Rigidbody[] projectilePool;
    private float fireTiming = 0;


	// Use this for initialization
	void Start ()
    {
        device = InputManager.ActiveDevice;

        projectilePool = new Rigidbody[bulletCapacity];
        for(int i = 0; i < projectilePool.Length; ++i)
        {
            Rigidbody bullet = Instantiate(projectile) as Rigidbody;
            bullet.gameObject.SetActive(false);
            bullet.hideFlags = HideFlags.HideInHierarchy;
            Physics.IgnoreCollision(bullet.GetComponent<Collider>(), transform.parent.parent.GetComponent<Collider>());
            projectilePool[i] = bullet;
        }
	}

    IEnumerator Despawn(Rigidbody bullet, float time)
    {
        yield return new WaitForSeconds(time);
        bullet.gameObject.SetActive(false);
    }

	// Update is called once per frame
	void Update ()
    {
        fireTiming -= Time.deltaTime;
        if ((device.RightTrigger.IsPressed || Input.GetMouseButton(0) ) && fireTiming <= 0)
        {
            fireTiming = fireRate;
            Rigidbody bullet = null;

            for(int i = 0; i < projectilePool.Length; ++i)
            {
                if(!projectilePool[i].gameObject.activeSelf)
                {
                    //StartCoroutine(Despawn(projectilePool[i], 5));
                    bullet = projectilePool[i];
                    projectilePool[i].gameObject.SetActive(true);
                    break;
                }
            }

            if(bullet != null)
            {
                bullet.position = transform.position;
                bullet.rotation = transform.rotation;
                bullet.velocity = transform.forward * bulletSpeed;
                bullet.GetComponent<Bullet>().ResetLifeTime();
            }
        }
	}
}
