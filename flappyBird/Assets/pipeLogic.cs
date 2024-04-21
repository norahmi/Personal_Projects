using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class pipeLogic : MonoBehaviour
{
    private float speed = 6.0f;
    private float deadZone = -45;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.position = transform.position + Vector3.left * speed * Time.deltaTime;

        if (transform.position.x < deadZone)
        {
            Destroy(gameObject);
        }
    }

    public void updateSpawnRate(float offset)
    {
        this.speed += offset;
        Debug.Log("incrementing speed " + speed);
    }
}
