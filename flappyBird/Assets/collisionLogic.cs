using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class collisionLogic : MonoBehaviour
{
 
    public gameLogic gameLogic;

    void Start()
    {
        gameLogic = GameObject.FindGameObjectWithTag("gameLogic").GetComponent<gameLogic>();
    }

    void Update()
    {
        
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log(collision.gameObject.layer);
        if(collision.gameObject.layer == 3)
            gameLogic.incrementScore(1);
    }
}
