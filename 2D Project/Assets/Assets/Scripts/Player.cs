using UnityEngine;
using System.Collections;

public class Player : MonoBehaviour
{
    public float jumpSpeed = 1f;
    public float force = 50f;
    public float maxSpeed = 1f;

    private Animator animator;
    private Rigidbody2D rigidBody;

    bool isGrounded = false;

    // Use this for initialization
    void Start ()
    {
        animator = GetComponent<Animator>();
        rigidBody = GetComponent<Rigidbody2D>();
	}
	
    void Jump()
    {
        rigidBody.AddForce(new Vector2(0, jumpSpeed), ForceMode2D.Impulse);
    }

    void Update()
    {
        if (isGrounded)
        {
            if (Input.GetButtonDown("Jump"))
            {
                Jump();
            }
        }   

    }

	// Update is called once per frame
	void FixedUpdate ()
    {
        if (Physics2D.CircleCast(transform.position, .21f, Vector2.down, .25f + .03f, LayerMask.GetMask("Ground")))
        {
            isGrounded = true;
        }
        else
            isGrounded = false;

       
        float horizontal = Input.GetAxis("Horizontal");

        horizontal *= (isGrounded) ? force : (force * .3f);
        
        rigidBody.AddForce(new Vector2(horizontal, 0), ForceMode2D.Force);

        GetComponent<SpriteRenderer>().flipX = (horizontal < 0) ? true : false;

        animator.SetFloat("YVel", rigidBody.velocity.y);

        Vector2 velocity = rigidBody.velocity;
        velocity.x = Mathf.Clamp(rigidBody.velocity.x, -maxSpeed, maxSpeed);
        rigidBody.velocity = velocity;

        animator.SetFloat("MoveSpeed", Mathf.Abs(velocity.x));
        

        animator.SetBool("IsGrounded", isGrounded);


	}
}
