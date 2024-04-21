using System.Collections;
using System.Collections.Generic;
using System.Threading;
using UnityEngine;

public class birdLogic : MonoBehaviour
{
    public Rigidbody2D birdBody;
    public gameLogic gameLogic;
    public Sprite bird1;
    public Sprite bird2;
    public Sprite deadBird;
    private int flapStrength;
    private int counter;
    private Sprite nextBird;
    private bool alive;
 
    void Start()
    {
        gameLogic = GameObject.FindGameObjectWithTag("gameLogic").GetComponent<gameLogic>();
        flapStrength = 10;
        counter = 0;
        nextBird = bird2;
        alive = true;
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) == true && alive) {
            birdBody.velocity = Vector2.up * flapStrength;
        }
    }

    public void increaseDifficulty()
    {
        birdBody.velocity = Vector2.one + birdBody.velocity;
        birdBody.gravityScale += 0.5f;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        alive = false;
        this.GetComponent<SpriteRenderer>().sprite = deadBird;
        gameLogic.gameOver();
    }

    public bool isAlive()
    {
        return alive;
    }
}
