using UnityEngine;
using System.Collections;
using InControl;

public class Shoot : MonoBehaviour
{
    // Enables gamepad input
    InputDevice device;

    [Tooltip("Projectile prefab")]
    public Rigidbody projectile;

    [Space()]
    [Header("Bullet Properties")]
    [Tooltip("How fast the bullet travels")]
    public float bulletSpeed = 100f;

    [Tooltip("Sets maximum number of bullets active")]
    public int bulletPool = 20; 

    [Tooltip("Bullets fired per second")]
    public int fireRate = 10;

    // Array to contain bullets
    private Rigidbody[] projectilePool;

    // Timer to control rate of fire
    private float fireTimer = 0;
    private float fireTiming;


	// Use this for initialization
	void Start ()
    {
        // Initializes gamepad if plugged in
        device = InputManager.ActiveDevice;

        // Sets timing on bullet fire rate
        fireTiming = 1f / (float)fireRate;

        // Pre-allocating bullets
        projectilePool = new Rigidbody[bulletPool];
        for(int i = 0; i < projectilePool.Length; ++i)
        {
            Rigidbody bullet = Instantiate(projectile) as Rigidbody;
            bullet.gameObject.SetActive(false);
            bullet.hideFlags = HideFlags.HideInHierarchy;
            Physics.IgnoreCollision(bullet.GetComponent<Collider>(), transform.parent.parent.GetComponent<Collider>()); // Removes collision between bullet and shooter
            projectilePool[i] = bullet;
        }
	}

    // Not used
    IEnumerator Despawn(Rigidbody bullet, float time)
    {
        yield return new WaitForSeconds(time);
        bullet.gameObject.SetActive(false);
    }

	// Update is called once per frame
	void Update ()
    {
        // Reduces fireTimer based on deltaTime
        fireTimer -= Time.deltaTime;

        // Checks for fire trigger and fires if fireTimer is below 0
        if ((device.RightTrigger.IsPressed || Input.GetMouseButton(0) ) && fireTimer <= 0)
        {
            // Resets timer
            fireTimer = fireTiming;


            Rigidbody bullet = null;

            // Selects an inactive bullet to fire
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
                // Fires bullet from spawner position
                bullet.position = transform.position;
                bullet.rotation = transform.rotation;
                bullet.velocity = transform.forward * bulletSpeed;
                bullet.GetComponent<Bullet>().ResetLifeTime();
            }
        }
	}
}
